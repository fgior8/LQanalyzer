#ifndef SignalPlots_h
#define SignalPlots_h

#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "Lepton.h"
#include "Jet.h"
#include <iostream>
class SignalPlots {
 
  Double_t dijetmass_tmp, dijetmass;
  static const Double_t Mass_W = 80.398;
 
 public:
  TH1F *h_jjmass, *h_llmass, *h_l1jjmass, *h_l2jjmass, *h_lljjmass, *h_MET, *h_bTag;
  TH2F *h_WandNmass;
  TH1F *h_leadingMuonPt, *h_secondMuonPt, *h_leadingJetPt, *h_secondJetPt;
  TH1F *h_leadingMuonIso, *h_secondMuonIso, *h_paircharge, *h_muonseta, *h_jetseta;
  TH1F *h_cosTheta1, *h_cosTheta2;
  TH1F *h_threeDjet;
 
  SignalPlots(TString name);
  ~SignalPlots();
  void Fill(Double_t MET, std::vector<Lepton>& muons, std::vector<Jet>& jets, Double_t weight, Bool_t ptok, Bool_t ssok);
  void Fill(Double_t MET, std::vector<Lepton>& muons, std::vector<Lepton>& muonsloose, std::vector<Jet>& jets, Double_t weight, Bool_t ptok, Bool_t ssok);
  void Write();

};


#endif
