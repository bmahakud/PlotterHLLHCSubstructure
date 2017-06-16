template <class classInst, class HistogramCreater> class Looper_bkg{
public:

void Loop(TChain *tr,classInst& read,HistogramCreater hs, string ProcessName);

bool Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool pTbin1(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool pTbin2(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool pTbin3(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool pTbin4(TChain *tr,classInst& read,string ProcessName,int iEvent);

};

template <class classInst,class HistogramCreater> void Looper_bkg<classInst,HistogramCreater>::Loop(TChain *tr,classInst& read,HistogramCreater hs,string ProcessName)

{//looper definition

string processes[5]={ "TTToSemiLeptonNoPU"  , "TTToSemiLeptonPU140"  , "QCD200"  , "QCD20"  , "QCDdata"  };
string dataprocesses[1]={ "QCDdata"  };
const int processesSize=5;
            auto it=std::find(processes,processes+processesSize,ProcessName);
            int processInt=it-processes;
       std::cout<<"Total number of entries: "<<tr->GetEntries()<<std::endl;

       for(int iEv=0;iEv<tr->GetEntries();iEv++){// event loop

       tr->GetEntry(iEv);

          if(iEv % 1000==0)std::cout<<"Running on "<<ProcessName<<" event no: "<<iEv<<"---completed : "<<(float(iEv)/float(tr->GetEntries()))*100<<" %"<<std::endl;

            if(Baseline(tr,read,ProcessName,iEv)  && ProcessCuts(tr,read,ProcessName, iEv)){ //Baseline for this processn

            double EventWeight=1;
if(pTbin1(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][0]->Fill(read.AK8PFPuppirimmedMass->at(0),EventWeight); 
         hs.h_[1][processInt][0]->Fill(read.AK8PFPuppiPrunedMass->at(0),EventWeight); 
         hs.h_[2][processInt][0]->Fill(read.AK8PFPuppiSoftdropMass->at(0),EventWeight); 
         hs.h_[3][processInt][0]->Fill(read.AK8PFPuppitau2->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[4][processInt][0]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[5][processInt][0]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau2->at(0),EventWeight); 
}

if(pTbin2(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][1]->Fill(read.AK8PFPuppirimmedMass->at(0),EventWeight); 
         hs.h_[1][processInt][1]->Fill(read.AK8PFPuppiPrunedMass->at(0),EventWeight); 
         hs.h_[2][processInt][1]->Fill(read.AK8PFPuppiSoftdropMass->at(0),EventWeight); 
         hs.h_[3][processInt][1]->Fill(read.AK8PFPuppitau2->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[4][processInt][1]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[5][processInt][1]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau2->at(0),EventWeight); 
}

if(pTbin3(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][2]->Fill(read.AK8PFPuppirimmedMass->at(0),EventWeight); 
         hs.h_[1][processInt][2]->Fill(read.AK8PFPuppiPrunedMass->at(0),EventWeight); 
         hs.h_[2][processInt][2]->Fill(read.AK8PFPuppiSoftdropMass->at(0),EventWeight); 
         hs.h_[3][processInt][2]->Fill(read.AK8PFPuppitau2->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[4][processInt][2]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[5][processInt][2]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau2->at(0),EventWeight); 
}

if(pTbin4(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][3]->Fill(read.AK8PFPuppirimmedMass->at(0),EventWeight); 
         hs.h_[1][processInt][3]->Fill(read.AK8PFPuppiPrunedMass->at(0),EventWeight); 
         hs.h_[2][processInt][3]->Fill(read.AK8PFPuppiSoftdropMass->at(0),EventWeight); 
         hs.h_[3][processInt][3]->Fill(read.AK8PFPuppitau2->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[4][processInt][3]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau1->at(0),EventWeight); 
         hs.h_[5][processInt][3]->Fill(read.AK8PFPuppitau3->at(0)/read.AK8PFPuppitau2->at(0),EventWeight); 
}

               }//Baseline for this process

       }//event loop

}//looper definition

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(
read. AK8PFPuppiJets->size()>0 && 
read. AK8PFPuppirimmedMass->at(0)>0 && 
read. AK8PFPuppiPrunedMass->at(0)>0 && 
read. AK8PFPuppiSoftdropMass->at(0)>0 && 
read. AK8PFPuppiJets->at(0).Pt()>500.0 && 
read. AK8PFPuppitau1->at(0)>0 && 
read. AK8PFPuppitau2->at(0)>0 &&
read. AK8PFPuppitau3->at(0)
){

return true;

}
else{
return false;

}
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(ProcessName=="TTToSemiLeptonPU140"){

return true;
}

if(ProcessName=="TTToSemiLeptonNoPU"){

return true;
}

if(ProcessName=="QCD200"){

return true;
}

if(ProcessName=="QCD20"){

return true;
}

if(ProcessName=="QCDdata"){

return true;
}

return false;
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::pTbin1(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::pTbin2(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::pTbin3(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::pTbin4(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

