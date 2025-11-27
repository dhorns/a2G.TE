#include "PScalers.h"

PScalers::PScalers()
{
    CorrTaggScal = new TH1D("CorrTaggScal", "Livetime corrected tagger scalers;Tagger Channel;LT*Scaler", 352, 0, 352);
    PolarizeScal = new TH1D("PolarizeScal", "Livetime and polarization corrected tagger scalers;Tagger Channel;LT*Pt*Pg*Scaler", 352, 0, 352);
}

PScalers::~PScalers()
{
}

Bool_t	PScalers::Init()
{
    cout << "Initialising physics analysis..." << endl;
    cout << "--------------------------------------------------" << endl << endl;

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

Bool_t	PScalers::Start()
{
    if(!IsGoATFile())
    {
        cout << "ERROR: Input File is not an Acqu file." << endl;
        return kFALSE;
    }
    SetAsPhysicsFile();

    TraverseValidEvents();

    //GoosyTagger(TaggerAccScal);
    //GoosyVuprom(TaggerAccScal);
    GoosyNewFPDRecabled(TaggerAccScal);

    return kTRUE;
}

void	PScalers::ProcessEvent()
{
}

void	PScalers::ProcessScalerRead()
{
    PPhysics::ProcessScalerRead();
}

Bool_t	PScalers::Write()
{
    Double_t livetime = ((LiveTimeScal->GetBinContent(2))/(LiveTimeScal->GetBinContent(1)));
    Double_t counts;
    Double_t targPol = 1;
    Double_t photonPol = 1;
    for (Int_t i=0; i<352; i++)
    {
      counts = TaggerAccScal->GetBinContent(i+1);
      //if(beamPol < 1) photonPol = CalcCircBeamPol(450,beamPol,GetSetupParameters()->GetTaggerPhotonEnergy(i));
      CorrTaggScal->SetBinContent(i+1,(livetime*counts));
      PolarizeScal->SetBinContent(i+1,(livetime*targPol*photonPol*counts));
    }

    // Write all GH1's and TObjects defined in this class
    if(!(GTreeManager::Write())) return false;

    return true;
}
