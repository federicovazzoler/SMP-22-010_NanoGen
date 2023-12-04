#define myselector_cxx
#include "myselector.h"
#include <TStyle.h>
#include <TDatime.h>
#include <TSystem.h>

void myselector::Begin(TTree * /*tree*/) {
  TString option = GetOption();

  TDatime now;
  Info("Begin", "%s", now.AsSQLString());
}

void myselector::SlaveBegin(TTree * /*tree*/) {
  TString option = GetOption();

  TDatime now;
  Info("SlaveBegin", "%s", now.AsSQLString());

  h_nevt = new TH1D("h_nevt", "h_nevt", 1, 0.5, 1.5);

  const double mll_bins[13] = {46., 54., 66., 76., 82., 86., 89., 92., 96., 100., 106., 116., 150.};
//  const double mll_bins[10] = {10., 40., 75., 80., 85., 95., 105., 125., 150., 300.};
  int n_mll_bins = static_cast<int>(arraySize(mll_bins)) - 1; 

  h_LHErew_w0  = new TH1D("h_LHErew_w0", "h_LHERew_w0",   500, 0.9, 1.1);
  h_LHErew_w1  = new TH1D("h_LHErew_w1", "h_LHERew_w1",   500, 0.9, 1.1);
  h_LHErew_w2  = new TH1D("h_LHErew_w2", "h_LHERew_w2",   500, 0.9, 1.1);
  h_LHErew_w3  = new TH1D("h_LHErew_w3", "h_LHERew_w3",   500, 0.9, 1.1);
  h_LHErew_w4  = new TH1D("h_LHErew_w4", "h_LHERew_w4",   500, 0.9, 1.1);
  h_LHErew_w5  = new TH1D("h_LHErew_w5", "h_LHERew_w5",   500, 0.9, 1.1);
  h_LHErew_w6  = new TH1D("h_LHErew_w6", "h_LHERew_w6",   500, 0.9, 1.1);
  h_LHErew_w7  = new TH1D("h_LHErew_w7", "h_LHERew_w7",   500, 0.9, 1.1);
  h_LHErew_w8  = new TH1D("h_LHErew_w8", "h_LHERew_w8",   500, 0.9, 1.1);
  h_LHErew_w9  = new TH1D("h_LHErew_w9", "h_LHERew_w9",   500, 0.9, 1.1);
  h_LHErew_w10 = new TH1D("h_LHErew_w10", "h_LHERew_w10", 500, 0.9, 1.1);

  h_LHEScaleWeight_w0  = new TH1D("h_LHEScaleWeight_w0", "h_LHEScaleWeight_w0",   1000, -10., 10.);
  h_LHEScaleWeight_w1  = new TH1D("h_LHEScaleWeight_w1", "h_LHEScaleWeight_w1",   1000, -10., 10.);
  h_LHEScaleWeight_w2  = new TH1D("h_LHEScaleWeight_w2", "h_LHEScaleWeight_w2",   1000, -10., 10.);
  h_LHEScaleWeight_w3  = new TH1D("h_LHEScaleWeight_w3", "h_LHEScaleWeight_w3",   1000, -10., 10.);
  h_LHEScaleWeight_w4  = new TH1D("h_LHEScaleWeight_w4", "h_LHEScaleWeight_w4",   1000, -10., 10.);
  h_LHEScaleWeight_w5  = new TH1D("h_LHEScaleWeight_w5", "h_LHEScaleWeight_w5",   1000, -10., 10.);
  h_LHEScaleWeight_w6  = new TH1D("h_LHEScaleWeight_w6", "h_LHEScaleWeight_w6",   1000, -10., 10.);
  h_LHEScaleWeight_w7  = new TH1D("h_LHEScaleWeight_w7", "h_LHEScaleWeight_w7",   1000, -10., 10.);
  h_LHEScaleWeight_w8  = new TH1D("h_LHEScaleWeight_w8", "h_LHEScaleWeight_w8",   1000, -10., 10.);  

  h_Generator_weight = new TH1D("h_Generator_weight", "h_Generator_weight", 1000., -100000., 100000.);

  h_dsig_dmll = new TH1D("h_dsig_dmll", "h_dsig_dmll", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w0 = new TH1D("h_dsig_dmll_fwd_w0", "h_dsig_dmll_fwd_w0", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w0 = new TH1D("h_dsig_dmll_bkw_w0", "h_dsig_dmll_bkw_w0", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w1 = new TH1D("h_dsig_dmll_fwd_w1", "h_dsig_dmll_fwd_w1", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w1 = new TH1D("h_dsig_dmll_bkw_w1", "h_dsig_dmll_bkw_w1", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w2 = new TH1D("h_dsig_dmll_fwd_w2", "h_dsig_dmll_fwd_w2", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w2 = new TH1D("h_dsig_dmll_bkw_w2", "h_dsig_dmll_bkw_w2", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w3 = new TH1D("h_dsig_dmll_fwd_w3", "h_dsig_dmll_fwd_w3", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w3 = new TH1D("h_dsig_dmll_bkw_w3", "h_dsig_dmll_bkw_w3", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w4 = new TH1D("h_dsig_dmll_fwd_w4", "h_dsig_dmll_fwd_w4", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w4 = new TH1D("h_dsig_dmll_bkw_w4", "h_dsig_dmll_bkw_w4", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w5 = new TH1D("h_dsig_dmll_fwd_w5", "h_dsig_dmll_fwd_w5", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w5 = new TH1D("h_dsig_dmll_bkw_w5", "h_dsig_dmll_bkw_w5", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w6 = new TH1D("h_dsig_dmll_fwd_w6", "h_dsig_dmll_fwd_w6", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w6 = new TH1D("h_dsig_dmll_bkw_w6", "h_dsig_dmll_bkw_w6", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w7 = new TH1D("h_dsig_dmll_fwd_w7", "h_dsig_dmll_fwd_w7", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w7 = new TH1D("h_dsig_dmll_bkw_w7", "h_dsig_dmll_bkw_w7", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w8 = new TH1D("h_dsig_dmll_fwd_w8", "h_dsig_dmll_fwd_w8", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w8 = new TH1D("h_dsig_dmll_bkw_w8", "h_dsig_dmll_bkw_w8", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w9 = new TH1D("h_dsig_dmll_fwd_w9", "h_dsig_dmll_fwd_w9", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w9 = new TH1D("h_dsig_dmll_bkw_w9", "h_dsig_dmll_bkw_w9", n_mll_bins, mll_bins);

  h_dsig_dmll_fwd_w10 = new TH1D("h_dsig_dmll_fwd_w10", "h_dsig_dmll_fwd_w10", n_mll_bins, mll_bins);
  h_dsig_dmll_bkw_w10 = new TH1D("h_dsig_dmll_bkw_w10", "h_dsig_dmll_bkw_w10", n_mll_bins, mll_bins);

  h_A4_yll_mll_fwd_w0 = new TH1D("h_A4_yll_mll_fwd_w0", "h_A4_yll_mll_fwd_w0", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w0 = new TH1D("h_A4_yll_mll_bkw_w0", "h_A4_yll_mll_bkw_w0", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w1 = new TH1D("h_A4_yll_mll_fwd_w1", "h_A4_yll_mll_fwd_w1", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w1 = new TH1D("h_A4_yll_mll_bkw_w1", "h_A4_yll_mll_bkw_w1", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w2 = new TH1D("h_A4_yll_mll_fwd_w2", "h_A4_yll_mll_fwd_w2", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w2 = new TH1D("h_A4_yll_mll_bkw_w2", "h_A4_yll_mll_bkw_w2", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w3 = new TH1D("h_A4_yll_mll_fwd_w3", "h_A4_yll_mll_fwd_w3", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w3 = new TH1D("h_A4_yll_mll_bkw_w3", "h_A4_yll_mll_bkw_w3", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w4 = new TH1D("h_A4_yll_mll_fwd_w4", "h_A4_yll_mll_fwd_w4", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w4 = new TH1D("h_A4_yll_mll_bkw_w4", "h_A4_yll_mll_bkw_w4", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w5 = new TH1D("h_A4_yll_mll_fwd_w5", "h_A4_yll_mll_fwd_w5", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w5 = new TH1D("h_A4_yll_mll_bkw_w5", "h_A4_yll_mll_bkw_w5", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w6 = new TH1D("h_A4_yll_mll_fwd_w6", "h_A4_yll_mll_fwd_w6", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w6 = new TH1D("h_A4_yll_mll_bkw_w6", "h_A4_yll_mll_bkw_w6", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w7 = new TH1D("h_A4_yll_mll_fwd_w7", "h_A4_yll_mll_fwd_w7", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w7 = new TH1D("h_A4_yll_mll_bkw_w7", "h_A4_yll_mll_bkw_w7", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w8 = new TH1D("h_A4_yll_mll_fwd_w8", "h_A4_yll_mll_fwd_w8", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w8 = new TH1D("h_A4_yll_mll_bkw_w8", "h_A4_yll_mll_bkw_w8", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w9 = new TH1D("h_A4_yll_mll_fwd_w9", "h_A4_yll_mll_fwd_w9", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w9 = new TH1D("h_A4_yll_mll_bkw_w9", "h_A4_yll_mll_bkw_w9", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  h_A4_yll_mll_fwd_w10 = new TH1D("h_A4_yll_mll_fwd_w10", "h_A4_yll_mll_fwd_w10", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);
  h_A4_yll_mll_bkw_w10 = new TH1D("h_A4_yll_mll_bkw_w10", "h_A4_yll_mll_bkw_w10", yll_mll_A4_bins, 0.5, yll_mll_A4_bins + 0.5);

  TObject* obj = 0;
  TIter next(gDirectory->GetList());

  // add all booked histograms to the selector output list
  while ((obj = next())) {
    if (!TString(obj->ClassName()).Contains("TH")) continue;
    if (!TString(obj->GetName()).Contains("h_")) continue;
    GetOutputList()->Add(obj);
  }
}

Bool_t myselector::Process(Long64_t entry) {
  fReader.SetLocalEntry(entry);

  h_nevt->Fill(1);

  double weight_gen = 1.;

  weight_gen = *Generator_weight;

  float s2w_w[11];
  for (int i = 0; i < 11; ++i) {
    s2w_w[i] = LHEReweightingWeight[i];
  }

  int ilep0_gen = -1;
  int ilep1_gen = -1;

  TLorentzVector lep0_gen;
  TLorentzVector lep1_gen;

  bool Z_lep_sel_gen = false;

  for (uint i = 0; i < *nGenDressedLepton; i++) {
//    if (fabs(GenDressedLepton_pdgId[i]) != 13) continue;
//    if (GenDressedLepton_pt[i] < 15) continue;
    if (fabs(GenDressedLepton_eta[i]) > 2.500) continue;

    if (ilep0_gen == -1) {
      ilep0_gen = i;
    } else {
      if (GenDressedLepton_pdgId[i] == GenDressedLepton_pdgId[ilep0_gen]) {
        if (GenDressedLepton_pt[i] > GenDressedLepton_pt[ilep0_gen]) {
          ilep0_gen = i;
        }
      } else {
        if (ilep1_gen == -1) {
          ilep1_gen = i;
        } else {
          if (GenDressedLepton_pt[i] > GenDressedLepton_pt[ilep1_gen]) {
            ilep1_gen = i;
          }
        }
      }
    }
  }

  if (ilep0_gen != -1) {
    lep0_gen.SetPtEtaPhiM(GenDressedLepton_pt[ilep0_gen], GenDressedLepton_eta[ilep0_gen], GenDressedLepton_phi[ilep0_gen], GenDressedLepton_mass[ilep0_gen]);
  }
  if (ilep1_gen != -1) {
    lep1_gen.SetPtEtaPhiM(GenDressedLepton_pt[ilep1_gen], GenDressedLepton_eta[ilep1_gen], GenDressedLepton_phi[ilep1_gen], GenDressedLepton_mass[ilep1_gen]);
  }

  // Order leptons accroding to their charge (+, -)
  int charge_ilep0_gen = GenDressedLepton_pdgId[ilep0_gen]; 
  int charge_ilep1_gen = GenDressedLepton_pdgId[ilep1_gen];

  double Z_lep0_lep1_gen_mll = 0.;
  double Z_lep0_lep1_gen_yll = 0.;
  double Z_lep0_lep1_gen_cll = 0.;

  if (ilep0_gen != -1 && ilep1_gen != -1) {
    Z_lep0_lep1_gen_mll = (lep0_gen + lep1_gen).M();
    Z_lep0_lep1_gen_yll = (lep0_gen + lep1_gen).Rapidity();
    Z_lep0_lep1_gen_cll = (charge_ilep0_gen > 0) ? cosCollinsSoper(lep0_gen, lep1_gen) : cosCollinsSoper(lep1_gen, lep0_gen);

//    if (Z_lep0_lep1_gen_mll >= 46. && (lep0_gen.Pt() > 30 || lep1_gen.Pt() > 30)) {
      Z_lep_sel_gen = true;
//    }
  }

  h_LHErew_w0->Fill(s2w_w[0]); 
  h_LHErew_w1->Fill(s2w_w[1]); 
  h_LHErew_w2->Fill(s2w_w[2]); 
  h_LHErew_w3->Fill(s2w_w[3]); 
  h_LHErew_w4->Fill(s2w_w[4]); 
  h_LHErew_w5->Fill(s2w_w[5]); 
  h_LHErew_w6->Fill(s2w_w[6]); 
  h_LHErew_w7->Fill(s2w_w[7]); 
  h_LHErew_w8->Fill(s2w_w[8]); 
  h_LHErew_w9->Fill(s2w_w[9]); 
  h_LHErew_w10->Fill(s2w_w[10]);

  h_LHEScaleWeight_w0->Fill(LHEScaleWeight[0]);
  h_LHEScaleWeight_w1->Fill(LHEScaleWeight[1]);
  h_LHEScaleWeight_w2->Fill(LHEScaleWeight[2]);
  h_LHEScaleWeight_w3->Fill(LHEScaleWeight[3]);
  h_LHEScaleWeight_w4->Fill(LHEScaleWeight[4]);
  h_LHEScaleWeight_w5->Fill(LHEScaleWeight[5]);
  h_LHEScaleWeight_w6->Fill(LHEScaleWeight[6]);
  h_LHEScaleWeight_w7->Fill(LHEScaleWeight[7]);
  h_LHEScaleWeight_w8->Fill(LHEScaleWeight[8]);
                     
  h_Generator_weight ->Fill(*Generator_weight);

  // Fill here the histos
  if (Z_lep_sel_gen) {
    int yll_mll_bin = 9999; 
    yll_mll_bin = get_yll_mll_bin(Z_lep0_lep1_gen_yll, Z_lep0_lep1_gen_mll);

    if (Z_lep0_lep1_gen_cll > 0.) {
      h_dsig_dmll->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[1]);

      h_dsig_dmll_fwd_w0->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[0]);
      h_dsig_dmll_fwd_w1->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[1]);
      h_dsig_dmll_fwd_w2->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[2]);
      h_dsig_dmll_fwd_w3->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[3]);
      h_dsig_dmll_fwd_w4->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[4]);
      h_dsig_dmll_fwd_w5->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[5]);
      h_dsig_dmll_fwd_w6->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[6]);
      h_dsig_dmll_fwd_w7->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[7]);
      h_dsig_dmll_fwd_w8->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[8]);
      h_dsig_dmll_fwd_w9->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[9]);
      h_dsig_dmll_fwd_w10->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[10]);
      
      h_A4_yll_mll_fwd_w0->Fill(yll_mll_bin, weight_gen * s2w_w[0]);
      h_A4_yll_mll_fwd_w1->Fill(yll_mll_bin, weight_gen * s2w_w[1]);
      h_A4_yll_mll_fwd_w2->Fill(yll_mll_bin, weight_gen * s2w_w[2]);
      h_A4_yll_mll_fwd_w3->Fill(yll_mll_bin, weight_gen * s2w_w[3]);
      h_A4_yll_mll_fwd_w4->Fill(yll_mll_bin, weight_gen * s2w_w[4]);
      h_A4_yll_mll_fwd_w5->Fill(yll_mll_bin, weight_gen * s2w_w[5]);
      h_A4_yll_mll_fwd_w6->Fill(yll_mll_bin, weight_gen * s2w_w[6]);
      h_A4_yll_mll_fwd_w7->Fill(yll_mll_bin, weight_gen * s2w_w[7]);
      h_A4_yll_mll_fwd_w8->Fill(yll_mll_bin, weight_gen * s2w_w[8]);
      h_A4_yll_mll_fwd_w9->Fill(yll_mll_bin, weight_gen * s2w_w[9]);
      h_A4_yll_mll_fwd_w10->Fill(yll_mll_bin, weight_gen * s2w_w[10]);
    } else {
      h_dsig_dmll->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[1]);

      h_dsig_dmll_bkw_w0->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[0]);
      h_dsig_dmll_bkw_w1->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[1]);
      h_dsig_dmll_bkw_w2->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[2]);
      h_dsig_dmll_bkw_w3->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[3]);
      h_dsig_dmll_bkw_w4->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[4]);
      h_dsig_dmll_bkw_w5->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[5]);
      h_dsig_dmll_bkw_w6->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[6]);
      h_dsig_dmll_bkw_w7->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[7]);
      h_dsig_dmll_bkw_w8->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[8]);
      h_dsig_dmll_bkw_w9->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[9]);
      h_dsig_dmll_bkw_w10->Fill(Z_lep0_lep1_gen_mll, weight_gen * s2w_w[10]);

      h_A4_yll_mll_bkw_w0->Fill(yll_mll_bin, weight_gen * s2w_w[0]);
      h_A4_yll_mll_bkw_w1->Fill(yll_mll_bin, weight_gen * s2w_w[1]);
      h_A4_yll_mll_bkw_w2->Fill(yll_mll_bin, weight_gen * s2w_w[2]);
      h_A4_yll_mll_bkw_w3->Fill(yll_mll_bin, weight_gen * s2w_w[3]);
      h_A4_yll_mll_bkw_w4->Fill(yll_mll_bin, weight_gen * s2w_w[4]);
      h_A4_yll_mll_bkw_w5->Fill(yll_mll_bin, weight_gen * s2w_w[5]);
      h_A4_yll_mll_bkw_w6->Fill(yll_mll_bin, weight_gen * s2w_w[6]);
      h_A4_yll_mll_bkw_w7->Fill(yll_mll_bin, weight_gen * s2w_w[7]);
      h_A4_yll_mll_bkw_w8->Fill(yll_mll_bin, weight_gen * s2w_w[8]);
      h_A4_yll_mll_bkw_w9->Fill(yll_mll_bin, weight_gen * s2w_w[9]);
      h_A4_yll_mll_bkw_w10->Fill(yll_mll_bin, weight_gen * s2w_w[10]);
    }
  }

  return kTRUE;
}

void myselector::SlaveTerminate() {
  TDatime now;
  Info("SlaveTerminate", "%s", now.AsSQLString());
}

void myselector::Terminate() {
  TDatime now;
  Info("Terminate", "%s", now.AsSQLString());
}
