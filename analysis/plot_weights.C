#include <iostream>
#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>

void plot_weights() {
    // Open the ROOT file
    TFile* file = TFile::Open("anal.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Cannot open the file 'anal.root'!" << std::endl;
        return;
    }

    TCanvas* canvas = new TCanvas("canvas", "wLHErew Comparison", 800, 600);
    canvas->SetGrid();

    TH1* hist[11];
    TLegend* legend = new TLegend(0.7, 0.6, 0.9, 0.9);

    std::vector<int> lineColors = {2, 3, 4, 6, 7, 28, 46, 9, 30, 12, 41};

    // Weight labels
    std::vector<double> weights = {0.23151, 0.23154, 0.23157, 0.2230, 0.2300, 0.2305, 0.2310, 0.2315, 0.2320, 0.2325, 0.2330};
    std::vector<TString> labels;
    for (size_t i = 0; i < weights.size(); ++i) {
        labels.push_back(Form("s2w = %.5f", weights[i]));
    }

    int i = 1;
    TString histName = Form("h_LHErew_w%d", i);
    TH1* tempHist = dynamic_cast<TH1*>(file->Get(histName));
    if (!tempHist) {
        std::cerr << "Histogram '" << histName << "' not found!" << std::endl;
    }

    hist[i] = static_cast<TH1*>(tempHist->Clone());
    hist[i]->SetLineColor(lineColors[i]); // Assign different colors to each histogram
    hist[i]->SetLineWidth(2);
    hist[i]->Draw("SAME");
    legend->AddEntry(hist[i], labels[i], "l");

    for (int i = 0; i <= 10; ++i) {
        if (i != 1) {
          TString histName = Form("h_LHErew_w%d", i);
          TH1* tempHist = dynamic_cast<TH1*>(file->Get(histName));
          if (!tempHist) {
              std::cerr << "Histogram '" << histName << "' not found!" << std::endl;
              continue;
          }

          hist[i] = static_cast<TH1*>(tempHist->Clone());
          hist[i]->SetLineColor(lineColors[i]); // Assign different colors to each histogram
          hist[i]->SetLineWidth(2);

              hist[i]->Draw("SAME");
              legend->AddEntry(hist[i], labels[i], "l");
       }
    }

    legend->Draw();
    // Set Y-axis to logarithmic scale
    canvas->SetLogy();
    // Update the canvas
    canvas->Update();
    canvas->Print("wLHErew_comparison.pdf");
}

