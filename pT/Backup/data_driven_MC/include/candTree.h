//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb 21 21:47:00 2017 by ROOT version 6.06/00
// from TTree candTree/Event Summary
// found on file: root://lxcms03//data3/Higgs/170203/AllData/ZZ4lAnalysis.root
//////////////////////////////////////////////////////////

#ifndef candTree_h
#define candTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

using namespace std;
class candTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           RunNumber;
   Long64_t        EventNumber;
   Int_t           LumiNumber;
   Short_t         NRecoMu;
   Short_t         NRecoEle;
   Short_t         Nvtx;
   Short_t         NObsInt;
   Float_t         NTrueInt;
   Float_t         PFMET;
   Float_t         PFMETPhi;
   Float_t         PFMETNoHF;
   Float_t         PFMETNoHFPhi;
   Short_t         nCleanedJets;
   Short_t         nCleanedJetsPt30;
   Short_t         nCleanedJetsPt30_jecUp;
   Short_t         nCleanedJetsPt30_jecDn;
   Short_t         nCleanedJetsPt30BTagged;
   Short_t         nCleanedJetsPt30BTagged_bTagSF;
   Short_t         nCleanedJetsPt30BTagged_bTagSFUp;
   Short_t         nCleanedJetsPt30BTagged_bTagSFDn;
   Short_t         trigWord;
   Float_t         ZZMass;
   Float_t         ZZMassErr;
   Float_t         ZZMassErrCorr;
   Float_t         ZZMassPreFSR;
   Short_t         ZZsel;
   Float_t         ZZPt;
   Float_t         ZZEta;
   Float_t         ZZPhi;
   Int_t           CRflag;
   Float_t         Z1Mass;
   Float_t         Z1Pt;
   Short_t         Z1Flav;
   Float_t         ZZMassRefit;
   Float_t         ZZMassRefitErr;
   Float_t         ZZMassUnrefitErr;
   Float_t         Z2Mass;
   Float_t         Z2Pt;
   Short_t         Z2Flav;
   Float_t         costhetastar;
   Float_t         helphi;
   Float_t         helcosthetaZ1;
   Float_t         helcosthetaZ2;
   Float_t         phistarZ1;
   Float_t         phistarZ2;
   Float_t         xi;
   Float_t         xistar;
   vector<float>   *LepPt;
   vector<float>   *LepEta;
   vector<float>   *LepPhi;
   vector<short>   *LepLepId;
   vector<float>   *LepSIP;
   vector<float>   *LepTime;
   vector<bool>    *LepisID;
   vector<short>   *LepisLoose;
   vector<float>   *LepBDT;
   vector<char>    *LepMissingHit;
   vector<float>   *LepCombRelIsoPF;
   vector<float>   *fsrPt;
   vector<float>   *fsrEta;
   vector<float>   *fsrPhi;
   vector<short>   *fsrLept;
   Bool_t          passIsoPreFSR;
   vector<float>   *JetPt;
   vector<float>   *JetEta;
   vector<float>   *JetPhi;
   vector<float>   *JetMass;
   vector<float>   *JetBTagger;
   vector<float>   *JetIsBtagged;
   vector<float>   *JetIsBtaggedWithSF;
   vector<float>   *JetIsBtaggedWithSFUp;
   vector<float>   *JetIsBtaggedWithSFDn;
   vector<float>   *JetQGLikelihood;
   vector<float>   *JetAxis2;
   vector<float>   *JetMult;
   vector<float>   *JetPtD;
   vector<float>   *JetSigma;
   vector<short>   *JetHadronFlavour;
   vector<short>   *JetPartonFlavour;
   vector<float>   *JetJERUp;
   vector<float>   *JetJERDown;
   vector<short>   *JetPUID;
   vector<float>   *JetPUValue;
   Float_t         DiJetMass;
   Float_t         DiJetDEta;
   Float_t         DiJetFisher;
   Short_t         nExtraLep;
   Short_t         nExtraZ;
   vector<float>   *ExtraLepPt;
   vector<float>   *ExtraLepEta;
   vector<float>   *ExtraLepPhi;
   vector<short>   *ExtraLepLepId;
   Float_t         ZXFakeweight;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghza2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghza4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_gha2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_gha4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen;
   Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal;
   Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECNominal;
   Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal;
   Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal;
   Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal;
   Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal;
   Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal;
   Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal;
   Float_t         p_bbH_SIG_kappa_1_JHUGen_JECNominal;
   Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp;
   Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECUp;
   Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECUp;
   Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECUp;
   Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp;
   Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp;
   Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp;
   Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp;
   Float_t         p_bbH_SIG_kappa_1_JHUGen_JECUp;
   Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn;
   Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECDn;
   Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECDn;
   Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECDn;
   Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn;
   Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn;
   Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn;
   Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn;
   Float_t         p_bbH_SIG_kappa_1_JHUGen_JECDn;
   Float_t         p_LepZH_SIG_ghz1_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghz2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghza1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghza2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghza4_1_JHUGen;
   Float_t         p_LepZH_SIG_gha2_1_JHUGen;
   Float_t         p_LepZH_SIG_gha4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_gha2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_gha4_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1prime2_1E4_JHUGen;
   Float_t         p_LepWH_SIG_ghw2_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw4_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen;
   Float_t         p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen;
   Float_t         p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gZPz1_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gZPz2_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz1_1_JHUGen;
   Float_t         p_GG_SIG_gXg2_1_gXz2_1_JHUGen;
   Float_t         p_GG_SIG_gXg3_1_gXz3_1_JHUGen;
   Float_t         p_GG_SIG_gXg4_1_gXz4_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz5_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz6_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz7_1_JHUGen;
   Float_t         p_GG_SIG_gXg5_1_gXz8_1_JHUGen;
   Float_t         p_GG_SIG_gXg5_1_gXz9_1_JHUGen;
   Float_t         p_GG_SIG_gXg5_1_gXz10_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz1_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz2_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz3_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz4_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz5_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz6_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz7_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz8_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz9_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz10_1_JHUGen;
   Float_t         pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;
   Float_t         p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;
   Float_t         p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;
   Float_t         p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;
   Float_t         pConst_GG_BKG_MCFM;
   Float_t         p_GG_BKG_MCFM;
   Float_t         pConst_QQB_BKG_MCFM;
   Float_t         p_QQB_BKG_MCFM;
   Float_t         p_ZJJ_BKG_MCFM;
   Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECNominal;
   Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECNominal;
   Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECNominal;
   Float_t         p_JJEW_BKG_MCFM_JECNominal;
   Float_t         p_JJVBF_BKG_MCFM_JECNominal;
   Float_t         p_JJQCD_BKG_MCFM_JECNominal;
   Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECUp;
   Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECUp;
   Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECUp;
   Float_t         p_JJEW_BKG_MCFM_JECUp;
   Float_t         p_JJVBF_BKG_MCFM_JECUp;
   Float_t         p_JJQCD_BKG_MCFM_JECUp;
   Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECDn;
   Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECDn;
   Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECDn;
   Float_t         p_JJEW_BKG_MCFM_JECDn;
   Float_t         p_JJVBF_BKG_MCFM_JECDn;
   Float_t         p_JJQCD_BKG_MCFM_JECDn;
   Float_t         p_m4l_SIG;
   Float_t         p_m4l_BKG;
   Float_t         p_m4l_SIG_ScaleDown;
   Float_t         p_m4l_BKG_ScaleDown;
   Float_t         p_m4l_SIG_ResDown;
   Float_t         p_m4l_BKG_ResDown;
   Float_t         p_m4l_SIG_ScaleUp;
   Float_t         p_m4l_BKG_ScaleUp;
   Float_t         p_m4l_SIG_ResUp;
   Float_t         p_m4l_BKG_ResUp;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_LumiNumber;   //!
   TBranch        *b_NRecoMu;   //!
   TBranch        *b_NRecoEle;   //!
   TBranch        *b_Nvtx;   //!
   TBranch        *b_NObsInt;   //!
   TBranch        *b_NTrueInt;   //!
   TBranch        *b_PFMET;   //!
   TBranch        *b_PFMETPhi;   //!
   TBranch        *b_PFMETNoHF;   //!
   TBranch        *b_PFMETNoHFPhi;   //!
   TBranch        *b_nCleanedJets;   //!
   TBranch        *b_nCleanedJetsPt30;   //!
   TBranch        *b_nCleanedJetsPt30_jecUp;   //!
   TBranch        *b_nCleanedJetsPt30_jecDn;   //!
   TBranch        *b_nCleanedJetsPt30BTagged;   //!
   TBranch        *b_nCleanedJetsPt30BTagged_bTagSF;   //!
   TBranch        *b_nCleanedJetsPt30BTagged_bTagSFUp;   //!
   TBranch        *b_nCleanedJetsPt30BTagged_bTagSFDn;   //!
   TBranch        *b_trigWord;   //!
   TBranch        *b_ZZMass;   //!
   TBranch        *b_ZZMassErr;   //!
   TBranch        *b_ZZMassErrCorr;   //!
   TBranch        *b_ZZMassPreFSR;   //!
   TBranch        *b_ZZsel;   //!
   TBranch        *b_ZZPt;   //!
   TBranch        *b_ZZEta;   //!
   TBranch        *b_ZZPhi;   //!
   TBranch        *b_CRflag;   //!
   TBranch        *b_Z1Mass;   //!
   TBranch        *b_Z1Pt;   //!
   TBranch        *b_Z1Flav;   //!
   TBranch        *b_ZZMassRefit;   //!
   TBranch        *b_ZZMassRefitErr;   //!
   TBranch        *b_ZZMassUnrefitErr;   //!
   TBranch        *b_Z2Mass;   //!
   TBranch        *b_Z2Pt;   //!
   TBranch        *b_Z2Flav;   //!
   TBranch        *b_costhetastar;   //!
   TBranch        *b_helphi;   //!
   TBranch        *b_helcosthetaZ1;   //!
   TBranch        *b_helcosthetaZ2;   //!
   TBranch        *b_phistarZ1;   //!
   TBranch        *b_phistarZ2;   //!
   TBranch        *b_xi;   //!
   TBranch        *b_xistar;   //!
   TBranch        *b_LepPt;   //!
   TBranch        *b_LepEta;   //!
   TBranch        *b_LepPhi;   //!
   TBranch        *b_LepLepId;   //!
   TBranch        *b_LepSIP;   //!
   TBranch        *b_LepTime;   //!
   TBranch        *b_LepisID;   //!
   TBranch        *b_LepisLoose;   //!
   TBranch        *b_LepBDT;   //!
   TBranch        *b_LepMissingHit;   //!
   TBranch        *b_LepCombRelIsoPF;   //!
   TBranch        *b_fsrPt;   //!
   TBranch        *b_fsrEta;   //!
   TBranch        *b_fsrPhi;   //!
   TBranch        *b_fsrLept;   //!
   TBranch        *b_passIsoPreFSR;   //!
   TBranch        *b_JetPt;   //!
   TBranch        *b_JetEta;   //!
   TBranch        *b_JetPhi;   //!
   TBranch        *b_JetMass;   //!
   TBranch        *b_JetBTagger;   //!
   TBranch        *b_JetIsBtagged;   //!
   TBranch        *b_JetIsBtaggedWithSF;   //!
   TBranch        *b_JetIsBtaggedWithSFUp;   //!
   TBranch        *b_JetIsBtaggedWithSFDn;   //!
   TBranch        *b_JetQGLikelihood;   //!
   TBranch        *b_JetAxis2;   //!
   TBranch        *b_JetMult;   //!
   TBranch        *b_JetPtD;   //!
   TBranch        *b_JetSigma;   //!
   TBranch        *b_JetHadronFlavour;   //!
   TBranch        *b_JetPartonFlavour;   //!
   TBranch        *b_JetJERUp;   //!
   TBranch        *b_JetJERDown;   //!
   TBranch        *b_JetPUID;   //!
   TBranch        *b_JetPUValue;   //!
   TBranch        *b_DiJetMass;   //!
   TBranch        *b_DiJetDEta;   //!
   TBranch        *b_DiJetFisher;   //!
   TBranch        *b_nExtraLep;   //!
   TBranch        *b_nExtraZ;   //!
   TBranch        *b_ExtraLepPt;   //!
   TBranch        *b_ExtraLepEta;   //!
   TBranch        *b_ExtraLepPhi;   //!
   TBranch        *b_ExtraLepLepId;   //!
   TBranch        *b_ZXFakeweight;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghza2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghza4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_gha2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_gha4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen;   //!
   TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECNominal;   //!
   TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp;   //!
   TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECUp;   //!
   TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn;   //!
   TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECDn;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghza2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghza4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_gha2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_gha4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_gha2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_gha4_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw2_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw4_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gZPz1_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gZPz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz1_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg2_1_gXz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg3_1_gXz3_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg4_1_gXz4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz6_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz7_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg5_1_gXz8_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg5_1_gXz9_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg5_1_gXz10_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz1_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz2_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz3_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz4_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz5_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz6_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz7_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz8_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz9_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz10_1_JHUGen;   //!
   TBranch        *b_pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;   //!
   TBranch        *b_p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;   //!
   TBranch        *b_p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;   //!
   TBranch        *b_p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;   //!
   TBranch        *b_pConst_GG_BKG_MCFM;   //!
   TBranch        *b_p_GG_BKG_MCFM;   //!
   TBranch        *b_pConst_QQB_BKG_MCFM;   //!
   TBranch        *b_p_QQB_BKG_MCFM;   //!
   TBranch        *b_p_ZJJ_BKG_MCFM;   //!
   TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_BKG_MCFM_JECNominal;   //!
   TBranch        *b_p_JJVBF_BKG_MCFM_JECNominal;   //!
   TBranch        *b_p_JJQCD_BKG_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_BKG_MCFM_JECUp;   //!
   TBranch        *b_p_JJVBF_BKG_MCFM_JECUp;   //!
   TBranch        *b_p_JJQCD_BKG_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECDn;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECDn;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECDn;   //!
   TBranch        *b_p_JJEW_BKG_MCFM_JECDn;   //!
   TBranch        *b_p_JJVBF_BKG_MCFM_JECDn;   //!
   TBranch        *b_p_JJQCD_BKG_MCFM_JECDn;   //!
   TBranch        *b_p_m4l_SIG;   //!
   TBranch        *b_p_m4l_BKG;   //!
   TBranch        *b_p_m4l_SIG_ScaleDown;   //!
   TBranch        *b_p_m4l_BKG_ScaleDown;   //!
   TBranch        *b_p_m4l_SIG_ResDown;   //!
   TBranch        *b_p_m4l_BKG_ResDown;   //!
   TBranch        *b_p_m4l_SIG_ScaleUp;   //!
   TBranch        *b_p_m4l_BKG_ScaleUp;   //!
   TBranch        *b_p_m4l_SIG_ResUp;   //!
   TBranch        *b_p_m4l_BKG_ResUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ;   //!

   candTree(TTree *tree=0);
   virtual ~candTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef candTree_cxx
candTree::candTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://lxcms03//data3/Higgs/170203/AllData/ZZ4lAnalysis.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://lxcms03//data3/Higgs/170203/AllData/ZZ4lAnalysis.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://lxcms03//data3/Higgs/170203/AllData/ZZ4lAnalysis.root:/CRZLLTree");
      dir->GetObject("candTree",tree);

   }
   Init(tree);
}

candTree::~candTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t candTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t candTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void candTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   LepPt = 0;
   LepEta = 0;
   LepPhi = 0;
   LepLepId = 0;
   LepSIP = 0;
   LepTime = 0;
   LepisID = 0;
   LepisLoose = 0;
   LepBDT = 0;
   LepMissingHit = 0;
   LepCombRelIsoPF = 0;
   fsrPt = 0;
   fsrEta = 0;
   fsrPhi = 0;
   fsrLept = 0;
   JetPt = 0;
   JetEta = 0;
   JetPhi = 0;
   JetMass = 0;
   JetBTagger = 0;
   JetIsBtagged = 0;
   JetIsBtaggedWithSF = 0;
   JetIsBtaggedWithSFUp = 0;
   JetIsBtaggedWithSFDn = 0;
   JetQGLikelihood = 0;
   JetAxis2 = 0;
   JetMult = 0;
   JetPtD = 0;
   JetSigma = 0;
   JetHadronFlavour = 0;
   JetPartonFlavour = 0;
   JetJERUp = 0;
   JetJERDown = 0;
   JetPUID = 0;
   JetPUValue = 0;
   ExtraLepPt = 0;
   ExtraLepEta = 0;
   ExtraLepPhi = 0;
   ExtraLepLepId = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("LumiNumber", &LumiNumber, &b_LumiNumber);
   fChain->SetBranchAddress("NRecoMu", &NRecoMu, &b_NRecoMu);
   fChain->SetBranchAddress("NRecoEle", &NRecoEle, &b_NRecoEle);
   fChain->SetBranchAddress("Nvtx", &Nvtx, &b_Nvtx);
   fChain->SetBranchAddress("NObsInt", &NObsInt, &b_NObsInt);
   fChain->SetBranchAddress("NTrueInt", &NTrueInt, &b_NTrueInt);
   fChain->SetBranchAddress("PFMET", &PFMET, &b_PFMET);
   fChain->SetBranchAddress("PFMETPhi", &PFMETPhi, &b_PFMETPhi);
   fChain->SetBranchAddress("PFMETNoHF", &PFMETNoHF, &b_PFMETNoHF);
   fChain->SetBranchAddress("PFMETNoHFPhi", &PFMETNoHFPhi, &b_PFMETNoHFPhi);
   fChain->SetBranchAddress("nCleanedJets", &nCleanedJets, &b_nCleanedJets);
   fChain->SetBranchAddress("nCleanedJetsPt30", &nCleanedJetsPt30, &b_nCleanedJetsPt30);
   fChain->SetBranchAddress("nCleanedJetsPt30_jecUp", &nCleanedJetsPt30_jecUp, &b_nCleanedJetsPt30_jecUp);
   fChain->SetBranchAddress("nCleanedJetsPt30_jecDn", &nCleanedJetsPt30_jecDn, &b_nCleanedJetsPt30_jecDn);
   fChain->SetBranchAddress("nCleanedJetsPt30BTagged", &nCleanedJetsPt30BTagged, &b_nCleanedJetsPt30BTagged);
   fChain->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSF", &nCleanedJetsPt30BTagged_bTagSF, &b_nCleanedJetsPt30BTagged_bTagSF);
   fChain->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSFUp", &nCleanedJetsPt30BTagged_bTagSFUp, &b_nCleanedJetsPt30BTagged_bTagSFUp);
   fChain->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSFDn", &nCleanedJetsPt30BTagged_bTagSFDn, &b_nCleanedJetsPt30BTagged_bTagSFDn);
   fChain->SetBranchAddress("trigWord", &trigWord, &b_trigWord);
   fChain->SetBranchAddress("ZZMass", &ZZMass, &b_ZZMass);
   fChain->SetBranchAddress("ZZMassErr", &ZZMassErr, &b_ZZMassErr);
   fChain->SetBranchAddress("ZZMassErrCorr", &ZZMassErrCorr, &b_ZZMassErrCorr);
   fChain->SetBranchAddress("ZZMassPreFSR", &ZZMassPreFSR, &b_ZZMassPreFSR);
   fChain->SetBranchAddress("ZZsel", &ZZsel, &b_ZZsel);
   fChain->SetBranchAddress("ZZPt", &ZZPt, &b_ZZPt);
   fChain->SetBranchAddress("ZZEta", &ZZEta, &b_ZZEta);
   fChain->SetBranchAddress("ZZPhi", &ZZPhi, &b_ZZPhi);
   fChain->SetBranchAddress("CRflag", &CRflag, &b_CRflag);
   fChain->SetBranchAddress("Z1Mass", &Z1Mass, &b_Z1Mass);
   fChain->SetBranchAddress("Z1Pt", &Z1Pt, &b_Z1Pt);
   fChain->SetBranchAddress("Z1Flav", &Z1Flav, &b_Z1Flav);
   fChain->SetBranchAddress("ZZMassRefit", &ZZMassRefit, &b_ZZMassRefit);
   fChain->SetBranchAddress("ZZMassRefitErr", &ZZMassRefitErr, &b_ZZMassRefitErr);
   fChain->SetBranchAddress("ZZMassUnrefitErr", &ZZMassUnrefitErr, &b_ZZMassUnrefitErr);
   fChain->SetBranchAddress("Z2Mass", &Z2Mass, &b_Z2Mass);
   fChain->SetBranchAddress("Z2Pt", &Z2Pt, &b_Z2Pt);
   fChain->SetBranchAddress("Z2Flav", &Z2Flav, &b_Z2Flav);
   fChain->SetBranchAddress("costhetastar", &costhetastar, &b_costhetastar);
   fChain->SetBranchAddress("helphi", &helphi, &b_helphi);
   fChain->SetBranchAddress("helcosthetaZ1", &helcosthetaZ1, &b_helcosthetaZ1);
   fChain->SetBranchAddress("helcosthetaZ2", &helcosthetaZ2, &b_helcosthetaZ2);
   fChain->SetBranchAddress("phistarZ1", &phistarZ1, &b_phistarZ1);
   fChain->SetBranchAddress("phistarZ2", &phistarZ2, &b_phistarZ2);
   fChain->SetBranchAddress("xi", &xi, &b_xi);
   fChain->SetBranchAddress("xistar", &xistar, &b_xistar);
   fChain->SetBranchAddress("LepPt", &LepPt, &b_LepPt);
   fChain->SetBranchAddress("LepEta", &LepEta, &b_LepEta);
   fChain->SetBranchAddress("LepPhi", &LepPhi, &b_LepPhi);
   fChain->SetBranchAddress("LepLepId", &LepLepId, &b_LepLepId);
   fChain->SetBranchAddress("LepSIP", &LepSIP, &b_LepSIP);
   fChain->SetBranchAddress("LepTime", &LepTime, &b_LepTime);
   fChain->SetBranchAddress("LepisID", &LepisID, &b_LepisID);
   fChain->SetBranchAddress("LepisLoose", &LepisLoose, &b_LepisLoose);
   fChain->SetBranchAddress("LepBDT", &LepBDT, &b_LepBDT);
   fChain->SetBranchAddress("LepMissingHit", &LepMissingHit, &b_LepMissingHit);
   fChain->SetBranchAddress("LepCombRelIsoPF", &LepCombRelIsoPF, &b_LepCombRelIsoPF);
   fChain->SetBranchAddress("fsrPt", &fsrPt, &b_fsrPt);
   fChain->SetBranchAddress("fsrEta", &fsrEta, &b_fsrEta);
   fChain->SetBranchAddress("fsrPhi", &fsrPhi, &b_fsrPhi);
   fChain->SetBranchAddress("fsrLept", &fsrLept, &b_fsrLept);
   fChain->SetBranchAddress("passIsoPreFSR", &passIsoPreFSR, &b_passIsoPreFSR);
   fChain->SetBranchAddress("JetPt", &JetPt, &b_JetPt);
   fChain->SetBranchAddress("JetEta", &JetEta, &b_JetEta);
   fChain->SetBranchAddress("JetPhi", &JetPhi, &b_JetPhi);
   fChain->SetBranchAddress("JetMass", &JetMass, &b_JetMass);
   fChain->SetBranchAddress("JetBTagger", &JetBTagger, &b_JetBTagger);
   fChain->SetBranchAddress("JetIsBtagged", &JetIsBtagged, &b_JetIsBtagged);
   fChain->SetBranchAddress("JetIsBtaggedWithSF", &JetIsBtaggedWithSF, &b_JetIsBtaggedWithSF);
   fChain->SetBranchAddress("JetIsBtaggedWithSFUp", &JetIsBtaggedWithSFUp, &b_JetIsBtaggedWithSFUp);
   fChain->SetBranchAddress("JetIsBtaggedWithSFDn", &JetIsBtaggedWithSFDn, &b_JetIsBtaggedWithSFDn);
   fChain->SetBranchAddress("JetQGLikelihood", &JetQGLikelihood, &b_JetQGLikelihood);
   fChain->SetBranchAddress("JetAxis2", &JetAxis2, &b_JetAxis2);
   fChain->SetBranchAddress("JetMult", &JetMult, &b_JetMult);
   fChain->SetBranchAddress("JetPtD", &JetPtD, &b_JetPtD);
   fChain->SetBranchAddress("JetSigma", &JetSigma, &b_JetSigma);
   fChain->SetBranchAddress("JetHadronFlavour", &JetHadronFlavour, &b_JetHadronFlavour);
   fChain->SetBranchAddress("JetPartonFlavour", &JetPartonFlavour, &b_JetPartonFlavour);
   fChain->SetBranchAddress("JetJERUp", &JetJERUp, &b_JetJERUp);
   fChain->SetBranchAddress("JetJERDown", &JetJERDown, &b_JetJERDown);
   fChain->SetBranchAddress("JetPUID", &JetPUID, &b_JetPUID);
   fChain->SetBranchAddress("JetPUValue", &JetPUValue, &b_JetPUValue);
   fChain->SetBranchAddress("DiJetMass", &DiJetMass, &b_DiJetMass);
   fChain->SetBranchAddress("DiJetDEta", &DiJetDEta, &b_DiJetDEta);
   fChain->SetBranchAddress("DiJetFisher", &DiJetFisher, &b_DiJetFisher);
   fChain->SetBranchAddress("nExtraLep", &nExtraLep, &b_nExtraLep);
   fChain->SetBranchAddress("nExtraZ", &nExtraZ, &b_nExtraZ);
   fChain->SetBranchAddress("ExtraLepPt", &ExtraLepPt, &b_ExtraLepPt);
   fChain->SetBranchAddress("ExtraLepEta", &ExtraLepEta, &b_ExtraLepEta);
   fChain->SetBranchAddress("ExtraLepPhi", &ExtraLepPhi, &b_ExtraLepPhi);
   fChain->SetBranchAddress("ExtraLepLepId", &ExtraLepLepId, &b_ExtraLepLepId);
   fChain->SetBranchAddress("ZXFakeweight", &ZXFakeweight, &b_ZXFakeweight);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz4_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghza2_1_JHUGen", &p_GG_SIG_ghg2_1_ghza2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghza2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghza4_1_JHUGen", &p_GG_SIG_ghg2_1_ghza4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghza4_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_gha2_1_JHUGen", &p_GG_SIG_ghg2_1_gha2_1_JHUGen, &b_p_GG_SIG_ghg2_1_gha2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_gha4_1_JHUGen", &p_GG_SIG_ghg2_1_gha4_1_JHUGen, &b_p_GG_SIG_ghg2_1_gha4_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen);
   fChain->SetBranchAddress("pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal", &pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal, &b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JVBF_SIG_ghv1_1_JHUGen_JECNominal", &p_JVBF_SIG_ghv1_1_JHUGen_JECNominal, &b_p_JVBF_SIG_ghv1_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JQCD_SIG_ghg2_1_JHUGen_JECNominal", &p_JQCD_SIG_ghg2_1_JHUGen_JECNominal, &b_p_JQCD_SIG_ghg2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_gha2_1_JHUGen_JECNominal", &p_JJVBF_SIG_gha2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_gha2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_gha4_1_JHUGen_JECNominal", &p_JJVBF_SIG_gha4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_gha4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal", &p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal", &p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal, &b_p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal", &p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal, &b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghza2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghza2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghza4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghza4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_gha2_1_JHUGen_JECNominal", &p_HadZH_SIG_gha2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_gha2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_gha4_1_JHUGen_JECNominal", &p_HadZH_SIG_gha4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_gha4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal", &p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw2_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw2_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw4_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw4_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal", &p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal, &b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal", &p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal, &b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal", &p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal, &b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("p_bbH_SIG_kappa_1_JHUGen_JECNominal", &p_bbH_SIG_kappa_1_JHUGen_JECNominal, &b_p_bbH_SIG_kappa_1_JHUGen_JECNominal);
   fChain->SetBranchAddress("pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp", &pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp, &b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JVBF_SIG_ghv1_1_JHUGen_JECUp", &p_JVBF_SIG_ghv1_1_JHUGen_JECUp, &b_p_JVBF_SIG_ghv1_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JQCD_SIG_ghg2_1_JHUGen_JECUp", &p_JQCD_SIG_ghg2_1_JHUGen_JECUp, &b_p_JQCD_SIG_ghg2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghza2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghza2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghza4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghza4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_gha2_1_JHUGen_JECUp", &p_JJVBF_SIG_gha2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_gha2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_gha4_1_JHUGen_JECUp", &p_JJVBF_SIG_gha4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_gha4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECUp", &p_JJQCD_SIG_ghg2_1_JHUGen_JECUp, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg4_1_JHUGen_JECUp", &p_JJQCD_SIG_ghg4_1_JHUGen_JECUp, &b_p_JJQCD_SIG_ghg4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp", &p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp, &b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza2_1_JHUGen_JECUp", &p_HadZH_SIG_ghza2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghza2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza4_1_JHUGen_JECUp", &p_HadZH_SIG_ghza4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghza4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_gha2_1_JHUGen_JECUp", &p_HadZH_SIG_gha2_1_JHUGen_JECUp, &b_p_HadZH_SIG_gha2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_gha4_1_JHUGen_JECUp", &p_HadZH_SIG_gha4_1_JHUGen_JECUp, &b_p_HadZH_SIG_gha4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp", &p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw2_1_JHUGen_JECUp", &p_HadWH_SIG_ghw2_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw4_1_JHUGen_JECUp", &p_HadWH_SIG_ghw4_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp", &p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp, &b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp", &p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp, &b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp", &p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp, &b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp);
   fChain->SetBranchAddress("p_bbH_SIG_kappa_1_JHUGen_JECUp", &p_bbH_SIG_kappa_1_JHUGen_JECUp, &b_p_bbH_SIG_kappa_1_JHUGen_JECUp);
   fChain->SetBranchAddress("pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn", &pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn, &b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JVBF_SIG_ghv1_1_JHUGen_JECDn", &p_JVBF_SIG_ghv1_1_JHUGen_JECDn, &b_p_JVBF_SIG_ghv1_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JQCD_SIG_ghg2_1_JHUGen_JECDn", &p_JQCD_SIG_ghg2_1_JHUGen_JECDn, &b_p_JQCD_SIG_ghg2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghza2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghza2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghza4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghza4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghza4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_gha2_1_JHUGen_JECDn", &p_JJVBF_SIG_gha2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_gha2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_gha4_1_JHUGen_JECDn", &p_JJVBF_SIG_gha4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_gha4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECDn", &p_JJQCD_SIG_ghg2_1_JHUGen_JECDn, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg4_1_JHUGen_JECDn", &p_JJQCD_SIG_ghg4_1_JHUGen_JECDn, &b_p_JJQCD_SIG_ghg4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn", &p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn, &b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza2_1_JHUGen_JECDn", &p_HadZH_SIG_ghza2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghza2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghza4_1_JHUGen_JECDn", &p_HadZH_SIG_ghza4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghza4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_gha2_1_JHUGen_JECDn", &p_HadZH_SIG_gha2_1_JHUGen_JECDn, &b_p_HadZH_SIG_gha2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_gha4_1_JHUGen_JECDn", &p_HadZH_SIG_gha4_1_JHUGen_JECDn, &b_p_HadZH_SIG_gha4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn", &p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw2_1_JHUGen_JECDn", &p_HadWH_SIG_ghw2_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw4_1_JHUGen_JECDn", &p_HadWH_SIG_ghw4_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn", &p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn, &b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn", &p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn, &b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn", &p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn, &b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_bbH_SIG_kappa_1_JHUGen_JECDn", &p_bbH_SIG_kappa_1_JHUGen_JECDn, &b_p_bbH_SIG_kappa_1_JHUGen_JECDn);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_JHUGen", &p_LepZH_SIG_ghz1_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1prime2_1E4_JHUGen", &p_LepZH_SIG_ghz1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghz1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz2_1_JHUGen", &p_LepZH_SIG_ghz2_1_JHUGen, &b_p_LepZH_SIG_ghz2_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz4_1_JHUGen", &p_LepZH_SIG_ghz4_1_JHUGen, &b_p_LepZH_SIG_ghz4_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghza1prime2_1E4_JHUGen", &p_LepZH_SIG_ghza1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghza1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghza2_1_JHUGen", &p_LepZH_SIG_ghza2_1_JHUGen, &b_p_LepZH_SIG_ghza2_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghza4_1_JHUGen", &p_LepZH_SIG_ghza4_1_JHUGen, &b_p_LepZH_SIG_ghza4_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_gha2_1_JHUGen", &p_LepZH_SIG_gha2_1_JHUGen, &b_p_LepZH_SIG_gha2_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_gha4_1_JHUGen", &p_LepZH_SIG_gha4_1_JHUGen, &b_p_LepZH_SIG_gha4_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen", &p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen", &p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_gha2_1_JHUGen", &p_LepZH_SIG_ghz1_1_gha2_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_gha2_1_JHUGen);
   fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_gha4_1_JHUGen", &p_LepZH_SIG_ghz1_1_gha4_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_gha4_1_JHUGen);
   fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_JHUGen", &p_LepWH_SIG_ghw1_1_JHUGen, &b_p_LepWH_SIG_ghw1_1_JHUGen);
   fChain->SetBranchAddress("p_LepWH_SIG_ghw1prime2_1E4_JHUGen", &p_LepWH_SIG_ghw1prime2_1E4_JHUGen, &b_p_LepWH_SIG_ghw1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_LepWH_SIG_ghw2_1_JHUGen", &p_LepWH_SIG_ghw2_1_JHUGen, &b_p_LepWH_SIG_ghw2_1_JHUGen);
   fChain->SetBranchAddress("p_LepWH_SIG_ghw4_1_JHUGen", &p_LepWH_SIG_ghw4_1_JHUGen, &b_p_LepWH_SIG_ghw4_1_JHUGen);
   fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen", &p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen, &b_p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen);
   fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen", &p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen, &b_p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen);
   fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen", &p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen, &b_p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen", &p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen, &b_p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen", &p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen, &b_p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gZPz1_1_JHUGen", &p_INDEPENDENT_SIG_gZPz1_1_JHUGen, &b_p_INDEPENDENT_SIG_gZPz1_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gZPz2_1_JHUGen", &p_INDEPENDENT_SIG_gZPz2_1_JHUGen, &b_p_INDEPENDENT_SIG_gZPz2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz1_1_JHUGen", &p_GG_SIG_gXg1_1_gXz1_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz1_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg2_1_gXz2_1_JHUGen", &p_GG_SIG_gXg2_1_gXz2_1_JHUGen, &b_p_GG_SIG_gXg2_1_gXz2_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg3_1_gXz3_1_JHUGen", &p_GG_SIG_gXg3_1_gXz3_1_JHUGen, &b_p_GG_SIG_gXg3_1_gXz3_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg4_1_gXz4_1_JHUGen", &p_GG_SIG_gXg4_1_gXz4_1_JHUGen, &b_p_GG_SIG_gXg4_1_gXz4_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz5_1_JHUGen", &p_GG_SIG_gXg1_1_gXz5_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz5_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen", &p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz6_1_JHUGen", &p_GG_SIG_gXg1_1_gXz6_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz6_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz7_1_JHUGen", &p_GG_SIG_gXg1_1_gXz7_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz7_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg5_1_gXz8_1_JHUGen", &p_GG_SIG_gXg5_1_gXz8_1_JHUGen, &b_p_GG_SIG_gXg5_1_gXz8_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg5_1_gXz9_1_JHUGen", &p_GG_SIG_gXg5_1_gXz9_1_JHUGen, &b_p_GG_SIG_gXg5_1_gXz9_1_JHUGen);
   fChain->SetBranchAddress("p_GG_SIG_gXg5_1_gXz10_1_JHUGen", &p_GG_SIG_gXg5_1_gXz10_1_JHUGen, &b_p_GG_SIG_gXg5_1_gXz10_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen);
   fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz1_1_JHUGen", &p_INDEPENDENT_SIG_gXz1_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz1_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz2_1_JHUGen", &p_INDEPENDENT_SIG_gXz2_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz2_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz3_1_JHUGen", &p_INDEPENDENT_SIG_gXz3_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz3_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz4_1_JHUGen", &p_INDEPENDENT_SIG_gXz4_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz4_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz5_1_JHUGen", &p_INDEPENDENT_SIG_gXz5_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz5_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen", &p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz6_1_JHUGen", &p_INDEPENDENT_SIG_gXz6_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz6_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz7_1_JHUGen", &p_INDEPENDENT_SIG_gXz7_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz7_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz8_1_JHUGen", &p_INDEPENDENT_SIG_gXz8_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz8_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz9_1_JHUGen", &p_INDEPENDENT_SIG_gXz9_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz9_1_JHUGen);
   fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz10_1_JHUGen", &p_INDEPENDENT_SIG_gXz10_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz10_1_JHUGen);
   fChain->SetBranchAddress("pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM", &pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM, &b_pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM);
   fChain->SetBranchAddress("p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM", &p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM, &b_p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM);
   fChain->SetBranchAddress("p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM", &p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM, &b_p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM);
   fChain->SetBranchAddress("p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM", &p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM, &b_p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM);
   fChain->SetBranchAddress("pConst_GG_BKG_MCFM", &pConst_GG_BKG_MCFM, &b_pConst_GG_BKG_MCFM);
   fChain->SetBranchAddress("p_GG_BKG_MCFM", &p_GG_BKG_MCFM, &b_p_GG_BKG_MCFM);
   fChain->SetBranchAddress("pConst_QQB_BKG_MCFM", &pConst_QQB_BKG_MCFM, &b_pConst_QQB_BKG_MCFM);
   fChain->SetBranchAddress("p_QQB_BKG_MCFM", &p_QQB_BKG_MCFM, &b_p_QQB_BKG_MCFM);
   fChain->SetBranchAddress("p_ZJJ_BKG_MCFM", &p_ZJJ_BKG_MCFM, &b_p_ZJJ_BKG_MCFM);
   fChain->SetBranchAddress("p_JJEW_SIG_ghv1_1_MCFM_JECNominal", &p_JJEW_SIG_ghv1_1_MCFM_JECNominal, &b_p_JJEW_SIG_ghv1_1_MCFM_JECNominal);
   fChain->SetBranchAddress("p_JJEW_BSI_ghv1_1_MCFM_JECNominal", &p_JJEW_BSI_ghv1_1_MCFM_JECNominal, &b_p_JJEW_BSI_ghv1_1_MCFM_JECNominal);
   fChain->SetBranchAddress("p_JJEW_BSI_ghv1_i_MCFM_JECNominal", &p_JJEW_BSI_ghv1_i_MCFM_JECNominal, &b_p_JJEW_BSI_ghv1_i_MCFM_JECNominal);
   fChain->SetBranchAddress("p_JJEW_BKG_MCFM_JECNominal", &p_JJEW_BKG_MCFM_JECNominal, &b_p_JJEW_BKG_MCFM_JECNominal);
   fChain->SetBranchAddress("p_JJVBF_BKG_MCFM_JECNominal", &p_JJVBF_BKG_MCFM_JECNominal, &b_p_JJVBF_BKG_MCFM_JECNominal);
   fChain->SetBranchAddress("p_JJQCD_BKG_MCFM_JECNominal", &p_JJQCD_BKG_MCFM_JECNominal, &b_p_JJQCD_BKG_MCFM_JECNominal);
   fChain->SetBranchAddress("p_JJEW_SIG_ghv1_1_MCFM_JECUp", &p_JJEW_SIG_ghv1_1_MCFM_JECUp, &b_p_JJEW_SIG_ghv1_1_MCFM_JECUp);
   fChain->SetBranchAddress("p_JJEW_BSI_ghv1_1_MCFM_JECUp", &p_JJEW_BSI_ghv1_1_MCFM_JECUp, &b_p_JJEW_BSI_ghv1_1_MCFM_JECUp);
   fChain->SetBranchAddress("p_JJEW_BSI_ghv1_i_MCFM_JECUp", &p_JJEW_BSI_ghv1_i_MCFM_JECUp, &b_p_JJEW_BSI_ghv1_i_MCFM_JECUp);
   fChain->SetBranchAddress("p_JJEW_BKG_MCFM_JECUp", &p_JJEW_BKG_MCFM_JECUp, &b_p_JJEW_BKG_MCFM_JECUp);
   fChain->SetBranchAddress("p_JJVBF_BKG_MCFM_JECUp", &p_JJVBF_BKG_MCFM_JECUp, &b_p_JJVBF_BKG_MCFM_JECUp);
   fChain->SetBranchAddress("p_JJQCD_BKG_MCFM_JECUp", &p_JJQCD_BKG_MCFM_JECUp, &b_p_JJQCD_BKG_MCFM_JECUp);
   fChain->SetBranchAddress("p_JJEW_SIG_ghv1_1_MCFM_JECDn", &p_JJEW_SIG_ghv1_1_MCFM_JECDn, &b_p_JJEW_SIG_ghv1_1_MCFM_JECDn);
   fChain->SetBranchAddress("p_JJEW_BSI_ghv1_1_MCFM_JECDn", &p_JJEW_BSI_ghv1_1_MCFM_JECDn, &b_p_JJEW_BSI_ghv1_1_MCFM_JECDn);
   fChain->SetBranchAddress("p_JJEW_BSI_ghv1_i_MCFM_JECDn", &p_JJEW_BSI_ghv1_i_MCFM_JECDn, &b_p_JJEW_BSI_ghv1_i_MCFM_JECDn);
   fChain->SetBranchAddress("p_JJEW_BKG_MCFM_JECDn", &p_JJEW_BKG_MCFM_JECDn, &b_p_JJEW_BKG_MCFM_JECDn);
   fChain->SetBranchAddress("p_JJVBF_BKG_MCFM_JECDn", &p_JJVBF_BKG_MCFM_JECDn, &b_p_JJVBF_BKG_MCFM_JECDn);
   fChain->SetBranchAddress("p_JJQCD_BKG_MCFM_JECDn", &p_JJQCD_BKG_MCFM_JECDn, &b_p_JJQCD_BKG_MCFM_JECDn);
   fChain->SetBranchAddress("p_m4l_SIG", &p_m4l_SIG, &b_p_m4l_SIG);
   fChain->SetBranchAddress("p_m4l_BKG", &p_m4l_BKG, &b_p_m4l_BKG);
   fChain->SetBranchAddress("p_m4l_SIG_ScaleDown", &p_m4l_SIG_ScaleDown, &b_p_m4l_SIG_ScaleDown);
   fChain->SetBranchAddress("p_m4l_BKG_ScaleDown", &p_m4l_BKG_ScaleDown, &b_p_m4l_BKG_ScaleDown);
   fChain->SetBranchAddress("p_m4l_SIG_ResDown", &p_m4l_SIG_ResDown, &b_p_m4l_SIG_ResDown);
   fChain->SetBranchAddress("p_m4l_BKG_ResDown", &p_m4l_BKG_ResDown, &b_p_m4l_BKG_ResDown);
   fChain->SetBranchAddress("p_m4l_SIG_ScaleUp", &p_m4l_SIG_ScaleUp, &b_p_m4l_SIG_ScaleUp);
   fChain->SetBranchAddress("p_m4l_BKG_ScaleUp", &p_m4l_BKG_ScaleUp, &b_p_m4l_BKG_ScaleUp);
   fChain->SetBranchAddress("p_m4l_SIG_ResUp", &p_m4l_SIG_ResUp, &b_p_m4l_SIG_ResUp);
   fChain->SetBranchAddress("p_m4l_BKG_ResUp", &p_m4l_BKG_ResUp, &b_p_m4l_BKG_ResUp);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ", &p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ", &p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ", &p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ", &p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ);
   fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ", &p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ);
   fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ", &p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ);
   Notify();
}

Bool_t candTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void candTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t candTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef candTree_cxx
