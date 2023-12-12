#include <iostream>
#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>

void plot_genweights(string infile="") {
    // Open the ROOT file
    TFile* file = TFile::Open(infile.c_str());
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Cannot open the file 'anal.root'!" << std::endl;
        return;
    }

    TCanvas* canvas = new TCanvas("canvas", "wLHErew Comparison", 800, 600);
    canvas->SetGrid();

    TLegend* legend = new TLegend(0.7, 0.6, 0.9, 0.9);

    std::vector<int> lineColors = {2, 3, 4, 6, 7, 28, 46, 9, 30, 12, 41};

    int i = 1;
    TString histName = "h_Generator_weight";
    TH1* tempHist = dynamic_cast<TH1*>(file->Get(histName));
    if (!tempHist) {
        std::cerr << "Histogram '" << histName << "' not found!" << std::endl;
    }

    tempHist->SetLineColor(lineColors[i]); // Assign different colors to each histogram
    tempHist->SetLineWidth(2);
    tempHist->Draw("SAME");
    legend->AddEntry(tempHist, "gen weights", "l");

    legend->Draw();
    // Set Y-axis to logarithmic scale
    canvas->SetLogy();
    // Update the canvas
    canvas->Update();
    std::string basename_infile = (infile.size() > 5 && infile.substr(infile.size() - 5) == ".root")
                                ? infile.substr(0, infile.size() - 5)
                                : infile;
    canvas->Print((basename_infile + "_h_Generator_weight_comparison.pdf").c_str());
}

