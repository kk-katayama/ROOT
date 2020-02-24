#include <string>
void DrawHist(std::string filename)
{
  TFile *file = TFile::Open(filename.c_str(),"READ");
  TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));
  TCanvas *can1 = new TCanvas("can1","can1",1500,1000);

  int adc1,adc2,tdc1,tdc2;

  tree->SetBranchAddress("adc1",&adc1);
  tree->SetBranchAddress("adc2",&adc2);
  tree->SetBranchAddress("tdc1",&tdc1);
  tree->SetBranchAddress("tdc2",&tdc2);

  TH1I *histadc1 = new TH1I("adc1","adc1",100,0,600);
  TH1I *histadc2 = new TH1I("adc2","adc2",100,0,600);
  TH1I *histtdc1 = new TH1I("tdc1","tdc1",100,0,600);
  TH1I *histtdc2 = new TH1I("tdc2","tdc2",100,0,600);  
  TH1I *histtof = new TH1I("tof","tof",100,-300,300);
  TH2I *histadctdc = new TH2I("adctdc","adc vs tdc",100,0,600,100,0,600);
  
  int nevents = tree->GetEntries();
  std::cout << nevents << std::endl;
  int adc1th = 110;
  int adc2th = 200;
  
  for(int i=0;i<nevents;++i){
    tree->GetEntry(i);
    if(adc1<=adc1th||adc2<=adc2th) continue;
    histadc1->Fill(adc1);
    histadc2->Fill(adc2);
    histtdc1->Fill(tdc1);
    histtdc2->Fill(tdc2);
    histtof->Fill(tdc1-tdc2);
    histadctdc->Fill(adc2,tdc2);
   }

  TLatex tl;
  tl.SetTextSize(0.1);
  
  can1->Divide(2,3);
  can1->cd(1);
  histadc1->Draw();
  can1->cd(2);
  histadc2->Draw();
  can1->cd(3);
  histtdc1->Draw();
  tl.DrawLatex(250.,10.,"#color[2]{5 ns}");
  can1->cd(4);
  histtdc2->Draw();
  can1->cd(5);
  histtof->Draw();
  histtof->Fit("gaus");
  can1->cd(6);
  histadctdc->Draw("colz");
}
