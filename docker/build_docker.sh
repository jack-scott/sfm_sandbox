#!/bin/bash

# relative path to the Dockerfile
DOCKERFILE="docker/Dockerfile.amd"
DEFAULT_IMAGE_NAME="sfm_sandbox"

BASE_DOCKERFILE="docker/Dockerfile.base"
DEFAULT_BASE_IMAGE_NAME="sfm_base"

# get absolute location of script directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# get parent directory of that
DIR="$(dirname "$DIR")"

# change to that directory
cd "$DIR"

# Parse command line arguments for image name or rebuild flag
while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
        -i|--image-name)
        IMAGE_NAME="$2"
        shift # past argument
        shift # past value
        ;;
        -r|--rebuild)
        REBUILD="true"
        shift # past argument
        ;;
        *)    # unknown option
        echo "Unknown option: $1"
        exit 1
        ;;
    esac
done

# Set default image and container names if not specified
IMAGE_NAME="${IMAGE_NAME:-$DEFAULT_IMAGE_NAME}"
REBUILD="${REBUILD:-false}"

# First build and tag the base image if requested
if [ "$REBUILD" = true ] ; then
    echo "Rebuilding base image"
    docker build -t $DEFAULT_BASE_IMAGE_NAME -f $BASE_DOCKERFILE --target opencv_gtsam .
fi


# Build the Docker image
docker build -t $IMAGE_NAME -f $DOCKERFILE .
