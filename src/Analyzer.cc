#include "Analyzer.h"

Analyzer::Analyzer() {

  if (debug) cout<<"inizio"<<endl;
  h_MET = new TH1F("h_MET","Missing Et",300,0.0,300.0);
  h_MET->SetDefaultSumw2(true);
  h_METsign = new TH1F("h_METsign","Missing Et significance",50,0.0,50.0);
  h_MuonMissCharge = new TH1F("h_MuonMissCharge","Miss Charge for muons",6,0,6);
  h_EventFakeType = new TH1F("h_EventFakeType","Event fake type",3,0,3);
  h_LeptvsVert = new TH2I("h_LeptvsVert","Leptons per Vertex",50,0,50,5,0,5);
  h_dRvsbTag = new TH2F("h_dRvsbTag","#deltaR vs b-tag discriminant",100,0.0,10.0,100,-5,14);

  h_nVertex= new TH1F("h_nVertex","number of verteces",50,0,50);
  h_nVertex0= new TH1F("h_nVertex0","number of verteces t0",50,0,50);
  h_nVertex1= new TH1F("h_nVertex1","number of verteces t1",50,0,50);
  h_nVertex2= new TH1F("h_nVertex2","number of verteces t2",50,0,50);
  
  h_nvtx_norw = new TH1F("h_nvtx_norw","Nvtx per bunch crossing at BX = 0 noreweight",60,0.0,60.0);
  h_nvtx_rw = new TH1F("h_nvtx_rw","Nvtx per bunch crossing at BX = 0 reweight",60,0.0,60.0);

  h_prova = new TH1F("h_prova","Di-Muon Mass (GeV)",200,0,200);
  h_RelIsoFR = new TH1F("h_RelIsoFR","RelIso FR weight",40,0,0.4);

  h_electrons = new ElectronPlots("electrons");
  h_electronsLoose = new ElectronPlots("loose electrons");
  h_muons = new MuonPlots("muons");
  h_muonsLoose = new MuonPlots("loose_muons");
  h_LnotT = new MuonPlots("loose_not_tight");
  //h_muonCharge = new MuonPlots("misscharge_muon");
  h_jets = new JetPlots("jets");
  h_jets_veto = new JetPlots("jets_w_veto");
  h_signal = new SignalPlots("signal");
  h_signalMET50 = new SignalPlots("signal_MET50");
  h_signalbTag = new SignalPlots("signal_bTag");
  h_signalTOT = new SignalPlots("signal_TOT");
  h_singlefakes = new SignalPlots("sf");
  h_doublefakes = new SignalPlots("df");
  h_totalfakes = new SignalPlots("tf");
  h_singlefakesMET50 = new SignalPlots("sf_MET50");
  h_doublefakesMET50 = new SignalPlots("df_MET50");
  h_totalfakesMET50 = new SignalPlots("tf_MET50");
  h_singlefakesbTag = new SignalPlots("sf_bTag");
  h_doublefakesbTag = new SignalPlots("df_bTag");
  h_totalfakesbTag = new SignalPlots("tf_bTag");
  h_singlefakesTOT = new SignalPlots("sf_TOT");
  h_doublefakesTOT = new SignalPlots("df_TOT");
  h_totalfakesTOT = new SignalPlots("tf_TOT");
  h_nsignal = new TH1F("h_signal","number of signal events ",5,-1,4);
  h_cutflow = new TH1F("h_cutflow","number of signal events in cut flow",4,0,4);
  h_singlefake = new TH1F("h_singlefake","number of single fakes ",4,-1,3);
  h_doublefake = new TH1F("h_doublefake","number of double fakes ",4,-1,3);

//  TFile *infile = new TFile("/uscms_data/d2/fgior8/LQntuple06/CMSSW_5_3_4_LQ/src/code/Total_FR_7.root");
  TFile *infile = new TFile("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/Total_FRcorr40_31.root");

  infile->cd();
  TDirectory *dir=gDirectory;             
  dir->GetObject("h_FOrate3",FRhisto);
  if (debug) cout<<"fine"<<endl;
}

Analyzer::~Analyzer() { }

void Analyzer::SetName(TString name, Int_t version) {
  completename = name + "_";
  completename += version;
  completename += ".root";
  outfile = new TFile(completename,"RECREATE");
}

void Analyzer::SetWeight(Double_t CrossSection, Double_t nevents) {

  MCweight = integratedlumi * CrossSection / nevents;
// lumi *  cs(pb) * gen filter efficiency / MCevents
  cout<<"MCweight = "<<MCweight<<endl;
 
}

void Analyzer::SetEvtN(Long64_t events) {
  events ? entrieslimit=events :  entrieslimit=-1;
  cout<<"events "<<events<<endl<<"entrieslimit "<<entrieslimit<<endl;
}

void Analyzer::Loop() {

  cout << "total number of entries " <<nentries<<endl;

  if (debug) cout<< "loop begins" <<endl;

  Double_t SingleFake=0; Double_t DoubleFake=0; Double_t Single_Double=0;
  Int_t nSingleFake=0; Int_t nDoubleFake=0;

  reweightPU = new ReweightPU("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/MC_pu.root", "/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/MyDataPileupHistogram.root");

  UInt_t nbinX=FRhisto->GetNbinsX(); UInt_t nbinY=FRhisto->GetNbinsY();

  singleFake=new Double_t*[nbinX];
  for (UInt_t i=0; i<nbinX; i++)
    singleFake[i]=new Double_t[nbinY];
  for (UInt_t i=0; i<nbinX; i++)
    for (UInt_t j=0; j<nbinY; j++)
      singleFake[i][j]=0;
  doubleFake=new Double_t***[nbinX];
  prova=new Double_t***[nbinX];
  for (UInt_t i=0; i<nbinX; i++) {
    doubleFake[i]=new Double_t**[nbinY];
    prova[i]=new Double_t**[nbinY];
  }
  for (UInt_t i=0; i<nbinX; i++)
    for (UInt_t j=0; j<nbinY; j++) {
      doubleFake[i][j]=new Double_t*[nbinX];
      prova[i][j]=new Double_t*[nbinX];
  }
  for (UInt_t i=0; i<nbinX; i++)
    for (UInt_t j=0; j<nbinY; j++)
      for (UInt_t m=0; m<nbinX; m++) {
	doubleFake[i][j][m]=new Double_t[nbinY];
        prova[i][j][m]=new Double_t[nbinY];
  }
  for (UInt_t i=0; i<nbinX; i++)
    for (UInt_t j=0; j<nbinY; j++)
      for (UInt_t m=0; m<nbinX; m++)
	for (UInt_t n=0; n<nbinY; n++) {
	  doubleFake[i][j][m][n]=0;
          prova[i][j][m][n]=0;
  }

  if(!MCweight) MCweight=1; 

  weight=MCweight;

  if (fChain == 0) 
    cout << "Ciao!" << endl;

//  cout << "Do you want limited events?" <<endl;
//  cin >> entrieslimit;
//  if (entrieslimit != -1)
//    nentries=entrieslimit;
//  entrieslimit = 1000000;

  if (debug) cout<< "at the loop" <<endl;
  std::set<int> runs;
  for (Long64_t jentry = 0; jentry < nentries; jentry++ ) {

    //    watch_getentry.Start(false);
    if (debug) cout<<"begin loop"<<endl;
    if (!(jentry % 1000))
      cout << jentry << endl;

    if (!fChain) cout<<"porcaccia"<<endl;
    fChain->GetEntry(jentry);

    if (isTrackingFailure || passTrackingFailureFilter) continue;

    if (!passBeamHaloFilterLoose) continue;

    if (passBadEESupercrystalFilter || passEcalDeadCellBoundaryEnergyFilter || passEcalDeadCellTriggerPrimitiveFilter || passEcalLaserCorrFilter) continue;

    if (!passHBHENoiseFilter || passHcalLaserEventFilter) continue;

    std::vector<TString> triggerslist;
    triggerslist.push_back("HLT_Mu17_TkMu8_v");

    if ( !TriggerSelector(triggerslist, *HLTInsideDatasetTriggerNames, *HLTInsideDatasetTriggerDecisions, *HLTInsideDatasetTriggerPrescales, prescaler) ) continue;
  
    if (MC_pu) {
      /// ***PU reweghting*** ///
      //weight_ = noreweight_;// mc weight;
      h_nvtx_norw->Fill(PileUpInteractionsTrue->at(0), MCweight);
      weight = reweightPU->GetWeight(PileUpInteractionsTrue->at(0))*MCweight;
      h_nvtx_rw->Fill(PileUpInteractionsTrue->at(0), weight);
    }  

    numberVertices = VertexNDF->size();
    goodVerticies = new Bool_t [numberVertices];
    h_nVertex->Fill(numberVertices, weight);
    if ( !isGoodEvent(numberVertices, *VertexIsFake, *VertexNDF, *VertexX, *VertexY, *VertexZ, goodVerticies) ) continue;

    for(UInt_t vv=0; vv<VertexNDF->size(); vv++) {
      if(goodVerticies[vv]) {
        VertexN=vv;
        break;
      }
    }
 
    ///// STARTING WITH PHYSICS OBJECTS COLLECTIONS /////

    if (debug) cout<< "Event number " <<jentry<<endl;
/* 
    std::vector<GenParticle> genTightColl;
    GenTight.SetPt(20); 
    GenTight.SetEta(3.0); 
    GenTight.SetBSdxy(0.20); 
    GenTight.GenSelection(*GenParticleEta, *GenParticlePt, *GenParticlePx, *GenParticlePy, *GenParticlePz, *GenParticleEnergy, *GenParticleVX, *GenParticleVY, *GenParticleVZ, VertexX->at(VertexN), VertexY->at(VertexN), VertexZ->at(VertexN), *GenParticlePdgId, *GenParticleStatus, *GenParticleNumDaught, *GenParticleMotherIndex, genTightColl);   
*/
    std::vector<Lepton> muonTightColl;
    MuonTight.SetPt(20); 
    MuonTight.SetEta(2.4);
    MuonTight.SetRelIso(0.12); 
    MuonTight.SetChiNdof(10); 
    MuonTight.SetBSdxy(0.01);
    MuonTight.SetBSdz(0.10);
    MuonTight.SetDeposits(4.0,6.0);
    MuonTight.MuonSelection(*MuonIsPF, *MuonIsGlobal, *MuonEta, *MuonPhi, *MuonPt, *MuonPtError, *MuonEnergy, *MuonPFIsoR04ChargedHadron, *MuonPFIsoR04NeutralHadron, *MuonPFIsoR04Photon, *MuonEcalVetoIso, *MuonHcalVetoIso, *MuonCharge, *MuonGlobalTrkValidHits, *MuonTrkPixelHits, *MuonStationMatches, *MuonTrackLayersWithMeasurement, *MuonGlobalChi2, *MuonTrkVx, *MuonTrkVy, *MuonTrkVz, *MuonTrkD0, *MuonTrkD0Error, VertexX->at(VertexN), VertexY->at(VertexN), VertexZ->at(VertexN), *MuonPFIsoR04PU, muonTightColl);

    std::vector<Lepton> muonLooseButNOTightColl;
    MuonLooseButNOTight.SetPt(20);
    MuonLooseButNOTight.SetEta(2.4);
    MuonLooseButNOTight.SetRelIso(0.12,0.40);
    MuonLooseButNOTight.SetChiNdof(10,50);
    MuonLooseButNOTight.SetBSdxy(0.01,0.20);
    MuonLooseButNOTight.SetBSdz(0.10);
    MuonLooseButNOTight.SetDeposits(4.0,6.0);
    MuonLooseButNOTight.MuonSelection(*MuonIsPF, *MuonIsGlobal, *MuonEta, *MuonPhi, *MuonPt, *MuonPtError, *MuonEnergy, *MuonPFIsoR04ChargedHadron, *MuonPFIsoR04NeutralHadron, *MuonPFIsoR04Photon, *MuonEcalVetoIso, *MuonHcalVetoIso, *MuonCharge, *MuonGlobalTrkValidHits, *MuonTrkPixelHits, *MuonStationMatches, *MuonTrackLayersWithMeasurement, *MuonGlobalChi2, *MuonTrkVx, *MuonTrkVy, *MuonTrkVz, *MuonTrkD0, *MuonTrkD0Error, VertexX->at(VertexN), VertexY->at(VertexN), VertexZ->at(VertexN), *MuonPFIsoR04PU, muonLooseButNOTightColl);

    std::vector<Lepton> muonLooseColl;
    MuonLoose.SetPt(20);
    MuonLoose.SetEta(2.4);
    MuonLoose.SetRelIso(0.40);
    MuonLoose.SetChiNdof(50);
    MuonLoose.SetBSdxy(0.20);
    MuonLoose.SetBSdz(0.10);
    MuonLoose.SetDeposits(4.0,6.0);
    MuonLoose.MuonSelection(*MuonIsPF, *MuonIsGlobal, *MuonEta, *MuonPhi, *MuonPt, *MuonPtError, *MuonEnergy, *MuonPFIsoR04ChargedHadron, *MuonPFIsoR04NeutralHadron, *MuonPFIsoR04Photon, *MuonEcalVetoIso, *MuonHcalVetoIso, *MuonCharge, *MuonGlobalTrkValidHits, *MuonTrkPixelHits, *MuonStationMatches, *MuonTrackLayersWithMeasurement, *MuonGlobalChi2, *MuonTrkVx, *MuonTrkVy, *MuonTrkVz, *MuonTrkD0, *MuonTrkD0Error, VertexX->at(VertexN), VertexY->at(VertexN), VertexZ->at(VertexN), *MuonPFIsoR04PU, muonLooseColl);

    std::vector<Lepton> electronTightColl;
    ElectronTight.SetPt(10); 
    ElectronTight.SetEta(2.4); 
    ElectronTight.SetRelIso(0.10); 
    ElectronTight.SetBSdxy(0.02); 
    ElectronTight.SetBSdz(0.10);
    ElectronTight.ElectronSelection(*ElectronIsEB, *ElectronIsEE, *ElectronHasTrackerDrivenSeed, *ElectronHasEcalDrivenSeed, *ElectronEta, *ElectronPhi, *ElectronPt, *ElectronEnergy, *ElectronPFPhotonIso03, *ElectronPFNeutralHadronIso03, *ElectronPFChargedHadronIso03, *ElectronCharge, *ElectronGsfCtfScPixCharge, *ElectronMissingHitsEG, *ElectronHasMatchedConvPhot, *ElectronDeltaEtaTrkSC, *ElectronDeltaPhiTrkSC, *ElectronSigmaIEtaIEta, *ElectronHoE, *ElectronCaloEnergy, *ElectronESuperClusterOverP, *ElectronTrackVx, *ElectronTrackVy, *ElectronTrackVz, VertexX->at(VertexN), VertexY->at(VertexN), VertexZ->at(VertexN), rhoJets, electronTightColl);
    
    std::vector<Jet> jetVetoColl;
    JetsVeto.SetPt(30); 
    JetsVeto.SetEta(2.4);
    JetsVeto.JetSelectionLeptonVeto(*PFJetPassLooseID, *PFJetEta, *PFJetPhi, *PFJetPt, *PFJetEnergy, *PFJetNeutralEmEnergyFraction, *PFJetNeutralHadronEnergyFraction, *PFJetChargedEmEnergyFraction, *PFJetChargedHadronEnergyFraction, *PFJetChargedMultiplicity, *PFJetNConstituents, *PFJetCombinedSecondaryVertexBTag, *PFJetClosestVertexWeighted3DSeparation, electronTightColl, muonTightColl, jetVetoColl);

    if (debug) cout<<"Selection done"<<endl;

    ///// SOME STANDARD PLOTS /////
    if (muonTightColl.size() > 0) {
      for (UInt_t i=0; i<muonTightColl.size(); i++) {
	index=muonTightColl[i].ilepton();
	h_muons->Fill(weight, (Int_t) muonTightColl.size(), muonTightColl[i].lorentzVec().Pt(), muonTightColl[i].eta(), muonTightColl[i].lorentzVec().Phi(), muonTightColl[i].charge(), MuonTrkIso->at(index), MuonEcalIso->at(index), MuonHcalIso->at(index), MuonEcalVetoIso->at(index), MuonHcalVetoIso->at(index), MuonPFIsoR04Photon->at(index), MuonPFIsoR04ChargedHadron->at(index), MuonPFIsoR04NeutralHadron->at(index), muonTightColl[i].chiNdof(), muonTightColl[i].dxy_BS(), muonTightColl[i].dz_BS(), MuonPFIsoR04PU->at(index), rhoJets);
	//	if (muonTightColl[i].fakeType() == Lepton::unknown && Muon_Gen_Mother[index]!=999) cout<<"SCONOSCIUTO!!!!!"<<" pdgID "<<Muon_Gen_Mother[index]<<endl;
      }	 
    }

    if (muonLooseButNOTightColl.size() > 0) {
      for (UInt_t i=0; i<muonLooseButNOTightColl.size(); i++) {
        index=muonLooseButNOTightColl[i].ilepton();
        h_LnotT->Fill(weight, (Int_t) muonLooseButNOTightColl.size(), muonLooseButNOTightColl[i].lorentzVec().Pt(), muonLooseButNOTightColl[i].eta(), muonLooseButNOTightColl[i].lorentzVec().Phi(), muonLooseButNOTightColl[i].charge(), MuonTrkIso->at(index), MuonEcalIso->at(index), MuonHcalIso->at(index), MuonEcalVetoIso->at(index), MuonHcalVetoIso->at(index), MuonPFIsoR04Photon->at(index), MuonPFIsoR04ChargedHadron->at(index), MuonPFIsoR04NeutralHadron->at(index), muonLooseButNOTightColl[i].chiNdof(), muonLooseButNOTightColl[i].dxy_BS(), muonLooseButNOTightColl[i].dz_BS(), MuonPFIsoR04PU->at(index), rhoJets);
      }
    }
    
    if (muonLooseColl.size() > 0) {
      for (UInt_t i=0; i<muonLooseColl.size(); i++) {
        index=muonLooseColl[i].ilepton();
        h_muonsLoose->Fill(weight, (Int_t) muonLooseColl.size(), muonLooseColl[i].lorentzVec().Pt(), muonLooseColl[i].eta(), muonLooseColl[i].lorentzVec().Phi(), muonLooseColl[i].charge(), MuonTrkIso->at(index), MuonEcalIso->at(index), MuonHcalIso->at(index), MuonEcalVetoIso->at(index), MuonHcalVetoIso->at(index), MuonPFIsoR04Photon->at(index), MuonPFIsoR04ChargedHadron->at(index), MuonPFIsoR04NeutralHadron->at(index), muonLooseColl[i].chiNdof(), muonLooseColl[i].dxy_BS(), muonLooseColl[i].dz_BS(), MuonPFIsoR04PU->at(index), rhoJets);
      }
    }

    if (electronTightColl.size() > 0) {
      for (UInt_t i=0; i<electronTightColl.size(); i++) {
	index=electronTightColl[i].ilepton();
	h_electrons->Fill(weight, (Int_t) electronTightColl.size(), electronTightColl[i].lorentzVec().Pt(), electronTightColl[i].eta(), electronTightColl[i].lorentzVec().Phi(), electronTightColl[i].charge(), ElectronTrkIsoDR03->at(index), ElectronEcalIsoDR03->at(index), ElectronHcalIsoDR03->at(index), electronTightColl[i].dxy_BS(), electronTightColl[i].dz_BS(), rhoJets);
      }	 
    }  
    
    b_found = false;
    if (jetVetoColl.size() > 0) {
      for (UInt_t i=0; i<jetVetoColl.size(); i++) {
	index=jetVetoColl[i].ijet();
	h_jets_veto->Fill( weight, (Int_t) jetVetoColl.size(), jetVetoColl[i].lorentzVec().Pt(), jetVetoColl[i].eta(), jetVetoColl[i].lorentzVec().Phi(), PFJetTrackCountingHighPurBTag->at(index), PFJetJetProbabilityBTag->at(index), jetVetoColl[i].btag_disc(), PFJetClosestVertexWeightedXYSeparation->at(index), PFJetClosestVertexWeightedZSeparation->at(index), PFJetClosestVertexWeighted3DSeparation->at(index) );
	if (jetVetoColl[i].btag_disc() > 0.898) 
	  b_found = true;
      }	 
    }  
    Double_t Wpair=999.9;
    Double_t temp_Wpair=999.9;
    if (jetVetoColl.size() >= 2) {
      for (UInt_t i=0; i<jetVetoColl.size()-1; i++)
	for (UInt_t j=1; j<jetVetoColl.size(); j++) {
	  temp_Wpair = (jetVetoColl[i].lorentzVec() + jetVetoColl[j].lorentzVec()).M();
	  if ( fabs(temp_Wpair-Mass_W) < fabs(Wpair-Mass_W) )
	    Wpair = temp_Wpair;
	}
    }
    if (Wpair > 125) continue;
    ///// END STANDARD PLOTS /////
    MET = PFMETType01XYCor->at(0); 
    h_MET->Fill(MET, weight);
    h_METsign->Fill(PFMETSigType01XYCor->at(0), weight);

    /// ***simple check for double muon invariant mass and 3rd lepton Z veto*** ///
    Double_t masslow=999.9;
    if (muonLooseColl.size() >= 2) {
      masslow = (muonLooseColl[0].lorentzVec() + muonLooseColl[1].lorentzVec()).M();
      h_prova->Fill(masslow, weight);
    }
    if (masslow <= 10.0) continue;
    Double_t mass3rd=999.9;
    Double_t temp_mass3rd=999.9;
    if (muonTightColl.size() > 2) {
      for(UInt_t i=0; i<muonTightColl.size()-1; i++)
	for(UInt_t j=i+1; j<muonTightColl.size(); j++) {
	  if ( muonTightColl[i].charge() != muonTightColl[j].charge() ) {
	    temp_mass3rd = (muonTightColl[i].lorentzVec() + muonTightColl[j].lorentzVec()).M();
	    if ( fabs(temp_mass3rd-Mass_Z) < fabs(mass3rd-Mass_Z) ) 
	      mass3rd=temp_mass3rd;
	  }
	}
    }    
    if (mass3rd > (Mass_Z-15) && mass3rd < (Mass_Z+15) ) continue;

       ///// SIGNAL and CONTROL region/////
    if (debug) cout<<"Signal selection"<<endl;

    VETO=false;
    Wcand_tmp=Wcand=0;
    if ( muonTightColl.size() == 2 && jetVetoColl.size() >= 2 ) {
      for(UInt_t i=0; i<muonTightColl.size()-1; i++)
	for(UInt_t j=i+1; j<muonTightColl.size(); j++) {
	  if ( muonTightColl[i].charge()*muonTightColl[j].charge() > 0 )
	    if ( muonTightColl[i].lorentzVec().Pt() >= 20) {
	      VETO=true;
	      cout << "UNO" <<endl;
	    }
	}
    }
    
    if(VETO) {
      h_nsignal->Fill(0.,weight);
      h_signalTOT->Fill(MET, muonTightColl, jetVetoColl, weight, false, false);
      if (MET>40) {
	h_nsignal->Fill(1., weight);
	h_signalMET50->Fill(MET, muonTightColl, jetVetoColl, weight, false, false);
      }
      else {
	if (b_found) {
	h_nsignal->Fill(2., weight);
	h_signalbTag->Fill(MET, muonTightColl, jetVetoColl, weight, false, false);
        }
        else {
	  h_nsignal->Fill(3., weight);
	  h_signal->Fill(MET, muonTightColl, jetVetoColl, weight, false, false);
	  h_nVertex2->Fill(numberVertices, weight);
        }
      }
    }

    ///// BACKGROUND /////
    if (debug) cout<<"Background selection"<<endl;

    DOUBLEFAKE=false;
    Wcand_tmp=Wcand=0;
    if (muonLooseButNOTightColl.size() == 2 && muonTightColl.size() == 0 && jetVetoColl.size() >= 2) {
      for(UInt_t i=0; i<muonLooseButNOTightColl.size()-1; i++)
	for(UInt_t j=i+1; j<muonLooseButNOTightColl.size(); j++) {
	  if (muonLooseButNOTightColl[i].charge()*muonLooseButNOTightColl[j].charge()>0)
	    if (muonLooseButNOTightColl[i].lorentzVec().Pt() >=20) {
	      DOUBLEFAKE=true;
	      DoubleFake=DoublebackGround(FRhisto, muonLooseButNOTightColl, i, j, doubleFake, 1);
	      Single_Double=Single_Doublebkg(FRhisto, muonLooseButNOTightColl, i, j);
	    }
	}
    }

    if (debug) cout<<"Double done"<<endl;

    if (DOUBLEFAKE) {
      if (debug) cout<<"        Double found"<<endl;
      nDoubleFake++;
      h_doublefakesTOT->Fill(MET, muonLooseButNOTightColl, jetVetoColl, DoubleFake*weight, false, false);
      h_totalfakesTOT->Fill(MET, muonLooseButNOTightColl, jetVetoColl, (DoubleFake+Single_Double)*weight, false, false);
      if (MET>40) {
	h_doublefakesMET50->Fill(MET, muonLooseButNOTightColl, jetVetoColl, DoubleFake*weight, false, false);
	h_totalfakesMET50->Fill(MET, muonLooseButNOTightColl, jetVetoColl, (DoubleFake+Single_Double)*weight, false, false);
      }
      else {
        if (b_found) {
	  h_doublefakesbTag->Fill(MET, muonLooseButNOTightColl, jetVetoColl, DoubleFake*weight, false, false);
	  h_totalfakesbTag->Fill(MET, muonLooseButNOTightColl, jetVetoColl, (DoubleFake+Single_Double)*weight, false, false);
        }
        else {
	  h_nVertex0->Fill(numberVertices, weight);
	  h_doublefakes->Fill(MET, muonLooseButNOTightColl, jetVetoColl, DoubleFake*weight, false, false);
          h_totalfakes->Fill(MET, muonLooseButNOTightColl, jetVetoColl, (DoubleFake+Single_Double)*weight, false, false);
        }
      }
    }
    
    SINGLEFAKE=false;
    Wcand_tmp=Wcand=0;
    if (muonLooseButNOTightColl.size() == 1 && muonTightColl.size() == 1 && jetVetoColl.size() >= 2) {
      for(UInt_t i=0; i<muonTightColl.size(); i++)
        for(UInt_t j=0; j<muonLooseButNOTightColl.size(); j++) {
          if (muonLooseButNOTightColl[j].charge()*muonTightColl[i].charge()>0)
            if (muonLooseButNOTightColl[j].lorentzVec().Pt() >=20 || muonTightColl[i].lorentzVec().Pt() >=20) {
              if (debug) cout<<"             Single found"<<endl;
              SINGLEFAKE=true;
	      SingleFake=SinglebackGround(FRhisto, muonLooseButNOTightColl, j, singleFake, 1);
	      FunzioProva(muonTightColl, i, muonLooseButNOTightColl, j, prova);
	      goto endSingle;
	    }
	}
    }
  endSingle:

    if (debug) cout<<"Single done, single = "<<SingleFake<<endl;

    if (SINGLEFAKE) {
      nSingleFake++;
      h_singlefakesTOT->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
      h_totalfakesTOT->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
      if (MET>40) {
	h_singlefakesMET50->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
	h_totalfakesMET50->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
      }
      else {
        if (b_found) {
	  h_singlefakesbTag->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
	  h_totalfakesbTag->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
        }
        else {
	  h_singlefakes->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
	  h_totalfakes->Fill(MET, muonTightColl, muonLooseButNOTightColl, jetVetoColl, SingleFake*weight, false, false);
	  h_nVertex1->Fill(numberVertices, weight);
        }
      }
    }
    /// BACKGROUND END ///
    if (debug) cout<<"cleaning"<<endl;
    muonTightColl.clear();  muonLooseButNOTightColl.clear(); muonLooseColl.clear();
    electronTightColl.clear(); jetVetoColl.clear();
    if (debug) cout<<"exiting loop"<<endl;    
  }
  if (debug) cout<< "out of the loop" <<endl;
  
  finalbkg1=finalbkgerror1=finalbkg2=finalbkgerror2=realsingle=realdouble=realtotal=doubletosingle=errdoubletosingle=0;
  BackGroundEstimate(FRhisto, singleFake, prova, doubleFake, finalbkg1, finalbkgerror1, finalbkg2, finalbkgerror2, realsingle, realsingleerror, realdouble, realtotal, doubletosingle, errdoubletosingle);

  cout<<"Single Fake n "<<nSingleFake<<" value "<<SingleFake<<endl;
  h_singlefake->SetBinContent(3,finalbkg1);
  h_singlefake->SetBinError(3,finalbkgerror1);
  h_singlefake->SetBinContent(1,realsingle);
  h_singlefake->SetBinError(1,realsingleerror);
  h_doublefake->SetBinContent(3,finalbkg2);
  h_doublefake->SetBinError(3,finalbkgerror2);
  h_doublefake->SetBinContent(1,realdouble);
  h_doublefake->SetBinContent(2,doubletosingle);
  h_doublefake->SetBinError(2,errdoubletosingle);
  cout<<"Double Fake n "<<nDoubleFake<<" value "<<DoubleFake<<endl;
  cout<<"Single_Double "<<Single_Double<<endl;
  cout<<"totale "<<realtotal<<", of which : "<<realsingle<<" single and "<<realdouble<<" double"<<endl;
  
  outfile->cd();
  h_nvtx_norw->Write();
  h_nvtx_rw->Write();
  h_prova->Write();
  h_MET->Write();
  h_METsign->Write();
  h_nVertex->Write();
  h_nVertex0->Write();
  h_nVertex1->Write();
  h_nVertex2->Write();
  h_nsignal->Write();
  h_singlefake->Write();
  h_doublefake->Write();

  Dir = outfile->mkdir("Heavy_Neutrino");
  outfile->cd( Dir->GetName() );
  h_signal->Write();
  h_signalMET50->Write();
  h_signalbTag->Write();
  h_signalTOT->Write();
  outfile->cd();

  Dir = outfile->mkdir("SingleFakes");
  outfile->cd( Dir->GetName() );
  h_singlefakes->Write();
  h_singlefakesMET50->Write();
  h_singlefakesbTag->Write();
  h_singlefakesTOT->Write();
  outfile->cd();
  Dir = outfile->mkdir("DoubleFakes");
  outfile->cd( Dir->GetName() );
  h_doublefakes->Write();
  h_doublefakesMET50->Write();
  h_doublefakesbTag->Write();
  h_doublefakesTOT->Write();
  outfile->cd();
  Dir = outfile->mkdir("TotalFakes");
  outfile->cd( Dir->GetName() );
  h_totalfakes->Write();
  h_totalfakesMET50->Write();
  h_totalfakesbTag->Write();
  h_totalfakesTOT->Write();
  outfile->cd();

  Dir = outfile->mkdir("Muons");
  outfile->cd( Dir->GetName() );
  h_muons->Write();
  h_muonsLoose->Write();
  h_LnotT->Write();
  //h_muonCharge->Write();
  //h_MuonMissCharge->Write();
  //h_RelIsoFR->Write();
  outfile->cd();

  Dir = outfile->mkdir("Electrons");
  outfile->cd( Dir->GetName() );
  h_electrons->Write();
  outfile->cd();  

  Dir = outfile->mkdir("Jets_with_veto");
  outfile->cd( Dir->GetName() );
  h_jets_veto->Write();
  outfile->cd();

  outfile->Close();

}
