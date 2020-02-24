void test(){
   TCanvas c1("c1");
   TObject *obj;
   for (Int_t i=0;i<10;i++) {
      obj = gPad->WaitPrimitive();
      if (!obj) break;
      printf("Loop i=%d, found objIsA=%s, name=%s\n",
         i,obj->ClassName(),obj->GetName());
   }
}
