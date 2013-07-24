{
  gROOT->ProcessLine(".L Reweight.cc+g");
  gROOT->ProcessLine(".L Data.cc+g");
  gROOT->ProcessLine(".L OtherFunctions.cc+g");
  gROOT->ProcessLine(".L SelectionFunctions.cc+g");
  gROOT->ProcessLine(".L LeptonSelection.cc+g");
  gROOT->ProcessLine(".L ElectronSelection.cc+g");
  gROOT->ProcessLine(".L MuonSelection.cc+g");
  gROOT->ProcessLine(".L JetSelection.cc+g");
  gROOT->ProcessLine(".L StdPlots.cc+g");
  gROOT->ProcessLine(".L ElectronPlots.cc+g");
  gROOT->ProcessLine(".L MuonPlots.cc+g");
  gROOT->ProcessLine(".L SignalPlots.cc+g");
  gROOT->ProcessLine(".L Analyzer.cc+g");
//  gROOT->ProcessLine(".L FakeRateCalculator.cc+g");
  gROOT->ProcessLine(".L ChainMaker.C+g");

  //////////////////////////////////////////////////////////
  //                          MC                          //
  //////////////////////////////////////////////////////////

  if (0) {
    TChain* chain = ChainMaker("/home/cms/fgior8/codeFall11/DataSetList/QCD_mu15.txt");
    FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("QCD_mu15_FR80_DEL",14.02); //Pippo.SetWeight(10.04, 2194752);
    std::cout << "QCD_mu\n";  Pippo.LoopFR();
    Pippo.~FRCalculator();
  }

  if (0) {
     TChain* chain = ChainMaker("/home/cms/fgior8/codeFall11/DataSetList/ttbar.txt");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("ttbar_FR40",14.30); Pippo.SetWeight(154.0, 3701947);
     std::cout << "ttbar\n";  Pippo.LoopFR();
     Pippo.~FRCalculator();
  }


  //////////////////////////////////////////////////////////
  //                        Data                          //
  //////////////////////////////////////////////////////////


  if (0) {
     TChain* chain = ChainMaker("/home/cms/fgior8/LQanalyzer/DataSetList/prova.txt");
     // 1076311113.674 (mb)^-1 
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("provaFR",1); //Pippo.SetWeight(.02);
     std::cout << "mu\n";  Pippo.LoopFR();
     //Pippo.~Analyzer();
  }

  if (1) {
     TChain* chain = ChainMaker("/home/cms/fgior8/LQanalyzer/DataSetList/prova.txt");
     // 1076311113.674 (mb)^-1 
     Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("prova",1); //Pippo.SetWeight(.02);
     std::cout << "mu\n";  Pippo.Loop();
     //Pippo.~Analyzer();
  }

}

