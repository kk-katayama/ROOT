void comphist()
{
  TFile *file1 = TFile::Open("test10.root","READ");
  TFile *file2 = TFile::Open("test12.root","READ");
  TFile *file3 = TFile::Open("test11.root","READ");
  
  TTree *tree1 = dynamic_cast<TTree*>(file1->Get("tree"));
  TTree *tree2 = dynamic_cast<TTree*>(file2->Get("tree"));
  TTree *tree3 = dynamic_cast<TTree*>(file3->Get("tree"));
  
  TCanvas *can1 = new TCanvas("can1","can1",800,1000);

  int adc1,adc2,tdc1,tdc2;

  tree1->SetBranchAddress("adc1",&adc1);
  tree1->SetBranchAddress("adc2",&adc2);
  tree1->SetBranchAddress("tdc1",&tdc1);
  tree1->SetBranchAddress("tdc2",&tdc2);

  tree2->SetBranchAddress("adc1",&adc1);
  tree2->SetBranchAddress("adc2",&adc2);
  tree2->SetBranchAddress("tdc1",&tdc1);
  tree2->SetBranchAddress("tdc2",&tdc2);

  tree3->SetBranchAddress("adc1",&adc1);
  tree3->SetBranchAddress("adc2",&adc2);
  tree3->SetBranchAddress("tdc1",&tdc1);
  tree3->SetBranchAddress("tdc2",&tdc2);  

  TH1I *nearadc1 = new TH1I("nearadc1","nearadc1",100,0,600);
  TH1I *nearadc2 = new TH1I("nearadc2","nearadc2",100,0,600);
  TH1I *centeradc1 = new TH1I("centeradc1","centeradc1",100,0,600);
  TH1I *centeradc2 = new TH1I("centeradc2","centeradc2",100,0,600);
  TH1I *faradc1 = new TH1I("faradc1","faradc1",100,0,600);
  TH1I *faradc2 = new TH1I("faradc2","faradc2",100,0,600);  

  TH1I *histtdc1 = new TH1I("tdc1","tdc1",100,0,600);
  TH1I *histtdc2 = new TH1I("tdc2","tdc2",100,0,600);  
  TH2I *histadctdc = new TH2I("adctdc","adc vs tdc",100,0,600,100,0,600);

  TH1I *histtof1 = new TH1I("tof1","near",20,0,120);
  TH1I *histtof2 = new TH1I("tof2","center",20,0,120);
  TH1I *histtof3 = new TH1I("tof3","far",20,0,120);  
  
  int nevents = tree1->GetEntries();
  std::cout << nevents << std::endl;
  int adc1th = 110;
  int adc2th = 190;
  
  for(int i=0;i<nevents;++i){
    tree1->GetEntry(i);
    if(adc1<=adc1th||adc2<=adc2th) continue;
    nearadc1->Fill(adc1);
    nearadc2->Fill(adc2);
    histtof1->Fill(tdc1-tdc2);
  }

  nevents = tree2->GetEntries();
  std::cout << nevents << std::endl;
  adc1th = 110;
  adc2th = 190;
  
  for(int i=0;i<nevents;++i){
    tree2->GetEntry(i);
    if(adc1<=adc1th||adc2<=adc2th) continue;
    centeradc1->Fill(adc1);
    centeradc2->Fill(adc2);
    histtof2->Fill(tdc1-tdc2);
   }

  nevents = tree3->GetEntries();
  std::cout << nevents << std::endl;
  adc1th = 110;
  adc2th = 190;
  
  for(int i=0;i<nevents;++i){
    tree3->GetEntry(i);
    if(adc1<=adc1th||adc2<=adc2th) continue;
    faradc1->Fill(adc1);
    faradc2->Fill(adc2);
    histtof3->Fill(tdc1-tdc2);
  }


  // TLatex tl;
  // tl.SetTextSize(0.1);
  
  // can1->Divide(1,3);
  // can1->cd(1);
  // histtof1->Draw();
  // histtof1->Fit("gaus");
  // tl.DrawLatex(10.,90.,"#color[1]{(small scinti) - (long scinti)}");
  // tl.DrawLatex(10.,50.,"#color[1]{near}");      
  // tl.DrawLatex(80.,90.,"#color[2]{68.2 ch ~ 3.41 ns}");  
  // can1->cd(2);
  // histtof2->Draw();
  // histtof2->Fit("gaus");
  // tl.DrawLatex(10.,50.,"#color[1]{center}");        
  // tl.DrawLatex(80.,90.,"#color[2]{55.9 ch ~ 2.80 ns}");    
  // can1->cd(3);
  // histtof3->Draw();
  // histtof3->Fit("gaus");
  // tl.DrawLatex(10.,50.,"#color[1]{far}");          
  // tl.DrawLatex(80.,150.,"#color[2]{41.6 ch ~ 2.08 ns}");      

  gStyle->SetOptFit(01111);
  can1->Divide(2,3);
  can1->cd(1);
  nearadc1->Draw();
  can1->cd(2);
  nearadc2->Draw();
  nearadc2->Fit("landau");  
  can1->cd(3);
  centeradc1->Draw();
  can1->cd(4);
  centeradc2->Draw();
  centeradc2->Fit("landau");  
  can1->cd(5);
  faradc1->Draw();
  can1->cd(6);
  faradc2->Draw();
  faradc2->Fit("landau");    
}
