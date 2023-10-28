# sfm_sandbox
A sandbox for playing with Structure from motion


# Getting started    
The whole dev environment is contained within the docker image. To build this image for the first time run: `./docker/build_docker.sh --rebuild`. The `--rebuild` flag just makes sure to build the base image also. If you need extra dependancies in your image/container you can add them to `Dockerfile.amd` and rerun without the `--rebuild` flag.

To start the container and get a terminal inside run: `./docker/create_or_start_container.sh`. This will handle the creation, startup and cleanup of a new docker container. It will also leave you inside a shell that is inside the container. Your local version of the code is mounted to this container so make any edits you want to the code in your editor locally and then compile from inside the container. The headers from inside the container are also copied to your local system to make Intelisense happy.

The first time you get everything setup you will have to manually build once.
`cd sfm_sandbox/sfm_sandbox`
`mkdir build`
`cd build`
`cmake ../`
`make`

To run from the terminal you can run `./SFMsandbox {path to image folder}` in the bin folder `sandbox/sfm_sandbox/build/bin`. 


If you are using VSCode then you will be able to build easily by just pressing `CTRL-Shift-B`>
To run tests in VSCode you can press `CTRL-Shift-P` and then search for a task called `Run test task`
To build and run use `CTRL-Shift-D` to bring up the debug tab and then use the `Build and run in already running container` task
You can also build and debug from this menu


# Psuedo code for next steps
* Assume that images are sequential
* Make feature matching frame to frame
* Make visualizer show 3D camera positions
* Calculate poses using fundamental matrix - compare to ground truth
* Calculate poses using essential matrix - compare to ground truth
* Add robustness to see how this effects the results
  * Use cross matching for features
  * RANSAC for matching using more points
* Use GTSAM for bundle adjustment