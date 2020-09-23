# -*- coding: utf-8 -*-
#LIBRERIE
import os.path
import sys  
import urllib2 
import ROOT 
from ROOT import * 



#FUNZIONI:
def fillHHMass(histo,filename): 

    secondPart=False
    p1 = [1,2,3,4]
    
    for line in open(filename,"r"): 
        words = line.split()
        if len(words)<10 : continue 
        if words[0] != idPart : continue 
        if secondPart: 
            h1=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
            h2=TLorentzVector(p1[0],p1[1],p1[2],p1[3]) 
            if fillVar == 0 : histo.Fill((h1+h2).M()) 
            elif fillVar == 1 : 
                histo.Fill(h1.Pt()) 
                #histo.Fill(h2.Pt())
            secondPart = False
        else : 
            p1 = [float(words[6]),float(words[7]),float(words[8]),float(words[9])]
            secondPart = True
  
#MAIN
names = ["1"] 
runlist = ["01"] #You can add more runs
outName="quad_ratio" #output
colors = [kBlue,kGreen,kBlack,kYellow,kRed]
styles = [1,1,1] 
fills = [3003] 
fillVar=1 #0=mass, 1=Pt 
idPart = "23" #Z Boson Code
gStyle.SetOptTitle(1) 
gStyle.SetOptStat(0)#gStyle.SetOptStat(111) 

#NORMALIZATION
XSBSM=0.130530826788 #fb 
XSSM=0.227908599622

nBins=30 #bins
histlistBSM = []
histlistSM=[] 
histlistRAPP=[]



if len(colors)<len(names): 
    for k in range(len(colors),len(names)): colors.append(kBlue+k) 
if len(styles)<len(names):
    for k in range(len(styles),len(names)): styles.append(1)
if len(fills)<len(names): 
    for k in range(len(fills),len(names)): fills.append(0)
    
for i in range(len(runlist)): 
    print "running lambda = ",names[i]
    if fillVar == 0: #Mass
        appendLeg = " ZZ Mass " 
        start=180 #Range
        end =1530 
    elif fillVar == 1 :
        appendLeg = " Z Transverse Momentum "
        start=0 
        end=1500
    histlistBSM.append(TH1F(appendLeg+" BSM",appendLeg+" BSM",nBins,start,end))
    histlistSM.append(TH1F(appendLeg+" SM",appendLeg+" SM",nBins,start,end))
    for j in range (0,200): 
    	if (os.path.isfile("/<path>/ZZ2e2mu_cW_QU/unweighted_events_"+str(j)+".lhe")):
    		fillHHMass(histlistBSM[i],"/<path>/ZZ2e2mu_cW_QU/unweighted_events_"+str(j)+".lhe")
    if(histlistBSM[i].GetBinContent(nBins+1)>0.):
    	histlistBSM[i].SetBinContent(nBins,histlistBSM[i].GetBinContent(nBins+1)+histlistBSM[i].GetBinContent(nBins))
    for j in range (1,200):
	if (os.path.isfile("/<path>/ZZ2e2mu_SM/unweighted_events_"+str(j)+".lhe")):
		fillHHMass(histlistSM[i],"<path>/ZZ2e2mu_SM/unweighted_events_"+str(j)+".lhe")
    if(histlistSM[i].GetBinContent(nBins+1)>0.):
    	histlistSM[i].SetBinContent(nBins,histlistSM[i].GetBinContent(nBins+1)+histlistSM[i].GetBinContent(nBins))#OVERFLOW
    
    print "nentries BSM lambda ",names[i]," = ",histlistBSM[i].GetEntries() 
    histlistBSM[i].SetLineColor(colors[i]) 
    histlistBSM[i].SetLineStyle(styles[i]) 
    histlistBSM[i].SetFillStyle(fills[i]) 
    print "nentries SM lambda ",names[i]," = ",histlistSM[i].GetEntries() 
    histlistSM[i].SetLineColor(colors[i]) 
    histlistSM[i].SetLineStyle(styles[i]) 
    histlistSM[i].SetFillStyle(fills[i])
    entriesBSM=histlistBSM[i].GetEntries()
    entriesSM=histlistSM[i].GetEntries()
    histlistBSM[i].Scale(XSBSM/entriesBSM)
    histlistSM[i].Scale(XSSM/entriesSM)
    histlistRAPP.append(TH1F(" Z P_{t} BSM/SM "," Z P_{t} BSM/SM ",nBins,start,end))
    
    print "float weightBSM[]={"
    for x in range(1,nBins+1): 
    	aBSM = histlistBSM[i].GetBinContent(x)
    	bSM = histlistSM[i].GetBinContent(x)
    	r = aBSM/bSM
    	histlistRAPP[i].SetBinContent(x,r)
    	print histlistRAPP[i].GetBinContent(x),","
    print "};"
if fillVar == 0 : outName+="_M" 
elif fillVar == 1 : outName+="_Pt"

   
c = TCanvas("c","c") 
c.cd(1)

for i in range(len(runlist)): 
    histlistRAPP[i].Draw("SAME")
    if fillVar == 0 : histlistRAPP[i].SetTitle("ZZ Mass Distribution QUAD/SM")
    else : histlistRAPP[i].SetTitle("Z P_{t} Distribution QUAD/SM")  
    histlistRAPP[i].GetYaxis().SetRangeUser(0,600)
    histlistRAPP[i].GetYaxis().SetTitle(" QUAD Events / SM Events ")
    if fillVar == 0 : histlistRAPP[i].GetXaxis().SetTitle(" ZZ Mass [GeV] ") 
    else : histlistRAPP[i].GetXaxis().SetTitle(" Z p_{t} [GeV] ")
               
c.SaveAs(outName+".pdf")
c.SaveAs(outName+".root")


                                           


    
	    
                                           
