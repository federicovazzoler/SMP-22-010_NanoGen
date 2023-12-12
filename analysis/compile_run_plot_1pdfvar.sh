~/DUST/analysis-tools/compile_selector.sh myselector.C
~/DUST/analysis-tools/run_selector.sh -s myselector.C -t Events -i ../filelist_1pdfvar.lst -o anal_1pdfvar.root
root -b -q    plot_weights.C\(\"anal_1pdfvar.root\"\)
root -b -q plot_difference.C\(\"anal_1pdfvar.root\"\)
root -b -q plot_genweights.C\(\"anal_1pdfvar.root\"\)
root -b -q  plot_PSweights.C\(\"anal_1pdfvar.root\"\)

#./create_df_from_input.py -i anal.root -o anal_hists
#./plot_all.sh
