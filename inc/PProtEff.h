#ifndef _PProtEff_h__
#define _PProtEff_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"
#include "TF1.h"
#include "TRandom3.h"

class	PProtEff  : public PPhysics
{
private:
    TH1*	TaggerAccScal;
    TH1*	LiveTimeScal;

    TH1*    CorrTaggScal;
    TH1*    Helicity;

    TH2*    Pi0_IM;

    TH2*    Pi0_IM_NN;
    TH2*    Pi0_IM_NC;
    TH2*    Pi0_IM_CC;

    TH2*    Pi0_IM_XXN;
    TH2*    Pi0_IM_XXC;
    TH2*    Pi0_IM_XXW;

    TH2*    Pi0_IM_NNS;
    TH2*    Pi0_IM_NCS;
    TH2*    Pi0_IM_CCS;

    TH2*    Pi0_IM_XXSN;
    TH2*    Pi0_IM_XXSC;
    TH2*    Pi0_IM_XXSW;

    TH2*    Split_OA_E;

    TH2*	Pi0_Dt;
    TH2*	Pi0_Dt_NN;

    TH3*        Pi0_IM_MM;
    TH3*        Pi0_IM_MM_R;

    TH3*        Pi0_MM;
    TH3*        Pi0_MM_R;

    TH3*        Pi0_MM_NN;
    TH3*        Pi0_MM_NN_R;
    TH3*        Pi0_MM_NC;
    TH3*        Pi0_MM_NC_R;
    TH3*        Pi0_MM_CC;
    TH3*        Pi0_MM_CC_R;

    TH3*        Pi0_MM_XXN;
    TH3*        Pi0_MM_XXN_R;
    TH3*        Pi0_MM_XXC;
    TH3*        Pi0_MM_XXC_R;
    TH3*        Pi0_MM_XXW;
    TH3*        Pi0_MM_XXW_R;

    TH3*        Pi0_MM_NNS;
    TH3*        Pi0_MM_NNS_R;
    TH3*        Pi0_MM_NCS;
    TH3*        Pi0_MM_NCS_R;
    TH3*        Pi0_MM_CCS;
    TH3*        Pi0_MM_CCS_R;

    TH3*        Pi0_MM_XXSN;
    TH3*        Pi0_MM_XXSN_R;
    TH3*        Pi0_MM_XXSC;
    TH3*        Pi0_MM_XXSC_R;
    TH3*        Pi0_MM_XXSW;
    TH3*        Pi0_MM_XXSW_R;

    TH3*        Pi0_Sp_IM_MM;
    TH3*        Pi0_Sp_IM_MM_R;

    TH3*        Pi0_Re_All;
    TH3*        Pi0_Re_All_R;
    TH3*        Pi0_Re_Det;
    TH3*        Pi0_Re_Det_R;
    TH3*        Pi0_Re_Dif;
    TH3*        Pi0_Re_Dif_R;
    TH3*        Pi0_Re_NoE;
    TH3*        Pi0_Re_NoE_R;

    TH3*        Pi0_Re_dT_Det;
    TH3*        Pi0_Re_dT_Det_R;
    TH3*        Pi0_Re_dT_NoE;
    TH3*        Pi0_Re_dT_NoE_R;

    TH1*        Pi0_Re_CA;

    TH3*        Pi0_Re_OA;
    TH3*        Pi0_Re_OA_R;
    TH3*        Pi0_Re_OA_Cut;
    TH3*        Pi0_Re_OA_Cut_R;

    Int_t    verbosity;
    Bool_t   excl_pi0;
    Bool_t   excl_pro;

    Double_t IMCut;
    Double_t MMLoC;
    Double_t MMHiC;
    Double_t OACut;
    Double_t ESCut;

    Bool_t   save_randoms;
    Bool_t   split_search;

    Double_t taps_eff;
    std::vector<Bool_t> ignoreTrack;

    Bool_t cir_beam;
    Bool_t lin_beam;
    Double_t beamPol;
    std::vector<Int_t> beamPolTime;
    std::vector<Double_t> beamPolMeas;

    Double_t targPol;
    std::vector<Int_t> targPolTime;
    std::vector<Double_t> targPolMeas;

    Bool_t firstEvent;

protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void	ProcessScalerRead();
    virtual Bool_t    Write();
			
public:
    PProtEff();
    virtual ~PProtEff();
    virtual Bool_t  Init();
    Bool_t InitVerbosity();
    Bool_t InitExclusivity();
    Bool_t InitInvariantMass();
    Bool_t InitMissingMass();
    Bool_t InitOpeningAngle();
    Bool_t InitEnergySum();
    Bool_t InitSaveRandoms();
    Bool_t InitTAPSEff();
    Bool_t InitBeamPol();
    Bool_t InitTargPol();
    Bool_t InitSplitSearch();
    Double_t TwoBodyAngleToEnergyMin(Double_t eBeam, Double_t mTarg, Double_t mPar1, Double_t mPar2, Double_t tPar1);
    Double_t TwoBodyAngleToEnergyMax(Double_t eBeam, Double_t mTarg, Double_t mPar1, Double_t mPar2, Double_t tPar1);
    Double_t TwoBodyEnergyToAngle(Double_t eBeam, Double_t mTarg, Double_t mPar1, Double_t mPar2, Double_t ePar1);
    Double_t CalcCircBeamPol(Double_t E_e, Double_t P_e, Double_t E_g);

};
#endif
