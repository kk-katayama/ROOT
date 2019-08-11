#include <TH1.h>
#include<TRandom3.h>
void RandomGaus(){
  TH1F* hist = new TH1F("hist gaus","gaus mean=0 sigma=1",100,-3.,3.);
  TRandom3 rndm(0);
  Int_t N = 1000000;
  for(int i=0;i<N;++i){
    Float_t rndm_x = rndm.Gaus(0,1);
    hist->Fill(rndm_x);
    
  }
  hist->Draw();
}
