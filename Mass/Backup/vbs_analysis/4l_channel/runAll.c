{
  gROOT->ProcessLine(".L plotterAndTemplateMakerLIN.c");
  plotterAndTemplateMakerLIN(2016,1,0);
  plotterAndTemplateMakerLIN(2017,1,0);
  plotterAndTemplateMakerLIN(2018,1,0);
  gROOT->ProcessLine(".L plotterAndTemplateMakerQUAD.c");
  plotterAndTemplateMakerQUAD(2016,1,0);
  plotterAndTemplateMakerQUAD(2017,1,0);
  plotterAndTemplateMakerQUAD(2018,1,0);
}
