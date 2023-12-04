#include <iostream>
#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>

void plot_difference() {
    // Open the ROOT file
    TFile* file = TFile::Open("anal.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Cannot open the file 'anal.root'!" << std::endl;
        return;
    }

    TCanvas* canvas = new TCanvas("canvas", "Difference Comparison", 800, 600);
    canvas->SetGrid();

    std::vector<int> lineColors = {2, 3, 4, 6, 7, 28, 46, 9, 30, 12, 41};
    std::vector<double> weights = {0.23151, 0.23154, 0.23157, 0.2230, 0.2300, 0.2305, 0.2310, 0.2315, 0.2320, 0.2325, 0.2330};
    std::vector<TString> labels;
    for (size_t i = 0; i < weights.size(); ++i) {
        labels.push_back(Form("s2w = %.5f", weights[i]));
    }

    TPad* pad1 = new TPad("pad1", "pad1", 0.0, 0.3, 1.0, 1.0);
    pad1->SetBottomMargin(0.001);
    pad1->Draw();
    pad1->SetGridy();
    pad1->cd();

    TH1* hist[11];
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);

    for (int i = 0; i <= 10; ++i) {
        if (i == 1 || i == 3 || i == 4 || i == 10) {
          TString histName_fwd = Form("h_dsig_dmll_fwd_w%d", i);
          TString histName_bkw = Form("h_dsig_dmll_bkw_w%d", i);

          TH1* hist_fwd = dynamic_cast<TH1*>(file->Get(histName_fwd));
          TH1* hist_bkw = dynamic_cast<TH1*>(file->Get(histName_bkw));

          if (!hist_fwd || !hist_bkw) {
              std::cerr << "Histogram pair not found for w" << i << std::endl;
              continue;
          }

          hist[i] = static_cast<TH1*>(hist_fwd->Clone());
          hist[i]->SetName(Form("h_dsig_dmll_diff_w%d", i));
          hist[i]->SetTitle("A_{FB} vs. m_{ll}");
          hist[i]->SetStats(kFALSE);

          for (int bin = 1; bin <= hist_fwd->GetNbinsX(); ++bin) {
              double fwd_content = hist_fwd->GetBinContent(bin);
              double bkw_content = hist_bkw->GetBinContent(bin);

              double diff = 0.0;
              if (fwd_content + bkw_content != 0) {
                  diff = (fwd_content - bkw_content) / (fwd_content + bkw_content);
              }

              hist[i]->SetBinContent(bin, diff);
              hist[i]->SetBinError(bin, 0);
          }

          hist[i]->SetLineColor(lineColors[i]); // Assign different colors to each histogram
          hist[i]->SetLineWidth(1);

          if (i == 0) {
              hist[i]->Draw();
          } else {
              hist[i]->Draw("SAME");
          }
          legend->AddEntry(hist[i], labels[i], "l");
       }
    }

    legend->Draw();

    // Create and draw the bottom pad
    canvas->cd();

    TPad* pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();
    pad2->cd();
    pad2->SetGridy();

    TH1* hist_diff[11];
    for (int i = 1; i <= 10; ++i) {
        if (i == 1 || i == 3 || i == 4 || i == 10) {
          hist_diff[i] = static_cast<TH1*>(hist[i]->Clone());
          hist_diff[i]->SetStats(kFALSE);
//          hist_diff[i]->Add(hist[0], -1); // Subtract hist[0]

          hist_diff[i]->SetLineColor(lineColors[i]); // Assign different colors to each histogram
          for (int bin = 1; bin <= hist_diff[i]->GetNbinsX(); ++bin) {
            hist_diff[i]->SetBinContent(bin, (hist[i]->GetBinContent(bin) - hist[1]->GetBinContent(bin)) / hist[1]->GetBinContent(bin) * 100.);
            hist_diff[i]->SetBinError(bin, 0);
          }
          hist_diff[i]->SetLineWidth(1);
          hist_diff[i]->Draw(i == 1 ? "" : "SAME");
          hist_diff[i]->GetYaxis()->SetRangeUser(-100., 100.);
       }
    }


    // Update the canvas
    canvas->Update();
    canvas->Print("AFB_comparison.pdf");
}

