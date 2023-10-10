#!/usr/bin/python3.6

import uproot
import matplotlib.pyplot as plt
import argparse
import os
import numpy as np
import awkward as ak

# Main function
def main():
    # Parse command-line arguments
    parser = argparse.ArgumentParser(description="Create TH1 plots from a ROOT file.")
    parser.add_argument("root_file", help="Path to the ROOT file (e.g., A.root)")
    args = parser.parse_args()

    # Get the directory path of the input file
    input_file_dir = os.path.dirname(args.root_file)

    # Extract the base name of the input file
    input_file_base_name = os.path.splitext(os.path.basename(args.root_file))[0]

    # Define the output folder based on the input file's directory
    output_folder = os.path.join(input_file_dir, input_file_base_name)
    os.makedirs(output_folder, exist_ok = True)

    # Open the ROOT file and access the "Events" tree
    root_file = uproot.open(args.root_file)
    tree = root_file["Events"]
    
    # Get the list of leaf names in the tree
    leaf_names = tree.keys()
    
    # Loop through each leaf and create a separate plot
    for leaf_name in leaf_names:
        try:
            # Get the leaf data
            leaf_data = tree[leaf_name].array()

#            # Skip NaN
#            if ak.any(ak.is_none(leaf_data)): continue

            # Create a histogram from the leaf data
            plt.hist(leaf_data, bins=50)  # You can customize the number of bins as needed
            
            # Set plot labels
            plt.xlabel(leaf_name)
            plt.ylabel("Frequency")
            
            # Save the plot as a PNG file with the leaf name as the filename
            plt.savefig(f"{output_folder}/{leaf_name}.png")
            print(f"{output_folder}/{leaf_name}.png", "created")
            print("")
            
            # Clear the plot for the next leaf
            plt.clf()
        except ValueError as e:
            # Handle the ValueError (autodetected range of [nan, nan] is not finite)
            print(f"An error occurred while printing {leaf_name}: {e}")
            continue  # Continue the loop without quitting
    # Close the ROOT file
    root_file.close()
  
if __name__ == "__main__":
    main()
