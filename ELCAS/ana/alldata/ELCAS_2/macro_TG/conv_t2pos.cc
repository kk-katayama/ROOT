/*
  conv_t2pos.cc
  
  Toshiyuki Gogami, Dec 20, 2019
*/

#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TLine.h>
#include <TApplication.h>
#include <fstream>
#include <iostream>
using namespace std;

extern double GetPos(double t, double vp);

const double c  = 3.0e+8; // (m/s)
const double l  = 0.3;    // (m)
const double L  = 0.20;    // (m)
const double allow = 0.02;// (m)

int main(int argc, char** argv){
  gStyle->SetOptStat(0);
  
  TApplication* app = new TApplication("app",&argc,argv);
  
  
  double time_offset = L/c * 1.0e+9; // ns (L'/c correction is the correct one)
  //double time_offset = 0.0; // ns
  double vp     = 1.63547e+08; // m/s
  double delta  = -4.03;       // ns
  char name[500];
    
  if(argc==1){
    sprintf(name,"t4");
  }
  else if (argc==2){
    sprintf(name,"%s",argv[1]);
  }
  else if (argc==3){
    sprintf(name,"%s",argv[1]);
    delta = atof(argv[2]);
  }
  else if (argc==4){
    sprintf(name,"%s",argv[1]);
    delta = atof(argv[2]);
    vp = atof(argv[3]);
  }
  else{
    cout << " Type ./pos (file_name) (delta) (vp) " << endl;
    return 80;
  }
  
  char filename[500];
  sprintf(filename,"./root/%s.root",name);
  TFile* f1 = new TFile(filename);
  TTree* t1 = (TTree*)f1->Get("tree");
  double time1, time2;
  double adc1, adc2;
  t1->SetBranchAddress("adc1",&adc1);
  t1->SetBranchAddress("adc2",&adc2);
  t1->SetBranchAddress("time1",&time1);
  t1->SetBranchAddress("time2",&time2);
  
  double ent = t1->GetEntries();
  
  TH1F* h1 = new TH1F("h1","",100,-10,10.0);
  h1->GetXaxis()->SetTitle("t (ns)");
  h1->GetYaxis()->SetTitle("Counts");
  TH1F* h1_ = (TH1F*)h1->Clone("h1_");
  h1_->SetFillStyle(3001);
  h1_->SetFillColor(9);
  
  TH1F* h2 = new TH1F("h2","",100,-20,20.0);
  h2->GetXaxis()->SetTitle("x (cm)");
  h2->GetYaxis()->SetTitle("Counts");
  h2->SetFillStyle(3001);
  h2->SetFillColor(9);
  
  
  
  for(int i=0 ; i<ent ; i++ ){
    t1->GetEntry(i);
    
    if(adc1>100.0 && adc2>100.0){
      
      double t = time2 - time1 - delta + time_offset;
      h1->Fill(t);
      
      double pos = GetPos(t, vp);
      pos = pos * 100; // m --> cm
      
      if(-25.0<pos && pos < 25.0){
	//cout << time_offset << " " << t << " " << pos << endl;
	cout << " " << t << " ns --> " << pos << " cm" << endl;
	h1_->Fill(t);
	h2->Fill(pos);
      }
    
    }
  }
  
  TCanvas* c1 = new TCanvas("c1","c1");
  c1->Divide(1,2);
  h1->GetXaxis()->SetRangeUser(-4.0,8.0);
  c1->cd(1);h1->Draw();h1_->Draw("same");
  c1->cd(2);h2->Draw();
  
  c1->cd(1);
  double t0  = 1./c * sqrt(pow(L,2.0) + pow(-l/2.0,2.0) );
  double t00 = t0 + l/vp;
  t0  = t0  * 1.0e+9;
  t00 = t00 * 1.0e+9;
  double hmax = h1->GetMaximum();
  TLine* l1 = new TLine(t0,0,t0,hmax*1.05);
  l1->SetLineColor(2);
  l1->SetLineWidth(2.0);
  l1->SetLineStyle(7);
  l1->Draw();
  
  TLine* l2 = new TLine(t00,0,t00,hmax*1.05);
  l2->SetLineColor(2);
  l2->SetLineWidth(2.0);
  l2->SetLineStyle(7);
  l2->Draw();
  
  
  app->Run();
  return 0;
}


double GetPos(double t, double vp){
  t = t * 1.0e-9;
  double A = 4.0 * (pow(vp/c,2.0) - 1.0);
  double B = 4.0 * (2.0*vp*t - l);
  double C1 = 4.0 * pow(vp,2.0) * ( pow(L/c,2.0) - pow(t,2.0) );
  double C2 = l * (4.0*vp*t - l);
  double C = C1 + C2;
  
  double pos1=-222.0, pos2=-222.0;
  if(pow(B,2.0)-4.0*A*C>0){
    pos1 = (-B + sqrt(pow(B,2.0)-4.0*A*C)) / (2.0*A);
    pos2 = (-B - sqrt(pow(B,2.0)-4.0*A*C)) / (2.0*A);
  }
  
  double min = -l/2.0 - allow;
  double max =  l/2.0 + allow;
  
  bool flag1 = false;
  bool flag2 = false;

  if(min<pos1 && pos1<max){
    flag1 = true;
  }
  else {
    flag1=false;
    pos1 = -200.;
  }
  
  if(min<pos2 && pos2<max){
    flag2 = true;
  }
  else {
    flag2=false;
    pos2 = -300;
  }

  double pospos = pos1;
  //if(flag1==false && flag2==true) pospos = pos2;
  //else if (flag2==true && flag1!=false) pospos = pos2;
  //else if (flag2==true && flag1==true){
  //  cout << " Warning: double condidates!!! " << pos1 << " " << pos2 << endl;
  //  pospos = pos1;
  //}
  //else pospos = -2222.0;
  
  return pospos;
}
