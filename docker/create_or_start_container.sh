#!/bin/bash

# Set default values for image name and container name
IMAGE_NAME="scraper_image"
CONTAINER_NAME="marketplace_scraper"

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
    # Create and start the Docker container
    docker run -it --name $CONTAINER_NAME \
        --privileged \
        --env DISPLAY=$DISPLAY  \
        --volume="$HOME/.Xauthority:/root/.Xauthority:rw" \
        --volume /tmp/.X11-unix:/tmp/.X11-unix \
        --volume $DIR:/$(basename $DIR) \
        --volume /etc/localtime:/etc/localtime:ro \
        --net=host \
        $IMAGE_NAME \
        bash
else
    # Container is already running, attach to the container's console'
    echo "Attaching to container"
    docker attach $CONTAINER_NAME
fi