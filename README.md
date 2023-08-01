# sfm_sandbox
A sandbox for playing with Structure from motion


# Getting started    
The whole dev environment is contained within the docker image. To build this image for the first time run: `./docker/build_docker.sh --rebuild`. The `--rebuild` flag just makes sure to build the base image also. If you need extra dependancies in your image/container you can add them to `Dockerfile.amd` and rerun without the `--rebuild` flag.

To start the container and get a terminal inside run: `./docker/create_or_start_container.sh`. This will handle the creation, startup and cleanup of a new docker container. It will also leave you inside a shell that is inside the container. Your local version of the code is mounted to this container so make any edits you want to the code and then compile from inside the container. The headers from inside the container are also copied to your local system to make Intelisense happy.