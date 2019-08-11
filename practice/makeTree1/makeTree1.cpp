#include <TFile.h>
#include <TTree.h>
void makeTree1(){
  const Int_t nentries = 5;
  Int_t    a_ntrack[nentries]  = {0, 1, 2, 3, 4}; 
  Double_t a_momentum[nentries] = {3200.4, 2893.2, 3603.9, 9899.1, 5674.3};
  Double_t a_position[nentries] = {7643, 9834, 11232, 10232, 8092};        
  Int_t    a_charge[nentries]   = {-1, 1, 1, -1, 1};                       
 

  TFile *file = TFile::Open("tree.root", "RECREATE");
  TTree *tree = new TTree("tree", "tree");
 

  Int_t    ntrack;
  Double_t momentum;
  Double_t position;
  Int_t    charge;
 

  tree->Branch("ntrack",  &ntrack,  "ntrack/I");
  tree->Branch("momentum", &momentum, "momentum/D");
  tree->Branch("position", &position, "position/D");
  tree->Branch("charge",   &charge,   "charge/I");
 

  for (Int_t ii = 0; ii < nentries; ii++) {
    ntrack  = a_ntrack[ii];
    momentum = a_momentum[ii];
    position = a_position[ii];
    charge   = a_charge[ii];
    tree->Fill();
  }
 

  tree->Write();
  file->Close();

}
