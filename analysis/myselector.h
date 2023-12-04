//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov 30 15:16:55 2023 by ROOT version 6.24/08
// from TTree Events/Events
// found on file: /afs/cern.ch/user/f/fvazzole/work/smp-22-010_genproduction/MiNNLOSamples/events/Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToMuMu-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-adds2wvars_cfg/SMP-RunIISummer20UL16wmLHEGEN-00645_onlys2wAndScaleWeights_cff.root
//////////////////////////////////////////////////////////

#ifndef myselector_h
#define myselector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TH1D.h>
#include <TLorentzVector.h>
#include <iostream>

// Headers needed by this particular selector


class myselector : public TSelector {
public :
  TTreeReader   fReader;  //!the tree reader
  TTree     *fChain = 0;  //!pointer to the analyzed TTree or TChain

  const double yll_mll_A4_bins = 6*12;

  TH1D* h_nevt = 0;

  TH1D* h_LHErew_w0  = 0;
  TH1D* h_LHErew_w1  = 0;
  TH1D* h_LHErew_w2  = 0;
  TH1D* h_LHErew_w3  = 0;
  TH1D* h_LHErew_w4  = 0;
  TH1D* h_LHErew_w5  = 0;
  TH1D* h_LHErew_w6  = 0;
  TH1D* h_LHErew_w7  = 0;
  TH1D* h_LHErew_w8  = 0;
  TH1D* h_LHErew_w9  = 0;
  TH1D* h_LHErew_w10 = 0;

  TH1D* h_LHEScaleWeight_w0 = 0;
  TH1D* h_LHEScaleWeight_w1 = 0;
  TH1D* h_LHEScaleWeight_w2 = 0;
  TH1D* h_LHEScaleWeight_w3 = 0;
  TH1D* h_LHEScaleWeight_w4 = 0;
  TH1D* h_LHEScaleWeight_w5 = 0;
  TH1D* h_LHEScaleWeight_w6 = 0;
  TH1D* h_LHEScaleWeight_w7 = 0;
  TH1D* h_LHEScaleWeight_w8 = 0;

  TH1D* h_Generator_weight  = 0;

  TH1D* h_dsig_dmll = 0;

  TH1D* h_dsig_dmll_fwd_w0 = 0;
  TH1D* h_dsig_dmll_bkw_w0 = 0;

  TH1D* h_dsig_dmll_fwd_w1 = 0;
  TH1D* h_dsig_dmll_bkw_w1 = 0;

  TH1D* h_dsig_dmll_fwd_w2 = 0;
  TH1D* h_dsig_dmll_bkw_w2 = 0;

  TH1D* h_dsig_dmll_fwd_w3 = 0;
  TH1D* h_dsig_dmll_bkw_w3 = 0;

  TH1D* h_dsig_dmll_fwd_w4 = 0;
  TH1D* h_dsig_dmll_bkw_w4 = 0;

  TH1D* h_dsig_dmll_fwd_w5 = 0;
  TH1D* h_dsig_dmll_bkw_w5 = 0;

  TH1D* h_dsig_dmll_fwd_w6 = 0;
  TH1D* h_dsig_dmll_bkw_w6 = 0;

  TH1D* h_dsig_dmll_fwd_w7 = 0;
  TH1D* h_dsig_dmll_bkw_w7 = 0;

  TH1D* h_dsig_dmll_fwd_w8 = 0;
  TH1D* h_dsig_dmll_bkw_w8 = 0;

  TH1D* h_dsig_dmll_fwd_w9 = 0;
  TH1D* h_dsig_dmll_bkw_w9 = 0;

  TH1D* h_dsig_dmll_fwd_w10 = 0;
  TH1D* h_dsig_dmll_bkw_w10 = 0;

  TH1D* h_A4_yll_mll_fwd_w0 = 0; 
  TH1D* h_A4_yll_mll_bkw_w0 = 0; 

  TH1D* h_A4_yll_mll_fwd_w1 = 0; 
  TH1D* h_A4_yll_mll_bkw_w1 = 0; 

  TH1D* h_A4_yll_mll_fwd_w2 = 0; 
  TH1D* h_A4_yll_mll_bkw_w2 = 0; 

  TH1D* h_A4_yll_mll_fwd_w3 = 0; 
  TH1D* h_A4_yll_mll_bkw_w3 = 0; 

  TH1D* h_A4_yll_mll_fwd_w4 = 0; 
  TH1D* h_A4_yll_mll_bkw_w4 = 0; 

  TH1D* h_A4_yll_mll_fwd_w5 = 0; 
  TH1D* h_A4_yll_mll_bkw_w5 = 0; 

  TH1D* h_A4_yll_mll_fwd_w6 = 0; 
  TH1D* h_A4_yll_mll_bkw_w6 = 0; 

  TH1D* h_A4_yll_mll_fwd_w7 = 0; 
  TH1D* h_A4_yll_mll_bkw_w7 = 0; 

  TH1D* h_A4_yll_mll_fwd_w8 = 0; 
  TH1D* h_A4_yll_mll_bkw_w8 = 0; 

  TH1D* h_A4_yll_mll_fwd_w9 = 0; 
  TH1D* h_A4_yll_mll_bkw_w9 = 0; 

  TH1D* h_A4_yll_mll_fwd_w10 = 0; 
  TH1D* h_A4_yll_mll_bkw_w10 = 0; 

  // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<UInt_t> run = {fReader, "run"};
   TTreeReaderValue<UInt_t> luminosityBlock = {fReader, "luminosityBlock"};
   TTreeReaderValue<ULong64_t> event = {fReader, "event"};
   TTreeReaderValue<Float_t> HTXS_Higgs_pt = {fReader, "HTXS_Higgs_pt"};
   TTreeReaderValue<Float_t> HTXS_Higgs_y = {fReader, "HTXS_Higgs_y"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_cat_pTjet25GeV = {fReader, "HTXS_stage1_1_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_cat_pTjet30GeV = {fReader, "HTXS_stage1_1_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_fine_cat_pTjet25GeV = {fReader, "HTXS_stage1_1_fine_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_fine_cat_pTjet30GeV = {fReader, "HTXS_stage1_1_fine_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_cat_pTjet25GeV = {fReader, "HTXS_stage1_2_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_cat_pTjet30GeV = {fReader, "HTXS_stage1_2_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_fine_cat_pTjet25GeV = {fReader, "HTXS_stage1_2_fine_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_fine_cat_pTjet30GeV = {fReader, "HTXS_stage1_2_fine_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage_0 = {fReader, "HTXS_stage_0"};
   TTreeReaderValue<Int_t> HTXS_stage_1_pTjet25 = {fReader, "HTXS_stage_1_pTjet25"};
   TTreeReaderValue<Int_t> HTXS_stage_1_pTjet30 = {fReader, "HTXS_stage_1_pTjet30"};
   TTreeReaderValue<UChar_t> HTXS_njets25 = {fReader, "HTXS_njets25"};
   TTreeReaderValue<UChar_t> HTXS_njets30 = {fReader, "HTXS_njets30"};
   TTreeReaderValue<UInt_t> nGenJetAK8 = {fReader, "nGenJetAK8"};
   TTreeReaderArray<Float_t> GenJetAK8_eta = {fReader, "GenJetAK8_eta"};
   TTreeReaderArray<Float_t> GenJetAK8_mass = {fReader, "GenJetAK8_mass"};
   TTreeReaderArray<Float_t> GenJetAK8_phi = {fReader, "GenJetAK8_phi"};
   TTreeReaderArray<Float_t> GenJetAK8_pt = {fReader, "GenJetAK8_pt"};
   TTreeReaderValue<UInt_t> nGenJet = {fReader, "nGenJet"};
   TTreeReaderArray<Float_t> GenJet_eta = {fReader, "GenJet_eta"};
   TTreeReaderArray<Float_t> GenJet_mass = {fReader, "GenJet_mass"};
   TTreeReaderArray<Float_t> GenJet_phi = {fReader, "GenJet_phi"};
   TTreeReaderArray<Float_t> GenJet_pt = {fReader, "GenJet_pt"};
   TTreeReaderValue<UInt_t> nGenPart = {fReader, "nGenPart"};
   TTreeReaderArray<Float_t> GenPart_eta = {fReader, "GenPart_eta"};
   TTreeReaderArray<Float_t> GenPart_mass = {fReader, "GenPart_mass"};
   TTreeReaderArray<Float_t> GenPart_phi = {fReader, "GenPart_phi"};
   TTreeReaderArray<Float_t> GenPart_pt = {fReader, "GenPart_pt"};
   TTreeReaderArray<Int_t> GenPart_genPartIdxMother = {fReader, "GenPart_genPartIdxMother"};
   TTreeReaderArray<Int_t> GenPart_pdgId = {fReader, "GenPart_pdgId"};
   TTreeReaderArray<Int_t> GenPart_status = {fReader, "GenPart_status"};
   TTreeReaderArray<Int_t> GenPart_statusFlags = {fReader, "GenPart_statusFlags"};
   TTreeReaderValue<Float_t> Generator_binvar = {fReader, "Generator_binvar"};
   TTreeReaderValue<Float_t> Generator_scalePDF = {fReader, "Generator_scalePDF"};
   TTreeReaderValue<Float_t> Generator_weight = {fReader, "Generator_weight"};
   TTreeReaderValue<Float_t> Generator_x1 = {fReader, "Generator_x1"};
   TTreeReaderValue<Float_t> Generator_x2 = {fReader, "Generator_x2"};
   TTreeReaderValue<Float_t> Generator_xpdf1 = {fReader, "Generator_xpdf1"};
   TTreeReaderValue<Float_t> Generator_xpdf2 = {fReader, "Generator_xpdf2"};
   TTreeReaderValue<Int_t> Generator_id1 = {fReader, "Generator_id1"};
   TTreeReaderValue<Int_t> Generator_id2 = {fReader, "Generator_id2"};
   TTreeReaderValue<Float_t> GenVtx_x = {fReader, "GenVtx_x"};
   TTreeReaderValue<Float_t> GenVtx_y = {fReader, "GenVtx_y"};
   TTreeReaderValue<Float_t> GenVtx_z = {fReader, "GenVtx_z"};
   TTreeReaderValue<UInt_t> nGenVisTau = {fReader, "nGenVisTau"};
   TTreeReaderArray<Float_t> GenVisTau_eta = {fReader, "GenVisTau_eta"};
   TTreeReaderArray<Float_t> GenVisTau_mass = {fReader, "GenVisTau_mass"};
   TTreeReaderArray<Float_t> GenVisTau_phi = {fReader, "GenVisTau_phi"};
   TTreeReaderArray<Float_t> GenVisTau_pt = {fReader, "GenVisTau_pt"};
   TTreeReaderArray<Int_t> GenVisTau_charge = {fReader, "GenVisTau_charge"};
   TTreeReaderArray<Int_t> GenVisTau_genPartIdxMother = {fReader, "GenVisTau_genPartIdxMother"};
   TTreeReaderArray<Int_t> GenVisTau_status = {fReader, "GenVisTau_status"};
   TTreeReaderValue<Float_t> genWeight = {fReader, "genWeight"};
   TTreeReaderValue<Float_t> LHEWeight_originalXWGTUP = {fReader, "LHEWeight_originalXWGTUP"};
   TTreeReaderValue<UInt_t> nLHEPdfWeight = {fReader, "nLHEPdfWeight"};
   TTreeReaderArray<Float_t> LHEPdfWeight = {fReader, "LHEPdfWeight"};
   TTreeReaderValue<UInt_t> nLHEReweightingWeight = {fReader, "nLHEReweightingWeight"};
   TTreeReaderArray<Float_t> LHEReweightingWeight = {fReader, "LHEReweightingWeight"};
   TTreeReaderValue<UInt_t> nLHEScaleWeight = {fReader, "nLHEScaleWeight"};
   TTreeReaderArray<Float_t> LHEScaleWeight = {fReader, "LHEScaleWeight"};
   TTreeReaderValue<UInt_t> nPSWeight = {fReader, "nPSWeight"};
   TTreeReaderArray<Float_t> PSWeight = {fReader, "PSWeight"};
   TTreeReaderValue<Float_t> LHE_HT = {fReader, "LHE_HT"};
   TTreeReaderValue<Float_t> LHE_HTIncoming = {fReader, "LHE_HTIncoming"};
   TTreeReaderValue<Float_t> LHE_Vpt = {fReader, "LHE_Vpt"};
   TTreeReaderValue<Float_t> LHE_AlphaS = {fReader, "LHE_AlphaS"};
   TTreeReaderValue<UChar_t> LHE_Njets = {fReader, "LHE_Njets"};
   TTreeReaderValue<UChar_t> LHE_Nb = {fReader, "LHE_Nb"};
   TTreeReaderValue<UChar_t> LHE_Nc = {fReader, "LHE_Nc"};
   TTreeReaderValue<UChar_t> LHE_Nuds = {fReader, "LHE_Nuds"};
   TTreeReaderValue<UChar_t> LHE_Nglu = {fReader, "LHE_Nglu"};
   TTreeReaderValue<UChar_t> LHE_NpNLO = {fReader, "LHE_NpNLO"};
   TTreeReaderValue<UChar_t> LHE_NpLO = {fReader, "LHE_NpLO"};
   TTreeReaderValue<UInt_t> nLHEPart = {fReader, "nLHEPart"};
   TTreeReaderArray<Float_t> LHEPart_pt = {fReader, "LHEPart_pt"};
   TTreeReaderArray<Float_t> LHEPart_eta = {fReader, "LHEPart_eta"};
   TTreeReaderArray<Float_t> LHEPart_phi = {fReader, "LHEPart_phi"};
   TTreeReaderArray<Float_t> LHEPart_mass = {fReader, "LHEPart_mass"};
   TTreeReaderArray<Float_t> LHEPart_incomingpz = {fReader, "LHEPart_incomingpz"};
   TTreeReaderArray<Int_t> LHEPart_pdgId = {fReader, "LHEPart_pdgId"};
   TTreeReaderArray<Int_t> LHEPart_status = {fReader, "LHEPart_status"};
   TTreeReaderArray<Int_t> LHEPart_spin = {fReader, "LHEPart_spin"};
   TTreeReaderValue<Float_t> GenMET_phi = {fReader, "GenMET_phi"};
   TTreeReaderValue<Float_t> GenMET_pt = {fReader, "GenMET_pt"};
   TTreeReaderValue<UInt_t> nGenDressedLepton = {fReader, "nGenDressedLepton"};
   TTreeReaderArray<Float_t> GenDressedLepton_eta = {fReader, "GenDressedLepton_eta"};
   TTreeReaderArray<Float_t> GenDressedLepton_mass = {fReader, "GenDressedLepton_mass"};
   TTreeReaderArray<Float_t> GenDressedLepton_phi = {fReader, "GenDressedLepton_phi"};
   TTreeReaderArray<Float_t> GenDressedLepton_pt = {fReader, "GenDressedLepton_pt"};
   TTreeReaderArray<Int_t> GenDressedLepton_pdgId = {fReader, "GenDressedLepton_pdgId"};
   TTreeReaderArray<Bool_t> GenDressedLepton_hasTauAnc = {fReader, "GenDressedLepton_hasTauAnc"};
   TTreeReaderValue<Float_t> MET_fiducialGenPhi = {fReader, "MET_fiducialGenPhi"};
   TTreeReaderValue<Float_t> MET_fiducialGenPt = {fReader, "MET_fiducialGenPt"};
   TTreeReaderValue<UInt_t> nGenIsolatedPhoton = {fReader, "nGenIsolatedPhoton"};
   TTreeReaderArray<Float_t> GenIsolatedPhoton_eta = {fReader, "GenIsolatedPhoton_eta"};
   TTreeReaderArray<Float_t> GenIsolatedPhoton_mass = {fReader, "GenIsolatedPhoton_mass"};
   TTreeReaderArray<Float_t> GenIsolatedPhoton_phi = {fReader, "GenIsolatedPhoton_phi"};
   TTreeReaderArray<Float_t> GenIsolatedPhoton_pt = {fReader, "GenIsolatedPhoton_pt"};
   TTreeReaderArray<Int_t> GenJetAK8_partonFlavour = {fReader, "GenJetAK8_partonFlavour"};
   TTreeReaderArray<UChar_t> GenJetAK8_hadronFlavour = {fReader, "GenJetAK8_hadronFlavour"};
   TTreeReaderArray<Int_t> GenJet_partonFlavour = {fReader, "GenJet_partonFlavour"};
   TTreeReaderArray<UChar_t> GenJet_hadronFlavour = {fReader, "GenJet_hadronFlavour"};
   TTreeReaderValue<Float_t> GenVtx_t0 = {fReader, "GenVtx_t0"};


  myselector(TTree * /*tree*/ =0) { }
  virtual ~myselector() { }
  virtual Int_t  Version() const { return 2; }
  virtual void  Begin(TTree *tree);
  virtual void  SlaveBegin(TTree *tree);
  virtual void  Init(TTree *tree);
  virtual Bool_t  Notify();
  virtual Bool_t  Process(Long64_t entry);
  virtual Int_t  GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  virtual void  SetOption(const char *option) { fOption = option; }
  virtual void  SetObject(TObject *obj) { fObject = obj; }
  virtual void  SetInputList(TList *input) { fInput = input; }
  virtual TList  *GetOutputList() const { return fOutput; }
  virtual void  SlaveTerminate();
  virtual void  Terminate();

  ClassDef(myselector,0);

};

#endif

#ifdef myselector_cxx
void myselector::Init(TTree *tree)
{
  fReader.SetTree(tree);
}

Bool_t myselector::Notify()
{
  return kTRUE;
}


// Cosine of the decay angle in the Collins-Soper frame
double cosCollinsSoper(TLorentzVector lep0_gen, TLorentzVector lep1_gen) {
  TLorentzVector ll = lep0_gen + lep1_gen;
  double nom = (lep0_gen.E() + lep0_gen.Pz()) * (lep1_gen.E() - lep1_gen.Pz()) - (lep0_gen.E() - lep0_gen.Pz()) * (lep1_gen.E() + lep1_gen.Pz());
  double denom = ll.M() * sqrt(ll.M2() + ll.Pt() * ll.Pt());

  if (denom != 0) {
    return TMath::Sign(1.0, ll.Pz()) * nom / denom;
  } else {
    // Handle division by zero, return a default value or set to zero
    // Here, returning zero in case of division by zero
    std::cout << "ERROR: cosCollinsSoper dividing by zero!" << std::endl;
    return 0.0;
  }
}

int get_yll_mll_bin(double yll, double mll) {
  int yll_mll_bin = 0;
  int bin_shift = 0;

  // force abs(yll)
  yll = fabs(yll);

  // A4(0.0 < yll < 1.6)
  if (yll >= 0.0 && yll < 0.4) {
    bin_shift = 12 * 0;
    if        (mll >= 46.0 && mll < 54.0) {
      yll_mll_bin = bin_shift + 1;
    } else if (mll >= 54.0 && mll < 66.0) {
      yll_mll_bin = bin_shift + 2;
    } else if (mll >= 66.0 && mll < 76.0) {
      yll_mll_bin = bin_shift + 3;
    } else if (mll >= 76.0 && mll < 82.0) {
      yll_mll_bin = bin_shift + 4;
    } else if (mll >= 82.0 && mll < 86.0) {
      yll_mll_bin = bin_shift + 5;
    } else if (mll >= 86.0 && mll < 89.0) {
      yll_mll_bin = bin_shift + 6;
    } else if (mll >= 89.0 && mll < 92.0) {
      yll_mll_bin = bin_shift + 7;
    } else if (mll >= 92.0 && mll < 96.0) {
      yll_mll_bin = bin_shift + 8;
    } else if (mll >= 96.0 && mll < 100.0) {
      yll_mll_bin = bin_shift + 9;
    } else if (mll >= 100.0 && mll < 106.0) {
      yll_mll_bin = bin_shift + 10;
    } else if (mll >= 106.0 && mll < 116.0) {
      yll_mll_bin = bin_shift + 11;
    } else if (mll >= 116.0 && mll <= 150.0) {
      yll_mll_bin = bin_shift + 12;
    }
  } else if (yll >= 0.4 && yll < 0.8) {
    bin_shift = 12 * 1;
    if        (mll >= 46.0 && mll < 54.0) {
      yll_mll_bin = bin_shift + 1;
    } else if (mll >= 54.0 && mll < 66.0) {
      yll_mll_bin = bin_shift + 2;
    } else if (mll >= 66.0 && mll < 76.0) {
      yll_mll_bin = bin_shift + 3;
    } else if (mll >= 76.0 && mll < 82.0) {
      yll_mll_bin = bin_shift + 4;
    } else if (mll >= 82.0 && mll < 86.0) {
      yll_mll_bin = bin_shift + 5;
    } else if (mll >= 86.0 && mll < 89.0) {
      yll_mll_bin = bin_shift + 6;
    } else if (mll >= 89.0 && mll < 92.0) {
      yll_mll_bin = bin_shift + 7;
    } else if (mll >= 92.0 && mll < 96.0) {
      yll_mll_bin = bin_shift + 8;
    } else if (mll >= 96.0 && mll < 100.0) {
      yll_mll_bin = bin_shift + 9;
    } else if (mll >= 100.0 && mll < 106.0) {
      yll_mll_bin = bin_shift + 10;
    } else if (mll >= 106.0 && mll < 116.0) {
      yll_mll_bin = bin_shift + 11;
    } else if (mll >= 116.0 && mll <= 150.0) {
      yll_mll_bin = bin_shift + 12;
    }
  } else if (yll >= 0.8 && yll < 1.2) {
    bin_shift = 12 * 2;
    if        (mll >= 46.0 && mll < 54.0) {
      yll_mll_bin = bin_shift + 1;
    } else if (mll >= 54.0 && mll < 66.0) {
      yll_mll_bin = bin_shift + 2;
    } else if (mll >= 66.0 && mll < 76.0) {
      yll_mll_bin = bin_shift + 3;
    } else if (mll >= 76.0 && mll < 82.0) {
      yll_mll_bin = bin_shift + 4;
    } else if (mll >= 82.0 && mll < 86.0) {
      yll_mll_bin = bin_shift + 5;
    } else if (mll >= 86.0 && mll < 89.0) {
      yll_mll_bin = bin_shift + 6;
    } else if (mll >= 89.0 && mll < 92.0) {
      yll_mll_bin = bin_shift + 7;
    } else if (mll >= 92.0 && mll < 96.0) {
      yll_mll_bin = bin_shift + 8;
    } else if (mll >= 96.0 && mll < 100.0) {
      yll_mll_bin = bin_shift + 9;
    } else if (mll >= 100.0 && mll < 106.0) {
      yll_mll_bin = bin_shift + 10;
    } else if (mll >= 106.0 && mll < 116.0) {
      yll_mll_bin = bin_shift + 11;
    } else if (mll >= 116.0 && mll <= 150.0) {
      yll_mll_bin = bin_shift + 12;
    }
  } else if (yll >= 1.2 && yll < 1.6) {
    bin_shift = 12 * 3;
    if        (mll >= 46.0 && mll < 54.0) {
      yll_mll_bin = bin_shift + 1;
    } else if (mll >= 54.0 && mll < 66.0) {
      yll_mll_bin = bin_shift + 2;
    } else if (mll >= 66.0 && mll < 76.0) {
      yll_mll_bin = bin_shift + 3;
    } else if (mll >= 76.0 && mll < 82.0) {
      yll_mll_bin = bin_shift + 4;
    } else if (mll >= 82.0 && mll < 86.0) {
      yll_mll_bin = bin_shift + 5;
    } else if (mll >= 86.0 && mll < 89.0) {
      yll_mll_bin = bin_shift + 6;
    } else if (mll >= 89.0 && mll < 92.0) {
      yll_mll_bin = bin_shift + 7;
    } else if (mll >= 92.0 && mll < 96.0) {
      yll_mll_bin = bin_shift + 8;
    } else if (mll >= 96.0 && mll < 100.0) {
      yll_mll_bin = bin_shift + 9;
    } else if (mll >= 100.0 && mll < 106.0) {
      yll_mll_bin = bin_shift + 10;
    } else if (mll >= 106.0 && mll < 116.0) {
      yll_mll_bin = bin_shift + 11;
    } else if (mll >= 116.0 && mll <= 150.0) {
      yll_mll_bin = bin_shift + 12;
    }
  } else if (yll >= 1.6 && yll < 2.0) {
    bin_shift = 12 * 4;
    if        (mll >= 46.0 && mll < 54.0) {
      yll_mll_bin = bin_shift + 1;
    } else if (mll >= 54.0 && mll < 66.0) {
      yll_mll_bin = bin_shift + 2;
    } else if (mll >= 66.0 && mll < 76.0) {
      yll_mll_bin = bin_shift + 3;
    } else if (mll >= 76.0 && mll < 82.0) {
      yll_mll_bin = bin_shift + 4;
    } else if (mll >= 82.0 && mll < 86.0) {
      yll_mll_bin = bin_shift + 5;
    } else if (mll >= 86.0 && mll < 89.0) {
      yll_mll_bin = bin_shift + 6;
    } else if (mll >= 89.0 && mll < 92.0) {
      yll_mll_bin = bin_shift + 7;
    } else if (mll >= 92.0 && mll < 96.0) {
      yll_mll_bin = bin_shift + 8;
    } else if (mll >= 96.0 && mll < 100.0) {
      yll_mll_bin = bin_shift + 9;
    } else if (mll >= 100.0 && mll < 106.0) {
      yll_mll_bin = bin_shift + 10;
    } else if (mll >= 106.0 && mll < 116.0) {
      yll_mll_bin = bin_shift + 11;
    } else if (mll >= 116.0 && mll <= 150.0) {
      yll_mll_bin = bin_shift + 12;
    }
  } else if (yll >= 2.0 && yll < 2.5) {
    bin_shift = 12 * 5;
    if        (mll >= 46.0 && mll < 54.0) {
      yll_mll_bin = bin_shift + 1;
    } else if (mll >= 54.0 && mll < 66.0) {
      yll_mll_bin = bin_shift + 2;
    } else if (mll >= 66.0 && mll < 76.0) {
      yll_mll_bin = bin_shift + 3;
    } else if (mll >= 76.0 && mll < 82.0) {
      yll_mll_bin = bin_shift + 4;
    } else if (mll >= 82.0 && mll < 86.0) {
      yll_mll_bin = bin_shift + 5;
    } else if (mll >= 86.0 && mll < 89.0) {
      yll_mll_bin = bin_shift + 6;
    } else if (mll >= 89.0 && mll < 92.0) {
      yll_mll_bin = bin_shift + 7;
    } else if (mll >= 92.0 && mll < 96.0) {
      yll_mll_bin = bin_shift + 8;
    } else if (mll >= 96.0 && mll < 100.0) {
      yll_mll_bin = bin_shift + 9;
    } else if (mll >= 100.0 && mll < 106.0) {
      yll_mll_bin = bin_shift + 10;
    } else if (mll >= 106.0 && mll < 116.0) {
      yll_mll_bin = bin_shift + 11;
    } else if (mll >= 116.0 && mll <= 150.0) {
      yll_mll_bin = bin_shift + 12;
    }
  }

  if (yll_mll_bin == 0) {
    if (mll >= 46.0 && mll <= 150.0 && yll <= 2.5) {
      std::cerr << "[ERROR get_yll_mll_bin]: get_yll_mll_bin(" << yll << ", " << mll << ") will return yll_mll_bin = " << yll_mll_bin << std::endl;
    }
  }

  return yll_mll_bin;
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) {
      return N;
}

#endif // #ifdef myselector_cxx
