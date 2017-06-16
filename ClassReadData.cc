#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
using namespace std;

class ClassReadData {

public :

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   Int_t           fCurrent; //!current Tree number in a TChain



// Fixed size dimensions of array or collections stored in the TTree if any.



   // Declaration of leaf types

   UInt_t          RunNum;

   UInt_t          LumiBlockNum;

   ULong64_t       EvtNum;

   Bool_t          AK4JetID;

   vector<TLorentzVector> *AK4Jets;

   vector<bool>    *AK4JetsIDMask;

   vector<TLorentzVector> *AK8GenJets;

   vector<TLorentzVector> *AK8PFCHSJets;

   vector<double>  *AK8PFCHSPrunedMass;

   vector<double>  *AK8PFCHSSoftdropMass;

   vector<double>  *AK8PFCHStau1;

   vector<double>  *AK8PFCHStau2;

   vector<double>  *AK8PFCHStau3;

   vector<double>  *AK8PFCHSTrimmedMass;

   vector<TLorentzVector> *AK8PFJets;

   vector<double>  *AK8PFPrunedMass;

   vector<TLorentzVector> *AK8PFPuppiJets;

   vector<double>  *AK8PFPuppiPrunedMass;

   vector<double>  *AK8PFPuppirimmedMass;

   vector<double>  *AK8PFPuppiSoftdropMass;

   vector<double>  *AK8PFPuppitau1;

   vector<double>  *AK8PFPuppitau2;

   vector<double>  *AK8PFPuppitau3;

   vector<double>  *AK8PFSoftdropMass;

   vector<double>  *AK8PFTrimmedMass;

   vector<TLorentzVector> *Electrons;

   vector<double>  *JetsAK4_bDiscriminatorCSV;

   Double_t        MET;

   Int_t           nAllVertices;

   Int_t           npu;

   Int_t           NVtx;



   // List of branches

   TBranch        *b_RunNum;   //!

   TBranch        *b_LumiBlockNum;   //!

   TBranch        *b_EvtNum;   //!

   TBranch        *b_AK4JetID;   //!

   TBranch        *b_AK4Jets;   //!

   TBranch        *b_AK4JetsIDMask;   //!

   TBranch        *b_AK8GenJets;   //!

   TBranch        *b_AK8PFCHSJets;   //!

   TBranch        *b_AK8PFCHSPrunedMass;   //!

   TBranch        *b_AK8PFCHSSoftdropMass;   //!

   TBranch        *b_AK8PFCHStau1;   //!

   TBranch        *b_AK8PFCHStau2;   //!

   TBranch        *b_AK8PFCHStau3;   //!

   TBranch        *b_AK8PFCHSTrimmedMass;   //!

   TBranch        *b_AK8PFJets;   //!

   TBranch        *b_AK8PFPrunedMass;   //!

   TBranch        *b_AK8PFPuppiJets;   //!

   TBranch        *b_AK8PFPuppiPrunedMass;   //!

   TBranch        *b_AK8PFPuppirimmedMass;   //!

   TBranch        *b_AK8PFPuppiSoftdropMass;   //!

   TBranch        *b_AK8PFPuppitau1;   //!

   TBranch        *b_AK8PFPuppitau2;   //!

   TBranch        *b_AK8PFPuppitau3;   //!

   TBranch        *b_AK8PFSoftdropMass;   //!

   TBranch        *b_AK8PFTrimmedMass;   //!

   TBranch        *b_Electrons;   //!

   TBranch        *b_JetsAK4_bDiscriminatorCSV;   //!

   TBranch        *b_MET;   //!

   TBranch        *b_nAllVertices;   //!

   TBranch        *b_npu;   //!

   TBranch        *b_NVtx;   //!



   ClassReadData(TTree *tree);

   virtual ~ClassReadData();

   

   

   

   virtual void     Init(TTree *tree);

   

   

   

};

ClassReadData::~ClassReadData()

{

   if (!fChain) return;

   delete fChain->GetCurrentFile();

}

void ClassReadData::Init(TTree *tree)

{

   // The Init() function is called when the selector needs to initialize

   // a new tree or chain. Typically here the branch addresses and branch

   // pointers of the tree will be set.

   // It is normally not necessary to make changes to the generated

   // code, but the routine can be extended by the user if needed.

   // Init() will be called many times when running on PROOF

   // (once per file to be processed).



   // Set object pointer

   AK4Jets = 0;

   AK4JetsIDMask = 0;

   AK8GenJets = 0;

   AK8PFCHSJets = 0;

   AK8PFCHSPrunedMass = 0;

   AK8PFCHSSoftdropMass = 0;

   AK8PFCHStau1 = 0;

   AK8PFCHStau2 = 0;

   AK8PFCHStau3 = 0;

   AK8PFCHSTrimmedMass = 0;

   AK8PFJets = 0;

   AK8PFPrunedMass = 0;

   AK8PFPuppiJets = 0;

   AK8PFPuppiPrunedMass = 0;

   AK8PFPuppirimmedMass = 0;

   AK8PFPuppiSoftdropMass = 0;

   AK8PFPuppitau1 = 0;

   AK8PFPuppitau2 = 0;

   AK8PFPuppitau3 = 0;

   AK8PFSoftdropMass = 0;

   AK8PFTrimmedMass = 0;

   Electrons = 0;

   JetsAK4_bDiscriminatorCSV = 0;

   // Set branch addresses and branch pointers

   if (!tree) return;

   fChain = tree;

   fCurrent = -1;

   fChain->SetMakeClass(1);



   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);

   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);

   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);

   fChain->SetBranchAddress("AK4JetID", &AK4JetID, &b_AK4JetID);

   fChain->SetBranchAddress("AK4Jets", &AK4Jets, &b_AK4Jets);

   fChain->SetBranchAddress("AK4JetsIDMask", &AK4JetsIDMask, &b_AK4JetsIDMask);

   fChain->SetBranchAddress("AK8GenJets", &AK8GenJets, &b_AK8GenJets);

   fChain->SetBranchAddress("AK8PFCHSJets", &AK8PFCHSJets, &b_AK8PFCHSJets);

   fChain->SetBranchAddress("AK8PFCHSPrunedMass", &AK8PFCHSPrunedMass, &b_AK8PFCHSPrunedMass);

   fChain->SetBranchAddress("AK8PFCHSSoftdropMass", &AK8PFCHSSoftdropMass, &b_AK8PFCHSSoftdropMass);

   fChain->SetBranchAddress("AK8PFCHStau1", &AK8PFCHStau1, &b_AK8PFCHStau1);

   fChain->SetBranchAddress("AK8PFCHStau2", &AK8PFCHStau2, &b_AK8PFCHStau2);

   fChain->SetBranchAddress("AK8PFCHStau3", &AK8PFCHStau3, &b_AK8PFCHStau3);

   fChain->SetBranchAddress("AK8PFCHSTrimmedMass", &AK8PFCHSTrimmedMass, &b_AK8PFCHSTrimmedMass);

   fChain->SetBranchAddress("AK8PFJets", &AK8PFJets, &b_AK8PFJets);

   fChain->SetBranchAddress("AK8PFPrunedMass", &AK8PFPrunedMass, &b_AK8PFPrunedMass);

   fChain->SetBranchAddress("AK8PFPuppiJets", &AK8PFPuppiJets, &b_AK8PFPuppiJets);

   fChain->SetBranchAddress("AK8PFPuppiPrunedMass", &AK8PFPuppiPrunedMass, &b_AK8PFPuppiPrunedMass);

   fChain->SetBranchAddress("AK8PFPuppirimmedMass", &AK8PFPuppirimmedMass, &b_AK8PFPuppirimmedMass);

   fChain->SetBranchAddress("AK8PFPuppiSoftdropMass", &AK8PFPuppiSoftdropMass, &b_AK8PFPuppiSoftdropMass);

   fChain->SetBranchAddress("AK8PFPuppitau1", &AK8PFPuppitau1, &b_AK8PFPuppitau1);

   fChain->SetBranchAddress("AK8PFPuppitau2", &AK8PFPuppitau2, &b_AK8PFPuppitau2);

   fChain->SetBranchAddress("AK8PFPuppitau3", &AK8PFPuppitau3, &b_AK8PFPuppitau3);

   fChain->SetBranchAddress("AK8PFSoftdropMass", &AK8PFSoftdropMass, &b_AK8PFSoftdropMass);

   fChain->SetBranchAddress("AK8PFTrimmedMass", &AK8PFTrimmedMass, &b_AK8PFTrimmedMass);

   fChain->SetBranchAddress("Electrons", &Electrons, &b_Electrons);

   fChain->SetBranchAddress("JetsAK4_bDiscriminatorCSV", &JetsAK4_bDiscriminatorCSV, &b_JetsAK4_bDiscriminatorCSV);

   fChain->SetBranchAddress("MET", &MET, &b_MET);

   fChain->SetBranchAddress("nAllVertices", &nAllVertices, &b_nAllVertices);

   fChain->SetBranchAddress("npu", &npu, &b_npu);

   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);

   

}

ClassReadData::ClassReadData(TTree *tree)
{
	Init(tree);
}