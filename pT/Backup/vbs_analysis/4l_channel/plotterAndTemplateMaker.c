// #include "external_cConstants.h"
#include <TSpline.h>
#include <TString.h>
#include <memory>
#include <iostream>
#include <fstream>

using namespace std;

void plotterAndTemplateMaker(int year = 2018, int useMCatNLO = 1, int enriched = 0){
  
       //useMCatNLO = 0 : use just POWHEG
       //useMCatNLO = 1 : use just aMCatNLO
       //useMCatNLO = 2 : use aMCatNLO for shape, POWHEG for integral

       //enriched = 0 : baseline selection
       //enriched = 1 : VBS-enriched
       //enriched = 2 : super-VBS-enriched
       //enriched = 3 : bkgd enriched
       //enriched = 4 : ptjet > 50 GeV

        float lumi = 35.9; 
        if (year == 2017) lumi = 41.5;
	if (year == 2018) lumi = 59.7;

        string theExtra = "";
        if (enriched == 1) theExtra = "_VBSenr";
	if (enriched == 2) theExtra = "_superVBSenr";
	if (enriched == 3) theExtra = "_bkgdEnr";
	if (enriched == 4) theExtra = "_ptjet50";
	if (enriched == 5) theExtra = "_superVBSenrMjj";

	//BINNING
        int nBinsTempl = 20;
        if (enriched == 2 || enriched == 5) nBinsTempl = 20;
        
        char filename[300];
        
        static const int vars = 7;
        float xmin=0.;
        float xmax=1000.;
	
	bool rebin = false; //if the histograms have been rebinned change to true  

        lumi *= 1000;
        
	float bincont1, bincont2, bincont3;

	float c_constant = 14.0;    //8.5;
        // if (year == 2017) c_constant = 3.5;
	// if (year == 2018) c_constant = 3.5; 
	TFile* f_ = TFile::Open("/<path>/CMSSW_8_0_26_patch1/src/pT/vbs_analysis/4l_channel/cconstants/SmoothKDConstant_m4l_DjjVBF13TeV.root");
	TSpline3* ts = (TSpline3*)(f_->Get("sp_gr_varReco_Constant_Smooth")->Clone());
	f_->Close();

        // find available samples  
	int nSamp = 0;  
	TString rootname[40];
 	sprintf(filename,"cutbased_samples%d.txt",year);

	ifstream parInput(filename);
        
	if (parInput.is_open()) {
	  while ( parInput.good() ) {
	    parInput >> rootname[nSamp]; 
            cout << nSamp << " " <<  rootname[nSamp] << endl; 
	    nSamp++;
	  }
	  parInput.close();
	} 

	//original variable declarations
	float ZZPt,ZZMass,Z1Mass,Z2Mass,DiJetMass,DiJetMassLHE,DiJetDEta,Z1Pt;
	float xsec,KFactorEWKqqZZ,overallEventWeight,L1prefiringWeight,genHEPMCweight,KFactorQCDqqZZ_M;
	vector<float> *LepPt=new vector<float>;
	vector<float> *JetPt=new vector<float>;
	vector<float> *JetEta=new vector<float>;
	short Z1Flav,Z2Flav;
	short nCleanedJetsPt30;
	float pvbf_VAJHU_old;
	float phjj_VAJHU_old;
	float bkg_VAMCFM,p0plus_VAJHU;
	short ZZsel;
	vector<short> *LepLepId=0;
	short nExtraLep;
	short nCleanedJetsPt30BTagged_bTagSF;
	
	//new variable declarations
	float p_JJEW_BKG_MCFM_JECNominal; //not in use
	float p_JJQCD_BKG_MCFM_JECNominal;
	float p_JJVBF_BKG_MCFM_JECNominal;
	float KFactorQCDggzz_Nominal;

	//additional and output variable declarations
	float weight, weight_up, weight_dn;
	float weight_vbf, weight_vbf_up, weight_vbf_dn;
	int chan,Nvtx;
	int vbfcate = 0;
	float dbkg_kin, theVar; 
	
	//output branches
	TTree *tnew[5]; 
	TFile *fnew[5];
	//template declarations (1D) 
	TH1F *temp_1d_4e[5];
	TH1F *temp_1d_4mu[5];
	TH1F *temp_1d_2e2mu[5];

	for (int it=0; it < 5; it++) {
	  if (it==0) sprintf(filename,"template/root_output_files/qqzz_Moriond_%d%s.root",year,theExtra.c_str()); 
	  if (it==1) sprintf(filename,"template/root_output_files/ggzz_Moriond_%d%s.root",year,theExtra.c_str()); 
	  if (it==2) sprintf(filename,"template/root_output_files/vbs_Moriond_%d%s.root",year,theExtra.c_str()); 
	  if (it==3) sprintf(filename,"template/root_output_files/data_%d%s.root",year,theExtra.c_str()); 
	  if (it==4) sprintf(filename,"template/root_output_files/ttzwzz_Moriond_%d%s.root",year,theExtra.c_str()); 
	  fnew[it] = new TFile(filename,"recreate");
	  tnew[it] = new TTree("SelectedTree","SelectedTree");
	  tnew[it]->Branch("mreco",&ZZMass,"mreco/F");
	  tnew[it]->Branch("dbkg_kin",&dbkg_kin,"dbkg_kin/F");
	  tnew[it]->Branch("weight",&weight,"weight/F");
	  tnew[it]->Branch("weight_up",&weight_up,"weight_up/F");
	  tnew[it]->Branch("weight_dn",&weight_dn,"weight_dn/F");
	  tnew[it]->Branch("chan",&chan,"chan/I");
	  tnew[it]->Branch("vbfcate",&vbfcate,"vbfcate/I");
	  temp_1d_4e[it] = new TH1F("temp_1d_4e","",nBinsTempl,xmin,xmax);
	  temp_1d_4mu[it] = new TH1F("temp_1d_4mu","",nBinsTempl,xmin,xmax);
	  temp_1d_2e2mu[it] = new TH1F("temp_1d_2e2mu","",nBinsTempl,xmin,xmax);
	}
	
	//for loop for different samples
	for(int is = 0; is < nSamp-1; is++){

	  //print cycle
	  std::cout << endl << is << endl;
	  
          TFile* input_file = TFile::Open(rootname[is].Data()); 
	  TH1F *hCounters= (TH1F*)input_file->Get("ZZTree/Counters");
	  float gen_sum_weights = hCounters->GetBinContent(40);
	  std::cout<<endl<<is<<"  "<< gen_sum_weights<<endl;
	  
	  //tchain and add function for multiple input files
	  TChain *tqqzz= new TChain("ZZTree/candTree");
	  tqqzz->Add(rootname[is].Data());
          
          //process class
          int j = 0;   // qqzz powheg
	  if (rootname[is].Contains("AllData")) j = 3;   
	  if (rootname[is].Contains("ggTo") || rootname[is].Contains("ggZZnew")) j = 1;      
          if (rootname[is].Contains("VBFTo")) j = 2;
	  if (rootname[is].Contains("amcatnlo")) j = 5; 
	  if (rootname[is].Contains("ZZ4l_inter")) j = 4;
	  if (rootname[is].Contains("WWZ")) j = 11; 
	  if (rootname[is].Contains("TTZ")) j = 12; 
	  if (rootname[is].Contains("WZZ")) j = 13; 
	  if (rootname[is].Contains("ZZZ")) j = 14;  
 
	  float my_sum = 0;
	  float mc_integral;
	  float data_integral;
	  //original brach addresses
	  tqqzz->SetBranchAddress("nExtraLep",&nExtraLep);
	  tqqzz->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSF",&nCleanedJetsPt30BTagged_bTagSF);
	  tqqzz->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal",&pvbf_VAJHU_old);
	  tqqzz->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal",&phjj_VAJHU_old);
	  tqqzz->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_JHUGen",&p0plus_VAJHU);
	  tqqzz->SetBranchAddress("p_QQB_BKG_MCFM",&bkg_VAMCFM);
	  tqqzz->SetBranchAddress("ZZPt",&ZZPt);
	  tqqzz->SetBranchAddress("ZZMass",&ZZMass);
	  tqqzz->SetBranchAddress("Z1Pt",&Z1Pt);
	  tqqzz->SetBranchAddress("Z1Flav",&Z1Flav);
	  tqqzz->SetBranchAddress("Z2Flav",&Z2Flav);
	  tqqzz->SetBranchAddress("Z1Mass",&Z1Mass);
	  tqqzz->SetBranchAddress("Z2Mass",&Z2Mass);
	  tqqzz->SetBranchAddress("KFactor_EW_qqZZ",&KFactorEWKqqZZ);
	  tqqzz->SetBranchAddress("xsec",&xsec);
	  tqqzz->SetBranchAddress("ZZsel",&ZZsel);
	  tqqzz->SetBranchAddress("LepLepId",&LepLepId);
	  tqqzz->SetBranchAddress("LepPt",&LepPt);
          tqqzz->SetBranchAddress("JetPt",&JetPt);
          tqqzz->SetBranchAddress("JetEta",&JetEta);
	  tqqzz->SetBranchAddress("overallEventWeight",&overallEventWeight);
	  tqqzz->SetBranchAddress("genHEPMCweight",&genHEPMCweight);
	  tqqzz->SetBranchAddress("L1prefiringWeight",&L1prefiringWeight);
	  tqqzz->SetBranchAddress("KFactor_QCD_qqZZ_M",&KFactorQCDqqZZ_M);
	  tqqzz->SetBranchAddress("nCleanedJetsPt30",&nCleanedJetsPt30);
	  tqqzz->SetBranchAddress("Nvtx",&Nvtx);
	  
	  //new branch addresses
	  tqqzz->SetBranchAddress("p_JJEW_BKG_MCFM_JECNominal",&p_JJEW_BKG_MCFM_JECNominal);
	  tqqzz->SetBranchAddress("p_JJVBF_BKG_MCFM_JECNominal",&p_JJVBF_BKG_MCFM_JECNominal);
	  tqqzz->SetBranchAddress("p_JJQCD_BKG_MCFM_JECNominal",&p_JJQCD_BKG_MCFM_JECNominal);
	  tqqzz->SetBranchAddress("DiJetMass",&DiJetMass);
	  tqqzz->SetBranchAddress("DiJetMassLHE",&DiJetMassLHE);
          tqqzz->SetBranchAddress("DiJetDEta",&DiJetDEta);
	  tqqzz->SetBranchAddress("KFactor_QCD_ggZZ_Nominal",&KFactorQCDggzz_Nominal);

	  //loop on entries
	  int enne = tqqzz->GetEntries();

	  // preliminary loop to fix MG wrong weights (only VBS 2017-18)
	  float resum = gen_sum_weights;
          if (j==2 && year>2016) resum = hCounters->GetBinContent(1);
  
	  for(int i=0;i<enne;i++){
	    tqqzz->GetEntry(i);
	    
	   	    //unique selection condition (see paper page 8) & DiJetMass condition
		    
	    if(DiJetMass>100 && ZZMass > 180 && nCleanedJetsPt30>1 && Z1Mass < 120 && Z1Mass > 60 && Z2Mass < 120 && Z2Mass > 60) { 
	      if (j>12 && DiJetMassLHE > 100) continue; 
	      if (enriched == 1 && (DiJetMass < 400 || fabs(DiJetDEta) < 2.4)) continue;
	      if (enriched == 2 && (DiJetMass < 400 || fabs(DiJetDEta) < 5.0)) continue;
	      if (enriched == 3 && DiJetMass > 400 && fabs(DiJetDEta) > 2.4) continue;
	      if (enriched == 4 && (JetPt->at(0) < 50 || JetPt->at(1) < 50)) continue;
	      if (enriched == 5 && (DiJetMass < 1000 || fabs(DiJetDEta) < 2.4)) continue;

	      //set vbf_category
	      vbfcate=1;
	      //weight definition
	      //KFactorEWKqqZZ = 1;
	      //KFactorQCDqqZZ_M = 1;
	      //weight=1;

	      // make sure prefiring weight is 1 for real data
	      float prefiringWeight = L1prefiringWeight;
	      if (j==2) prefiringWeight = 1.; 
	      
	      weight= (xsec*overallEventWeight*prefiringWeight*lumi)/(resum);
	      if (j==0 || j==5) weight= (xsec*KFactorEWKqqZZ*overallEventWeight*KFactorQCDqqZZ_M*prefiringWeight*lumi)/(resum);
	      if (j==4) weight *= 0.5;
	      // correct k-factor for NNLO/NLO?
	      // if (j==1) weight= (xsec*overallEventWeight*KFactorQCDggzz_Nominal*prefiringWeight*lumi)/(resum);
	      // if (j==1 && useMCatNLO==1) weight /=1.7;
	      if (j==1) weight= (xsec*overallEventWeight*1.53*1.64*prefiringWeight*lumi)/(resum);
              // LO weight from dynamic to fixed scale + NLO k-factor
	      if (j==2 && year>2016) weight= (xsec*overallEventWeight*prefiringWeight*lumi)/(genHEPMCweight*resum);             
	      if (j==3) weight=prefiringWeight; 

	      //TEMPORARY FOR MISSING 2e2mu SAMPLE
	      //if (j==2 && year==2017) weight *= 2.;

	      //division in channels
	      if(abs(Z1Flav)==abs(Z2Flav) && abs(Z1Flav)==121) chan=2;
	      else if (abs(Z1Flav)==abs(Z2Flav) && abs(Z1Flav)!=121) chan=1;
	      else chan=3;
	      
	      //kin variable
              float c_mzz = c_constant*ts->Eval(ZZMass);
	      dbkg_kin = p_JJVBF_BKG_MCFM_JECNominal/(p_JJVBF_BKG_MCFM_JECNominal+ p_JJQCD_BKG_MCFM_JECNominal*c_mzz);
	     
	      if (dbkg_kin < 0.00 || dbkg_kin > 1.00) continue;

	      // fill templates 
	      if (useMCatNLO > 0 && j==5) {
		tnew[0]->Fill();
		// if(chan==1) { 
		temp_1d_4mu[0]->Fill(Z1Pt,weight);  
		// else if(chan==2) { 
		temp_1d_4e[0]->Fill(Z1Pt,weight); 
	        // else { 
		temp_1d_2e2mu[0]->Fill(Z1Pt,weight); 
	      } else if (useMCatNLO == 0 && j==0) {
		tnew[0]->Fill();
		// if(chan==1) { 
		temp_1d_4mu[0]->Fill(Z1Pt,weight); 
		// else if(chan==2) { 
		temp_1d_4e[0]->Fill(Z1Pt,weight); 
	        // else { 
		temp_1d_2e2mu[0]->Fill(Z1Pt,weight); 
	      } else if (j==1) {
		tnew[j]->Fill();
		temp_1d_4mu[j]->Fill(Z1Pt,weight);
		temp_1d_4e[j]->Fill(Z1Pt,weight);
	        temp_1d_2e2mu[j]->Fill(Z1Pt,weight);
	      } else if (j==4) {
		tnew[0]->Fill();     tnew[2]->Fill();
		temp_1d_4mu[0]->Fill(Z1Pt,weight);
		temp_1d_4e[0]->Fill(Z1Pt,weight);
	       	temp_1d_2e2mu[0]->Fill(Z1Pt,weight);
		if(chan==1) {temp_1d_4mu[2]->Fill(Z1Pt,weight); }
		else if(chan==2) {temp_1d_4e[2]->Fill(Z1Pt,weight); } 
	        else {temp_1d_2e2mu[2]->Fill(Z1Pt,weight); }
	      } else if (j>9) {
		tnew[4]->Fill();
		temp_1d_4mu[4]->Fill(Z1Pt,weight);
		temp_1d_4e[4]->Fill(Z1Pt,weight);
	     	temp_1d_2e2mu[4]->Fill(Z1Pt,weight);
	      } else {
		tnew[j]->Fill();
		if(chan==1) {temp_1d_4mu[j]->Fill(Z1Pt,weight); }
		else if(chan==2) {temp_1d_4e[j]->Fill(Z1Pt,weight); } 
	        else {temp_1d_2e2mu[j]->Fill(Z1Pt,weight); }
	      }
	    }
	  }//entries loop  end
	}//file loop  end
       
       
	//ZX CONTRIBUTION
	TChain *tqqzz_zx= new TChain("candTree");
	sprintf(filename,"/<path>/CMSSW_8_0_26_patch1/src/pT/data_driven_MC/ZX%d_noCut%s.root",year,theExtra.c_str()); 
	tqqzz_zx->Add(filename);
	
	//histogram declaration
	TH1F *hzx; 
	TH1F *hzx_ee; 
	TH1F *hzx_em; 
	TH1F *hzx_mm; 
	
	hzx = new TH1F("hzx","hzx",nBinsTempl,xmin,xmax); //full histogram
	hzx_ee = new TH1F("hzx_ee","hzx_ee",nBinsTempl,xmin,xmax); //full histogramhzx
	hzx_mm = new TH1F("hzx_mm","hzx_mm",nBinsTempl,xmin,xmax); //full histogram
	hzx_em = new TH1F("hzx_em","hzx_em",nBinsTempl,xmin,xmax); //full histogram

	
	//new variable declarations
	float var_zx, dbkg_kin_zx, ZZMass_zx, DiJetMass_zx, DiJetDEta_zx,Z1Pt_zx;
	float ptjet1_zx,ptjet2_zx,etajet1_zx,etajet2_zx; 
	float weight_zx;
	int chan_zx;
	
	//original branch addresses
	tqqzz_zx->SetBranchAddress("dbkg_kin",&dbkg_kin_zx);
	tqqzz_zx->SetBranchAddress("ZZMass",&ZZMass_zx);
	tqqzz_zx->SetBranchAddress("Z1Pt",&Z1Pt_zx);
	tqqzz_zx->SetBranchAddress("DiJetMass",&DiJetMass_zx);
	tqqzz_zx->SetBranchAddress("DiJetDEta",&DiJetDEta_zx);
	tqqzz_zx->SetBranchAddress("weight",&weight_zx);
	tqqzz_zx->SetBranchAddress("ptjet1",&ptjet1_zx); 
	tqqzz_zx->SetBranchAddress("ptjet2",&ptjet2_zx);   
	tqqzz_zx->SetBranchAddress("etajet1",&etajet1_zx); 
	tqqzz_zx->SetBranchAddress("etajet2",&etajet2_zx);
	tqqzz_zx->SetBranchAddress("chan",&chan_zx);

	//entries loop
	for(int i=0;i<tqqzz_zx->GetEntries();i++){
	  tqqzz_zx->GetEntry(i);
	  
	  //1D kin var hist fill
	  var_zx = Z1Pt_zx;
	  if (fabs(weight_zx) < 100000.) {
	  
		hzx->Fill(var_zx,weight_zx);
		if (chan_zx == 2) hzx_ee->Fill(var_zx,weight_zx);
		if (chan_zx == 1) hzx_mm->Fill(var_zx,weight_zx);
		if (chan_zx == 3) hzx_em->Fill(var_zx,weight_zx);
		}
	    
	}
	
	
	//OVERFLOW
	for (int it=0; it < 5; it++){
		if(temp_1d_4e[it]->GetBinContent(nBinsTempl+1)>0.){
			temp_1d_4e[it]->SetBinContent(nBinsTempl,temp_1d_4e[it]->GetBinContent(nBinsTempl)+temp_1d_4e[it]->GetBinContent(nBinsTempl+1));
			}
		if(temp_1d_4mu[it]->GetBinContent(nBinsTempl+1)>0.){
			temp_1d_4mu[it]->SetBinContent(nBinsTempl,temp_1d_4mu[it]->GetBinContent(nBinsTempl)+temp_1d_4mu[it]->GetBinContent(nBinsTempl+1));
			}
		if(temp_1d_2e2mu[it]->GetBinContent(nBinsTempl+1)>0.){
			temp_1d_2e2mu[it]->SetBinContent(nBinsTempl,temp_1d_2e2mu[it]->GetBinContent(nBinsTempl)+temp_1d_2e2mu[it]->GetBinContent(nBinsTempl+1));
			}								
	}
	
	if (rebin==true){
		double xbins[]={};
		int newbins=30;
		hzx->Rebin(newbins,"hzx_new",xbins);
		for (int it=0; it < 5; it++){
			temp_1d_4e[it]->Rebin(newbins,"temp_1d_4e_new",xbins);
			temp_1d_4mu[it]->Rebin(newbins,"temp_1d_4mu_new",xbins);
			temp_1d_2e2mu[it]->Rebin(newbins,"temp_1d_2e2mu_new",xbins);
		}
		
		
	}
			
	
	sprintf(filename,"MCyields_%d%s.txt",year,theExtra.c_str());
	ofstream yields(filename);
	yields << temp_1d_4mu[2]->Integral() << "\t" << hzx_mm->Integral() << "\t" << temp_1d_4mu[0]->Integral()  << "\t" << temp_1d_4mu[1]->Integral() << "\t" << temp_1d_4mu[4]->Integral() << "\t" << temp_1d_4e[2]->Integral() << "\t" << hzx_ee->Integral() << "\t" <<  temp_1d_4e[0]->Integral()  << "\t" << temp_1d_4e[1]->Integral() << "\t" << temp_1d_4e[4]->Integral() << "\t" << temp_1d_2e2mu[2]->Integral() << "\t" << hzx_em->Integral() << "\t" <<  temp_1d_2e2mu[0]->Integral() << "\t" << temp_1d_2e2mu[1]->Integral() << "\t" << temp_1d_2e2mu[4]->Integral() << endl;
	yields.close();
	
        sprintf(filename,"datayields_%d%s.txt",year,theExtra.c_str());
	ofstream yields2(filename);
	yields2 << temp_1d_4mu[3]->Integral() << "\t" << temp_1d_4e[3]->Integral() << "\t" << temp_1d_2e2mu[3]->Integral() << endl;
	yields2.close();

	
	for (int it=0; it < 5; it++) {
	  fnew[it]->cd();
	  if (it < 3 || it == 4) {
	    temp_1d_4e[it]->Write();
	    temp_1d_4mu[it]->Write();
	    temp_1d_2e2mu[it]->Write();
	  }
	  
	  if(it==3){
	  	hzx->Write();
	  	temp_1d_4e[it]->Write();
	  	temp_1d_4mu[it]->Write();
	  	temp_1d_2e2mu[it]->Write();
	  	}
	  
	  tnew[it]->Write();
	  fnew[it]->Close();
	}

	
}
