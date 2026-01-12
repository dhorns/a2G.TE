void TE(TString sBeam, TString sBkg1, TString sBkg2)
{
	// Open the 3 files
	TFile fBeam( sBeam, "READ");
	TFile fBkg1( sBkg1, "READ");
	TFile fBkg2( sBkg2, "READ");
	
	//Histo for Beam
	TH1D *hBeamAllHits = (TH1D*)fBeam.Get( "TaggerAllHits");
	TH1D *hBeamSingles = (TH1D*)fBeam.Get( "TaggerSingles");
	TH1D *hBeamDoubles = (TH1D*)fBeam.Get( "TaggerDoubles");
	TH1D *hBeamLiveTime = (TH1D*)fBeam.Get( "LiveTimeScal");
	TH2D *hBeamTaggScalers = (TH2D*) fBeam.Get( "TaggerScalers");
	Double_t dBeamClock = hBeamLiveTime->GetBinContent(hBeamLiveTime->GetXaxis()->FindBin( "Clock"));
	Double_t dBeamInhib = hBeamLiveTime->GetBinContent(hBeamLiveTime->GetXaxis()->FindBin( "Inhibited"));

	// setupParameters tree is needed to get the TimeStamp
	TTree *tBeamParameters = (TTree*)fBeam.Get("setupParameters");
	Int_t iBeamTimeStamp;
	tBeamParameters -> SetBranchAddress( "TimeStamp", &iBeamTimeStamp);
	tBeamParameters -> GetEntry( 0);

	// Scalers tree is needed to get the n of clock per scaler read (as well as the n of scaler reads)
	TTree *tBeamScaler = (TTree*)fBeam.Get( "scalers");
	UInt_t iBeamScalers[8706];
	tBeamScaler -> SetBranchAddress( "scalers", iBeamScalers);
	Int_t iBeamnScalerReads = tBeamScaler -> GetEntries();

//	const Int_t nBeamnScalerReads = iBeamnScalerReads;
	const Int_t nBeamnScalerReads = 2000;

	//Histo for Bkg1
	TH1D *hBkg1LiveTime = (TH1D*)fBkg1.Get( "LiveTimeScal");
	TH2D *hBkg1TaggScalers = (TH2D*) fBkg1.Get( "TaggerScalers");

	// setupParameters tree is needed to get the TimeStamp
	TTree *tBkg1Parameters = (TTree*)fBkg1.Get( "setupParameters");
	Int_t iBkg1TimeStamp;
	tBkg1Parameters -> SetBranchAddress( "TimeStamp", &iBkg1TimeStamp);
	tBkg1Parameters -> GetEntry(0);

	// Scalers tree is needed to get the n of clock per scaler read (as well as the n of scaler reads)
	TTree *tBkg1Scaler = (TTree*)fBkg1.Get( "scalers");
	UInt_t iBkg1Scalers[8706];
	tBkg1Scaler -> SetBranchAddress( "scalers", iBkg1Scalers);
	Int_t iBkg1nScalerReads = tBkg1Scaler -> GetEntries();

	//Histo for Bkg2
	TH1D *hBkg2LiveTime = (TH1D*)fBkg2.Get( "LiveTimeScal");
	TH2D *hBkg2TaggScalers = (TH2D*) fBkg2.Get( "TaggerScalers");

	// setupParameters tree is needed to get the TimeStamp
	TTree *tBkg2Parameters = (TTree*)fBkg2.Get( "setupParameters");
	Int_t iBkg2TimeStamp;
	tBkg2Parameters -> SetBranchAddress( "TimeStamp", &iBkg2TimeStamp);
	tBkg2Parameters -> GetEntry(0);

	// Scalers tree is needed to get the n of clock per scaler read (as well as the n of scaler reads)
	TTree *tBkg2Scaler = (TTree*)fBkg2.Get( "scalers");
	UInt_t iBkg2Scalers[8706];
	tBkg2Scaler -> SetBranchAddress( "scalers", iBkg2Scalers);
	Int_t iBkg2nScalerReads = tBkg2Scaler -> GetEntries();

	// Starting time for the Beam and Bgk2, as respect to Bkg1 (it always starts at time 0)
	Double_t dTimeBkg1 = 0.;
	Double_t dTimeBeam = iBeamTimeStamp - iBkg1TimeStamp; //s
	Double_t dTimeBkg2 = iBkg2TimeStamp - iBkg1TimeStamp; //s

//
// Background fitting
//

	const Int_t nCh = 328;
	const Int_t n = iBkg1nScalerReads-2+iBkg2nScalerReads-2;

	const UInt_t N = 100;

	Double_t dBkgTimeScRd[N]; // x-axis 
	Double_t dBkgRateScRdMean[N]; // y-axis for mean
	Double_t dBkgRateScRdCh[nCh][N]; // y-axis for ch
	TH1D *hBkgTaggScalers_ProjY;

	// Loop over scaler reads in Bkg1
	for ( Int_t iBkg1ScRd = 1; iBkg1ScRd < iBkg1nScalerReads-1; iBkg1ScRd++)
	{
		tBkg1Scaler -> GetEntry(iBkg1ScRd);
		Double_t dTimeScRd = iBkg1Scalers[191] * 1.E-6;
		if (iBkg1ScRd == 1) dBkgTimeScRd[iBkg1ScRd-1] =  dTimeScRd; // x-axis
		if (iBkg1ScRd > 1) dBkgTimeScRd[iBkg1ScRd-1] = dBkgTimeScRd[iBkg1ScRd-2] +  dTimeScRd; // x-axis
		hBkgTaggScalers_ProjY = (TH1D*) hBkg1TaggScalers -> ProjectionY("hBkgTaggScalers_ProjY", iBkg1ScRd, iBkg1ScRd);
		dBkgRateScRdMean[iBkg1ScRd-1] = hBkgTaggScalers_ProjY -> Integral() / dTimeScRd / nCh;
		for (Int_t iCh = 1; iCh <= nCh; iCh ++ )
			dBkgRateScRdCh[iCh-1][iBkg1ScRd-1] = hBkgTaggScalers_ProjY -> GetBinContent(iCh) / dTimeScRd;
	}

	Int_t iBkg2ScRd;
	Int_t iBkg1ScRd;
	
	// Loop over scaler reads in Bkg2
	for (Int_t iBkg2ScRd = 1; iBkg2ScRd < iBkg2nScalerReads-1; iBkg2ScRd++)
	{
		tBkg2Scaler -> GetEntry(iBkg2ScRd);
		Double_t dTimeScRd = iBkg2Scalers[191] * 1.E-6;
		if (iBkg2ScRd == 1) dBkgTimeScRd[(iBkg1ScRd-1) + (iBkg2ScRd-1)] = dTimeBkg2 + dTimeScRd; // offset
		if (iBkg2ScRd > 1) dBkgTimeScRd[(iBkg1ScRd-1) + (iBkg2ScRd-1)] = dBkgTimeScRd[(iBkg1ScRd-2) + (iBkg2ScRd-1)] +  dTimeScRd; // x-axis
		hBkgTaggScalers_ProjY = (TH1D*) hBkg2TaggScalers -> ProjectionY("hBkgTaggScalers_ProjY", iBkg2ScRd, iBkg2ScRd);
		dBkgRateScRdMean[(iBkg1ScRd-1) + (iBkg2ScRd-1)] = hBkgTaggScalers_ProjY -> Integral() / dTimeScRd / nCh;
		for (Int_t iCh = 1; iCh <= nCh; iCh ++ )
			dBkgRateScRdCh[iCh-1][(iBkg1ScRd-1) + (iBkg2ScRd-1)] = hBkgTaggScalers_ProjY -> GetBinContent(iCh) / dTimeScRd;
	}
	
	TGraph *gBkgRateMean = new TGraph(n, dBkgTimeScRd, dBkgRateScRdMean);
	TF1 *fBkgFit = new TF1("fBkgFit","[0] + [1] * exp(-1.*[2]*x)");
	gBkgRateMean -> Fit("fBkgFit","0");

	// Make a Bkg function for every tagger channel, using the Lambda constant from the fit of the mean
	TGraph *gBkgRateCh[nCh];
	TF1 *fBkgFitCh[nCh];
	for( Int_t iCh = 0; iCh < nCh; iCh ++)
	{
		TString sGrName = "BkgRateCh_"; sGrName += (iCh+1);
		TString sGrTitle = "Background rate for channel #"; sGrTitle += (iCh+1);
		gBkgRateCh[iCh] = new TGraph(n, dBkgTimeScRd, dBkgRateScRdCh[iCh]);
		gBkgRateCh[iCh] -> SetNameTitle(sGrName,sGrTitle);
		gBkgRateCh[iCh] -> SetMarkerStyle(3);
		gBkgRateCh[iCh] -> GetXaxis() -> SetTitle("Time after the start of Bkg1 [s]");
		gBkgRateCh[iCh] -> GetYaxis() -> SetTitle("Rate [Hz]");
		TString sName = "fBkgFitCh"; sName += iCh;
		fBkgFitCh[iCh] = new TF1(sName, "[0] + [1] * exp(-1.*[2]*x)");
		fBkgFitCh[iCh] -> FixParameter(2, fBkgFit->GetParameter(2));
		gBkgRateCh[iCh] -> Fit(sName,"0");
	}
	  
//
// Beam file
//
	//Define stuff only for checking rate mean distribution also including the beam
	Double_t dBeamTimeScRd[nBeamnScalerReads];
	Double_t dBeamRateScRdMean[nBeamnScalerReads];
	TH1D *hBeamTaggScalers_ProjY;
	TH2D *hBeamTaggScalersExpBkgSub = (TH2D*) hBeamTaggScalers -> Clone( "hBeamTaggScalersExpBkgSub");
	
	for ( Int_t iBeamScRd = 0; iBeamScRd < iBeamnScalerReads; iBeamScRd++)
	{
		tBeamScaler -> GetEntry(iBeamScRd);
		Double_t dTimeScRd = iBeamScalers[191] * 1.E-6;
		if (iBeamScRd == 0) dBeamTimeScRd[(iBeamScRd)] = dTimeBeam + dTimeScRd; // offset
		if (iBeamScRd > 0) dBeamTimeScRd[(iBeamScRd)] = dBeamTimeScRd[(iBeamScRd-1)] +  dTimeScRd; // x-axis
		hBeamTaggScalers_ProjY = (TH1D*) hBeamTaggScalers -> ProjectionY("hBeamTaggScalers_ProjY", iBeamScRd, iBeamScRd);
		dBeamRateScRdMean[(iBeamScRd)] = hBeamTaggScalers_ProjY -> Integral() / dTimeScRd  / nCh;
		for ( Int_t iCh = 1; iCh <= nCh; iCh ++ )
		{
			Double_t dBeamScCh = hBeamTaggScalers_ProjY -> GetBinContent(iCh) / dTimeScRd;
			dBeamScCh = (dBeamScCh - fBkgFitCh[iCh-1] -> Eval(dBeamTimeScRd[(iBeamScRd)])) * dTimeScRd;
			hBeamTaggScalersExpBkgSub -> SetBinContent(iBeamScRd, iCh, dBeamScCh);
		}
	}

	// Finally we can make taggeffs
	TString sOut = sBeam;
	sOut.ReplaceAll( "goat", "ExpBkgSub");

	cout << "outfile = " << sOut << endl;

	TFile fOut( sOut, "RECREATE");
	
	TH1D *hEffAllHitsExpBkgSub = (TH1D*) hBeamAllHits -> Clone( "TaggEffAllHitsExpBkgSub");
	TH1D *hEffSinglesExpBkgSub = (TH1D*) hBeamSingles -> Clone( "TaggEffSinglesExpBkgSub");
	TH1D *hEffDoublesExpBkgSub = (TH1D* )hBeamDoubles -> Clone( "TaggEffDoublesExpBkgSub");
	TH1D *hEffAccScalExpBkgSub = (TH1D*) hBeamTaggScalersExpBkgSub -> ProjectionY( "TaggEffAccScalExpBkgSub", 0, iBeamnScalerReads);
	hEffAccScalExpBkgSub -> Sumw2();

	hEffAccScalExpBkgSub -> Scale(dBeamInhib/dBeamClock);
	hEffAllHitsExpBkgSub -> Divide(hEffAccScalExpBkgSub);
	hEffSinglesExpBkgSub -> Divide(hEffAccScalExpBkgSub);
	hEffDoublesExpBkgSub -> Divide(hEffAccScalExpBkgSub);

	hEffAllHitsExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");
	hEffAllHitsExpBkgSub -> GetYaxis() -> SetTitle( "Tagging Efficiency");
	hEffSinglesExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");
	hEffSinglesExpBkgSub -> GetYaxis() -> SetTitle( "Tagging Efficiency");
	hEffDoublesExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");
	hEffDoublesExpBkgSub -> GetYaxis() -> SetTitle( "Tagging Efficiency");
	hEffAccScalExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");

	// Add in the output file the exp fit of the bkg (just in case...)
	gBkgRateMean -> SetNameTitle( "BkgRateMean", "Background rate mean over channels");
	gBkgRateMean -> SetMarkerStyle(3);
	gBkgRateMean -> GetXaxis() -> SetTitle( "Time after the start of Bkg1 [s]");
	gBkgRateMean -> GetYaxis() -> SetTitle( "Rate mean per channel [Hz]");
	gBkgRateMean -> Write();
	TDirectory *dirBkgRateCh = fOut.mkdir( "BkgRateChannels");
	dirBkgRateCh -> cd();
	for(Int_t iCh = 0; iCh < nCh; iCh ++) gBkgRateCh[iCh] -> Write();

	fOut.cd();
	fOut.Write();
	fOut.Close();
}

/*
void TEsingle( UInt_t run_no)
{
	TString filename;

	// Open the file
	filename = Form( "goat_%d.root", run_no);
	TFile fBeam( filename, "READ");
	
	TH1D *hBeamAllHits = (TH1D*)fBeam.Get( "TaggerAllHits");
	TH1D *hBeamSingles = (TH1D*)fBeam.Get( "TaggerSingles");
	TH1D *hBeamDoubles = (TH1D*)fBeam.Get( "TaggerDoubles");
	TH2D *hBeamTaggScalers = (TH2D*) fBeam.Get( "TaggerScalers");

	Double_t dBeamTimeScRd[2000];
	Double_t dBeamRateScRdMean[2000];
	TH1D *hBeamTaggScalers_ProjY;
	TH2D *hBeamTaggScalersExpBkgSub = (TH2D*) hBeamTaggScalers -> Clone( "hBeamTaggScalersExpBkgSub");
	
	for ( Int_t iBeamScRd = 0; iBeamScRd < iBeamnScalerReads; iBeamScRd ++)
	{
		tBeamScaler -> GetEntry(iBeamScRd);
		Double_t dTimeScRd = iBeamScalers[191] * 1.E-6;
		if (iBeamScRd == 0) dBeamTimeScRd[(iBeamScRd)] = dTimeBeam + dTimeScRd; // offset
		if (iBeamScRd > 0) dBeamTimeScRd[(iBeamScRd)] = dBeamTimeScRd[(iBeamScRd-1)] +  dTimeScRd; // x-axis
		hBeamTaggScalers_ProjY = (TH1D*) hBeamTaggScalers -> ProjectionY("hBeamTaggScalers_ProjY", iBeamScRd, iBeamScRd);
		dBeamRateScRdMean[(iBeamScRd)] = hBeamTaggScalers_ProjY -> Integral() / dTimeScRd  / nCh;
		for ( Int_t iCh = 1; iCh <= nCh; iCh ++ )
		{
			Double_t dBeamScCh = hBeamTaggScalers_ProjY -> GetBinContent(iCh) / dTimeScRd;
			dBeamScCh = (dBeamScCh - fBkgFitCh[iCh-1] -> Eval(dBeamTimeScRd[(iBeamScRd)])) * dTimeScRd;
			hBeamTaggScalersExpBkgSub -> SetBinContent(iBeamScRd, iCh, dBeamScCh);
		}
	}

	// Finally we can make taggeffs
	TString sOut = sBeam;
	sOut.ReplaceAll( "goat", "Output");

	cout << "outfile = " << sOut << endl;

	TFile fOut( sOut, "RECREATE");
	
	TH1D *hEffAllHitsExpBkgSub = (TH1D*) hBeamAllHits -> Clone( "TaggEffAllHitsExpBkgSub");
	TH1D *hEffSinglesExpBkgSub = (TH1D*) hBeamSingles -> Clone( "TaggEffSinglesExpBkgSub");
	TH1D *hEffDoublesExpBkgSub = (TH1D* )hBeamDoubles -> Clone( "TaggEffDoublesExpBkgSub");
	TH1D *hEffAccScalExpBkgSub = (TH1D*) hBeamTaggScalersExpBkgSub -> ProjectionY( "TaggEffAccScalExpBkgSub", 0, iBeamnScalerReads);
	hEffAccScalExpBkgSub -> Sumw2();

	hEffAccScalExpBkgSub -> Scale(dBeamInhib/dBeamClock);
	hEffAllHitsExpBkgSub -> Divide(hEffAccScalExpBkgSub);
	hEffSinglesExpBkgSub -> Divide(hEffAccScalExpBkgSub);
	hEffDoublesExpBkgSub -> Divide(hEffAccScalExpBkgSub);

	hEffAllHitsExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");
	hEffAllHitsExpBkgSub -> GetYaxis() -> SetTitle( "Tagging Efficiency");
	hEffSinglesExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");
	hEffSinglesExpBkgSub -> GetYaxis() -> SetTitle( "Tagging Efficiency");
	hEffDoublesExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");
	hEffDoublesExpBkgSub -> GetYaxis() -> SetTitle( "Tagging Efficiency");
	hEffAccScalExpBkgSub -> GetXaxis() -> SetTitle( "Tagger Channel");

	fOut.cd();
	fOut.Write();
	fOut.Close();
}
*/
