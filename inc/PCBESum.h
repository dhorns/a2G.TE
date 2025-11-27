#ifndef _PCBESum_h__
#define _PCBESum_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"
#include "TF1.h"
#include "TRandom3.h"

class	PCBESum  : public PPhysics
{
private:
    TH1*     h1_Raw_Sum;
    TH2*     h2_Raw_Max;
    TH2*     h2_Max_Sum;
    TH2*     h2_NADCs_Rat;

    Int_t    n_Tot_Chan;
    Double_t d_Max_Ratio;

    Bool_t  firstEvent;

protected:
    virtual Bool_t Start();
    virtual void ProcessEvent();
    virtual void ProcessScalerRead();
    virtual Bool_t Write();

public:
    PCBESum();
    virtual ~PCBESum();
    virtual Bool_t Init();
    Bool_t InitEnergySum();

};
#endif
