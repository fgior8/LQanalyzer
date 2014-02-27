#!/bin/sh

cd /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code

source /uscmst1/prod/sw/cms/bashrc prod
echo `pwd`
eval `scramv1 runtime -sh`

clusterNumber=$1
list=$2
num=$3

cd ${_CONDOR_SCRATCH_DIR}

echo "Seeds:"
echo $var0 $var1

export CMSSW_SEARCH_PATH=${CMSSW_SEARCH_PATH}:`pwd`


cat > rootiamo_job${clusterNumber}.C<<EOF

{
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/Reweight.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/Data.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/OtherFunctions.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/SelectionFunctions.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/LeptonSelection.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/ElectronSelection.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/MuonSelection.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/MuonSelectionProbe.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/JetSelection.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/GenSelection.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/StdPlots.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/ElectronPlots.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/MuonPlots.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/JetPlots.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/SignalPlots.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/Analyzer.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/Analyzer_Ele.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/FakeRateCalculator.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/FakeRateCalculator_Ele.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/EfficiencyCalculator.cc+");
  gROOT->ProcessLine(".L /uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/ChainMaker.C+");

  TString extralabel = "";

  //////////////////////////////////////////////////////////
  //                          MC                          //
  //////////////////////////////////////////////////////////

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_mu15_v3_FR60_job$num",90); 
    Pippo.SetWeight(364000000*0.00037, 21484602);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_15-20_mu_FR_10_job$num",15); 
    Pippo.SetWeight(702200000*0.0039, 1722681);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_20-30_mu_FR_10_job$num",15); 
    Pippo.SetWeight(287000000*0.0065, 8486904);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_30-50_mu_FR_10_job$num",15); 
    Pippo.SetWeight(66090000*0.0122, 9560265);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_50-80_mu_FR_10_job$num",15); 
    Pippo.SetWeight(8082000*0.0218, 10365230);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_80-120_mu_FR_10_job$num",15); 
    Pippo.SetWeight(1024000*0.0395, 9238642);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_120-170_mu_FR_10_job$num",15); 
    Pippo.SetWeight(157800*0.0473, 8501935);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_170-300_mu_FR_10_job$num",15);
    Pippo.SetWeight(34020*0.0676, 7669947);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_300-470_mu_FR_10_job$num",15);
    Pippo.SetWeight(1757*0.0864, 7832261);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_470-600_mu_FR_10_job$num",15);
    Pippo.SetWeight(115.2*0.1024, 3783069);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_600-800_mu_FR_10_job$num",15);
    Pippo.SetWeight(27.01*0.0996, 4119000);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_800-1000_mu_FR_10_job$num",15);
    Pippo.SetWeight(3.57*0.1033, 4107853);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_1000_mu_FR_10_job$num",15);
    Pippo.SetWeight(0.774*0.1097, 3873970);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("QCD_20-30_EM_FR40_job$num",60);
    Pippo.SetWeight(2.89E+08*0.0101, 35040695);
    std::cout << "QCD_EM\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("QCD_30-80_EM_FR40_job$num",60);
    Pippo.SetWeight(7.43E+07*0.0621, 33088888);
    std::cout << "QCD_EM\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("QCD_80-170_EM_FR40_job$num",60);
    Pippo.SetWeight(1191000.0*0.1539, 34542763);
    std::cout << "QCD_EM\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("QCD_170-250_EM_FR40_job$num",60);
    Pippo.SetWeight(30990.0*0.148, 31697066);
    std::cout << "QCD_EM\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("QCD_250-350_EM_FR40_job$num",60);
    Pippo.SetWeight(4250.0*0.131, 34611322);
    std::cout << "QCD_EM\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("QCD_350_EM_FR40_job$num",60);
    Pippo.SetWeight(810.0*0.11, 34080562);
    std::cout << "QCD_EM\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Wgamma_FR40_job$num",76);
    Pippo.SetWeight(461.6, 4802358);
    std::cout << "Wgamma\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("Wgamma_FR40_job$num",60);
    Pippo.SetWeight(461.6, 4802358);
    std::cout << "Wgamma\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("ttbar_FR40_job$num",76); 
     Pippo.SetWeight(234., 6736135);
     std::cout << "ttbar\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("ttbar_FR40_job$num",60); 
     Pippo.SetWeight(234., 6736135);
     std::cout << "ttbar\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Wjets_FR40_job$num",76);
     Pippo.SetWeight(37509.0, 57709905);
     std::cout << "Wjets\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("Wjets_FR40_job$num",60);
     Pippo.SetWeight(37509.0, 57709905);
     std::cout << "Wjets\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DY_10-50_FR40_job$num",76); 
     Pippo.SetWeight(11050., 37835275);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("DY_10-50_FR40_job$num",60); 
     Pippo.SetWeight(11050., 37835275);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DY_50_FR40_job$num",76); 
     Pippo.SetWeight(3503.71, 30459503);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("DY_50_FR40_job$num",60); 
     Pippo.SetWeight(3503.71, 30459503);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DY1jet_10-50_FR40_job$num",30); 
     Pippo.SetWeight(716.0, 8041028);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DY1jet_50_FR40_job$num",24); 
     Pippo.SetWeight(666.3, 24045248);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DY2jet_50_FR40_job$num",24); 
     Pippo.SetWeight(214.97, 21852156);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DY3jet_50_FR40_job$num",24); 
     Pippo.SetWeight(60.69, 11015445);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DY4jet_50_FR40_job$num",24); 
     Pippo.SetWeight(27.36, 6402827);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("W1jet_50_FR40_job$num",24); 
     Pippo.SetWeight(6440.42, 23141598);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("W2jet_50_FR40_job$num",24); 
     Pippo.SetWeight(2087.17, 34044921);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("W3jet_50_FR40_job$num",24); 
     Pippo.SetWeight(619., 15539503);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("W4jet_50_FR40_job$num",24); 
     Pippo.SetWeight(255.23, 13382803);
     std::cout << "DY\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("WW_inclusive_FR40_job$num",31);
     Pippo.SetWeight(54.838, 10000431);
     std::cout << "WW\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("WZ_inclusive_FR40_job$num",31); 
     Pippo.SetWeight(33.21, 10000283);
     std::cout << "WZ\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("ZZ_inclusive_FR40_job$num",31); 
     Pippo.SetWeight(17.654, 9799908);
     std::cout << "ZZ\n";  Pippo.LoopFR();
  }

  if (1) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("QCD_mumu_job$num",31); 
     Pippo.SetWeight(4.9590002E10*4.0E-7, 1074400);
     std::cout << "QCD_mumu\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("ttbar_job$num",90); 
     Pippo.SetWeight(234., 6736135);
     std::cout << "ttbar\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WgammaStar_job$num",31); 
     //Pippo.SetWeight(10.04, 2194752);
     std::cout << "WgStar\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("QCD_X_mu_job$num",90); 
     //Pippo.SetWeight(10.04, 2194752);
     std::cout << "QCD_X_mu\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("W_jets_job$num",90); 
     Pippo.SetWeight(37509.0, 57709905);
     std::cout << "W_jets\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("ZZ_inclusive_job$num",71); 
     Pippo.SetWeight(17.654, 9799908);
     std::cout << "ZZ\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WZ_inclusive_job$num",71); 
     Pippo.SetWeight(33.21, 10000283);
     std::cout << "WZ\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WW_inclusive_job$num",71);
     Pippo.SetWeight(54.838, 10000431);
     std::cout << "WW\n";  Pippo.Loop();
  }

  //////////////////////////////////////////////////////////
  //                        Data                          //
  //////////////////////////////////////////////////////////

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
    EffCalculator Pippo; Pippo.Init(chain); Pippo.SetName("DoubleMu_Eff_job$num",13);
    std::cout << "mu\n";  Pippo.LoopEff();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("SingleMu_FR40_job$num",51);
     std::cout << "mu\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     FRCalculator_Ele Pippo; Pippo.Init(chain); Pippo.SetName("SingleElectron_FR40_job$num",60);
     std::cout << "Ele\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/$list");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("DoubleMu_40_job$num",61);
     std::cout << "mu\n";  Pippo.Loop();
  }


}


EOF

root -q -b rootiamo_job${clusterNumber}.C

