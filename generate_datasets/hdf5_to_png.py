import h5py
import numpy as np
import argparse
import PIL.Image as Image
import code
import os
from shell_helper import InteractiveShellHelper

if __name__ == "__main__":
    # helper = InteractiveShellHelper()
    argparse = argparse.ArgumentParser()
    argparse.add_argument("--input_dir", type=str, required=True)
    argparse.add_argument("--output_dir", type=str, required=True)
    argparse.add_argument("--datatype", type=str, default="colors")
    args = argparse.parse_args()
    datatype = args.datatype
    
    #if output_dir does not exist, create it
    if not os.path.exists(args.output_dir):
        os.makedirs(args.output_dir)
    
    #find all hdf5 files in input_dir
    files = os.listdir(args.input_dir)
    files = [f for f in files if f.endswith(".hdf5")]

    for file_name in files:
        file_path = os.path.join(os.path.abspath(args.input_dir), file_name)
        output_path = os.path.join(os.path.abspath(args.output_dir), f"{file_name.strip('.hdf5')}.png")
        with h5py.File(file_path) as data:
            image = Image.fromarray(np.array(data[datatype]))
            image.save(output_path, "PNG")
            print(f"Saved {output_path}")