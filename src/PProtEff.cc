#include "PProtEff.h"

PProtEff::PProtEff()
{
    CorrTaggScal = new TH1D("CorrTaggScal", "Livetime corrected tagger scalers;Tagger Channel;LT*Scaler", 352, 0, 352);

    Helicity = new TH1D("Helicity", "Helicity", 3, 0, 3);

    Pi0_IM = new TH2D("Pi0_IM", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);

    Pi0_IM_NN = new TH2D("Pi0_IM_NN", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_NC = new TH2D("Pi0_IM_NC", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_CC = new TH2D("Pi0_IM_CC", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);

    Pi0_IM_XXN = new TH2D("Pi0_IM_XXN", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_XXC = new TH2D("Pi0_IM_XXC", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_XXW = new TH2D("Pi0_IM_XXW", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);

    Pi0_IM_NNS = new TH2D("Pi0_IM_NNS", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_NCS = new TH2D("Pi0_IM_NCS", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_CCS = new TH2D("Pi0_IM_CCS", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);

    Pi0_IM_XXSN = new TH2D("Pi0_IM_XXSN", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_XXSC = new TH2D("Pi0_IM_XXSC", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);
    Pi0_IM_XXSW = new TH2D("Pi0_IM_XXSW", "Neutral Pion Invariant Mass;N_{extra};m_{#gamma#gamma} (MeV)", 10, 0, 10, 400, 0, 400);

    Split_OA_E = new TH2D("Split_OA_E", "Split OA vs Energy Ratio;E_{split}/E_{#gamma};#theta_{OA} (deg)", 200, 0, 1, 180, 0, 180);

    Pi0_Dt = new TH2D("Pi0_Dt", "Pi0 Time;Tagger Channel;t_{#gamma}-t_{#pi^{0}} (ns)", 352, 0, 352, 1400, -700, 700);
    Pi0_Dt_NN = new TH2D("Pi0_Dt_NN", "Pi0 Time;Tagger Channel;t_{#gamma}-t_{#pi^{0}} (ns)", 352, 0, 352, 1400, -700, 700);

    Pi0_IM_MM = new TH3D("Pi0_IM_MM", "Pi0 Missing Mass;Tagger Channel;m_{#gamma#gamma} (MeV);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 100, 0, 200, 80, -80, 120);
    Pi0_IM_MM_R = new TH3D("Pi0_IM_MM_R", "Pi0 Missing Mass;Tagger Channel;m_{#gamma#gamma} (MeV);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 100, 0, 200, 80, -80, 120);

    Pi0_MM = new TH3D("Pi0_MM", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_R = new TH3D("Pi0_MM_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);

    Pi0_MM_NN = new TH3D("Pi0_MM_NN", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_NN_R = new TH3D("Pi0_MM_NN_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_NC = new TH3D("Pi0_MM_NC", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_NC_R = new TH3D("Pi0_MM_NC_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_CC = new TH3D("Pi0_MM_CC", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_CC_R = new TH3D("Pi0_MM_CC_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);

    Pi0_MM_XXN = new TH3D("Pi0_MM_XXN", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXN_R = new TH3D("Pi0_MM_XXN_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXC = new TH3D("Pi0_MM_XXC", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXC_R = new TH3D("Pi0_MM_XXC_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXW = new TH3D("Pi0_MM_XXW", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXW_R = new TH3D("Pi0_MM_XXW_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);

    Pi0_MM_NNS = new TH3D("Pi0_MM_NNS", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_NNS_R = new TH3D("Pi0_MM_NNS_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_NCS = new TH3D("Pi0_MM_NCS", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_NCS_R = new TH3D("Pi0_MM_NCS_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_CCS = new TH3D("Pi0_MM_CCS", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_CCS_R = new TH3D("Pi0_MM_CCS_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);

    Pi0_MM_XXSN = new TH3D("Pi0_MM_XXSN", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXSN_R = new TH3D("Pi0_MM_XXSN_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXSC = new TH3D("Pi0_MM_XXSC", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXSC_R = new TH3D("Pi0_MM_XXSC_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXSW = new TH3D("Pi0_MM_XXSW", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);
    Pi0_MM_XXSW_R = new TH3D("Pi0_MM_XXSW_R", "Pi0 Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss}-m_{targ} (MeV)", 352, 0, 352, 36, 0, 180, 80, -80, 120);

    Pi0_Sp_IM_MM = new TH3D("Pi0_Sp_IM_MM", "Pi0 Split Improvment;Tagger Channel;|m_{#gamma#gamma}-m_{#pi^0}|-|m_{#gamma#gamma S}-m_{#pi^0}| (MeV);|m_{miss}-m_{targ}|-|m_{miss S}-m_{targ}| (MeV)", 352, 0, 352, 50, 0, 50, 150, -50, 100);
    Pi0_Sp_IM_MM_R = new TH3D("Pi0_Sp_IM_MM_R", "Pi0 Split Improvment;Tagger Channel;|m_{#gamma#gamma}-m_{#pi^0}|-|m_{#gamma#gamma S}-m_{#pi^0}| (MeV);|m_{miss}-m_{targ}|-|m_{miss S}-m_{targ}| (MeV)", 352, 0, 352, 50, 0, 50, 150, -50, 100);

    Pi0_Re_All = new TH3D("Pi0_Re_All", "Pi0 Missing Mass;Recoil Energy (MeV);#theta_{miss} (deg);Tagger Channel", 200, 0, 200, 36, 0, 180, 352, 0, 352);
    Pi0_Re_All_R = new TH3D("Pi0_Re_All_R", "Pi0 Missing Mass;Recoil Energy (MeV);#theta_{miss} (deg);Tagger Channel", 200, 0, 200, 36, 0, 180, 352, 0, 352);
    Pi0_Re_Det = new TH3D("Pi0_Re_Det", "Pi0 Missing Mass;Recoil Energy (MeV);#theta_{miss} (deg);Tagger Channel", 200, 0, 200, 36, 0, 180, 352, 0, 352);
    Pi0_Re_Det_R = new TH3D("Pi0_Re_Det_R", "Pi0 Missing Mass;Recoil Energy (MeV);#theta_{miss} (deg);Tagger Channel", 200, 0, 200, 36, 0, 180, 352, 0, 352);
    Pi0_Re_Dif = new TH3D("Pi0_Re_Dif", "Pi0 Missing Mass;E_{miss}-E_{det} (MeV);#theta_{miss} (deg);Tagger Channel", 150, -50, 100, 36, 0, 180, 352, 0, 352);
    Pi0_Re_Dif_R = new TH3D("Pi0_Re_Dif_R", "Pi0 Missing Mass;E_{miss}-E_{det} (MeV);#theta_{miss} (deg);Tagger Channel", 150, -50, 100, 36, 0, 180, 352, 0, 352);
    Pi0_Re_NoE = new TH3D("Pi0_Re_NoE", "Pi0 Missing Mass;Recoil Energy (MeV);#theta_{miss} (deg);Tagger Channel", 200, 0, 200, 36, 0, 180, 352, 0, 352);
    Pi0_Re_NoE_R = new TH3D("Pi0_Re_NoE_R", "Pi0 Missing Mass;Recoil Energy (MeV);#theta_{miss} (deg);Tagger Channel", 200, 0, 200, 36, 0, 180, 352, 0, 352);

    Pi0_Re_dT_Det = new TH3D("Pi0_Re_dT_Det", "Pi0 Missing Mass;#theta_{miss}-#theta_{det} (deg);#theta_{miss} (deg);Tagger Channel", 30, -15, 15, 70, 0, 70, 352, 0, 352);
    Pi0_Re_dT_Det_R = new TH3D("Pi0_Re_dT_Det_R", "Pi0 Missing Mass;#theta_{miss}-#theta_{det} (deg);#theta_{miss} (deg);Tagger Channel", 30, -15, 15, 70, 0, 70, 352, 0, 352);
    Pi0_Re_dT_NoE = new TH3D("Pi0_Re_dT_NoE", "Pi0 Missing Mass;#theta_{miss}-#theta_{det} (deg);#theta_{miss} (deg);Tagger Channel", 30, -15, 15, 70, 0, 70, 352, 0, 352);
    Pi0_Re_dT_NoE_R = new TH3D("Pi0_Re_dT_NoE_R", "Pi0 Missing Mass;#theta_{miss}-#theta_{det} (deg);#theta_{miss} (deg);Tagger Channel", 30, -15, 15, 70, 0, 70, 352, 0, 352);

    Pi0_Re_CA = new TH1D("Pi0_Re_CA", "Pi0 Recoil Coplanarity Angle;Coplanarity Angle (deg)", 360, 0, 360);

    Pi0_Re_OA = new TH3D("Pi0_Re_OA", "Pi0 Recoil Opening Angle;Tagger Channel;#theta_{miss} (deg);Opening Angle (deg)", 352, 0, 352, 12, 0, 60, 90, 0, 180);
    Pi0_Re_OA_R = new TH3D("Pi0_Re_OA_R", "Pi0 Recoil Opening Angle;Tagger Channel;#theta_{miss} (deg);Opening Angle (deg)", 352, 0, 352, 12, 0, 60, 90, 0, 180);
    Pi0_Re_OA_Cut = new TH3D("Pi0_Re_OA_Cut", "Pi0 Recoil Opening Angle;Tagger Channel;#theta_{miss} (deg);Opening Angle (deg)", 352, 0, 352, 12, 0, 60, 90, 0, 180);
    Pi0_Re_OA_Cut_R = new TH3D("Pi0_Re_OA_Cut_R", "Pi0 Recoil Opening Angle;Tagger Channel;#theta_{miss} (deg);Opening Angle (deg)", 352, 0, 352, 12, 0, 60, 90, 0, 180);

    verbosity = 0;
    excl_pi0 = false;
    excl_pro = false;

    IMCut = 134.98;
    MMLoC = 800.00;
    MMHiC = 938.27;
    OACut = 180;
    ESCut = 0;

    save_randoms = false;
    split_search = false;

    taps_eff = 1;

    cir_beam = false;
    lin_beam = false;
    beamPol = 1;
    targPol = 1;

    firstEvent = true;
    gRandom->SetSeed(0);
}

PProtEff::~PProtEff()
{
}

Bool_t	PProtEff::Init()
{
    cout << "Initialising physics analysis..." << endl;
    cout << "--------------------------------------------------" << endl << endl;

    if(!InitBackgroundCuts()) return kFALSE;
    if(!InitTargetMass()) return kFALSE;
    if(!InitVerbosity()) return kFALSE;
    if(!InitExclusivity()) return kFALSE;
    if(!InitInvariantMass()) return kFALSE;
    if(!InitMissingMass()) return kFALSE;
    if(!InitOpeningAngle()) return kFALSE;
    if(!InitEnergySum()) return kFALSE;
    if(!InitSaveRandoms()) return kFALSE;
    if(!InitTAPSEff()) return kFALSE;
    if(!InitBeamPol()) return kFALSE;
    if(!InitTargPol()) return kFALSE;
    if(!InitSplitSearch()) return kFALSE;

    if(!PPhysics::Init()) return kFALSE;

    TaggerAccScal = GetScalerHist("TaggerAccScal");
    if(!TaggerAccScal)
    {
        cout << "No tagger scaler histogram available" << endl;
        return kFALSE;
    }
    LiveTimeScal = GetScalerHist("LiveTimeScal");
    if(!LiveTimeScal)
    {
        cout << "No live time histogram available" << endl;
        return kFALSE;
    }

    cout << "--------------------------------------------------" << endl;
	return kTRUE;
}

Bool_t	PProtEff::Start()
{
    if(!IsAcquFile())
    {
        cout << "ERROR: Input File is not an Acqu file." << endl;
        return kFALSE;
    }
    SetAsGoATFile();

    TraverseValidEvents();

    //GoosyTagger(TaggerAccScal);
    //GoosyVuprom(TaggerAccScal);
    GoosyNewFPDRecabled(TaggerAccScal);

    return kTRUE;
}

void	PProtEff::ProcessEvent()
{
    if (firstEvent)
    {
        Int_t fileTime = GetSetupParameters()->GetTimeStamp();
        cout << endl << "Time Stamp for this run: " << fileTime << endl;
        Int_t timeDiff = fileTime;

        for (UInt_t i = 0; i<beamPolTime.size(); i++)
        {
            if (TMath::Abs(beamPolTime.at(i) - fileTime) < timeDiff)
            {
                beamPol = beamPolMeas.at(i);
                timeDiff = TMath::Abs(beamPolTime.at(i) - fileTime);
            }
        }
        for (UInt_t i = 0; i<targPolTime.size(); i+=2)
        {
            if ((targPolTime.at(i) < fileTime) && (fileTime < targPolTime.at(i+1)))
            {
                Double_t tau = ((targPolTime.at(i)-targPolTime.at(i+1))/TMath::Log(targPolMeas.at(i+1)/targPolMeas.at(i)));
                targPol = targPolMeas.at(i)*TMath::Exp((targPolTime.at(i)-fileTime)/tau);
                break;
            }
        }

        cout << "E Beam polarization for this run: " << 100*beamPol << "%" << endl;
        cout << "Target polarization for this run: " << 100*targPol << "%" << endl << endl;
        firstEvent = false;
    }

    if (GetEventNumber()%100000 == 0) cout << "Event " << GetEventNumber() << endl;

    if (GetTrigger()->GetEnergySum() < ESCut) return;

    Float_t event_weight = 1;
    if (IsMCFile()) event_weight = GetTrigger()->GetMCWeight();

    Bool_t hel = 0;
    if (cir_beam && !(IsMCFile()))
    {
        if(!(GetTrigger()->HasHelicity())) return;
	hel = GetTrigger()->GetHelicity();
    }

    for (Int_t i=0; i<(GetTrigger()->GetNErrors()); i++)
    {
        if (!(IsMCFile()) && (cir_beam || (GetTrigger()->GetErrorModuleID())[i] >= 0 || (GetTrigger()->GetErrorModuleIndex())[i] >= 0))
	{
            Helicity->Fill(2);
            return;
	}
    }

    Helicity->Fill(hel);

    Int_t tagg_chan;
    Double_t pi0_time, tagg_time, tagg_energy, time, energy, theta, phi, temp_ang, copl_ang, open_ang, m_miss;
    Double_t energy_0, energy_1, energy_s, energy_r;
    TLorentzVector beam, target, pi0, pi0_XX, missing, ptot;
    TVector3 lab_to_cm, recoil, split;
    TLorentzVector track_0, track_1, track_s, miss_0, miss_1;
    target = GetTarget();

    Bool_t pi0_X, pi0_NN, pi0_NC, pi0_CC;
    Bool_t spl_N, spl_C;
    Bool_t rec_N, rec_C, rec_W;
    Bool_t cut_CA, cut_OA;
    pi0_X = pi0_NN = pi0_NC = pi0_CC = spl_N = spl_C = rec_N = rec_C = rec_W = cut_CA = cut_OA = false;
    Int_t num_extra = 0;

    Int_t nTagg = GetTagger()->GetNTagged();

    Double_t minIM = 0;

    ignoreTrack.clear();

    //////////////////////////////////////////////////
    // Check for tracks in TAPS
    //////////////////////////////////////////////////
    for (Int_t i=0; i<(GetTracks()->GetNTracks()); i++)
    {
        if ((GetTracks()->HasTAPS(i)) && (gRandom->Rndm() >= taps_eff)) ignoreTrack.push_back(true);
	else ignoreTrack.push_back(false);
    }

    //////////////////////////////////////////////////
    // Initial pi0 stuff
    //////////////////////////////////////////////////
    Int_t i0, i1, ir, is;
    i0 = i1 = ir = is = -1;

    for (Int_t i=0; i<(GetTracks()->GetNTracks()-1); i++)
    {
	energy_0 = GetTracks()->GetClusterEnergy(i);
	if (energy_0 == 0 || ignoreTrack.at(i)) continue;
	track_0 = GetTracks()->GetVector(i);

	for (Int_t j=i+1; j<(GetTracks()->GetNTracks()); j++)
	{
	    energy_1 = GetTracks()->GetClusterEnergy(j);
	    if (energy_1 == 0 || ignoreTrack.at(j)) continue;
	    track_1 = GetTracks()->GetVector(j);

	    ptot = track_0 + track_1;
	    if (TMath::Abs(134.98 - ptot.M()) < TMath::Abs(134.98 - minIM))
	    {
		if ((GetTracks()->HasCB(i)) && (GetTracks()->HasCB(j))) pi0_time = 0.5*(GetTracks()->GetTime(i) + GetTracks()->GetTime(j));
		else if (GetTracks()->HasCB(i)) pi0_time = (GetTracks()->GetTime(i));
		else if (GetTracks()->HasCB(j)) pi0_time = (GetTracks()->GetTime(j));
		else continue;
		i0 = i;
		i1 = j;
		ir = -1;
		is = -1;
		pi0 = track_0 + track_1;
		minIM = pi0.M();
		if (GetTracks()->IsNeutral(i) && GetTracks()->IsNeutral(j)) pi0_NN = true;
		else if (GetTracks()->IsNeutral(i) || GetTracks()->IsNeutral(j)) pi0_NC = true;
		else pi0_CC = true;
		spl_N = spl_C = rec_N = rec_C = rec_W = cut_CA = false;
		num_extra = (GetTracks()->GetNTracks())-2;
		copl_ang = 360;

		//////////////////////////////////////////////////
		// Look for best recoil
		//////////////////////////////////////////////////
		for (Int_t k=0; k<(GetTracks()->GetNTracks()); k++)
		{
		    if (k == i || k == j || ignoreTrack.at(k)) continue;
		    temp_ang = TMath::Abs(pi0.Phi()*TMath::RadToDeg()-GetTracks()->GetPhi(k));
		    if (TMath::Abs(180.0-temp_ang) < TMath::Abs(180.0-copl_ang))
		    {
			copl_ang = temp_ang;
			ir = k;
		    }
		}

		//////////////////////////////////////////////////
		// Check best recoil
		//////////////////////////////////////////////////
		if (TMath::Abs(180.0-copl_ang) < OACut)
		{
		    cut_CA = true;
		    energy_r = GetTracks()->GetClusterEnergy(ir);
		    recoil = GetTracks()->GetUnitVector(ir);
		    if (GetTracks()->IsNeutral(ir)) rec_N = true;
		    else if (energy_r > 0) rec_C = true;
		    else rec_W = true;
		    num_extra = (GetTracks()->GetNTracks())-3;
		}
		else ir = -1;
	    }
	    
	    if (!split_search) continue;
	    //////////////////////////////////////////////////
	    // Look for splits
	    //////////////////////////////////////////////////
	    for (Int_t k=0; k<(GetTracks()->GetNTracks()); k++)
	    {
		energy_s = GetTracks()->GetClusterEnergy(k);
		if (k == i || k == j || energy_s == 0 || ignoreTrack.at(k)) continue;
		track_s = GetTracks()->GetVector(k);
		split = GetTracks()->GetUnitVector(k);

		Split_OA_E->Fill(energy_s/energy_0,(TMath::RadToDeg()*track_0.Angle(split)));
		Split_OA_E->Fill(energy_s/energy_1,(TMath::RadToDeg()*track_1.Angle(split)));

		if ((TMath::RadToDeg()*track_0.Angle(split)) < 40*(1-(2*energy_s/energy_0)) ||
		    (TMath::RadToDeg()*track_1.Angle(split)) < 40*(1-(2*energy_s/energy_1)))
		{
		    ptot = track_0 + track_1 + track_s;
		    if (TMath::Abs(134.98 - ptot.M()) < TMath::Abs(134.98 - minIM))
		    {
		        if ((GetTracks()->HasCB(i)) && (GetTracks()->HasCB(j))) pi0_time = 0.5*(GetTracks()->GetTime(i) + GetTracks()->GetTime(j));
			else if (GetTracks()->HasCB(i)) pi0_time = (GetTracks()->GetTime(i));
			else if (GetTracks()->HasCB(j)) pi0_time = (GetTracks()->GetTime(j));
			else continue;
			i0 = i;
			i1 = j;
			ir = -1;
			is = k;
			pi0 = track_0 + track_1 + track_s;
			pi0_XX = track_0 + track_1;
			minIM = pi0.M();
			if (GetTracks()->IsNeutral(i) && GetTracks()->IsNeutral(j)) pi0_NN = true;
			else if (GetTracks()->IsNeutral(i) || GetTracks()->IsNeutral(j)) pi0_NC = true;
			else pi0_CC = true;
			if (GetTracks()->IsNeutral(k)) spl_N = true;
			else spl_C = true;
			rec_N = rec_C = rec_W = cut_CA = false;
			num_extra = (GetTracks()->GetNTracks())-3;
			copl_ang = 360;

			//////////////////////////////////////////////////
			// Look for best recoil
			//////////////////////////////////////////////////
			for (Int_t l=0; l<(GetTracks()->GetNTracks()); l++)
			{
			    if (l == i || l == j || l == k || ignoreTrack.at(l)) continue;
			    temp_ang = TMath::Abs(pi0.Phi()*TMath::RadToDeg()-GetTracks()->GetPhi(l));
			    if (TMath::Abs(180.0-temp_ang) < TMath::Abs(180.0-copl_ang))
			    {
				copl_ang = temp_ang;
				ir = l;
			    }
			}
			
			//////////////////////////////////////////////////
			// Check best recoil
			//////////////////////////////////////////////////
			if (TMath::Abs(180.0-copl_ang) < OACut)
			{
			    cut_CA = true;
			    energy_r = GetTracks()->GetClusterEnergy(ir);
			    recoil = GetTracks()->GetUnitVector(ir);
			    if (GetTracks()->IsNeutral(ir)) rec_N = true;
			    else if (energy_r > 0) rec_C = true;
			    else rec_W = true;
			    num_extra = (GetTracks()->GetNTracks())-4;
			}
			else ir = -1;
		    }
		}
	    }
	}
    }

    if (minIM > 0)
    {
        pi0_X = (TMath::Abs(134.98 - minIM) < IMCut);
	theta = pi0.Theta()*TMath::RadToDeg();
	phi = pi0.Phi()*TMath::RadToDeg();

        Pi0_IM->Fill(num_extra, minIM, event_weight);
	if (spl_N || spl_C)
	{
	    if (rec_N) Pi0_IM_XXSN->Fill(num_extra, minIM, event_weight);
	    else if (rec_C) Pi0_IM_XXSC->Fill(num_extra, minIM, event_weight);
	    else if (rec_W) Pi0_IM_XXSW->Fill(num_extra, minIM, event_weight);
	    else if (pi0_NN) Pi0_IM_NNS->Fill(num_extra, minIM, event_weight);
	    else if (pi0_NC) Pi0_IM_NCS->Fill(num_extra, minIM, event_weight);
	    else if (pi0_CC) Pi0_IM_CCS->Fill(num_extra, minIM, event_weight);
	}
	else
	{
	    if (rec_N) Pi0_IM_XXN->Fill(num_extra, minIM, event_weight);
	    else if (rec_C) Pi0_IM_XXC->Fill(num_extra, minIM, event_weight);
	    else if (rec_W) Pi0_IM_XXW->Fill(num_extra, minIM, event_weight);
	    else if (pi0_NN) Pi0_IM_NN->Fill(num_extra, minIM, event_weight);
	    else if (pi0_NC) Pi0_IM_NC->Fill(num_extra, minIM, event_weight);
	    else if (pi0_CC) Pi0_IM_CC->Fill(num_extra, minIM, event_weight);
	}

	if (pi0_X) Pi0_Re_CA->Fill(copl_ang, event_weight);
    }

    Int_t num_clust = 0;
    Double_t avg_time = 0;
    for (Int_t i = 0; i < GetTracks()->GetNTracks(); i++)
    {
        if (GetTracks()->GetClusterEnergy(i) != 0)
        {
            avg_time += GetTracks()->GetTime(i);
            num_clust++;
        }
    }
    avg_time = avg_time/num_clust;

    //////////////////////////////////////////////////
    // Tagger loop
    //////////////////////////////////////////////////
    for (Int_t i = 0; i < nTagg; i++)
    {
        if (RejectTagged(i)) continue;

        tagg_chan = GetTagger()->GetTaggedChannel(i);
        tagg_time = GetTagger()->GetTaggedTime(i);
        tagg_energy = GetTagger()->GetTaggedEnergy(i);
        beam = TLorentzVector(0., 0., tagg_energy, tagg_energy);

        if (minIM > 0)
	{
            time = tagg_time - pi0_time;
            missing = beam + target - pi0;
	    m_miss = missing.M()-target.M();
	    Pi0_Dt->Fill(tagg_chan,time,event_weight);

            if (GHistBGSub::IsPrompt(time)) Pi0_IM_MM->Fill(tagg_chan,minIM,m_miss,event_weight);
            else if (GHistBGSub::IsRandom(time)) Pi0_IM_MM_R->Fill(tagg_chan,minIM,m_miss,event_weight);
	}

        if (pi0_X)
	{
            time = tagg_time - pi0_time;
            missing = beam + target - pi0;
	    m_miss = missing.M()-target.M();

	    cut_OA = false;
	    if (cut_CA)
	    {
		open_ang = (TMath::RadToDeg()*missing.Angle(recoil));
		cut_OA = (open_ang < OACut);
	    }

            if (GHistBGSub::IsPrompt(time))
	    {
		Pi0_MM->Fill(tagg_chan,theta,m_miss,event_weight);
		if (cut_CA) Pi0_Re_OA->Fill(tagg_chan,missing.Theta()*TMath::RadToDeg(),open_ang,event_weight);
		if (TMath::Abs(m_miss) < 15)
		{
		    Pi0_Re_All->Fill(missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
		    if (cut_CA) Pi0_Re_OA_Cut->Fill(tagg_chan,missing.Theta()*TMath::RadToDeg(),open_ang,event_weight);
		    if (cut_OA)
		    {
			if (energy_r > 0)
			{
			    Pi0_Re_Det->Fill(missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			    Pi0_Re_Dif->Fill(missing.E()-missing.M()-energy_r,missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			    Pi0_Re_dT_Det->Fill((missing.Theta()-recoil.Theta())*TMath::RadToDeg(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			}
			else 
			{
			    Pi0_Re_NoE->Fill(missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			    Pi0_Re_dT_NoE->Fill((missing.Theta()-recoil.Theta())*TMath::RadToDeg(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			}
		    }
		}
	    }
            else if (GHistBGSub::IsRandom(time)) 
	    {
		Pi0_MM_R->Fill(tagg_chan,theta,m_miss,event_weight);
		if (cut_CA) Pi0_Re_OA_R->Fill(tagg_chan,missing.Theta()*TMath::RadToDeg(),open_ang,event_weight);
		if (TMath::Abs(m_miss) < 15)
		{
		    Pi0_Re_All_R->Fill(missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
		    if (cut_CA) Pi0_Re_OA_Cut_R->Fill(tagg_chan,missing.Theta()*TMath::RadToDeg(),open_ang,event_weight);
		    if (cut_OA)
		    {
			if (energy_r > 0)
			{
			    Pi0_Re_Det_R->Fill(missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			    Pi0_Re_Dif_R->Fill(missing.E()-missing.M()-energy_r,missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			    Pi0_Re_dT_Det_R->Fill((missing.Theta()-recoil.Theta())*TMath::RadToDeg(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			}
			else 
			{
			    Pi0_Re_NoE_R->Fill(missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			    Pi0_Re_dT_NoE_R->Fill((missing.Theta()-recoil.Theta())*TMath::RadToDeg(),missing.Theta()*TMath::RadToDeg(),tagg_chan,event_weight);
			}
		    }
		}
	    }

	    if (spl_N || spl_C)
	    {
		if (rec_N && cut_OA)
                {
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_XXSN->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_XXSN_R->Fill(tagg_chan,theta,m_miss,event_weight);
                }
		else if (rec_C && cut_OA)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_XXSC->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_XXSC_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (rec_W && cut_OA)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_XXSW->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_XXSW_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (pi0_NN)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_NNS->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_NNS_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (pi0_NC)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_NCS->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_NCS_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (pi0_CC)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_CCS->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_CCS_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}

		missing = beam + target - pi0_XX;
		if (GHistBGSub::IsPrompt(time)) Pi0_Sp_IM_MM->Fill(tagg_chan,(TMath::Abs(pi0_XX.M()-134.98)-TMath::Abs(pi0.M()-134.98)),(TMath::Abs(missing.M()-target.M())-TMath::Abs(m_miss)),event_weight);
		else if (GHistBGSub::IsRandom(time)) Pi0_Sp_IM_MM_R->Fill(tagg_chan,(TMath::Abs(pi0_XX.M()-134.98)-TMath::Abs(pi0.M()-134.98)),(TMath::Abs(missing.M()-target.M())-TMath::Abs(m_miss)),event_weight);
	    }  
	    else
	    {
		if (rec_N && cut_OA)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_XXN->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_XXN_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (rec_C && cut_OA)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_XXC->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_XXC_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (rec_W && cut_OA)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_XXW->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_XXW_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (pi0_NN)
		{
		    Pi0_Dt_NN->Fill(tagg_chan,time,event_weight);
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_NN->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_NN_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (pi0_NC)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_NC->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_NC_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
		else if (pi0_CC)
		{
		    if (GHistBGSub::IsPrompt(time)) Pi0_MM_CC->Fill(tagg_chan,theta,m_miss,event_weight);
		    else if (GHistBGSub::IsRandom(time)) Pi0_MM_CC_R->Fill(tagg_chan,theta,m_miss,event_weight);
		}
	    }
	}
    }
}

Bool_t 	PProtEff::InitVerbosity()
{
    Int_t sc1;
    string config = ReadConfig("Verbosity");
    if(sscanf( config.c_str(), "%d\n", &sc1) == 1)
    {
        cout << "Setting verbosity: " << sc1 << endl << endl;
        verbosity = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Verbosity not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PProtEff::InitExclusivity()
{
    Int_t sc1, sc2;
    string config = ReadConfig("Exclusivity");
    if(sscanf( config.c_str(), "%d%d\n", &sc1, &sc2) == 2)
    {
        cout << "Setting exclusivity: pi0 = " << sc1 << ", p = " << sc2 << endl << endl;
        excl_pi0 = sc1;
        excl_pro = sc2;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Exclusivity not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PProtEff::InitInvariantMass()
{
    Double_t sc1;
    string config = ReadConfig("Invariant-Mass-Cut");
    if(sscanf( config.c_str(), "%lf\n", &sc1) == 1)
    {
        cout << "Setting invariant mass width: +/-" << sc1 << " MeV " << endl << endl;
        IMCut = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Invariant mass cut not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PProtEff::InitMissingMass()
{
    Double_t sc1, sc2;
    string config = ReadConfig("Missing-Mass-Cut");
    if(sscanf( config.c_str(), "%lf%lf\n", &sc1, &sc2) == 2)
    {
        cout << "Setting missing mass cut: " << sc1 << " to " << sc2 << " MeV " << endl << endl;
        MMLoC = sc1;
        MMHiC = sc2;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Missing mass cut not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PProtEff::InitOpeningAngle()
{
    Double_t sc1;
    string config = ReadConfig("Opening-Angle-Cut");
    if(sscanf( config.c_str(), "%lf\n", &sc1) == 1)
    {
        cout << "Setting opening angle: " << sc1 << " deg " << endl << endl;
        OACut = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Opening angle cut not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PProtEff::InitEnergySum()
{
    Double_t sc1;
    string config = ReadConfig("Energy-Sum-Cut");
    if(sscanf( config.c_str(), "%lf\n", &sc1) == 1)
    {
        cout << "Setting energy sum: " << sc1 << " MeV " << endl << endl;
        ESCut = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Energy sum cut not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PProtEff::InitSaveRandoms()
{
    Int_t sc1;
    string config = ReadConfig("Save-Randoms");
    if(sscanf( config.c_str(), "%d\n", &sc1) == 1)
    {
        cout << "Save random hists: " << sc1 << endl << endl;
        save_randoms = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Save randoms not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PProtEff::InitTAPSEff()
{
    Double_t sc1;
    string config = ReadConfig("TAPS-Efficiency");
    if(sscanf( config.c_str(), "%lf\n", &sc1) == 1)
    {
        cout << "TAPS efficiency: " << sc1 << endl << endl;
        taps_eff = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "TAPS efficiency not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t  PProtEff::InitBeamPol()
{
    string config;
    Int_t instance = 0;
    Int_t time;
    Double_t meas;

    do
    {
        config = ReadConfig("Beam-Polarization",instance);

        if(sscanf( config.c_str(), "%d %lf\n", &time, &meas) == 2)
        {
            beamPolTime.push_back(time);
            beamPolMeas.push_back(meas);
            cout << "Beam polarization measurement: " << 100*meas << "% at " << time << endl;
            instance++;
        }
        else if(strcmp(config.c_str(), "nokey") != 0)
        {
            cout << "Beam polarization not set correctly" << endl;
            return kFALSE;
        }
    } while (strcmp(config.c_str(), "nokey") != 0);

    if(instance)
    {
        cir_beam = true;
	cout << endl;
    }

    Int_t sc1;
    config = ReadConfig("Linear-Pol");
    if(sscanf( config.c_str(), "%d\n", &sc1) == 1)
    {
        cout << "Use linear polarization: " << sc1 << endl << endl;
	lin_beam = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
	cout << "Linear polarization not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;
}

Bool_t  PProtEff::InitTargPol()
{
    string config;
    Int_t instance = 0;
    Int_t time1, time2;
    Double_t meas1, meas2;

    do
    {
        config = ReadConfig("Target-Polarization",instance);

        if(sscanf( config.c_str(), "%d %lf %d %lf\n", &time1, &meas1, &time2, &meas2) == 4)
        {
            targPolTime.push_back(time1);
            targPolMeas.push_back(meas1);
            targPolTime.push_back(time2);
            targPolMeas.push_back(meas2);
            cout << "Target polarization measurement: " << endl;
	    cout << "\tInitial: " << 100*meas1 << "% at " << time1 << endl;
	    cout << "\tFinal:   " << 100*meas2 << "% at " << time2 << endl;
            instance++;
        }
        else if(strcmp(config.c_str(), "nokey") != 0)
        {
            cout << "Target polarization not set correctly" << endl;
            return kFALSE;
        }
    } while (strcmp(config.c_str(), "nokey") != 0);

    if(instance) cout << endl;

    return kTRUE;
}

Bool_t 	PProtEff::InitSplitSearch()
{
    Int_t sc1;
    string config = ReadConfig("Split-Search");
    if(sscanf( config.c_str(), "%d\n", &sc1) == 1)
    {
        cout << "Search for splits: " << sc1 << endl << endl;
        split_search = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Split search not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Double_t  PProtEff::TwoBodyAngleToEnergyMin(Double_t eBeam, Double_t mTarg, Double_t mPar1, Double_t mPar2, Double_t tPar1)
{
    Double_t dX = ((eBeam*(mPar1-mTarg))-(0.5*(TMath::Power((mTarg-mPar1),2.0)))+(0.5*mPar2*mPar2));

    Double_t dA = ((TMath::Power(eBeam*TMath::Cos(tPar1*(TMath::DegToRad())),2.0))-(TMath::Power((eBeam+mTarg),2.0)));

    Double_t dB = ((2.0*mPar1*(TMath::Power(eBeam*TMath::Cos(tPar1*(TMath::DegToRad())),2.0)))-((2.0*dX*(eBeam+mTarg))));

    Double_t dC = (-dX*dX);

    Double_t dY = ((dB*dB)-(4.0*dA*dC));

    if (dA==0 || dY<0) return 0;

    Double_t dP = ((-dB+(TMath::Sqrt(dY)))/(2.0*dA));
    Double_t dM = ((-dB-(TMath::Sqrt(dY)))/(2.0*dA));
    return TMath::Min(dP,dM);
}

Double_t  PProtEff::TwoBodyAngleToEnergyMax(Double_t eBeam, Double_t mTarg, Double_t mPar1, Double_t mPar2, Double_t tPar1)
{
    Double_t dX = ((eBeam*(mPar1-mTarg))-(0.5*(TMath::Power((mTarg-mPar1),2.0)))+(0.5*mPar2*mPar2));

    Double_t dA = ((TMath::Power(eBeam*TMath::Cos(tPar1*(TMath::DegToRad())),2.0))-(TMath::Power((eBeam+mTarg),2.0)));

    Double_t dB = ((2.0*mPar1*(TMath::Power(eBeam*TMath::Cos(tPar1*(TMath::DegToRad())),2.0)))-((2.0*dX*(eBeam+mTarg))));

    Double_t dC = (-dX*dX);

    Double_t dY = ((dB*dB)-(4.0*dA*dC));

    if (dA==0 || dY<0) return 0;

    Double_t dP = ((-dB+(TMath::Sqrt(dY)))/(2.0*dA));
    Double_t dM = ((-dB-(TMath::Sqrt(dY)))/(2.0*dA));
    return TMath::Max(dP,dM);
}

Double_t  PProtEff::TwoBodyEnergyToAngle(Double_t eBeam, Double_t mTarg, Double_t mPar1, Double_t mPar2, Double_t ePar1)
{
    return ((TMath::RadToDeg())*(TMath::ACos(((ePar1*(eBeam+mTarg))+(eBeam*(mPar1-mTarg))-(0.5*(TMath::Power((mTarg-mPar1),2.0)))+(0.5*mPar2*mPar2))/(eBeam*TMath::Sqrt((ePar1*ePar1)+(2.0*ePar1*mPar1))))));
}

Double_t PProtEff::CalcCircBeamPol(Double_t E_e, Double_t P_e, Double_t E_g)
{
    Double_t P_g = P_e*(((4*E_g*E_e)-(E_g*E_g))/((4*E_e*E_e)-(4*E_g*E_e)+(3*E_g*E_g)));

    return P_g;
}

void	PProtEff::ProcessScalerRead()
{
    PPhysics::ProcessScalerRead();
}

Bool_t	PProtEff::Write()
{
    Double_t livetime = ((LiveTimeScal->GetBinContent(2))/(LiveTimeScal->GetBinContent(1)));
    Double_t counts;
    Double_t photonPol = 1;
    for (Int_t i=0; i<352; i++)
    {
        counts = TaggerAccScal->GetBinContent(i+1);
        if(beamPol < 1) photonPol = CalcCircBeamPol(450,beamPol,GetSetupParameters()->GetTaggerPhotonEnergy(i));
        CorrTaggScal->SetBinContent(i+1,(livetime*counts));
    }

    Double_t ratio = GHistBGSub::GetBackgroundSumbtractionFactor();

    if(save_randoms && !(IsMCFile()))
    {
        TH3D *Pi0_IM_MM_P = (TH3D*)Pi0_IM_MM->Clone("Pi0_IM_MM_P");

        TH3D *Pi0_MM_P = (TH3D*)Pi0_MM->Clone("Pi0_MM_P");

        TH3D *Pi0_MM_NN_P = (TH3D*)Pi0_MM_NN->Clone("Pi0_MM_NN_P");
        TH3D *Pi0_MM_NC_P = (TH3D*)Pi0_MM_NC->Clone("Pi0_MM_NC_P");
        TH3D *Pi0_MM_CC_P = (TH3D*)Pi0_MM_CC->Clone("Pi0_MM_CC_P");

        TH3D *Pi0_MM_XXN_P = (TH3D*)Pi0_MM_XXN->Clone("Pi0_MM_XXN_P");
        TH3D *Pi0_MM_XXC_P = (TH3D*)Pi0_MM_XXC->Clone("Pi0_MM_XXC_P");
        TH3D *Pi0_MM_XXW_P = (TH3D*)Pi0_MM_XXW->Clone("Pi0_MM_XXW_P");

        TH3D *Pi0_MM_NNS_P = (TH3D*)Pi0_MM_NNS->Clone("Pi0_MM_NNS_P");
        TH3D *Pi0_MM_NCS_P = (TH3D*)Pi0_MM_NCS->Clone("Pi0_MM_NCS_P");
        TH3D *Pi0_MM_CCS_P = (TH3D*)Pi0_MM_CCS->Clone("Pi0_MM_CCS_P");

        TH3D *Pi0_MM_XXSN_P = (TH3D*)Pi0_MM_XXSN->Clone("Pi0_MM_XXSN_P");
        TH3D *Pi0_MM_XXSC_P = (TH3D*)Pi0_MM_XXSC->Clone("Pi0_MM_XXSC_P");
        TH3D *Pi0_MM_XXSW_P = (TH3D*)Pi0_MM_XXSW->Clone("Pi0_MM_XXSW_P");

        TH3D *Pi0_Sp_IM_MM_P = (TH3D*)Pi0_Sp_IM_MM->Clone("Pi0_Sp_IM_MM_P");

        TH3D *Pi0_Re_All_P = (TH3D*)Pi0_Re_All->Clone("Pi0_Re_All_P");
        TH3D *Pi0_Re_Det_P = (TH3D*)Pi0_Re_Det->Clone("Pi0_Re_Det_P");
        TH3D *Pi0_Re_Dif_P = (TH3D*)Pi0_Re_Dif->Clone("Pi0_Re_Dif_P");
        TH3D *Pi0_Re_NoE_P = (TH3D*)Pi0_Re_NoE->Clone("Pi0_Re_NoE_P");

        TH3D *Pi0_Re_dT_Det_P = (TH3D*)Pi0_Re_dT_Det->Clone("Pi0_Re_dT_Det_P");
        TH3D *Pi0_Re_dT_NoE_P = (TH3D*)Pi0_Re_dT_NoE->Clone("Pi0_Re_dT_NoE_P");

        TH3D *Pi0_Re_OA_P = (TH3D*)Pi0_Re_OA->Clone("Pi0_Re_OA_P");
        TH3D *Pi0_Re_OA_Cut_P = (TH3D*)Pi0_Re_OA_Cut->Clone("Pi0_Re_OA_Cut_P");

        Pi0_IM_MM_P->Write();

        Pi0_MM_P->Write();

        Pi0_MM_NN_P->Write();
        Pi0_MM_NC_P->Write();
        Pi0_MM_CC_P->Write();

        Pi0_MM_XXN_P->Write();
        Pi0_MM_XXC_P->Write();
        Pi0_MM_XXW_P->Write();

        Pi0_MM_NNS_P->Write();
        Pi0_MM_NCS_P->Write();
        Pi0_MM_CCS_P->Write();

        Pi0_MM_XXSN_P->Write();
        Pi0_MM_XXSC_P->Write();
        Pi0_MM_XXSW_P->Write();

        Pi0_Sp_IM_MM_P->Write();

        Pi0_Re_All_P->Write();
        Pi0_Re_Det_P->Write();
        Pi0_Re_Dif_P->Write();
        Pi0_Re_NoE_P->Write();

        Pi0_Re_dT_Det_P->Write();
        Pi0_Re_dT_NoE_P->Write();

        Pi0_Re_OA_P->Write();
        Pi0_Re_OA_Cut_P->Write();

        delete Pi0_IM_MM_P;

        delete Pi0_MM_P;

        delete Pi0_MM_NN_P;
        delete Pi0_MM_NC_P;
        delete Pi0_MM_CC_P;

        delete Pi0_MM_XXN_P;
        delete Pi0_MM_XXC_P;
        delete Pi0_MM_XXW_P;

        delete Pi0_MM_NNS_P;
        delete Pi0_MM_NCS_P;
        delete Pi0_MM_CCS_P;

        delete Pi0_MM_XXSN_P;
        delete Pi0_MM_XXSC_P;
        delete Pi0_MM_XXSW_P;

        delete Pi0_Sp_IM_MM_P;

        delete Pi0_Re_All_P;
        delete Pi0_Re_Det_P;
        delete Pi0_Re_Dif_P;
        delete Pi0_Re_NoE_P;

        delete Pi0_Re_dT_Det_P;
        delete Pi0_Re_dT_NoE_P;

        delete Pi0_Re_OA_P;
        delete Pi0_Re_OA_Cut_P;
    }

    if(!(IsMCFile()))
    {
        Pi0_IM_MM->Sumw2();
        Pi0_IM_MM->Add(Pi0_IM_MM_R,-ratio);

        Pi0_MM->Sumw2();
        Pi0_MM->Add(Pi0_MM_R,-ratio);

        Pi0_MM_NN->Sumw2();
        Pi0_MM_NN->Add(Pi0_MM_NN_R,-ratio);
        Pi0_MM_NC->Sumw2();
        Pi0_MM_NC->Add(Pi0_MM_NC_R,-ratio);
        Pi0_MM_CC->Sumw2();
        Pi0_MM_CC->Add(Pi0_MM_CC_R,-ratio);

        Pi0_MM_XXN->Sumw2();
        Pi0_MM_XXN->Add(Pi0_MM_XXN_R,-ratio);
        Pi0_MM_XXC->Sumw2();
        Pi0_MM_XXC->Add(Pi0_MM_XXC_R,-ratio);
        Pi0_MM_XXW->Sumw2();
        Pi0_MM_XXW->Add(Pi0_MM_XXW_R,-ratio);

        Pi0_MM_NNS->Sumw2();
        Pi0_MM_NNS->Add(Pi0_MM_NNS_R,-ratio);
        Pi0_MM_NCS->Sumw2();
        Pi0_MM_NCS->Add(Pi0_MM_NCS_R,-ratio);
        Pi0_MM_CCS->Sumw2();
        Pi0_MM_CCS->Add(Pi0_MM_CCS_R,-ratio);

        Pi0_MM_XXSN->Sumw2();
        Pi0_MM_XXSN->Add(Pi0_MM_XXSN_R,-ratio);
        Pi0_MM_XXSC->Sumw2();
        Pi0_MM_XXSC->Add(Pi0_MM_XXSC_R,-ratio);
        Pi0_MM_XXSW->Sumw2();
        Pi0_MM_XXSW->Add(Pi0_MM_XXSW_R,-ratio);

        Pi0_Sp_IM_MM->Sumw2();
        Pi0_Sp_IM_MM->Add(Pi0_Sp_IM_MM_R,-ratio);

        Pi0_Re_All->Sumw2();
        Pi0_Re_All->Add(Pi0_Re_All_R,-ratio);
        Pi0_Re_Det->Sumw2();
        Pi0_Re_Det->Add(Pi0_Re_Det_R,-ratio);
        Pi0_Re_Dif->Sumw2();
        Pi0_Re_Dif->Add(Pi0_Re_Dif_R,-ratio);
        Pi0_Re_NoE->Sumw2();
        Pi0_Re_NoE->Add(Pi0_Re_NoE_R,-ratio);

        Pi0_Re_dT_Det->Sumw2();
        Pi0_Re_dT_Det->Add(Pi0_Re_dT_Det_R,-ratio);
        Pi0_Re_dT_NoE->Sumw2();
        Pi0_Re_dT_NoE->Add(Pi0_Re_dT_NoE_R,-ratio);

        Pi0_Re_OA->Sumw2();
        Pi0_Re_OA->Add(Pi0_Re_OA_R,-ratio);
        Pi0_Re_OA_Cut->Sumw2();
        Pi0_Re_OA_Cut->Add(Pi0_Re_OA_Cut_R,-ratio);
    }

    if(save_randoms && !(IsMCFile()))
    {
        Pi0_IM_MM_R->Write();

        Pi0_MM_R->Write();

        Pi0_MM_NN_R->Write();
        Pi0_MM_NC_R->Write();
        Pi0_MM_CC_R->Write();

        Pi0_MM_XXN_R->Write();
        Pi0_MM_XXC_R->Write();
        Pi0_MM_XXW_R->Write();

        Pi0_MM_NNS_R->Write();
        Pi0_MM_NCS_R->Write();
        Pi0_MM_CCS_R->Write();

        Pi0_MM_XXSN_R->Write();
        Pi0_MM_XXSC_R->Write();
        Pi0_MM_XXSW_R->Write();

        Pi0_Sp_IM_MM_R->Write();

        Pi0_Re_All_R->Write();
        Pi0_Re_Det_R->Write();
        Pi0_Re_Dif_R->Write();
        Pi0_Re_NoE_R->Write();

        Pi0_Re_dT_Det_R->Write();
        Pi0_Re_dT_NoE_R->Write();

        Pi0_Re_OA_R->Write();
        Pi0_Re_OA_Cut_R->Write();
    }

    delete Pi0_IM_MM_R;

    delete Pi0_MM_R;

    delete Pi0_MM_NN_R;
    delete Pi0_MM_NC_R;
    delete Pi0_MM_CC_R;

    delete Pi0_MM_XXN_R;
    delete Pi0_MM_XXC_R;
    delete Pi0_MM_XXW_R;

    delete Pi0_MM_NNS_R;
    delete Pi0_MM_NCS_R;
    delete Pi0_MM_CCS_R;

    delete Pi0_MM_XXSN_R;
    delete Pi0_MM_XXSC_R;
    delete Pi0_MM_XXSW_R;

    delete Pi0_Sp_IM_MM_R;

    delete Pi0_Re_All_R;
    delete Pi0_Re_Det_R;
    delete Pi0_Re_Dif_R;
    delete Pi0_Re_NoE_R;

    delete Pi0_Re_dT_Det_R;
    delete Pi0_Re_dT_NoE_R;

    delete Pi0_Re_OA_R;
    delete Pi0_Re_OA_Cut_R;

    // Write all GH1's and TObjects defined in this class
    if(!(GTreeManager::Write())) return false;

    return true;
}
