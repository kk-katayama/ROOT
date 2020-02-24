void read_test11_tof(){
  TH1F *hist = new TH1F("hist","adc2@test11",100,1300,1800);
  TH2F *hist2 = new TH2F("hist2","adc2 vs tof",100,0,500,100,0,500);
  TH2F *hist5 = new TH2F("hist5","adc2 vs tof",100,0,500,100,0,500);    
  TFile *file = TFile::Open("data/test11.root","READ");
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
    if(a1<85) continue;
    // if(a1-a2<-30||a1-a2>60) continue;
    hist->Fill(t2);
    hist2->Fill(a1,a2);
    hist5->Fill(a2,t1-t2);
  }
  //  can->Divide(1,2);
  //  can->cd(1);
  // hist->Draw();
  // hist->Fit("gaus");
  // gStyle->SetOptFit();    
  //  can->cd(2);
  // hist2->Draw("colz");
  hist5->Draw("colz");
  

  TProfile *pf = hist5->ProfileX();
  // pf->Draw();
  TF1 *func = new TF1("func","[0]+[1]/x+[2]/(x*x)",60,300);
  // TF1 *func = new TF1("func","[0]+[1]/x",0,100);
  func->SetParameters(1,1,1);
  //  func->Draw();
  // pf->Fit(func,"","",60,300);
  // hist5->Draw("colz");
  // func->Draw("same");
  TH1F *hist3 = new TH1F("hist3","tof_cal_adc2",100,-200,200);
  TH2F *hist4 = new TH2F("hist4","adc1 vs tof(cal_adc2)",100,0,500,100,-250,250);  
  for(int i=0;i<nevents;++i){
    tree->GetEntry(i);
    if(a1<85) continue;
    hist3->Fill(t1-t2-308.7-493.351/a2+305230/(a2*a2));
    hist4->Fill(a1,t1-t2-308.7-493.351/a2+305230/(a2*a2));
  }

  // hist3->Draw();
  // hist3->Fit("gaus");
  // gStyle->SetOptFit();  
  // //  can->cd(1);
  // hist4->Draw("colz");

  TProfile *pf2 = hist4->ProfileX();
  //  pf->Draw();
  //    TF1 *func = new TF1("func","[0]+[1]/x+[2]/(x*x)+[3]/(x*x*x)+[4]/(x*x*x*x)",0,100);
  TF1 *func2 = new TF1("func2","[0]+[1]/x+[2]/(x*x)",80,300);  
  func2->SetParameters(1,1,1,1);
  //  func2->Draw();
  pf2->Fit(func2,"","",80,300);
  
  // hist4->Draw("colz");
  // func2->Draw("same");
  
  TH1F *hist6 = new TH1F("hist6","tof_cal_adc1_adc2",100,-200,200);
  TH2F *hist7 = new TH2F("hist7","adc2 vs tof(cal_adc1_adc2)",100,0,500,100,-250,250);  
  for(int i=0;i<nevents;++i){
    tree->GetEntry(i);
    if(a1<85) continue;
    hist6->Fill(t1-t2-308.7-493.351/a2+305230/(a2*a2)+32.6497-3276.51/a1-71677.6/(a1*a1));
    hist7->Fill(a2,t1-t2-308.7-493.351/a2+305230/(a2*a2)+32.6497-3276.51/a1-71677.6/(a1*a1));
  }

  
  // TFile *file10 = TFile::Open("data/test10.root","READ");
  // TTree *tree10 = dynamic_cast<TTree*>(file->Get("tree"));

  // int nevents10 = tree10->GetEntries();

  // for(int i=0;i<nevents;++i){
  //   tree->GetEntry(i);
  //   if(a1<85||a2<85) continue;
  
  //   hist3->Fill(1800-t1+t2-1539+25637/a2-4782210/(a2*a2)+322360000/(a2*a2*a2)-7424990000/(a2*a2*a2*a2)-31.1021+1866.27/(a1)+152370/(a1*a1));
  //   hist4->Fill(a1,1800-t1+t2-1539+25637/a2-4782210/(a2*a2)+322360000/(a2*a2*a2)-7424990000/(a2*a2*a2*a2)-31.1021+1866.27/(a1)+152370/(a1*a1));

  // }


  

  // hist6->Draw();
  // hist6->Fit("gaus");
  // gStyle->SetOptFit();  
  // hist7->Draw("colz");




   

}
