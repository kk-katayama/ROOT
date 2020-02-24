#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
void Analysis(std::string filename)
{
  //  std::string filename = filenam;

  std::string rootfilename = filename + ".root";
  std::string textfilename = "../data/" + filename + ".dat";

  TFile *file = TFile::Open(rootfilename.c_str(),"RECREATE");
  TTree *tree = new TTree("tree","2 adc and 2 tdc");

  std::ifstream ifs(textfilename);
  std::string str;
  std::string separator = " ";
  
  int data[4];
  tree->Branch("adc1",&data[0],"adc1/I");
  tree->Branch("adc2",&data[1],"adc2/I");
  tree->Branch("tdc1",&data[2],"tdc1/I");
  tree->Branch("tdc2",&data[3],"tdc2/I");  
  
  while(getline(ifs,str)){
    int cnt = 0;
    std::string buf;    
    std::string::size_type offset = 0;
    std::string::size_type pos = str.find(separator,offset);
    while(pos!=std::string::npos){
      std::stringstream ss;
      buf=str.substr(offset,pos-offset);
      ss << buf;
      ss >> data[cnt++];
      offset = pos + 1;
      pos = str.find(separator,offset);
    }
    std::stringstream sss;    
    buf=str.substr(offset);
    sss << buf;
    sss >> data[cnt];
    tree->Fill();
  }

  tree->Write();
  file->Close();
  
}
