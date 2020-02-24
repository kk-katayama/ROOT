/*
  get_delta.cc
  
  Toshiyuki Gogami, Dec 20, 2019
*/


void get_delta(){
  ifstream* ifs = new ifstream("vprime.dat");
  char tempc[500];
  double t1, t2, t3;
  double t1_er, t2_er, t3_er;
  
  *ifs >> tempc >> t1 >> t1_er;
  *ifs >> tempc >> t2 >> t2_er;
  *ifs >> tempc >> t3 >> t3_er;
  cout << t1 << " " << t2 << " " << t3 << endl;
  
  double t1_ref, t2_ref, t3_ref;
  *ifs >> tempc >> t1_ref >> tempc;
  *ifs >> tempc >> t2_ref >> tempc;
  *ifs >> tempc >> t3_ref >> tempc;
  
  cout << t1_ref << endl;
  cout << t2_ref << endl;
  cout << t3_ref << endl;
  
  const int n = 3;
  double x[n], x_er[n];
  double y[n], y_er[n];
  
  y[0]    = t1-t1_ref;
  y_er[0] = t1_er;
  
  y[1]    = t2-t2_ref;
  y_er[1] = t2_er;
  
  y[2]    = t3-t3_ref;
  y_er[2] = t3_er;
  
  for(int i=0 ; i<n ; i++){
    x[i] = i+1;
    x_er[i] = 0.0;
    
    cout << " " << i << ": " << y[i] << " " << y_er [i] << endl;
  }
  cout << endl;

  TGraphErrors* gr1 = new TGraphErrors(n,x,y,x_er,y_er);
  gr1->SetName("gr1");
  
  TH2F* hemp = new TH2F("hemp","",100,0.0,5.0,100,-10.0,0.0);
  hemp->GetYaxis()->SetTitle("#Delta (ns)");
  TCanvas*c1 = new TCanvas("c1","c1");
  hemp->Draw();
  gr1->Draw("*same");
  
  TF1* func1 = new TF1("func1","[0]",0.0,5.0);
  func1->SetParameter(0,-4.0);
  gr1->Fit("func1","","",0.0,5.0);
  

  double delta_bar    = func1->GetParameter(0);
  double delta_bar_er = func1->GetParError(0);
  
  cout << endl;
  cout << " Delta bar = " << delta_bar << "+/-" << delta_bar_er << endl;
  cout << t1-delta_bar << endl;
  cout << t2-delta_bar << endl;
  cout << t3-delta_bar << endl;

  


  
}
