#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
void Analysis()
{
  std::string textfilename = "data2.dat";

  std::ifstream ifs(textfilename);
  std::string str;

  TCanvas *can = new TCanvas("can","can",600,600);
  TH1 *frame = can->DrawFrame(0.,0.,360.,100.);

  std::vector<double> x,y;
  
  while(!ifs.eof()){
    double xx,yy,zz;
    ifs >> xx >> yy >> zz;
    x.push_back(xx);
    y.push_back(yy/zz);
    std::cout << yy/zz << "\n";
  }
  ifs.close();

  double *xpointer = &(x.at(0));
  double *ypointer = &(y.at(0));
  
  TGraph *gp = new TGraph(x.size(),xpointer,ypointer);
  
  gp->Draw();

}
