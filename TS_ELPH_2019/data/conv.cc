/*
  conv.cc
  
  Toshi Gogami, Oct 10, 2019
*/

void conv(int run = 11){
  char name[500];
  char name0[500];
  sprintf(name,"%s%d","test",run);
  char datname[500];
  char ROOTname[500];
  sprintf(datname,"%s.dat",name);
  sprintf(ROOTname,"%s.root",name);

  
  ifstream* ifs = new ifstream(datname);
  char tempc[500];
  int runid=run;
  int evid=0;
  double a1, a2;
  double t1, t2;
  
  TFile* fnew = new TFile(ROOTname,"recreate");
  TTree* tnew = new TTree("tree","test of TS used for AFT in Kyoto");
  tnew->Branch("runid", &runid, "runid/I");
  tnew->Branch("evid", &evid, "evid/I");
  tnew->Branch("a1", &a1, "a1/D");
  tnew->Branch("a2", &a2, "a2/D");
  tnew->Branch("t1", &t1, "t1/D");
  tnew->Branch("t2", &t2, "t2/D");

  *ifs >> tempc >> tempc >> tempc;
  //cout << tempc << endl;
  while( !ifs->eof() ){
    a1 = -2222.0;
    a2 = -2222.0;
    t1 = -2222.0;
    t2 = -2222.0;
    *ifs >> a1 >> a2 >> t1 >> t2;
    
    if(a1!=0 && a2!=0) {
      cout << a1 << " " << a2 << " " << t1 << " " << t2 << endl;
      tnew->Fill();
      evid++;
    }
    
  }
  tnew->Write();
  fnew->Close();

  cout << endl;
  cout << " " << datname << " --> " << ROOTname << endl;
  
}
