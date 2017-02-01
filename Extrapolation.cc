#include "parameters.h"
#include "AlphaMethod.h"

#include <TStyle.h>
#include <TF1.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TMath.h>
#include <TFile.h>


using namespace std;

void AlphaMethod::Extrapolation(){

  TFile* F_CR_DATA;
  TFile* F_CR_READDATA;
  TFile* F_CR_TTbar;
  TFile* F_CR_TTbar_RealTaus;
  TFile* F_CR_SingleTop;
  TFile* F_CR_WJets;
  TFile* F_CR_DYJets;
  TFile* F_CR_Diboson;
  TFile* F_SR_TTbar;
  TFile* F_SR_WJets;

  // Sideband data files
  if(AlphaMethod::syst==0 || AlphaMethod::syst==1 || AlphaMethod::syst==2 || AlphaMethod::syst==3 || AlphaMethod::syst==4 || AlphaMethod::syst==5 || AlphaMethod::syst==6 || AlphaMethod::syst==7){
    F_CR_DATA = new TFile(AlphaMethod::SR_path+AlphaMethod::_systematic+AlphaMethod::OUTPUTfile,AlphaMethod::FileOption);
    F_CR_READDATA = new TFile(AlphaMethod::CR_path+AlphaMethod::DATAfile,"READ");
  }

  if(AlphaMethod::syst==0 || AlphaMethod::syst==1 || AlphaMethod::syst==2 || AlphaMethod::syst==4 || AlphaMethod::syst==5 || AlphaMethod::syst==6 || AlphaMethod::syst==7){
    F_CR_TTbar = new TFile(AlphaMethod::CR_path+AlphaMethod::TTfile,"READ"); // this should be ttbar (including some real taus) !!!!!
    F_CR_SingleTop = new TFile(AlphaMethod::CR_path+AlphaMethod::STfile,"READ");
    F_CR_WJets = new TFile(AlphaMethod::CR_path+AlphaMethod::WJfile,"READ");
    F_CR_DYJets = new TFile(AlphaMethod::CR_path+AlphaMethod::DYfile,"READ");
    F_CR_Diboson = new TFile(AlphaMethod::CR_path+AlphaMethod::DIBOSONfile,"READ");
    F_CR_TTbar_RealTaus = new TFile(AlphaMethod::CR_path+AlphaMethod::TTREALfile, "READ");

    // get the file with tau fakes only for the correct extrapolation
    F_SR_TTbar = new TFile(AlphaMethod::SR_path+AlphaMethod::TTFAKEfile,"READ");
    F_SR_WJets = new TFile(AlphaMethod::SR_path+AlphaMethod::WJfile,"READ");
  }

  if(AlphaMethod::syst==3){
    F_CR_TTbar = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::TTfile,"READ");   // this should be ttbar (including some real taus) !!!!!
    F_CR_SingleTop = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::STfile,"READ");
    F_CR_WJets = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::WJfile,"READ");
    F_CR_DYJets = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::DYfile,"READ");
    F_CR_Diboson = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::DIBOSONfile,"READ");
    F_CR_TTbar_RealTaus = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::TTREALfile, "READ");

    // get the file with tau fakes only for the correct extrapolation
    F_SR_TTbar = new TFile(AlphaMethod::SR_path+AlphaMethod::_systematic+AlphaMethod::TTFAKEfile,"READ");
    F_SR_WJets = new TFile(AlphaMethod::SR_path+AlphaMethod::_systematic+AlphaMethod::WJfile,"READ");
  }

  if(AlphaMethod::syst==8){
    F_CR_READDATA = new TFile(AlphaMethod::CR_path+AlphaMethod::DATAfile,"READ");
    if(AlphaMethod::_variation == "scalettup"){
      F_CR_DATA = new TFile(AlphaMethod::SR_path+"TTSCALE_up/"+AlphaMethod::OUTPUTfile,"RECREATE");
    }
    if(AlphaMethod::_variation == "scalettdn"){
      F_CR_DATA = new TFile(AlphaMethod::SR_path+"TTSCALE_down/"+AlphaMethod::OUTPUTfile,"RECREATE");
    }

    F_CR_TTbar = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::TTfile,"READ"); // this should be ttbar (including some real taus) !!!!!
    F_CR_SingleTop = new TFile(AlphaMethod::CR_path+AlphaMethod::STfile,"READ");
    F_CR_WJets = new TFile(AlphaMethod::CR_path+AlphaMethod::WJfile,"READ");
    F_CR_DYJets = new TFile(AlphaMethod::CR_path+AlphaMethod::DYfile,"READ");
    F_CR_Diboson = new TFile(AlphaMethod::CR_path+AlphaMethod::DIBOSONfile,"READ");
    F_CR_TTbar_RealTaus = new TFile(AlphaMethod::CR_path+AlphaMethod::TTREALfile, "READ");

    // get the file with tau fakes only for the correct extrapolation
    F_SR_TTbar = new TFile(AlphaMethod::SR_path+AlphaMethod::_systematic+AlphaMethod::TTFAKEfile,"READ");
    F_SR_WJets = new TFile(AlphaMethod::SR_path+AlphaMethod::WJfile,"READ");
  }

  if(AlphaMethod::syst==9){
    F_CR_READDATA = new TFile(AlphaMethod::CR_path+AlphaMethod::DATAfile,"READ");
    if(AlphaMethod::_variation == "scalewjup"){
      F_CR_DATA = new TFile(AlphaMethod::SR_path+"WJSCALE_up/"+AlphaMethod::OUTPUTfile,"RECREATE");
    }
    if(AlphaMethod::_variation == "scalewjdn"){
      F_CR_DATA = new TFile(AlphaMethod::SR_path+"WJSCALE_down/"+AlphaMethod::OUTPUTfile,"RECREATE");
    }

    F_CR_TTbar = new TFile(AlphaMethod::CR_path+AlphaMethod::TTfile,"READ"); // this should be ttbar (including some real taus) !!!!!
    F_CR_SingleTop = new TFile(AlphaMethod::CR_path+AlphaMethod::STfile,"READ");
    F_CR_WJets = new TFile(AlphaMethod::CR_path+AlphaMethod::_systematic+AlphaMethod::WJfile,"READ");
    F_CR_DYJets = new TFile(AlphaMethod::CR_path+AlphaMethod::DYfile,"READ");
    F_CR_Diboson = new TFile(AlphaMethod::CR_path+AlphaMethod::DIBOSONfile,"READ");
    F_CR_TTbar_RealTaus = new TFile(AlphaMethod::CR_path+AlphaMethod::TTREALfile, "READ");

    // get the file with tau fakes only for the correct extrapolation
    F_SR_TTbar = new TFile(AlphaMethod::SR_path+AlphaMethod::TTFAKEfile,"READ");
    F_SR_WJets = new TFile(AlphaMethod::SR_path+AlphaMethod::_systematic+AlphaMethod::WJfile,"READ");
  }



  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // get the histos
  TString histname = "Pt_tophad_own_binned";  

  TH1D* dataTTbar[n_cat];
  TH1D* CR_TTbar[n_cat];
  TH1D* CR_TTbarReal[n_cat];
  TH1D* CR_SingleTop[n_cat];
  TH1D* CR_WJets[n_cat];
  TH1D* CR_DYJets[n_cat];
  TH1D* CR_Diboson[n_cat];
  TH1D* SR_TTbar[n_cat];
  TH1D* SR_TTbar_Int[n_cat];
  TH1D* CR_TTbar_Int[n_cat];
  TH1D* SR_WJets_Int[n_cat];
  TH1D* CR_WJets_Int[n_cat];

  for(int i=0; i<n_cat; i++){
    dataTTbar[i]=(TH1D*)F_CR_READDATA->Get(cats[i]+"/"+histname);
    CR_TTbar[i]=(TH1D*)F_CR_TTbar->Get(cats[i]+"/"+histname);
    CR_TTbarReal[i]=(TH1D*)F_CR_TTbar_RealTaus->Get(cats[i]+"/"+histname);
    CR_SingleTop[i]=(TH1D*)F_CR_SingleTop->Get(cats[i]+"/"+histname);
    CR_WJets[i]=(TH1D*)F_CR_WJets->Get(cats[i]+"/"+histname);
    CR_DYJets[i]=(TH1D*)F_CR_DYJets->Get(cats[i]+"/"+histname);
    CR_Diboson[i]=(TH1D*)F_CR_Diboson->Get(cats[i]+"/"+histname);
    SR_TTbar[i]=(TH1D*)F_SR_TTbar->Get(cats[i]+"/"+histname);
    SR_TTbar_Int[i]=(TH1D*)F_SR_TTbar->Get(cats[i]+"/N"); // needed for the uncertainty on the integral
    CR_TTbar_Int[i]=(TH1D*)F_CR_TTbar->Get(cats[i]+"/N"); // needed for the uncertainty on the integral
    SR_WJets_Int[i]=(TH1D*)F_SR_WJets->Get(cats[i]+"/N"); // needed for the uncertainty on the integral
    CR_WJets_Int[i]=(TH1D*)F_CR_WJets->Get(cats[i]+"/N"); // needed for the uncertainty on the integral
  }


  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // get all background together. This is needed to scale the background to the data in order to get a better estimation of the ttbar fraction in data   
  TH1D* CR_Allbkg[n_cat];
  for(int i=0; i<n_cat; i++){
    CR_Allbkg[i]=(TH1D*)CR_TTbar[i]->Clone();
    CR_Allbkg[i]->Add(CR_TTbarReal[i]);
    CR_Allbkg[i]->Add(CR_SingleTop[i]);
    CR_Allbkg[i]->Add(CR_WJets[i]);
    CR_Allbkg[i]->Add(CR_DYJets[i]);
    CR_Allbkg[i]->Add(CR_Diboson[i]);
    for(int j=1; j<n_bins+1; j++){
      CR_SingleTop[i]->SetBinContent(j, CR_SingleTop[i]->GetBinContent(j) * dataTTbar[i]->GetBinContent(j) / CR_Allbkg[i]->GetBinContent(j));
      CR_WJets[i]->SetBinContent(j, CR_WJets[i]->GetBinContent(j) * dataTTbar[i]->GetBinContent(j) / CR_Allbkg[i]->GetBinContent(j));
      CR_DYJets[i]->SetBinContent(j, CR_DYJets[i]->GetBinContent(j) * dataTTbar[i]->GetBinContent(j) / CR_Allbkg[i]->GetBinContent(j));
      CR_Diboson[i]->SetBinContent(j, CR_Diboson[i]->GetBinContent(j) * dataTTbar[i]->GetBinContent(j) / CR_Allbkg[i]->GetBinContent(j));
      CR_TTbarReal[i]->SetBinContent(j, CR_TTbarReal[i]->GetBinContent(j) * dataTTbar[i]->GetBinContent(j) / CR_Allbkg[i]->GetBinContent(j));
    }
  }
  

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // here: subtract the scaled backgrounds from data
  
  for(int i=0; i<n_cat; i++){
    dataTTbar[i]->Add(CR_SingleTop[i],-1);
    dataTTbar[i]->Add(CR_DYJets[i],-1);
    dataTTbar[i]->Add(CR_Diboson[i],-1);
  }

  cout << endl << endl;
  if(AlphaMethod::syst!=0){
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "+++++++++++" << AlphaMethod::_systematic << "+++++++++++++++++++++++++++++++" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl << endl;
  }
  
  for(int i=0; i<n_cat; i++){
    cout << "#ttbar and WJets from data, " << cats[i] << ": " << dataTTbar[i]->Integral() << endl;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // uncertainties on the integral
  
  double TT_SR[n_cat];
  double WJ_SR[n_cat];
  double TT_CR[n_cat];
  double WJ_CR[n_cat];
  double TT_SR_ERR[n_cat];
  double WJ_SR_ERR[n_cat];
  double TT_CR_ERR[n_cat];
  double WJ_CR_ERR[n_cat];
  for(int i=0; i<n_cat; i++){
    TT_SR[i] = SR_TTbar_Int[i]->GetBinContent(1);
    WJ_SR[i] = SR_WJets_Int[i]->GetBinContent(1);
    TT_CR[i] = CR_TTbar_Int[i]->GetBinContent(1);
    WJ_CR[i] = CR_WJets_Int[i]->GetBinContent(1);
    TT_SR_ERR[i] = SR_TTbar_Int[i]->GetBinError(1);
    WJ_SR_ERR[i] = SR_WJets_Int[i]->GetBinError(1);
    TT_CR_ERR[i] = CR_TTbar_Int[i]->GetBinError(1);
    WJ_CR_ERR[i] = CR_WJets_Int[i]->GetBinError(1);
  }
  

  if(AlphaMethod::syst==4){
    for(int i=0; i<n_cat; i++){
      TT_SR[i]*=ttrate;
      TT_CR[i]*=ttrate;
    }
  }
  if(AlphaMethod::syst==5){
    for(int i=0; i<n_cat; i++){
      TT_SR[i]*=(2-ttrate);
      TT_CR[i]*=(2-ttrate);
    }
  }
  if(AlphaMethod::syst==6){
    for(int i=0; i<n_cat; i++){
      WJ_SR[i]*=wjrate;
      WJ_CR[i]*=wjrate;
    }
  }
  if(AlphaMethod::syst==7){
    for(int i=0; i<n_cat; i++){
      WJ_SR[i]*=(2-wjrate);
      WJ_CR[i]*=(2-wjrate);
    }
  }

  //++
  double Factor[n_cat];
  double Err[n_cat];
  double Factor_Up[n_cat];
  double Factor_Dn[n_cat];

  for(int i=0; i<n_cat; i++){
    Factor[i] = (TT_SR[i]+WJ_SR[i])/(TT_CR[i]+WJ_CR[i]);
    Err[i] = sqrt(  (pow(TT_SR_ERR[i],2)+pow(WJ_SR_ERR[i],2))/(pow(TT_CR[i]+WJ_CR[i],2)) + (pow(TT_SR[i]+WJ_SR[i],2)*(pow(TT_CR_ERR[i],2)+pow(WJ_CR_ERR[i],2)))/(pow(TT_CR[i]+WJ_CR[i],4))       );
    Factor_Up[i] = Factor[i] + Err[i];
    Factor_Dn[i] = Factor[i] - Err[i];
  }
  
  
  cout << endl << endl;
  for(int i=0; i<n_cat; i++){
    cout << cats[i] << endl;
    cout << "Int: " << Factor[i] << endl;
    cout << "Up:  " << Factor_Up[i] << endl;
    cout << "Dn:  " << Factor_Dn[i] << endl;
    cout << "(up-nominal)/Int = " << (Factor_Up[i]-Factor[i])/Factor[i] << endl;
    cout << "(nominal-dn)/Int = " << (Factor[i]-Factor_Dn[i])/Factor[i] << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  }
 

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // extrapolate the ttbar from data (sideband) to the signal region
  if(AlphaMethod::syst==0 || AlphaMethod::syst==3 || AlphaMethod::syst==4 || AlphaMethod::syst==5 || AlphaMethod::syst==6 || AlphaMethod::syst==7 || AlphaMethod::syst==8 || AlphaMethod::syst==9){
    for(int i=0; i<n_cat; i++){
      dataTTbar[i]->Scale(Factor[i]);
    }
  }
  if(AlphaMethod::syst==1){
    for(int i=0; i<n_cat; i++){
      dataTTbar[i]->Scale(Factor_Up[i]);
    }
  }
  if(AlphaMethod::syst==2){
    for(int i=0; i<n_cat; i++){
      dataTTbar[i]->Scale(Factor_Dn[i]);
    }
  }

  // just as a comparison: ttbar (sideband) scaled to the signal region
  for(int i=0; i<n_cat; i++){
    CR_TTbar[i]->Scale(SR_TTbar[i]->Integral()/CR_TTbar[i]->Integral());
  }
  cout << "before adding the real tau part" << endl;
  for(int i=0; i<n_cat; i++){
    cout << "#ttbar from data, " << cats[i] << ": " << dataTTbar[i]->Integral() << endl;
    cout << "#ttbar+wjets(SR), " << cats[i] << ": " << SR_TTbar[i]->Integral()+SR_WJets_Int[i]->Integral() << endl;
  }


  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // write the ttbar histos from data in the file and delete the origin histos
  for(int i=0; i<n_cat; i++){
    F_CR_DATA->mkdir(cats[i]);
    F_CR_DATA->cd(cats[i]);
    dataTTbar[i]->Write();
  }
  F_CR_DATA->Write();

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // plots..
  
  TCanvas* asd[n_cat];
  TString plotname[n_cat];
  for(int i=0; i<n_cat; i++){
    plotname[i] = cats[i]+"_plot";
    asd[i] = new TCanvas(plotname[i], plotname[i], 800,600);
    dataTTbar[i]->SetStats(0);
    dataTTbar[i]->GetXaxis()->SetTitle("p_{T}^{top}");
    dataTTbar[i]->GetXaxis()->SetTitleSize(0.04);
    dataTTbar[i]->GetYaxis()->SetTitle("Events");
    dataTTbar[i]->GetYaxis()->SetTitleSize(0.04);
    dataTTbar[i]->GetYaxis()->SetRangeUser(dataTTbar[i]->GetMinimum()*umin-1,dataTTbar[i]->GetMaximum()*umax+3);
    if(dataTTbar[i]->GetMinimum()<=1) dataTTbar[i]->GetYaxis()->SetRangeUser(0,dataTTbar[i]->GetMaximum());
    dataTTbar[i]->SetLineColor(2);
    dataTTbar[i]->SetLineWidth(2);
    dataTTbar[i]->Draw("E1");
    SR_TTbar[i]->SetLineColor(1);
    SR_TTbar[i]->SetLineWidth(2);
    SR_TTbar[i]->SetLineStyle(1);
    SR_TTbar[i]->Draw("E1 SAME");
    CR_TTbar[i]->SetLineColor(1);
    CR_TTbar[i]->SetLineWidth(2);
    CR_TTbar[i]->SetLineStyle(6);
    CR_TTbar[i]->Draw("E1 SAME");
    TLegend *leg2;
    leg2 = new TLegend(0.52,0.67,0.80,0.88,"","brNDC");//x+0.1
    leg2->AddEntry(SR_TTbar[i], "t#bar{t} MC (SR)");
    leg2->AddEntry(CR_TTbar[i], "t#bar{t} MC (CR)");
    leg2->AddEntry(dataTTbar[i], "t#bar{t} DATA");
    leg2->SetTextSize(0.06);
    leg2->SetFillStyle(0);
    leg2->SetBorderSize(0);
    leg2->SetFillColor(0);
    leg2->Draw();

  }
  
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //save plots
  if(AlphaMethod::syst==0){  
    for(int i=0; i<n_cat; i++){
      asd[i]->SaveAs(cats[i]+"_TTbarExtrapolated.pdf");
    }
  }
  if(AlphaMethod::syst==1 || AlphaMethod::syst==2){
    
    for(int i=0; i<n_cat; i++){
      asd[i]->SaveAs(cats[i]+"_TTbarExtrapolated_"+AlphaMethod::_variation+".pdf");
    }
  }
  if(AlphaMethod::syst==3){
    /*
      for(int i=0; i<n_cat; i++){
      asd[i]->SaveAs(cats[i]+"_TTbarExtrapolated_"+AlphaMethod::_systematic+".pdf");
      }
    */
  }


  for(int i=0; i<n_cat; i++) {
    delete dataTTbar[i];
    delete CR_TTbar[i];
    delete CR_SingleTop[i];
    delete CR_WJets[i];
    delete CR_DYJets[i];
    delete CR_Diboson[i];
    delete SR_TTbar[i];
    delete SR_TTbar_Int[i];
    delete CR_TTbar_Int[i];
    delete SR_WJets_Int[i];
    delete CR_WJets_Int[i];
    delete CR_Allbkg[i];
  }
  delete F_CR_DATA;
  delete F_CR_READDATA;
  delete F_CR_TTbar;
  delete F_CR_SingleTop;
  delete F_CR_WJets;
  delete F_CR_DYJets;
  delete F_CR_Diboson;
  delete F_SR_TTbar;
  delete F_SR_WJets;
}
