#~/DUST/analysis-tools/compile_selector.sh myselector.C
#~/DUST/analysis-tools/run_selector.sh -s myselector.C -t Events -i ../filelist.lst -o anal.root
root -b -q    plot_weights.C\(\"anal.root\"\)
root -b -q plot_difference.C\(\"anal.root\"\)
root -b -q plot_genweights.C\(\"anal.root\"\)
root -b -q  plot_PSweights.C\(\"anal.root\"\)

#./create_df_from_input.py -i anal.root -o anal_hists
#./plot_all.sh
