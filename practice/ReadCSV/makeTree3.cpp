#include <fstream>
#include <TString.h>
#include <TFile.h>
#include <TTree.h>
void makeTree3(){
  std::ifstream fin;
  fin.open("particles.txt",std::ios::in);

  TFile *file = TFile::Open("tree.root", "RECREATE");
  TTree *tree = new TTree("tree", "tree");
  
  TString str;
  Int_t    ntrack;
  Double_t momentum;
  Double_t position;
  Int_t    charge;
  Int_t    count = 0;
  
  tree->Branch("ntrack",  &ntrack,  "ntrack/I");
  tree->Branch("momentum", &momentum, "momentum/D");
  tree->Branch("position", &position, "position/D");
  tree->Branch("charge",   &charge,   "charge/I");
  
  while(std::getline(fin,str,',')){
    if(count%4==0) ntrack = TString::Atoi(str);
    else if(count%4==1) momentum = TString::Atof(str);
    else if(count%4==2) position = TString::Atof(str);
    else{
      charge = TString::Atoi(str);
      tree->Fill();
    }
    count++;
  }

  tree->Write();
  file->Close();
  
}
