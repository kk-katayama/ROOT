/*
  plot_time.cc
  
  Toshiyuki Gogami, Dec 20, 2019
*/

#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TApplication.h>
#include <fstream>
#include <iostream>
using namespace std;


int main (int argc, char** argv){
  TApplication* app = new TApplication("app",&argc,argv);
 
  double delta = 0.0;
  
  char name[500];
  if (argc==1){
    sprintf(name,"test10");     // Name of ROOT file
  }
  else if (argc==2){
    sprintf(name,"%s",argv[1]); // Name of ROOT file
  }
  else{
    sprintf(name,"%s",argv[1]);// Name of ROOT file
    delta = atof(argv[2]);     // Time offset parameter
  }

  
  char filename[500];
  sprintf(filename,"./root/%s.root",name);
  
  TFile* f1 = new TFile(filename);
  TTree* t1 = (TTree*)f1->Get("tree");
  double adc1, adc2;
  double time1, time2;
  
  t1->SetBranchAddress("adc1", &adc1);
  t1->SetBranchAddress("adc2", &adc2);
  t1->SetBranchAddress("time1",&time1);
  t1->SetBranchAddress("time2",&time2);
  
  double ent = t1->GetEntries();
  
  TH1F* h1 = new TH1F("h1","",100,-20.0-delta,20.0-delta);
  h1->GetXaxis()->SetTitle("t (ns)");
  h1->GetYaxis()->SetTitle("Counts / ns");
  
  for(int i=0 ; i<ent ; i++){
    t1->GetEntry(i);
    if(adc1>100.0 && adc2>200.){
      double t = time2 - time1 - delta;
      h1->Fill(t);
      //cout << t << endl;
    }
  }
  
  TCanvas* c1 = new TCanvas("c1","c1");
  h1->Draw();
  app->Run();
  
}
