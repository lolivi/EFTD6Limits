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

        int nBinsTempl = 27;
        if (enriched == 2 || enriched == 5) nBinsTempl = 20;
	
	static const int vars = 7;
        string titlex[vars] = {"K_{D}","M_{4l} [GeV]","M_{jj} [GeV]","#Delta #eta_{jj}","p_{T,j}","#eta_{j}","Nvtx"};        
        string titley[vars] = {"Events/0.025","Events/16 GeV","Events/40 GeV","Events/0.175","Events/5 GeV","Events/0.33","Events/2"};     
	string namegif[vars] = {"Dbkgkin","m4l","mjj","detajj","ptj","etaj","Nvtx"};
        int bins[vars] = {20,27,30,20,40,30,35};
        float xmin[vars] = {0.,180.,100.,0.,0.,-5.,0.};
	float xmax[vars] = {1.,1530.,1300.,8.,400.,5.,70.};	
	bool drawSignal[vars] = {false,false,true,true,true,true,false};

	//histogram stack
        char filename[300]; char filetitle[300];
	THStack *hs[vars];
        for(int iv = 0; iv < vars; iv++){
	  sprintf(filename,"hs%d",iv);   
	  sprintf(filetitle,"CMS Preliminary                %2.1f fb^{-1};%s;%s",lumi,titlex[iv].c_str(),titley[iv].c_str());  
	  hs[iv] = new THStack(filename,filetitle);
	}  

        lumi *= 1000;

        //histograms

	// TH1F *h_complete_data[vars]; //all data
	// TH1F *h00[vars]; //bkg_kin<0.7 cut full background plot
	TH1F *hdata[vars]; //data, because we are hiding higher energies in this phase
	TH1F *hqqzz_powheg[vars]; //ew
	TH1F *hqqzz[vars]; //ew+zx -> real ew
	TH1F *hggzz[vars]; //gg
	TH1F *hvbs[vars]; //vbs
	TH1F *hsum1[vars]; //gg+ew -> real gg
	TH1F *hsum2[vars]; //gg+ew+vbs
	// TH1F *h6[vars]; //gg+ew+vbs+zx ->real vbs
	TH1F *hqqzz_ee[vars]; //qqzz e
	TH1F *hqqzz_mm[vars]; //qqzz mu
	TH1F *hqqzz_em[vars]; //qqzz e mu
	TH1F *hggzz_ee[vars];//ggzz e
	TH1F *hggzz_mm[vars];//ggzz mu
	TH1F *hggzz_em[vars]; //ggzz e mu
	TH1F *hvbs_ee[vars];//vbs e
	TH1F *hvbs_mm[vars];//vbs mu
	TH1F *hvbs_em[vars];//vbs e mu
	TH1F *hdata_ee[vars];//vbs e
	TH1F *hdata_mm[vars];//vbs mu
	TH1F *hdata_em[vars];//vbs e mu
	TH1F *httzwzz[vars];//ttz + wwz
	TH1F *httz[vars];//ttz + wwz
	TH1F *hwzz[vars];//ttz + wwz
	TH1F *hwwz[vars];//ttz + wwz
	TH1F *hzzz[vars];//ttz + wwz
	TH1F *httzwzz_ee[vars];//ttz + wwz e
	TH1F *httzwzz_mm[vars];//ttz + wwz mu
	TH1F *httzwzz_em[vars];//ttz + wwz e mu

	for(int iv = 0; iv < vars; iv++){
	  if (enriched == 1 || enriched == 2 || enriched == 5) bins[iv] /= 2; 
	  // sprintf(filename,"hcd%d",iv);   h_complete_data[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //all data
	  // sprintf(filename,"h00_%d",iv);   h00[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //bkg_kin<0.7 cut full background plot
	  sprintf(filename,"hdata_%d",iv);   hdata[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //data, because we are hiding higher energies in this phase
	  sprintf(filename,"hqqzz_powheg_%d",iv);   hqqzz_powheg[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //ew
	  sprintf(filename,"hqqzz_%d",iv);   hqqzz[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //ew+zx -> real ew
	  sprintf(filename,"hggzz_%d",iv);   hggzz[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //gg
	  sprintf(filename,"hvbs_%d",iv);   hvbs[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //vbs
	  sprintf(filename,"hsum1_%d",iv);   hsum1[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //gg+ew -> real gg
	  sprintf(filename,"hsum2_%d",iv);   hsum2[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //gg+ew+vbs
	  // sprintf(filename,"h6_%d",iv);   h6[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //gg+ew+vbs+zx ->real vbs
	  sprintf(filename,"hqqzz_ee_%d",iv);   hqqzz_ee[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //qqzz e
	  sprintf(filename,"hqqzz_mm_%d",iv);   hqqzz_mm[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //qqzz mu
	  sprintf(filename,"hqqzz_em_%d",iv);   hqqzz_em[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //qqzz e mu
	  sprintf(filename,"hggzz_ee_%d",iv);   hggzz_ee[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//ggzz e
	  sprintf(filename,"hggzz_mm_%d",iv);   hggzz_mm[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//ggzz mu
	  sprintf(filename,"hggzz_em_%d",iv);  hggzz_em[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //ggzz e mu
	  sprintf(filename,"hvbs_ee_%d",iv); hvbs_ee[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//vbs e
	  sprintf(filename,"hvbs_mm_%d",iv); hvbs_mm[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//vbs mu
	  sprintf(filename,"hvbs_em_%d",iv); hvbs_em[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//vbs e mu
	  sprintf(filename,"hdataee_%d",iv); hdata_ee[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//vbs e
	  sprintf(filename,"hdatamm_%d",iv); hdata_mm[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//vbs mu
	  sprintf(filename,"hdataem_%d",iv); hdata_em[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//vbs e mu
	  // sprintf(filename,"h2bis_%d",iv); h2bis[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//for 2018 rescale
	  sprintf(filename,"httzwzz_%d",iv); httzwzz[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);
	  sprintf(filename,"httz_%d",iv); httz[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);
	  sprintf(filename,"hwzz_%d",iv); hwzz[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);
	  sprintf(filename,"hwwz_%d",iv); hwwz[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);
	  sprintf(filename,"hzzz_%d",iv); hzzz[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);
	  sprintf(filename,"httzwzz_ee_%d",iv); httzwzz_ee[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//ttzwzz e
	  sprintf(filename,"httzwzz_mm_%d",iv); httzwzz_mm[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//ttzwzz mu
	  sprintf(filename,"httzwzz_em_%d",iv); httzwzz_em[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]);//ttzwzz e mu
	}   
	gStyle->SetPalette(1);
	TFile *input_file;
        int nbins=17;
	double xbin[18]={
	  160,166,170,176,182,188,194,
	  200,208,216,224,234,246,260,278,302,338,1500
	}; 

	float c_constant = 14.0;    //8.5;
        // if (year == 2017) c_constant = 3.5;
	// if (year == 2018) c_constant = 3.5; 
	TFile* f_ = TFile::Open("/afs/cern.ch/user/l/lolivi/test/CMSSW_8_0_26_patch1/src/vbs_analysis/4l_channel/cconstants/SmoothKDConstant_m4l_DjjVBF13TeV.root");
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
	float ZZPt,ZZMass,Z1Mass,Z2Mass,DiJetMass,DiJetMassLHE,DiJetDEta;
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
	//template declarations (2D) 
	TH2F *temp_zz_4e[5];
	TH2F *temp_zz_4mu[5];
	TH2F *temp_zz_2e2mu[5];

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
	  temp_zz_4e[it] = new TH2F("temp_zz_4e","",nbins,xbin,40,0.,1.);
	  temp_zz_4mu[it] = new TH2F("temp_zz_4mu","",nbins,xbin,40,0.,1.);
	  temp_zz_2e2mu[it] = new TH2F("temp_zz_2e2mu","",nbins,xbin,40,0.,1.);
	  temp_1d_4e[it] = new TH1F("temp_1d_4e","",nBinsTempl,180,1530);
	  temp_1d_4mu[it] = new TH1F("temp_1d_4mu","",nBinsTempl,180,1530);
	  temp_1d_2e2mu[it] = new TH1F("temp_1d_2e2mu","",nBinsTempl,180,1530);
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
              int conta=0;
              if(c_mzz<0) conta++;
              cout<<" CONTA QUANTI EVENTI CI SONO IN MENO "<<conta<<endl;
	      dbkg_kin = p_JJVBF_BKG_MCFM_JECNominal/(p_JJVBF_BKG_MCFM_JECNominal+ p_JJQCD_BKG_MCFM_JECNominal*c_mzz);
	      if (dbkg_kin < 0.00 || dbkg_kin > 1.00) continue;

	      // fill templates 
	      if (useMCatNLO > 0 && j==5) {
		tnew[0]->Fill();
		// if(chan==1) { 
		temp_zz_4mu[0]->Fill(ZZMass,dbkg_kin,weight); temp_1d_4mu[0]->Fill(ZZMass,weight);  
		// else if(chan==2) { 
		temp_zz_4e[0]->Fill(ZZMass,dbkg_kin,weight); temp_1d_4e[0]->Fill(ZZMass,weight); 
	        // else { 
		temp_zz_2e2mu[0]->Fill(ZZMass,dbkg_kin,weight); temp_1d_2e2mu[0]->Fill(ZZMass,weight); 
	      } else if (useMCatNLO == 0 && j==0) {
		tnew[0]->Fill();
		// if(chan==1) { 
		temp_zz_4mu[0]->Fill(ZZMass,dbkg_kin,weight); temp_1d_4mu[0]->Fill(ZZMass,weight); 
		// else if(chan==2) { 
		temp_zz_4e[0]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4e[0]->Fill(ZZMass,weight); 
	        // else { 
		temp_zz_2e2mu[0]->Fill(ZZMass,dbkg_kin,weight); temp_1d_2e2mu[0]->Fill(ZZMass,weight); 
	      } else if (j==1) {
		tnew[j]->Fill();
		temp_zz_4mu[j]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4mu[j]->Fill(ZZMass,weight);
		temp_zz_4e[j]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4e[j]->Fill(ZZMass,weight);
	        temp_zz_2e2mu[j]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_2e2mu[j]->Fill(ZZMass,weight);
	      } else if (j==4) {
		tnew[0]->Fill();     tnew[2]->Fill();
		temp_zz_4mu[0]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4mu[0]->Fill(ZZMass,weight);
		temp_zz_4e[0]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4e[0]->Fill(ZZMass,weight);
	        temp_zz_2e2mu[0]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_2e2mu[0]->Fill(ZZMass,weight);
		if(chan==1) { temp_zz_4mu[2]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4mu[2]->Fill(ZZMass,weight); }
		else if(chan==2) { temp_zz_4e[2]->Fill(ZZMass,dbkg_kin,weight); temp_1d_4e[2]->Fill(ZZMass,weight); } 
	        else { temp_zz_2e2mu[2]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_2e2mu[2]->Fill(ZZMass,weight); }
	      } else if (j>9) {
		tnew[4]->Fill();
		temp_zz_4mu[4]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4mu[4]->Fill(ZZMass,weight);
		temp_zz_4e[4]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4e[4]->Fill(ZZMass,weight);
	        temp_zz_2e2mu[4]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_2e2mu[4]->Fill(ZZMass,weight);
	      } else {
		tnew[j]->Fill();
		if(chan==1) { temp_zz_4mu[j]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_4mu[j]->Fill(ZZMass,weight); }
		else if(chan==2) { temp_zz_4e[j]->Fill(ZZMass,dbkg_kin,weight); temp_1d_4e[j]->Fill(ZZMass,weight); } 
	        else { temp_zz_2e2mu[j]->Fill(ZZMass,dbkg_kin,weight);  temp_1d_2e2mu[j]->Fill(ZZMass,weight); }
	      }

              // fill plots
	      for(int il = 0; il < vars+2; il++){
                int iv = il; 
		if (il == 0) theVar = dbkg_kin;
		if (il == 1) theVar = ZZMass;
		if (il == 2) theVar = DiJetMass;
		if (il == 3) theVar = fabs(DiJetDEta);
                if (il == 4) theVar = JetPt->at(0);
                if (il == 5) theVar = JetEta->at(0);
                if (il == 6) {theVar = JetPt->at(1);   iv = 4;}
		if (il == 7) {theVar = JetEta->at(1);   iv = 5;}
		if (il == 8) {theVar = Nvtx;   iv = 6;}
   	      
		//1D kin var hist fill
		//this is the normalization histogram
		// if (j<3){
		//  if (theVar <= 1.1) h00[iv]->Fill(theVar,weight);    
		// h_complete_data[iv]->Fill(theVar,weight);
		//}
		
		if (j==3){
		  // if (iv > 0 || theVar < 0.75 || year == 2016) 
		  hdata[iv]->Fill(theVar);
		  //else cout << "Blinded event!" << endl;
		  hdata[iv]->SetMarkerStyle(20);
		  if (chan == 2) hdata_ee[iv]->Fill(theVar);
		  if (chan == 1) hdata_mm[iv]->Fill(theVar);
		  if (chan == 3) hdata_em[iv]->Fill(theVar);
		}
		if (j==0){                              //qqzz
		  hqqzz_powheg[iv]->Fill(theVar,weight);
		  
		  /* if (chan == 1) hqqzz_mm[iv]->Fill(theVar,weight); //mu
		  if (chan == 2) hqqzz_ee[iv]->Fill(theVar,weight); //e
		  if (chan == 3)  hqqzz_em[iv]->Fill(theVar,weight);  */        //mu+e
		}
		if (j==1){                              //gg
		  hggzz[iv]->Fill(theVar,weight);
		  hggzz[iv]->SetFillColor(kBlue);
		  
		  if (chan == 1) hggzz_mm[iv]->Fill(theVar,weight); //mu
		  if (chan == 2) hggzz_ee[iv]->Fill(theVar,weight); //e
		  if (chan == 3)  hggzz_em[iv]->Fill(theVar,weight);          //mu+e
		  
		}
		if (j==2 || j==4){                              //vbs
		  hvbs[iv]->Fill(theVar,weight);
		  hvbs[iv]->SetFillColor(kMagenta);

		  if (chan == 1) hvbs_mm[iv]->Fill(theVar,weight); //mu
		  if (chan == 2) hvbs_ee[iv]->Fill(theVar,weight); //e
		  if (chan == 3) hvbs_em[iv]->Fill(theVar,weight);          //mu+e
		  
		}
		if (j==5 || j==4) {
		  hqqzz[iv]->Fill(theVar,weight);

		  if (chan == 1) hqqzz_mm[iv]->Fill(theVar,weight); //mu
		  if (chan == 2) hqqzz_ee[iv]->Fill(theVar,weight); //e
		  if (chan == 3)  hqqzz_em[iv]->Fill(theVar,weight);
		}
		if (j>9) {
		  httzwzz[iv]->Fill(theVar,weight);
		  if (j==11) hwwz[iv]->Fill(theVar,weight);
		  if (j==12) httz[iv]->Fill(theVar,weight);
		  if (j==13) hwzz[iv]->Fill(theVar,weight);
		  if (j==14) hzzz[iv]->Fill(theVar,weight);
                  
		  if (chan == 1) httzwzz_mm[iv]->Fill(theVar,weight); //mu
		  if (chan == 2) httzwzz_ee[iv]->Fill(theVar,weight); //e
		  if (chan == 3) httzwzz_em[iv]->Fill(theVar,weight);          //mu+e
		}
		  
		//kin_zz->GetYaxis()->SetTitle("Events/0.05");
		//add histogram to stack
		//for cycle ends here
	      }
	    }
	  }//entries loop  end
	}//file loop  end
       
	//ZX CONTRIBUTION
	  
	TChain *tqqzz_zx= new TChain("candTree");
	sprintf(filename,"/afs/cern.ch/user/l/lolivi/test/CMSSW_8_0_26_patch1/src/data_driven_MC/ZX%d_noCut%s.root",year,theExtra.c_str()); 
	tqqzz_zx->Add(filename);
	
	//histogram declaration
	TH1F *hzx[vars]; 
	TH1F *hzx_ee[vars]; 
	TH1F *hzx_em[vars]; 
	TH1F *hzx_mm[vars]; 
	for(int iv = 0; iv < vars; iv++){
	/*if(iv==1){
	  sprintf(filename,"hzx%d",iv);   hzx[iv] = new TH1F(filename,"",27,180,1530); //full histogram
	  sprintf(filename,"hzx_ee%d",iv);   hzx_ee[iv] = new TH1F(filename,"",27,180,1530); //full histogram
	  sprintf(filename,"hzx_mm%d",iv);   hzx_mm[iv] = new TH1F(filename,"",27,180,1530); //full histogram
	  sprintf(filename,"hzx_em%d",iv);   hzx_em[iv] = new TH1F(filename,"",27,180,1530); //full histogram
	}
	else{*/
	  sprintf(filename,"hzx%d",iv);   hzx[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //full histogram
	  sprintf(filename,"hzx_ee%d",iv);   hzx_ee[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //full histogram
	  sprintf(filename,"hzx_mm%d",iv);   hzx_mm[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //full histogram
	  sprintf(filename,"hzx_em%d",iv);   hzx_em[iv] = new TH1F(filename,"",bins[iv],xmin[iv],xmax[iv]); //full histogram
	//}
	}
	//new variable declarations
	float var_zx, dbkg_kin_zx, ZZMass_zx, DiJetMass_zx, DiJetDEta_zx;
	float ptjet1_zx,ptjet2_zx,etajet1_zx,etajet2_zx; 
	float weight_zx;
	int chan_zx;
	
	//original branch addresses
	tqqzz_zx->SetBranchAddress("dbkg_kin",&dbkg_kin_zx);
	tqqzz_zx->SetBranchAddress("ZZMass",&ZZMass_zx);
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
	  for(int il = 0; il < vars+2; il++){
            int iv = il; 
	    if (iv == 0) var_zx = dbkg_kin_zx;
	    if (iv == 1) var_zx = ZZMass_zx;
	    if (iv == 2) var_zx = DiJetMass_zx;
	    if (iv == 3) var_zx = fabs(DiJetDEta_zx);
	    if (il == 4) var_zx = ptjet1_zx;
	    if (il == 5) var_zx = etajet1_zx;
	    if (il == 6) {var_zx = ptjet2_zx;   iv = 4;}
	    if (il == 7) {var_zx = etajet2_zx;   iv = 5;}
	    if (il == 8) {var_zx = ptjet1_zx/5.;   iv = 6;}
	    if (fabs(weight_zx) < 100000.) {
	      hzx[iv]->Fill(var_zx,weight_zx);
	      if (chan_zx == 2) hzx_ee[iv]->Fill(var_zx,weight_zx);
	      if (chan_zx == 1) hzx_mm[iv]->Fill(var_zx,weight_zx);
	      if (chan_zx == 3) hzx_em[iv]->Fill(var_zx,weight_zx);
	    }
	    // if (var_zx<=0.7) h00[iv]->Fill(var_zx,weight_zx);
	    
	  }
	}
	
	
	cout<<" Prova su ee "<<hzx_ee[1]->Integral()<<endl;
	cout<<" Prova su mumu "<<hzx_mm[1]->Integral()<<endl;
	cout<<" Prova su mu e "<<hzx_em[1]->Integral()<<endl;
	
	
	//OVERFLOW
	for (int it=0; it < 5; it++){
		if(temp_1d_4e[it]->GetBinContent(nBinsTempl+1)>0.){
			cout<<"OVERFLOW MANCANTE IN temp_1d_4e_["<<it<<"]"<<endl;
			cout<<temp_1d_4e[it]->GetBinContent(nBinsTempl)<<endl;
			cout<<temp_1d_4e[it]->GetBinContent(nBinsTempl+1)<<endl;
			temp_1d_4e[it]->SetBinContent(nBinsTempl,temp_1d_4e[it]->GetBinContent(nBinsTempl)+temp_1d_4e[it]->GetBinContent(nBinsTempl+1));
			cout<<"Dopo ho "<<temp_1d_4e[it]->GetBinContent(nBinsTempl)<<endl;
			}
		if(temp_1d_4mu[it]->GetBinContent(nBinsTempl+1)>0.){
			cout<<"OVERFLOW MANCANTE IN temp_1d_4mu_["<<it<<"]"<<endl;
			cout<<temp_1d_4mu[it]->GetBinContent(nBinsTempl)<<endl;
			cout<<temp_1d_4mu[it]->GetBinContent(nBinsTempl+1)<<endl;
			temp_1d_4mu[it]->SetBinContent(nBinsTempl,temp_1d_4mu[it]->GetBinContent(nBinsTempl)+temp_1d_4mu[it]->GetBinContent(nBinsTempl+1));
			cout<<"Dopo ho "<<temp_1d_4mu[it]->GetBinContent(nBinsTempl)<<endl;
			}
		if(temp_1d_2e2mu[it]->GetBinContent(nBinsTempl+1)>0.){
			cout<<"OVERFLOW MANCANTE IN temp_1d_2e2mu_["<<it<<"]"<<endl;
			cout<<temp_1d_2e2mu[it]->GetBinContent(nBinsTempl)<<endl;
			cout<<temp_1d_2e2mu[it]->GetBinContent(nBinsTempl+1)<<endl;
			temp_1d_2e2mu[it]->SetBinContent(nBinsTempl,temp_1d_2e2mu[it]->GetBinContent(nBinsTempl)+temp_1d_2e2mu[it]->GetBinContent(nBinsTempl+1));
			cout<<"Dopo ho "<<temp_1d_2e2mu[it]->GetBinContent(nBinsTempl)<<endl;
			}								
	}
	
	/*if (hzx[1]->GetBinContent(28)>0.){
	 		cout<<"OVERFLOW MANCANTE IN hzx_[1]"<<endl;
			cout<<hzx[1]->GetBinContent(27)<<endl;
			cout<<hzx[1]->GetBinContent(28)<<endl;
			hzx[1]->SetBinContent(27,hzx[1]->GetBinContent(27)+hzx[1]->GetBinContent(28));
			cout<<"Dopo ho "<<hzx[1]->GetBinContent(27)<<endl;
			}
	if(hzx_ee[1]->GetBinContent(28)>0.){
			cout<<"OVERFLOW MANCANTE IN hzx_ee_[1]"<<endl;
			cout<<hzx_ee[1]->GetBinContent(27)<<endl;
			cout<<hzx_ee[1]->GetBinContent(28)<<endl;
			hzx_ee[1]->SetBinContent(27,hzx_ee[1]->GetBinContent(28)+hzx_ee[1]->GetBinContent(27));
			cout<<"Dopo ho "<<hzx_ee[1]->GetBinContent(27)<<endl;
			}
	if(hzx_em[1]->GetBinContent(28)>0.){
			cout<<"OVERFLOW MANCANTE IN hzx_em_[1]"<<endl;
			cout<<hzx_em[1]->GetBinContent(27)<<endl;
			cout<<hzx_em[1]->GetBinContent(28)<<endl;
			hzx_em[1]->SetBinContent(27,hzx_em[1]->GetBinContent(28)+hzx_em[1]->GetBinContent(27));
			cout<<"Dopo ho "<<hzx_em[1]->GetBinContent(27)<<endl;
			}
	if(hzx_mm[1]->GetBinContent(28)>0.){
			cout<<"OVERFLOW MANCANTE IN hzx_mm_[1]"<<endl;
			cout<<hzx_mm[1]->GetBinContent(27)<<endl;
			cout<<hzx_mm[1]->GetBinContent(28)<<endl;
			hzx_mm[1]->SetBinContent(27,hzx_mm[1]->GetBinContent(28)+hzx_mm[1]->GetBinContent(27));
			cout<<"Dopo ho "<<hzx_mm[1]->GetBinContent(27)<<endl;
			}	
*/

	cout<< temp_1d_4mu[2]->Integral() << "\t" << hzx_mm[1]->Integral() << "\t" << temp_1d_4mu[0]->Integral()  << "\t" << temp_1d_4mu[1]->Integral() << "\t" << temp_1d_4mu[4]->Integral() << "\t" << temp_1d_4e[2]->Integral() << "\t" << hzx_ee[1]->Integral() << "\t" <<  temp_1d_4e[0]->Integral()  << "\t" << temp_1d_4e[1]->Integral() << "\t" << temp_1d_4e[4]->Integral() << "\t" << temp_1d_2e2mu[2]->Integral() << "\t" << hzx_em[1]->Integral() << "\t" <<  temp_1d_2e2mu[0]->Integral() << "\t" << temp_1d_2e2mu[1]->Integral() << "\t" << temp_1d_2e2mu[4]->Integral() << endl;
	cout << temp_1d_4mu[3]->Integral() << "\t" << temp_1d_4e[3]->Integral() << "\t" << temp_1d_2e2mu[3]->Integral() << endl;
	//INTEGRAL CHECK
	sprintf(filename,"MCyields_%d%s.txt",year,theExtra.c_str());
	ofstream yields(filename);
	yields << temp_1d_4mu[2]->Integral() << "\t" << hzx_mm[1]->Integral() << "\t" << temp_1d_4mu[0]->Integral()  << "\t" << temp_1d_4mu[1]->Integral() << "\t" << temp_1d_4mu[4]->Integral() << "\t" << temp_1d_4e[2]->Integral() << "\t" << hzx_ee[1]->Integral() << "\t" <<  temp_1d_4e[0]->Integral()  << "\t" << temp_1d_4e[1]->Integral() << "\t" << temp_1d_4e[4]->Integral() << "\t" << temp_1d_2e2mu[2]->Integral() << "\t" << hzx_em[1]->Integral() << "\t" <<  temp_1d_2e2mu[0]->Integral() << "\t" << temp_1d_2e2mu[1]->Integral() << "\t" << temp_1d_2e2mu[4]->Integral() << endl;
	yields.close();
	
        sprintf(filename,"datayields_%d%s.txt",year,theExtra.c_str());
	ofstream yields2(filename);
	yields2 << temp_1d_4mu[3]->Integral() << "\t" << temp_1d_4e[3]->Integral() << "\t" << temp_1d_2e2mu[3]->Integral() << endl;
	yields2.close();

	
	for (int it=0; it < 5; it++) {
	  fnew[it]->cd();
	  if (it < 3 || it == 4) {
	    //TH2F* final_4e = rebinTemplate(temp_zz_4e[it],year,it);
	    //final_4e->Write();
	    temp_1d_4e[it]->Write();
	    //TH2F* final_4mu = rebinTemplate(temp_zz_4mu[it],year,it);
	    //final_4mu->Write();
	    temp_1d_4mu[it]->Write();
	    //TH2F* final_2e2mu = rebinTemplate(temp_zz_2e2mu[it],year,it);
	    //final_2e2mu->Write();
	    temp_1d_2e2mu[it]->Write();
	  }
	  if(it==3){
	  	temp_1d_4e[it]->Write();
	  	temp_1d_4mu[it]->Write();
	  	temp_1d_2e2mu[it]->Write();
	  	}
	  	
	  for(int il = 0; il < vars; il++){
	    if (it==0) hqqzz[il]->Write();  
	    if (it==1) hggzz[il]->Write();
	    if (it==2) hvbs[il]->Write();
	    if (it==3) {hdata[il]->Write();    hzx[il]->Write();}
	    if (it==4) httzwzz[il]->Write();
	  }
	  tnew[it]->Write();
	  fnew[it]->Close();
	}

	
}
