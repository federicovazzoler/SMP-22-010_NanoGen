#!/bin/python3

import uproot
import pandas as pd
import numpy as np
import argparse
import os

def get_histogram_dataframe_from_input_file(histo_name, input_file_path):
  try:
    root_file = uproot.open(input_file_path)
  except:
    raise Exception(f"Unable to open '{input_file_path}'")

  if histo_name not in root_file:
    raise Exception(f"Unable to find '{histo_name}' in file '{input_file_path}'")

  histogram = root_file[histo_name]
  bin_edges = histogram.axis().edges()
  bin_content = histogram.values()
  bin_errors = histogram.errors()

  # Create the DataFrame
  data_dict = {
    "bin_center": (bin_edges[1:] + bin_edges[:-1]) / 2,
    "bin_content": bin_content,
    "bin_error": bin_errors
  }
  df = pd.DataFrame(data_dict)

  return df

def compute_AFB(NF, delta_NF, NB, delta_NB):
  AFB = (NF - NB) / (NF + NB)
  delta_AFB = np.sqrt(np.power(2. * NB / np.power(NF + NB, 2) * delta_NF, 2) + np.power(2. * NF / np.power(NF + NB, 2) * delta_NB, 2))

  return AFB, delta_AFB

def compute_A4(NF, delta_NF, NB, delta_NB):
  AFB, delta_AFB = compute_AFB(NF, delta_NF, NB, delta_NB)

  return 8./3.*AFB, 8./3.*delta_AFB

def save_dataframe(df, file_path):
  df.to_pickle(file_path)
  print(file_path, "created")

def parse_arguments():
  parser = argparse.ArgumentParser()
  parser.add_argument("-i", "--input_file_path", help="Input file path", type=str, required=True)
  parser.add_argument("-o", "--output_folder_path", help="Output folder path", type=str, required=True)

  return parser.parse_args()

def main():
  args = parse_arguments()

  # create output folder
  os.makedirs(args.output_folder_path, exist_ok=True)

  # Define inputs
  hist_type_list = [ 
    ["h_dsig_dmll_fwd_w0", "h_dsig_dmll_bkw_w0", "h_A4_mll_w0"],
    ["h_dsig_dmll_fwd_w1", "h_dsig_dmll_bkw_w1", "h_A4_mll_w1"],
    ["h_dsig_dmll_fwd_w2", "h_dsig_dmll_bkw_w2", "h_A4_mll_w2"],
    ["h_dsig_dmll_fwd_w3", "h_dsig_dmll_bkw_w3", "h_A4_mll_w3"],
    ["h_dsig_dmll_fwd_w4", "h_dsig_dmll_bkw_w4", "h_A4_mll_w4"],
    ["h_dsig_dmll_fwd_w5", "h_dsig_dmll_bkw_w5", "h_A4_mll_w5"],
    ["h_dsig_dmll_fwd_w6", "h_dsig_dmll_bkw_w6", "h_A4_mll_w6"],
    ["h_dsig_dmll_fwd_w7", "h_dsig_dmll_bkw_w7", "h_A4_mll_w7"],
    ["h_dsig_dmll_fwd_w8", "h_dsig_dmll_bkw_w8", "h_A4_mll_w8"],
    ["h_dsig_dmll_fwd_w9", "h_dsig_dmll_bkw_w9", "h_A4_mll_w9"],
    ["h_dsig_dmll_fwd_w10", "h_dsig_dmll_bkw_w10", "h_A4_mll_w10"],

    ["h_A4_yll_mll_fwd_w0", "h_A4_yll_mll_bkw_w0", "h_A4_yll_mll_w0"],
    ["h_A4_yll_mll_fwd_w1", "h_A4_yll_mll_bkw_w1", "h_A4_yll_mll_w1"],
    ["h_A4_yll_mll_fwd_w2", "h_A4_yll_mll_bkw_w2", "h_A4_yll_mll_w2"],
    ["h_A4_yll_mll_fwd_w3", "h_A4_yll_mll_bkw_w3", "h_A4_yll_mll_w3"],
    ["h_A4_yll_mll_fwd_w4", "h_A4_yll_mll_bkw_w4", "h_A4_yll_mll_w4"],
    ["h_A4_yll_mll_fwd_w5", "h_A4_yll_mll_bkw_w5", "h_A4_yll_mll_w5"],
    ["h_A4_yll_mll_fwd_w6", "h_A4_yll_mll_bkw_w6", "h_A4_yll_mll_w6"],
    ["h_A4_yll_mll_fwd_w7", "h_A4_yll_mll_bkw_w7", "h_A4_yll_mll_w7"],
    ["h_A4_yll_mll_fwd_w8", "h_A4_yll_mll_bkw_w8", "h_A4_yll_mll_w8"],
    ["h_A4_yll_mll_fwd_w9", "h_A4_yll_mll_bkw_w9", "h_A4_yll_mll_w9"],
    ["h_A4_yll_mll_fwd_w10", "h_A4_yll_mll_bkw_w10", "h_A4_yll_mll_w10"],
  ]

  for hist_type in hist_type_list:
    # Get F and B dataframes
    df_fwd = get_histogram_dataframe_from_input_file(hist_type[0], args.input_file_path)
    df_bkw = get_histogram_dataframe_from_input_file(hist_type[1], args.input_file_path)

    # Compute A4 dataframe
    df_A4 = pd.DataFrame()
    df_A4["bin index"] = df_fwd["bin_center"]

    # Constants for the ranges
    yll_ranges = [0.0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.5]
    mll_ranges = [46., 54., 66., 76., 82., 86., 89., 92., 96., 100., 106., 116., 150.]
    yll_bins = []
    mll_bins = []
    
    for yll_bin in range(len(yll_ranges) - 1):
        for mll_bin in range(len(mll_ranges) - 1):
            yll_bins.append([yll_ranges[yll_bin], yll_ranges[yll_bin + 1]])
            mll_bins.append([mll_ranges[mll_bin], mll_ranges[mll_bin + 1]])
#    df_A4["yll_min"] = [bin[0] for bin in yll_bins]
#    df_A4["yll_max"] = [bin[1] for bin in yll_bins]
#    df_A4["mll_min"] = [bin[0] for bin in mll_bins]
#    df_A4["mll_max"] = [bin[1] for bin in mll_bins]
    df_A4["$A_4$"], df_A4["MC. unc."] = compute_A4(df_fwd["bin_content"], df_fwd["bin_error"], df_bkw["bin_content"], df_bkw["bin_error"])

    # Save A4 dataframe to file
    save_dataframe(df_A4, os.path.join(args.output_folder_path, hist_type[2] + ".pkl"))

if __name__ == "__main__":
    main()
