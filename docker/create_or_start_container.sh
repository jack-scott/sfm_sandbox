#!/bin/bash
set -e
# Set default values for image name and container name
IMAGE_NAME="sfm_sandbox"
CONTAINER_NAME="sfm_build_env"

#If arg is run, run the container
# ARG="./main.py"

#get script location
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
DIR="$(dirname "$DIR")"

# Parse command line arguments for image name and container name
while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
        -i|--image-name)
        IMAGE_NAME="$2"
        shift # past argument
        shift # past value
        ;;
        -c|--container-name)
        CONTAINER_NAME="$2"
        shift # past argument
        shift # past value
        ;;
        *)    # unknown option
        echo "Unknown option: $1"
        exit 1
        ;;
    esac
done

# Check if container exists and is running
if [ ! "$(docker ps -q -f name=$CONTAINER_NAME)" ]; then
    # Check if container exists but is stopped
    if [ "$(docker ps -aq -f status=exited -f name=$CONTAINER_NAME)" ]; then
        # Remove stopped container
        echo "Removing old container"
        docker rm $CONTAINER_NAME
    fi
    echo "Creating container"
    docker create -it --name $CONTAINER_NAME \
    --privileged \
    --env DISPLAY=$DISPLAY  \
    --volume="$HOME/.Xauthority:/root/.Xauthority:rw" \
    --volume /tmp/.X11-unix:/tmp/.X11-unix \
    --volume $DIR:/home/user/$(basename $DIR) \
    --volume /etc/localtime:/etc/localtime:ro \
    --net=host \
    $IMAGE_NAME \
    bash
    echo "Removing old headers"
    rm -rf $DIR/.container_headers
    mkdir -p $DIR/.container_headers/usr/include
    mkdir -p $DIR/.container_headers/usr/local/include

    echo "Copying headers and libraries from container"
    # Make local copy of the headers
    docker cp -L $CONTAINER_NAME:/usr/include $DIR/.container_headers/usr/include
    docker cp -L $CONTAINER_NAME:/usr/local/include $DIR/.container_headers/usr/local/include

    # Start the Docker container
    echo "Starting container"
    docker start $CONTAINER_NAME

    # Attach to the container's console
    echo "Attaching to container"
    docker exec -it $CONTAINER_NAME bash

else
    # Container is already running, attach to the container's console'
    echo "Attaching to container"
    docker exec -it $CONTAINER_NAME bash
fi