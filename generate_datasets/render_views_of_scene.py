import blenderproc as bproc

import argparse 
import numpy as np
import os

if __name__ == "__main__":
    argparse = argparse.ArgumentParser()
    argparse.add_argument("--output_dir", type=str, required=True)
    
    args = argparse.parse_args()
    #if output_dir does not exist, create it
    if not os.path.exists(args.output_dir):
        os.makedirs(args.output_dir)

    # Initialize the library
    bproc.init()
    # Create a simple object:
    obj = bproc.object.create_primitive("MONKEY")

    # Create a point light next to it
    light = bproc.types.Light()
    light.set_location([2, -2, 0])
    light.set_energy(300)

    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([0, -5, 0], [np.pi / 2, 0, 0])
    bproc.camera.add_camera_pose(cam_pose)


    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([1, -5, 0], [np.pi / 2, 0, 0])
    bproc.camera.add_camera_pose(cam_pose)

    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([1, -5, 0], [np.pi / 2, 0.5, 0])
    bproc.camera.add_camera_pose(cam_pose)
    
    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([1, -5, 0], [np.pi / 2, 0, 0.3])
    bproc.camera.add_camera_pose(cam_pose)
    
    
    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([1.8, -5, 0], [np.pi / 2, 0, 0.3])
    bproc.camera.add_camera_pose(cam_pose)
    
    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([2.5, -5, 0], [np.pi / 2, 0, 0.3])
    bproc.camera.add_camera_pose(cam_pose)
    
    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([2.5, -5, 2], [np.pi / 2, 0, 0.3])
    bproc.camera.add_camera_pose(cam_pose)
    
    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([-2.2, -5, 2], [np.pi / 3, 0, -0.35])
    bproc.camera.add_camera_pose(cam_pose)
    
    # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([-2.2, -5, 2], [np.pi / 3, 0, -0.35])
    bproc.camera.add_camera_pose(cam_pose)
    
        # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([-2.2, -5, 0], [np.pi / 3, 0, -0.35])
    bproc.camera.add_camera_pose(cam_pose)
    
        # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([-2.2, -5, 2], [np.pi / 3, 0.3, -0.35])
    bproc.camera.add_camera_pose(cam_pose)
    
        # Set the camera to be in front of the object
    cam_pose = bproc.math.build_transformation_mat([-1.2, -5, 2], [np.pi / 2, 0, -0.35])
    bproc.camera.add_camera_pose(cam_pose)
    
    
    # Render the scene
    data = bproc.renderer.render()
    # Write the rendering into a hdf5 file
    bproc.writer.write_hdf5(args.output_dir, data)
