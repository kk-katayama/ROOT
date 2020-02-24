void func_add(){
  TF1 *fcos = new TF1 ("fcos", "[0]*cos(x)", 0., 10.);
  //  fcos->SetParNames( "cos");
  fcos->SetParameter( 0, 1.1);

  TF1 *fsin = new TF1 ("fsin", "[0]*x", 0., 10.);
  //  fsin->SetParNames( "sin");
  fsin->SetParameter( 0, -1);
  TF1 *fsincos = new TF1 ("fsc", "fcos+fsin", 0., 10.);

  fsincos->Draw();

  TF1 *fs2 = new TF1 ("fs2", "fsc+fsc");
}
