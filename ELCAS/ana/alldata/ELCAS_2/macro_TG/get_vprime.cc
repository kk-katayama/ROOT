/*
  get_vprime.cc
  
  Toshiyuki Gogami, Dec 20, 2019
*/

double d = 0.25; // (m); distance between two setup

const double c = 3.0e+8;

void get_vprime(){
  ifstream* ifs = new ifstream("vprime.dat");
  char tempc[500];
  double t1, t2;
  double t1_er, t2_er;
  
  *ifs >> tempc >> t1 >> t1_er;
  *ifs >> tempc >> t2 >> t2_er;
  
  double tdiff, tdiff_er;
  double vprime, vprime_er;
  tdiff = (t2 - t1) * 1.0e-9;
  tdiff_er = sqrt(pow(t1_er,2.0) + pow(t2_er,2.0)) + 1.0e-9;
  
  vprime = d/tdiff;
  vprime_er = tdiff_er/tdiff * d;
  
  cout << " " << vprime << " +/- " << vprime_er << " m/s "<< endl;
  cout << " (" << vprime/c << " +/- " << vprime_er/c << " c)" << endl;
  
}
