#pragma once

#include <TString.h>

using namespace std;


// number of bins in the discriminating variable
const int n_bins = 4;
// rate variation
const double ttrate = 1.15;
const double wjrate = 1.5;
// defintion of 'syst'
//int syst=0;
// number of categories
const int n_cat = 4; // OS/SS high/low ST regions
const int n_catnew = 1; // two tau category
// categories
const TString cats[n_cat] = {"LQMod_OS_LQ_ST1200","LQMod_OS_LQ_LowMasses","LQMod_SS_LQ_ST1200","LQMod_SS_LQ_LowMasses"};
const TString catsnew[n_catnew] = {"LQMod_LQ_TwoTaus_final"};

// for plotting
const double umin = 0.5;
const double umax = 1.8;
