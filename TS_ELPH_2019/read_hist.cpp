void read_hist(){
  TH1F *hist = new TH1F("hist","hist",4096,0,1024);
  TH2F *hist2 = new TH2F("hist2","hist",100,0,400,100,1400,1600);  
  TFile *file = TFile::Open("data/test.root","READ");
  TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));
  TCanvas *can = new TCanvas("can","can");

  
  double a1;
  double a2;
  double t1;
  double t2;

  tree->SetBranchAddress("a1",&a1);
  tree->SetBranchAddress("a2",&a2);  
  tree->SetBranchAddress("t1",&t1);
  tree->SetBranchAddress("t2",&t2);    

  int nevents = tree->GetEntries();

  std::cout << nevents << "\n";
  for(int i=0;i<nevents;++i){
    tree->GetEntry(i);
    //    hist->Fill(a1);
    hist2->Fill(a2-70,t2);
  }
  //  hist->Draw();
  hist2->Draw("colz");
  //  hist->Fit("gaus");

  // can->SaveAs("ped_adc1.eps");

  
}
