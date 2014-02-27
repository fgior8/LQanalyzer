{
  gROOT->ProcessLine(".L Reweight.cc+g");
  gROOT->ProcessLine(".L Data.cc+g");
  gROOT->ProcessLine(".L OtherFunctions.cc+g");
  gROOT->ProcessLine(".L SelectionFunctions.cc+g");
  gROOT->ProcessLine(".L LeptonSelection.cc+g");
  gROOT->ProcessLine(".L ElectronSelection.cc+g");
  gROOT->ProcessLine(".L MuonSelection.cc+g");
  gROOT->ProcessLine(".L MuonSelectionProbe.cc+g");
  gROOT->ProcessLine(".L JetSelection.cc+g");
  gROOT->ProcessLine(".L GenSelection.cc+g");
  gROOT->ProcessLine(".L StdPlots.cc+g");
  gROOT->ProcessLine(".L ElectronPlots.cc+g");
  gROOT->ProcessLine(".L MuonPlots.cc+g");
  gROOT->ProcessLine(".L JetPlots.cc+g");
  gROOT->ProcessLine(".L SignalPlots.cc+g");
  gROOT->ProcessLine(".L Analyzer.cc+g");
  gROOT->ProcessLine(".L Analyzer_Ele.cc+g");
  gROOT->ProcessLine(".L FakeRateCalculator.cc+g");
  gROOT->ProcessLine(".L FakeRateCalculator_Ele.cc+g");
  gROOT->ProcessLine(".L EfficiencyCalculator.cc+g");
  gROOT->ProcessLine(".L ChainMaker.C+g");

  //////////////////////////////////////////////////////////
  //                          MC                          //
  //////////////////////////////////////////////////////////

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Wgamma_leptons.txt");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Wgamma_FR40",31);
    Pippo.SetWeight(461.6, 4802358);
    std::cout << "Wgamma\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/QCD_mu15.txt");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_mu15_FR",8); //Pippo.SetWeight(10.04, 2194752);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/QCD_600-800_mu.txt");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_300-470_mu_FR_delete",8); //Pippo.SetWeight(10.04, 2194752);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
  }

  if (0) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_0-15.txt");
    EffCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_0-15_Eff",9); //Pippo.SetWeight(10.04, 2194752);
    std::cout << "QCD_mu\n";  Pippo.LoopEff();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/ttbar.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("ttbar_FR",50); 
     Pippo.SetWeight(234., 6736135);
     std::cout << "ttbar\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Wjets.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Wjets_PLOT",8); Pippo.SetWeight(36257.2, 57709905*2316/1818);
     std::cout << "Wjets\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_0-15.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_0-15_FR40_30",24); 
     Pippo.SetWeight(4935.578, 200448);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_15-20.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_15-20_FR40_30",24);
     Pippo.SetWeight(172.6416, 200236);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_20-30.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_20-30_FR40_30",24); 
     Pippo.SetWeight(156.8129, 150120);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_30-50.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_30-50_FR40_30",24); 
     Pippo.SetWeight(102.5517, 150165);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_50-80.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_50-80_FR40_30",24); 
     Pippo.SetWeight(40.15132, 100200);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_80-120.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_80-120_FR40_30",24);
     Pippo.SetWeight(12.69172, 100172);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_120-170.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_120-170_FR40_30",24); 
     Pippo.SetWeight(3.56208, 100160);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_170-230.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_170-230_FR40_30",24);
     Pippo.SetWeight(0.9677884, 100172);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_230-300.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_230-300_FR40_30",24);
     Pippo.SetWeight(0.2684074, 70500);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/Zjet_300.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("Zjet_300_FR40_30",24); 
     Pippo.SetWeight(0.9677884, 100172);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/WW_inclusive.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("WW_inclusive_FR",9); //Pippo.SetWeight(0.9677884, 100172);
     std::cout << "Zjet\n";  Pippo.LoopFR();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/QCD_mumu.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("QCD_mumu",31); 
     //Pippo.SetWeight(154.0, 3701947);
     std::cout << "QCD_mumu\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/ttbar.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("ttbar_del",31); 
     //Pippo.SetWeight(154.0, 3701947);
     std::cout << "ttbar\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/QCD_1000_mu.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("QCD_1000_mu_del",8); //Pippo.SetWeight(154.0, 3701947);
     std::cout << "QCD_mu\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana50.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana50",77); 
     Pippo.SetWeight(1071.1, 49996);
     std::cout << "Majorana50\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana70.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana70",77); 
     Pippo.SetWeight(211.96, 49994);
     std::cout << "Majorana70\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana90.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana90",77); 
     Pippo.SetWeight(7.1047, 49996);
     std::cout << "Majorana90\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana100.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana100",95); 
     Pippo.SetWeight(3.5618, 49994);
     std::cout << "Majorana100\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana125.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana125",71); 
     Pippo.SetWeight(1.0767, 49995);
     std::cout << "Majorana125\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana150.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana150",75);
     Pippo.SetWeight(0.4594, 49995);
     std::cout << "Majorana150\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana175.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana175",61);
     Pippo.SetWeight(0.23266, 49995);
     std::cout << "Majorana175\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana200.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana200",75);
     Pippo.SetWeight(0.13127, 49992);
     std::cout << "Majorana200\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana250.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana250",75);
     Pippo.SetWeight(0.050928, 49997);
     std::cout << "Majorana250\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana300.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana300",75);
     Pippo.SetWeight(0.023214, 49996);
     std::cout << "Majorana300\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana350.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana350",75);
     Pippo.SetWeight(0.011705, 49995);
     std::cout << "Majorana350\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana400.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana400",75);
     Pippo.SetWeight(0.0063324, 49996);
     std::cout << "Majorana400\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana500.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana500",75); 
     Pippo.SetWeight(0.0021542, 49995);
     std::cout << "Majorana500\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana600.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana600",75);
     Pippo.SetWeight(8.545E-04, 49994);
     std::cout << "Majorana600\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/Majorana700.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("Majorana700",75);
     Pippo.SetWeight(3.83E-04, 49998);
     std::cout << "Majorana700\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/ZZ_inclusive.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("ZZ_inclusive",11); Pippo.SetWeight(17.654, 9799908);
     std::cout << "ZZ\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/WZ_inclusive.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WZ_inclusive_mio",7); Pippo.SetWeight(33.21, 10000283);
     std::cout << "WZ\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/WpWp.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WpWp",95); 
     Pippo.SetWeight(0.2482, 99985);
     std::cout << "WpWp\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/WmWm.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WmWm",95); 
     Pippo.SetWeight(0.08888, 96392);
     std::cout << "WmWm\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/WW_dp.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WW_dp",46); 
     Pippo.SetWeight(0.5879, 834040);
     std::cout << "WW_dp\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/WWW.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WWW",95);
     Pippo.SetWeight(0.08217, 220549);
     std::cout << "WWW\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/ttW.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("ttW",95); 
     Pippo.SetWeight(0.232, 196046);
     std::cout << "ttW\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/ttZ.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("ttZ",95); 
     Pippo.SetWeight(0.1743, 210160);
     std::cout << "ttZ\n";  Pippo.Loop();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/WR700_MNu350.txt");
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("WR700_MNu350",46); 
     Pippo.SetWeight(8.598, 500195);
     std::cout << "WR\n";  Pippo.Loop();
  }

  //////////////////////////////////////////////////////////
  //                        Data                          //
  //////////////////////////////////////////////////////////


  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_09/CMSSW_5_3_4_LQ/src/code/DataSetList/SingleMuA_recover.txt");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("SingleMuA_del",1); //Pippo.SetWeight(.02);
     std::cout << "mu\n";  Pippo.LoopFR();
     //Pippo.~Analyzer();
  }

  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_11/CMSSW_5_3_8_LQ/src/code/DataSetList/DoubleMuA_22Jan.txt");
     // 1076311113.674 (mb)^-1 
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("DoubleMu_prova",1); //Pippo.SetWeight(.02);
     std::cout << "mu\n";  Pippo.Loop();
  }

}

