#ifndef _PScalers_h__
#define _PScalers_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"
#include "TF1.h"

class	PScalers  : public PPhysics
{
private:
    TH1*    TaggerAccScal;
    TH1*    LiveTimeScal;
    TH1*    CorrTaggScal;
    TH1*    PolarizeScal;

protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void    ProcessScalerRead();
    virtual Bool_t  Write();
			
public:
    PScalers();
    virtual ~PScalers();
    virtual Bool_t  Init();

};
#endif
