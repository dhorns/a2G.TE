void GetTaggEff(TString sBeam, TString sBkg1="", TString sBkg2="", Bool_t bFreeScal=true){
  gStyle->SetTitleOffset(1.2,"x");
  gStyle->SetTitleOffset(1.2,"y");

  TFile fBeam(sBeam,"READ");
  if(sBkg1 != "") TFile fBkg1(sBkg1,"READ");  
  if(sBkg2 != "") TFile fBkg2(sBkg2,"READ");
  gROOT->cd();
  gStyle->SetOptStat(0);

  TCanvas *c1 = new TCanvas("c1","c1",800,300);

  TH1D *hBeamHits = (TH1D*)fBeam.Get("TaggerAllHits");
  TH1D *hBeamScal = (TH1D*)fBeam.Get("ScalerAllHits");
  TH1D *hBeamLive = (TH1D*)fBeam.Get("LiveTimeScal");

  Double_t dBeamClock = hBeamLive->GetBinContent(hBeamLive->GetXaxis()->FindBin("Clock"));
  Double_t dBeamInhib = hBeamLive->GetBinContent(hBeamLive->GetXaxis()->FindBin("Inhibited"));

  Double_t dBackClock = 0;
  Double_t dBackInhib = 0;

  TH1D *hBackScal = new TH1D("hBackScal","Tagger Scalers",hBeamScal->GetNbinsX(),0,hBeamScal->GetNbinsX());
  
  if(sBkg1 != ""){
    TH1D *hBkg1Scal = (TH1D*)fBkg1.Get("ScalerAllHits");
    TH1D *hBkg1Live = (TH1D*)fBkg1.Get("LiveTimeScal");

    hBackScal->Add(hBkg1Scal);
    
    dBackClock = hBkg1Live->GetBinContent(hBkg1Live->GetXaxis()->FindBin("Clock"));
    dBackInhib = hBkg1Live->GetBinContent(hBkg1Live->GetXaxis()->FindBin("Inhibited"));
  }
  if(sBkg2 != ""){
    TH1D *hBkg2Scal = (TH1D*)fBkg2.Get("ScalerAllHits");
    TH1D *hBkg2Live = (TH1D*)fBkg2.Get("LiveTimeScal");
    
    hBackScal->Add(hBkg2Scal);
    
    dBackClock += hBkg2Live->GetBinContent(hBkg2Live->GetXaxis()->FindBin("Clock"));
    dBackInhib += hBkg2Live->GetBinContent(hBkg2Live->GetXaxis()->FindBin("Inhibited"));
  }

  TString sOut = sBeam;
  sOut.ReplaceAll(".root","_BkgSub.root");

  TFile fOut(sOut,"RECREATE");

  TH1D *hEffHits = (TH1D*)hBeamHits->Clone("TaggEffHits");
  TH1D *hEffScal = (TH1D*)hBeamScal->Clone("TaggEffScal");

  hEffScal->Sumw2();

  if(bFreeScal){
    if(dBackClock) hEffScal->Add(hBackScal,(-dBeamClock/dBackClock));
    hEffScal->Scale(dBeamInhib/dBeamClock);
  }
  else{
    if(dBackInhib) hEffScal->Add(hBackScal,(-dBeamInhib/dBackInhib));
  }

  hEffHits->Divide(hEffScal);

  Double_t dAvg, dPeak, dMin, dMax;
  printf("\n");

  TH1D *hProHits = new TH1D("ProHitsPro","Tagging Efficiency - All Channels;Tagging Efficiency",5000,0,1);
  TF1 fProHits("fProHits","gaus",0,352);
  TF1 fAvgHits("fAvgHits","pol0",0,352);

  for(Int_t i=0; i<hEffHits->GetNbinsX(); i++){
    if((hEffHits->GetBinContent(i+1) > 0) && (hEffHits->GetBinContent(i+1) < 1)) hProHits->Fill(hEffHits->GetBinContent(i+1));
  }
  while(hProHits->GetBinContent(hProHits->GetMaximumBin()) < 16) hProHits->Rebin(2);
  dAvg = dPeak = hProHits->GetBinCenter(hProHits->GetMaximumBin());
  hProHits->Fit("fProHits","Q0","",(0.95*dAvg),(1.05*dAvg));
  dAvg = fProHits.GetParameter(1);
  fAvgHits.SetParameter(0,dAvg);

  dMin = (dAvg-5*(fProHits.GetParameter(2)));
  dMax = (dAvg+5*(fProHits.GetParameter(2)));
  hProHits->GetXaxis()->SetRangeUser(dMin,dMax);
  
  dMax = 0.015*TMath::Nint(100*dAvg);
  hEffHits->GetYaxis()->SetRangeUser(0,dMax);

  hEffHits->SetTitle("Tagging Efficiency - Each Channel;Tagger Channel;Tagging Efficiency");

  fProHits.SetLineColor(2);
  fAvgHits.SetLineColor(2);

  gROOT->cd();
  c1->Divide(2);
  c1->cd(1);
  hProHits->DrawClone();
  fProHits.DrawClone("same");
  c1->cd(2);
  hEffHits->DrawClone();
  fAvgHits.DrawClone("same");

  sOut.ReplaceAll("GoAT_","");
  sOut.ReplaceAll("_BkgSub.root",".pdf");
  c1->SaveAs(sOut);
  sOut.ReplaceAll("pdf","png");
  c1->SaveAs(sOut);

  if(dBackClock) printf("\nBackground subtracted\n");
  else printf("\nBackground NOT subtracted\n");
  printf("Peak Efficiency = %.2f \%\tFit Efficiency = %.2f \%\n",100*dPeak,100*fAvgHits.GetParameter(0));

  fOut.Write();
  fOut.Close();
}
