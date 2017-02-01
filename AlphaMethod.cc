#include <TString.h>
#include <TFile.h>

#include "AlphaMethod.h"



AlphaMethod::AlphaMethod(const TString & variation, const TString & systematic, const TString & region):_variation(variation),_systematic(systematic),_region(region){


  // define 'steering' parameter for systematic
  if(_variation == "central") syst=0;
  if(_variation == "up") syst=1;
  if(_variation == "down") syst=2;
  if(_variation == "allbkgs") syst=3;
  if(_variation == "ttcsup") syst=4;
  if(_variation == "ttcsdn") syst=5;
  if(_variation == "wjcsup") syst=6;
  if(_variation == "wjcsdn") syst=7;
  if(_variation == "scalettup" || _variation == "scalettdn") syst=8;
  if(_variation == "scalewjup" || _variation == "scalewjdn") syst=9;



  // define input paths
  if(_region=="CR" || _region=="CR1" || _region=="CR2") SR_path = "/nfs/dust/cms/user/mstoev/sFrame_new/LQAnalysis/Run2/MuSel_80X_v2/";
  if(_region=="CR1toCR2") SR_path = "/nfs/dust/cms/user/mstoev/sFrame_new/LQAnalysis/Run2/Inclusive_80X_v2/";
  if(_region=="CR" || _region=="CR1" || _region=="CR1toCR2") CR_path = "/nfs/dust/cms/user/mstoev/sFrame_new/LQAnalysis/Run2/TTbarSideBand_80X_v2/";
  if(_region=="CR2") CR_path = "/nfs/dust/cms/user/mstoev/sFrame_new/LQAnalysis/Run2/Inclusive_80X_v2/";

  if(_region=="CR" || _region=="CR1") OUTPUTfile = "uhh2.AnalysisModuleRunner.MC.TTbarFromData_test.root";
  if(_region=="CR1toCR2") OUTPUTfile = "uhh2.AnalysisModuleRunner.MC.FakeTTbarFromData_test.root";
  if(_region=="CR2") OUTPUTfile = "uhh2.AnalysisModuleRunner.MC.RealTTbarFromData_test.root";
  DATAfile = "uhh2.AnalysisModuleRunner.DATA.DATA.root";
  TTfile = "uhh2.AnalysisModuleRunner.MC.TTbar.root";
  if(_region=="CR" || _region=="CR1" || _region=="CR1toCR2") TTFAKEfile = "uhh2.AnalysisModuleRunner.MC.TTbar_onlyfakes.root";
  if(_region=="CR2") TTFAKEfile = "uhh2.AnalysisModuleRunner.MC.FakeTTbarFromData_test.root";
  TTREALfile = "uhh2.AnalysisModuleRunner.MC.TTbar_onlyrealtaus.root";
  WJfile = "uhh2.AnalysisModuleRunner.MC.WJetsHT.root";
  DYfile = "uhh2.AnalysisModuleRunner.MC.DYJetsHT.root";
  STfile = "uhh2.AnalysisModuleRunner.MC.SingleTop.root";
  DIBOSONfile = "uhh2.AnalysisModuleRunner.MC.Diboson.root";


  if(_region=="CR" || _region=="CR1toCR2" || _region=="CR2") FileOption = "RECREATE";
  if(_region=="CR1") FileOption = "UPDATE";


}
