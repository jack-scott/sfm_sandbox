#!/bin/bash

# relative path to the Dockerfile
DOCKERFILE="docker/Dockerfile.amd"
DEFAULT_IMAGE_NAME="sfm_sandbox"

# get absolute location of script directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# get parent directory of that
DIR="$(dirname "$DIR")"

# change to that directory
cd "$DIR"

# Parse command line arguments for image name
while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
        -i|--image-name)
        IMAGE_NAME="$2"
        shift # past argument
        shift # past value
        ;;
        *)    # unknown option
        echo "Unknown option: $1"
        exit 1
        ;;
    esac
done

# Set default image and container names if not specified
IMAGE_NAME="${IMAGE_NAME:-$DEFAULT_IMAGE_NAME}"

# Build the Docker image
docker build -t $IMAGE_NAME -f $DOCKERFILE .
