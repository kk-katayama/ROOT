void drawHistgram(){
  TH1F* myHist = new TH1F("myHist","My first histgram",10,0.,10.);
  myHist->Fill(3.4);
  myHist->Fill(3.4);  

  myHist->SetFillStyle(3004);
  myHist->SetFillColor(2);
  myHist->Draw();
}
