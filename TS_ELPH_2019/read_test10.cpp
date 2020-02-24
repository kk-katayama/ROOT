void read_test10(){
  TH1F *hist = new TH1F("hist","hist",4096,1400,1600);
  TH2F *hist2 = new TH2F("hist2","adc2 vs tdc2",100,0,400,100,1400,1600);  
  TFile *file = TFile::Open("data/test10.root","READ");
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
    hist->Fill(t2);
    hist2->Fill(a2,t2);
  }
  //  can->Divide(1,2);
  //  can->cd(1);
  // hist->Draw();
  // hist->Fit("gaus");
  //  can->cd(2);
  //  hist2->Draw("colz");

  TProfile *pf = hist2->ProfileX();
  //  pf->Draw();
  TF1 *func = new TF1("func","[0]+[1]/x+[2]/(x*x)+[3]/(x*x*x)+[4]/(x*x*x*x)",0,100);
  func->SetParameters(1,1,1,1,1);
  //  func->Draw();
  //  pf->Fit(func,"","",40,200);
  // can->SaveAs("ped_adc1.eps");

  TH2F *temp1 = new TH2F("temp1","temp1",100,0,400,100,0,1800);
  for(double i=0;i<400;++i){
    temp1->Fill(i,1539-25637/i+4782210/(i*i)-322360000/(i*i*i)+7424990000/(i*i*i*i));
  }
  //  can->cd(1);
  //  temp1->Draw();

  //  func->Draw();
  TH1F *hist3 = new TH1F("hist3","tdc2_cal",100,-200,200);
  TH2F *hist4 = new TH2F("hist4","adc2 vs tdc2",100,0,400,100,-100,100);  
  for(int i=0;i<nevents;++i){
    tree->GetEntry(i);
    hist3->Fill(t2-1539+25637/a2-4782210/(a2*a2)+322360000/(a2*a2*a2)-7424990000/(a2*a2*a2*a2));
    hist4->Fill(a2,t2-1539+25637/a2-4782210/(a2*a2)+322360000/(a2*a2*a2)-7424990000/(a2*a2*a2*a2));
  }
  //  can->cd(2);
  hist3->Draw();
  hist3->Fit("gaus");
  gStyle->SetOptFit();  
  //  can->cd(1);
  //  hist4->Draw("colz");
}
