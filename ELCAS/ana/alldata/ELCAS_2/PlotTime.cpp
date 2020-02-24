#include <string>
void PlotTime(std::string filename,int delta=0)
{
  filename = "root/" + filename;
  TFile *file = TFile::Open(filename.c_str(),"READ");
  TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));
  TCanvas *can1 = new TCanvas("can1","can1",800,800);

  int a1,a2,t1,t2;

  tree->SetBranchAddress("a1",&a1);
  tree->SetBranchAddress("a2",&a2);
  tree->SetBranchAddress("t1",&t1);
  tree->SetBranchAddress("t2",&t2);

  TH1I *hista1 = new TH1I("a1","a1",100,0,600);
  TH1I *hista2 = new TH1I("a2","a2",100,0,600);
  TH1I *histt1 = new TH1I("t1","t1",100,0,600);
  TH1I *histt2 = new TH1I("t2","t2",100,0,600);  
  TH1I *histtof = new TH1I("Time","Time",100,-300,300);
  TH2I *histadctdc = new TH2I("adctdc","adc vs tdc",100,0,600,100,0,600);
  
  int nevents = tree->GetEntries();
  std::cout << nevents << std::endl;
  int a1th = 110;
  int a2th = 200;
  
  for(int i=0;i<nevents;++i){
    tree->GetEntry(i);
    if(a1<=a1th||a2<=a2th) continue;
    hista1->Fill(a1);
    hista2->Fill(a2);
    histt1->Fill(t1);
    histt2->Fill(t2);
    histtof->Fill(t2-t1-delta);
    histadctdc->Fill(a2,t2);
   }

  TLatex tl;
  tl.SetTextSize(0.1) ;

  //  gStyle->SetFitOpt(0111);
  histtof->Draw();
  // can1->Divide(2,3);
  // can1->cd(1);
  // hista1->Draw();
  // can1->cd(2);
  // hista2->Draw();
  // can1->cd(3);
  // histt1->Draw();
  // tl.DrawLatex(250.,10.,"#color[2]{5 ns}");
  // can1->cd(4);
  // histt2->Draw();
  // can1->cd(5);
  // histtof->Draw();
  // histtof->Fit("gaus");
  // can1->cd(6);
  // histadctdc->Draw("colz");
}
