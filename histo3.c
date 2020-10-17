#include <TFile.h>
#include <TH1.h>
#include <TString.h>

using namespace RooFit;

void newhisto (TString chan = "4mu", TString year = "2017") {

	TFile *SM_FILE = new TFile ("1D_vbs4lSyst_"+chan+"1S_"+year+".input_func.root ");
	TFile *LIN_FILE = new TFile ("lin_1D_vbs4lSyst_"+chan+"1S_"+year+".input_func.root ");
	TFile *QUAD_FILE = new TFile ("quad_1D_vbs4lSyst_"+chan+"1S_"+year+".input_func.root ");
	
	TH1F *sm;
	TH1F *lin;
	TH1F *quad;
	
	sm = (TH1F*)SM_FILE->Get("sm");
	lin = (TH1F*)LIN_FILE->Get("linear_1");
	quad = (TH1F*)QUAD_FILE->Get("quadratic_1");
	
	/*SM_FILE->Close();
	LIN_FILE->Close();
	QUAD_FILE->Close();*/
	
	TH1F *newlin;
	TH1F *newquad;
	
	newlin =(TH1F*)sm->Clone();
	newquad =(TH1F*)quad->Clone();
	
	newlin->Add(lin);
	newlin->Add(quad);
	newlin->SetName("sm_lin_quad_cqq3");
	newlin->SetTitle("sm_lin_quad_cqq3");
	
	newquad->SetName("quad_cqq3");
	newquad->SetTitle("quad_cqq3");
	
	TFile *NEWLIN_FILE = new TFile("newlin_1D_vbs4lSyst_"+chan+"1S_"+year+".input_func.root","recreate");
	newlin->Write();
	NEWLIN_FILE->Close();
	
	TFile *NEWQUAD_FILE = new TFile("newquad_1D_vbs4lSyst_"+chan+"1S_"+year+".input_func.root","recreate");
	newquad->Write();
	NEWQUAD_FILE->Close();
	
	}

void histo3 (TString chan, TString year){
  newhisto(chan,year);
}
