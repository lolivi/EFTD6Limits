//#include "HiggsAnalysis/CombinedLimit/src/VerticalInterpHistPdf.cc+"
//#include "VerticalInterpPdf.cc+"

using namespace RooFit;

// highmass = 0 onshell
// highmass = 1 offshell
// highmass = 2 search 
//
//
// cate_vbf =0 ggH
// cate_vbf =1 VBF
// cate_vbf =2 RSE
// cate_vbf =3 TLE
//

void dosomething(TString chan="2e2mu", int year=2016, int enriched = 0){
  
        string theExtra = "";
        if (enriched == 1) theExtra = "_VBSenr";
	if (enriched == 2) theExtra = "_superVBSenr";
	if (enriched == 3) theExtra = "_bkgdEnr";
	if (enriched == 4) theExtra = "_ptjet50";
	if (enriched == 5) theExtra = "_superVBSenrMjj";

        int nBinsTempl = 40;
        if (enriched == 1) nBinsTempl = 25;
        if (enriched == 2 || enriched == 5) nBinsTempl = 10;
        
        bool rebin=false;
   
        char filename[300];

        static const int samples = 5;
        string namesamp[samples] = {"lin_vbs","zjet","qqzz","ggzz","ttzwzz"}; 
	static const int systs = 0;   //4
        string namesyst[systs] = {};	
	bool hasShape[samples][systs] = {{},
					 {},
					 {},
					 {},
					 {}};
	string newnamesyst[systs] = {};
	float normalizations[samples][3];

	// normalize histos, otherwise combine complains...
	sprintf(filename,"lin_MCyields_%d%s.txt",year,theExtra.c_str());
        ifstream parInput(filename);

	if (parInput.is_open()) { //qui legge MCyields e assegna le varie normalizations
	  while ( parInput.good() ) {
	    parInput >> normalizations[0][0] >> normalizations[0][1] >> normalizations[0][2] ; 
	  }
	  parInput.close();
	}


	TH1F *temp_1d[samples];
	TH1F *temp_1d_jup[samples][systs]; //questi non li ho
	TH1F *temp_1d_jdown[samples][systs];

	int channum=1;
	if(chan=="2e2mu")
	  channum=3;
	else if(chan=="4e")
	  channum=2;
	else if(chan=="4mu")
	  channum=1;
	  
	if (rebin==true) chan=chan+"_new";

	for (int is = 0; is < samples; is++) {

	  if (is==1) continue;    // zx later!
	  sprintf(filename,"./template/root_output_files/%s_Moriond_%d%s.root",namesamp[is].c_str(),year,theExtra.c_str()); 
	  TFile *ff = new TFile(filename); //apre il vbs moriond e i restanti
	  temp_1d[is]=(TH1F*)ff->Get("temp_1d_"+chan);
          if (enriched == 1 || enriched == 2 || enriched == 5) temp_1d[is]->Rebin(2);
	  
	  for(int bx=0;bx<temp_1d[is]->GetNbinsX();bx++){
	    if(temp_1d[is]->GetBinContent(bx+1)<=0.){
	      temp_1d[is]->SetBinContent(bx+1,1.0e-6);  
	    }
	  }
	
	  sprintf(filename,"bkg_%s",namesamp[is].c_str());
	  if(is==0) sprintf(filename,"linear_1");
	  temp_1d[is]->SetNameTitle(filename,filename);

	}

	//zx
	//TChain *t=new TChain("candTree");
	//t->Add("/afs/cern.ch/work/c/cthorbur/VBF_ANALYSIS/CMSSW_8_0_24_patch1new/src/HZZ4l-plotter/ZXinput_mjj.root");
        //sprintf(filename,"/afs/cern.ch/user/l/lolivi/test/CMSSW_8_0_26_patch1/src/data_driven_MC/ZX%d_noCut%s.root", year,theExtra.c_str());
	//t->Add(filename);
	//TH1F* zx1d = new TH1F("zx1d","",nBinsTempl,200,1500);
	//t->Draw("ZZMass>>zx1d","(ZZMass > 0.)*weight");   // use the same for 3 final states (not enough stats)
	//zx1d->SetNameTitle("bkg_zjet","bkg_zjet");

	//data
	//TChain *tdata = new TChain("SelectedTree");
	sprintf(filename,"./template/root_output_files/data_%d%s.root",year,theExtra.c_str());
	TFile *fdata = new TFile(filename);
	TFile *fZX = new TFile(filename);
	//tdata->Add(filename);
	TH1F* data_1d;// = new TH1F("data_1d","",nBinsTempl,200,1500);
	TH1F* zx1d;
	data_1d=(TH1F*)fdata->Get("temp_1d_"+chan);
	if (rebin==true) zx1d=(TH1F*)fZX->Get("hzx_new");
	if (rebin==false) zx1d=(TH1F*)fZX->Get("hzx");
		
	data_1d->SetNameTitle("data_obs","data_obs");
	zx1d->SetNameTitle("bkg_zjet","bkg_zjet");

	TFile *fwork ;
	float theScale, theIntegral = 0;
	fwork= new TFile("workspace/lin_1D_vbs4lSyst_"+chan+Form("1S_%d.input_func%s.root",year,theExtra.c_str()),"recreate");
	fwork->cd();
	for (int is = 0; is < samples; is++) {
	  if (is==1) continue;    // zx later!
	  theIntegral = temp_1d[is]->Integral();
          theScale = 1.;
 	  theScale = normalizations[is][channum-1]/theIntegral;
	  temp_1d[is]->Scale(theScale);
	}
	temp_1d[0]->Write();
	fwork->Close();
}

void bkgWorkspace1dLIN(TString chan, int year, int isVBSenriched){
  dosomething(chan,year,isVBSenriched);
}
