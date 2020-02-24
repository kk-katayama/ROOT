#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
void Analysis(std::string filename)
{
  //  std::string filename = filenam;

  std::string rootfilename = "root/" + filename + ".root";
  std::string textfilename = "data/" + filename + ".dat";

  TFile *file = TFile::Open(rootfilename.c_str(),"RECREATE");
  TTree *tree = new TTree("tree","2 adc and 2 tdc");

  std::ifstream ifs(textfilename);
  std::string str;
  std::string separator = " ";
  
  int data[4];
  tree->Branch("a1",&data[0],"a1/I");
  tree->Branch("a2",&data[1],"a2/I");
  tree->Branch("t1",&data[2],"t1/I");
  tree->Branch("t2",&data[3],"t2/I");  
  
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
