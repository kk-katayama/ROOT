void ped_adc2(){
  TH1F *hist = new TH1F("hist","adc2_trigS1",100,0,100);
  TFile *file = TFile::Open("data/test9.root","READ");
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
    hist->Fill(a2);
  }
  hist->Draw();
  hist->Fit("gaus");

  // can->SaveAs("ped_adc1.eps");

  
}
