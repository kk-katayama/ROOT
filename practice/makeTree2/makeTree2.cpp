#include <TTree.h>
#include <TFile.h>
void makeTree2(){
  Int_t    ntrack;
  Double_t momentum;
  Double_t position;
  Int_t    charge;
 
  TFile *file = TFile::Open("tree.root", "RECREATE");
  TTree *tree = new TTree("tree", "tree");
 
  TString input = "particles.txt";
  tree->ReadFile(input.Data(), "ntracks/I:momentum/D:position/D:charge/I");
 
  tree->Write();
  file->Close();
  
}
