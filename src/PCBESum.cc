#include "PCBESum.h"

PCBESum::PCBESum()
{
    h1_Raw_Sum = new TH1D("h1_Raw_Sum", "Sum of Raw Values;Raw Sum", 20000, 0, 20000);
    h2_Raw_Max = new TH2D("h2_Raw_Max", "Raw Value of Max Channel;Raw Max;Max Channel", 4096, 0, 4096, 720, 0, 720);
    h2_Max_Sum = new TH2D("h2_Max_Sum", "Raw Value of Max Channel;Raw Sum;Max Channel", 4096, 0, 4096, 720, 0, 720);
    h2_NADCs_Rat = new TH2D("h2_NADCs_Rat", "Ratio of Max Channel vs Number of ADCs;Number of ADCs;Max/Sum", 180, 0, 180, 100, 0, 1);

    n_Tot_Chan = 3;
    d_Max_Ratio = 0.9;

    firstEvent = true;
}

PCBESum::~PCBESum()
{
}

Bool_t	PCBESum::Init()
{
    cout << "Initialising physics analysis..." << endl;
    cout << "--------------------------------------------------" << endl << endl;

    if(!InitEnergySum()) return kFALSE;

    if(!PPhysics::Init()) return kFALSE;

    cout << "--------------------------------------------------" << endl;
    return kTRUE;
}

Bool_t	PCBESum::Start()
{
    if(!IsAcquFile())
    {
        cout << "ERROR: Input File is not an Acqu file." << endl;
        return kFALSE;
    }
    SetAsGoATFile();

    TraverseValidEvents();

    return kTRUE;
}

void	PCBESum::ProcessEvent()
{
    //////////////////////////////////////////////////
    // Read in polarization info on first event
    //////////////////////////////////////////////////
    if (firstEvent)
    {
        firstEvent = false;
    }

    if (GetEventNumber()%100000 == 0) cout << "Event " << GetEventNumber() << endl;

    //////////////////////////////////////////////////
    // Reject events from non ESum triggers
    //////////////////////////////////////////////////
    Bool_t b_Reject = true;
    for (Int_t i=0; i<(GetTrigger()->GetNTriggerPattern()); i++)
    {
        if ((GetTrigger()->GetTriggerPattern(i)) == 16) b_Reject = false;
    }
    if (b_Reject) return;

    //////////////////////////////////////////////////
    // Reject events below energy sum cut
    //////////////////////////////////////////////////
    //if (GetTrigger()->GetEnergySum() < ESCut) return;

    //////////////////////////////////////////////////
    // Event weighting for MC
    //////////////////////////////////////////////////
    //Float_t event_weight = 1;
    //if (IsMCFile()) event_weight = GetTrigger()->GetMCWeight();

    Int_t i_Raw, i_Raw_Sum = 0, i_Raw_Max = 0, i_Chan;

    for (Int_t i=0; i<(GetDetectorHits()->GetNNaIADCs()); i++)
    {
        //cout << GetEventNumber() << "\t" << i << "\t" << GetDetectorHits()->GetNaIADCs(i) << "\t" << GetDetectorHits()->GetNaIADCsRaw(GetDetectorHits()->GetNaIADCs(i)) << endl;
        i_Raw = GetDetectorHits()->GetNaIADCsRaw(GetDetectorHits()->GetNaIADCs(i));
        i_Raw_Sum += i_Raw;
        if (i_Raw > i_Raw_Max)
        {
            i_Raw_Max = i_Raw;
            i_Chan = GetDetectorHits()->GetNaIADCs(i);
        }
    }

    h1_Raw_Sum->Fill(i_Raw_Sum);
    if (((GetDetectorHits()->GetNNaIADCs()) <= n_Tot_Chan) && (i_Raw_Max >= (d_Max_Ratio * i_Raw_Sum)))
    {
        h2_Raw_Max->Fill(i_Raw_Max, i_Chan);
        h2_Max_Sum->Fill(i_Raw_Sum, i_Chan);
        if (i_Raw_Max < 2000) cout << GetEventNumber() << "\t" << i_Chan << "\t" << i_Raw_Max << "\t" << i_Raw_Sum << endl;
    }
    if (i_Raw_Sum > 0) h2_NADCs_Rat->Fill(GetDetectorHits()->GetNNaIADCs(), (1.0*i_Raw_Max)/i_Raw_Sum);

}

//////////////////////////////////////////////////
// Energy sum stuff
//////////////////////////////////////////////////
Bool_t 	PCBESum::InitEnergySum()
{
    Int_t sc1;
    Double_t sc2;
    string config = ReadConfig("Energy-Sum");
    if(sscanf( config.c_str(), "%d %lf\n", &sc1, &sc2) == 2)
    {
        cout << "Setting energy sum: Max of " << sc1 << " ADCs, with a ratio up to " << sc2 << endl << endl;
        n_Tot_Chan = sc1;
        d_Max_Ratio = sc2;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Energy sum not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

//////////////////////////////////////////////////
// Individual scaler read stuff
//////////////////////////////////////////////////
void	PCBESum::ProcessScalerRead()
{
    PPhysics::ProcessScalerRead();
}

//////////////////////////////////////////////////
// Process histograms, prompt/random subtraction
//////////////////////////////////////////////////
Bool_t	PCBESum::Write()
{

    // Write all GH1's and TObjects defined in this class
    if(!(GTreeManager::Write())) return false;

    return true;
}
