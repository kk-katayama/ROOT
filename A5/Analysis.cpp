#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
void Analysis()
{
  std::string textfilename = "data.dat";

  std::ifstream ifs(textfilename);
  std::string str;

  TCanvas *can = new TCanvas("can","can",600,600);
  TH1 *frame = can->DrawFrame(0.,0.,4.,100.);

  std::vector<double> x,y;
  
  while(!ifs.eof()){
    double xx,yy;
    ifs >> xx >> yy;
    x.push_back(xx);
    y.push_back(yy);
  }
  ifs.close();

  double *xpointer = &(x.at(0));
  double *ypointer = &(y.at(0));
  
  TGraph *gp = new TGraph(x.size(),xpointer,ypointer);

  TF1 *f = new TF1("f","TMath::sqrt(([0]-[0]*TMath::Cos(x)+([1]+66)*TMath::Sin(x))*([0]-[0]*TMath::Cos(x)+([1]+66)*TMath::Sin(x))+([1]-[0]*TMath::Sin(x)+([1]+66)*TMath::Cos(x))*([1]-[0]*TMath::Sin(x)+([1]+66)*TMath::Cos(x))",0.,4.);
  
  
  gp->Draw();

}
