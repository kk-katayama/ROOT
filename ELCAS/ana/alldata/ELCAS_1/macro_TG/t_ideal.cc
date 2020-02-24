/*
  t_ideal.cc
  
  Toshiyuki Gogami, Dec 20, 2019
*/

// "prime.dat"
// 1.63547e+08 +/- 5.60571e+06 m/s 


const double vprime = 1.63547e+08;//  (m/s)

double get_t_ideal(double d){return d/vprime;}

void t_ideal(){
  const double d1 =  2.5e-2; // (m)
  const double d2 = 15.0e-2; // (m)
  const double d3 = 27.5e-2; // (m)
  
  cout << " Ideal values: " << endl;
  cout << " t1 (" << d1*100 << " cm) = " << get_t_ideal(d1)*1.0e+9 << " ns" << endl;
  cout << " t2 (" << d2*100 << " cm) = " << get_t_ideal(d2)*1.0e+9 << " ns" << endl;
  cout << " t3 (" << d3*100 << " cm) = " << get_t_ideal(d3)*1.0e+9 << " ns" << endl;
}
