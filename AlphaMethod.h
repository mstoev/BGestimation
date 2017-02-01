#pragma once

#include <cmath>
#include <iostream>
#include <TString.h>
#include <TFile.h>

using namespace std;



class AlphaMethod {

 public:
  // Constructors, destructor
  ///AlphaMethod() : _systematic("") {}
  AlphaMethod(const TString & variation, const TString & systematic, const TString & region);
  AlphaMethod(const AlphaMethod &) = default;
  AlphaMethod & operator = (const AlphaMethod &) = default;
  ~AlphaMethod() = default;

    
  // Setter and getter functions
  inline TString variation(){ return _variation;}
  inline TString systematic(){ return _systematic;}
  inline const TString variation() const{return _variation;}
  inline const TString systematic() const{return _systematic;}
  inline void set_variation(TString x){_variation = x;}
  inline void set_systematic(TString x){_systematic = x;}

  //Main functions for extrapolation, defined in AlphaMethod.cc
  void Extrapolation();
  void ExtrapolationCR1();
  void ExtrapolationCR2();

 private:
  TString _variation, _systematic,_region, SR_path, CR_path, FileOption, OUTPUTfile, DATAfile, TTfile, TTFAKEfile,TTREALfile, WJfile, DYfile, STfile, DIBOSONfile;
  int syst=0;
}; // end of class AlphaMethod
