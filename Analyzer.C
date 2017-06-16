#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
#include "ClassReadSig.cc"
#include "ClassReadBkg.cc"
#include "ClassReadData.cc" 
#include "Loader.C"
 #include "Looper_sig.C"
#include "Looper_bkg.C" 
#include "Looper_data.C"
  #include "HistCreater.C"
using namespace std;


void Analyzer(){
 
Loader L;



TFile *f=new TFile("Histograms.root","RECREATE");
HistCreater hs;
Looper_sig<ClassReadSig,HistCreater> loop_s;



TChain *tree_TTToSemiLeptonNoPU=L.Load("TTToSemiLeptonNoPU");
ClassReadSig TTToSemiLeptonNoPU(tree_TTToSemiLeptonNoPU);
loop_s.Loop(tree_TTToSemiLeptonNoPU,TTToSemiLeptonNoPU,hs,"TTToSemiLeptonNoPU");



TChain *tree_TTToSemiLeptonPU140=L.Load("TTToSemiLeptonPU140");
ClassReadSig TTToSemiLeptonPU140(tree_TTToSemiLeptonPU140);
loop_s.Loop(tree_TTToSemiLeptonPU140,TTToSemiLeptonPU140,hs,"TTToSemiLeptonPU140");







Looper_bkg<ClassReadBkg,HistCreater> loop_b;
TChain *tree_QCD200=L.Load("QCD200");
ClassReadBkg QCD200(tree_QCD200);
loop_b.Loop(tree_QCD200,QCD200,hs,"QCD200");



TChain *tree_QCD20=L.Load("QCD20");
ClassReadBkg QCD20(tree_QCD20);
loop_b.Loop(tree_QCD20,QCD20,hs,"QCD20");







Looper_data<ClassReadData,HistCreater> loop_d;
TChain *tree_QCDdata=L.Load("QCDdata");
ClassReadData QCDdata(tree_QCDdata);
loop_d.Loop(tree_QCDdata,QCDdata,hs,"QCDdata");





f->Write();

}
