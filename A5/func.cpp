#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
void func()
{
  TCanvas *can = new TCanvas("can","can",600,600);
  TH1 *frame = can->DrawFrame(0.,10.,160.,3.);
  can->SetLogy();
  
  TF1 *f = new TF1("f","TMath::Power(TMath::Sin(x/360.*TMath::Pi()),-4)+TMath::Power(TMath::Cos(x/360*TMath::Pi()),-4)+3./2.*TMath::Power(TMath::Sin(x/360.*TMath::Pi()),-2)*TMath::Power(TMath::Cos(x/360.*TMath::Pi()),-2)*TMath::Cos(20*TMath::Log(TMath::Power(TMath::Tan(x/360.*TMath::Pi()),2)))",10.,160.);

  f->Draw();
}
