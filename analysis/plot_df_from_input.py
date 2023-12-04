#!/bin/python3

import pandas as pd
import matplotlib.pyplot as plt
import os
from matplotlib.ticker import AutoMinorLocator
import argparse

color_linestyle_marker_list = [
  ["tab:blue", "dotted", "."],
  ["tab:orange", "dotted", "."],
  ["tab:green", "dotted", "."],
  ["tab:red", "dotted", "."],
  ["tab:purple", "dotted", "."],
  ["tab:brown", "dotted", "."],
  ["tab:pink", "dotted", "."],
  ["tab:gray", "dotted", "."],
  ["tab:olive", "dotted", "."],
  ["tab:cyan", "dotted", "."]
]

def parse_arguments():
  parser = argparse.ArgumentParser()
  parser.add_argument("-i", "--input_file_paths", nargs="+", help="Input file(s) path in the form [input_file.pkl:histo title]", type=str, required=True)
  parser.add_argument("-o", "--output_file_path", help="Output file path (relative to /eos/user/f/fvazzole/www/", type=str, required=True)

  return parser.parse_args()

def load_dataframe_from_input_file(input_file_path):
  filename, title = input_file_path.split(":", 1)
  filename = filename.strip()
  title = title.strip()

  try:
    df = pd.read_pickle(filename)
  except:
    raise Exception(f"Unable to load dataframe in '{input_file_path}'")

  df.name = title

  return df

def create_canvas():
  fig, ax = plt.subplots(nrows = 2, ncols = 1, gridspec_kw = {'height_ratios': [6, 4]}, figsize = (15, 10), sharex = True)

  return fig, ax

def save_canvas(fig, output_file_path):
#  www_folder_path = "/eos/user/f/fvazzole/www"
  www_folder_path = "/afs/desy.de/user/v/vazzolef/www/SMP-22-010/gridpacks"
  output_file_path = os.path.join(www_folder_path, output_file_path)

  # create output folder
  os.makedirs(os.path.dirname(output_file_path), exist_ok=True)

  fig.savefig(output_file_path, dpi = 500)
  print(output_file_path, "created")

def plot(x_values, y_values, y_uncertainties, ax, **kwargs):
  if len(x_values) != len(y_values) != len(y_uncertainties):
    raise Exception(f"Unable to plot: len(x_values) != len(y_values) != len(y_uncertainties)")

  y_values = y_values.fillna(0)
  y_uncertainties = [0 if pd.isna(value) else value for value in y_uncertainties]

  ax.errorbar(
    x_values,
    y_values,
    yerr = y_uncertainties,
    capsize = 3,
    fmt='.--',
    marker = kwargs.get('marker', '.'),
    linestyle = kwargs.get('linestyle', 'solid'),
    linewidth = kwargs.get('linewidth', 1.0),
    color = kwargs.get('color', 'black'),
    label = kwargs.get('label', '_label_')
  )

def apply_cosmetics(fig, ax):
  # Create legend
  ax[0].legend(
    loc = (0.01, 0.67),
    ncol = 1,
    fontsize = 15.5,
    frameon = True,
    framealpha = 0,
    edgecolor = "white"
  )

  # Set axes labels
  ax[0].set_ylabel("$A_4(|y_{\ell\ell}|, m_{\ell\ell})$",
                   fontsize = 16,
                   loc = "top")
  ax[1].set_xlabel("$(|y_{\ell\ell}|, m_{\ell\ell})$ bin",
                fontsize = 16,
                loc = "right")

  ax[1].set_ylabel("$\Delta A_4$ wrt. PHOTOS",
                   fontsize = 16,
                   loc = "top")

  # Set the y-axis tick label format to scientific notation
  for iax in range(len(ax)):
    ax[iax].ticklabel_format(style='sci', axis='y', scilimits=(0,0))
    ax[iax].tick_params(axis='x', which='both', labelsize = 16, bottom = True, top = True, direction = "in")
    ax[iax].tick_params(axis='y', which='both', labelsize = 16, left = True,right = True, direction = "in")
    ax[iax].grid(axis = 'y', linestyle = '-', linewidth = 0.3, color = 'lightgray')
    ax[iax].grid(which='minor', axis='y', linestyle='-', linewidth=0.3, color = 'lightgray')

  # Set y lim on delta pad
  #ax[0].set_ylim(-1e1, 1e1)
  #x[1].set_ylim(-1e-2, 1e-2)

  # apply tight layout
  fig.set_tight_layout(True)

def main():
  args = parse_arguments()

  # Load dataframes
  dfs = [load_dataframe_from_input_file(input_file_path) for input_file_path in args.input_file_paths]

  # Load Aleko's numbers
  #df_unc_data = pd.read_csv("dA4.txt", header=None, names=["data unc"])

  # Create canvas
  fig, ax = create_canvas()

  # Plot the input files
  # Plot data unc.
  #plot(dfs[0]["bin index"], [0.0 for i in range(len(dfs[0]["$A_4$"]))], df_unc_data["data unc"], ax[1], color = "black")
  #ax[1].fill_between(dfs[0]["bin index"], 0.0 + df_unc_data["data unc"], 0.0 - df_unc_data["data unc"], facecolor = "whitesmoke", edgecolor = "black", hatch = "", alpha = 1, label = "Data unc.")
  # Plot A4 distributions
  for iplot, df in enumerate(dfs):
    # Plot A4
    plot(df["bin index"], df["$A_4$"], df["MC. unc."], ax[0], linestyle = "None", color = color_linestyle_marker_list[iplot][0], label = df.name)
    # Plot Delta A4
    plot(df["bin index"], df["$A_4$"] - dfs[0]["$A_4$"], [0.0 for i in range(len(dfs[0]["$A_4$"]))], ax[1], color = color_linestyle_marker_list[iplot][0])
    # Plot MC. unc. on A4
    plot(df["bin index"], dfs[0]["$A_4$"] - dfs[0]["$A_4$"], dfs[0]["MC. unc."], ax[1], color = color_linestyle_marker_list[0][0])
  # Plot vertical lines to separate yll bins
  #yll_bins_boundaries = [12.5, 24.5, 36.5, 48.5, 60.5]
  #for x in yll_bins_boundaries:
    #ax[0].axvline(x = x, color = 'red', linestyle=':')
    #ax[1].axvline(x = x, color = 'red', linestyle=':')

  apply_cosmetics(fig, ax)

  save_canvas(fig, args.output_file_path)

if __name__ == "__main__":
    main()
