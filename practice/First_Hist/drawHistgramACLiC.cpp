#include <TH1.h>
#include <TFile.h>
void drawHistgramACLiC(){
  TH1F* myHist = new TH1F("myHist","My first histgram",10,0.,10.);
  TFile* file = new TFile("output.root","RECREATE");
  myHist->Fill(3.4);
  myHist->Fill(3.4);  

  myHist->SetFillStyle(3004);
  myHist->SetFillColor(2);

  file->cd();
  myHist->Write();
  file->Close();
  
}
