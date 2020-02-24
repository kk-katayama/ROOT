/*
  mkroot.cc
  DATA file --> ROOT file
  
  Toshiyuki Gogami, December 20, 2019
*/

#include <TFile.h>
#include <TTree.h>
#include <fstream>
#include <iostream>
using namespace std;

//const double ch2time = 0.0568; // ch --> ns
const double ch2time = 0.0560; // ch --> ns
const double offset1 = 0;
const double offset2 = 0;

int main(int argc, char** argv){
  char name[500];
  char fname[500];
  char ofname[500];
  
  if(argc==1){
    sprintf(name,"test10");
  }
  else if(argc==2){
    sprintf(name,"%s",argv[1]);
  }
  
  
  sprintf(fname,"./data/%s.dat",name);
  sprintf(ofname,"./root/%s.root",name);
  ifstream* ifs = new ifstream(fname);
  if (!ifs) return 99;
  
  double a1, a2;
  double t1, t2;
  
  TFile* fnew = new TFile(ofname,"recreate");
  TTree* tnew = new TTree("tree","Data for ELCAS 2019");
  tnew->Branch("adc1",&a1,"adc1/D");
  tnew->Branch("adc2",&a2,"adc2/D");
   tnew->Branch("time1",&t1,"time1/D");
  tnew->Branch("time2",&t2,"time2/D");
  
  while (!ifs->eof()){
    *ifs >> a1 >> a2 >> t1 >> t2;
    
    t1 = t1 * ch2time - offset1;
    t2 = t2 * ch2time - offset2;
    
    if(a1!=0 
       && a2!=0
       && fabs(t1)<5000.0
       && fabs(t2)<5000.0
       ){
      tnew->Fill();
      cout << " " << a1 << " " << a2 << " " << t1 << " " << t2 << endl;
    }
    
  }
  tnew->Write();
  fnew->Close();
  
  
  return 0;
}
