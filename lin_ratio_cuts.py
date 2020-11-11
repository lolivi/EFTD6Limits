# -*- coding: utf-8 -*-
#LIBRERIE
import os.path
import sys  
import urllib2 
import ROOT #ROOT
from ROOT import * 
from array import array



#FUNZIONI:
def rebinning(histo1,histo2,j,fillVar):

	xbins=[]
	formerbins=histo1.GetNbinsX()
	if (formerbins-j)%2==0: j=j-1
	newbins = (j-1) + (formerbins+1-j)/2
	if fillVar==1 : binwidth=0.
	if fillVar==0 : binwidth=180.
	xbins.append(binwidth)
	for h in range(1,newbins+1):
		if (h<j): binwidth=binwidth+50.
		else: binwidth=binwidth+100.
		xbins.append(binwidth)
	
	xbinsd = array('d',xbins)
	histo1.Rebin(newbins,"SM New",xbinsd)
	histo2.Rebin(newbins,"BSM New",xbinsd)
	histlistSM=[]
	histlistBSM=[]
	histlistSM.append(histo1)
	histlistBSM.append(histo2)
	
	rebincount=1
	newrange=200
	rebincheck=True
	
	while (rebincheck==True and newrange<=800):
	 	
		for k in range(1,newbins+1):
		
	    		if ((histlistSM[i].GetBinContent(k)) < 5 or (histlistBSM[i].GetBinContent(k)) < 5) : 
	    		
	    			rebincount=rebincount+1
	    			#printonscreen = "Rebinning numero {num}".format(num=rebincount)
	    			#print printonscreen
	    			
	    			#print " Il bin incriminato e' quello di " , k , "che inizia con ", xbins[k-1] 
	    			
	    			titolohisto1=" SM New {num}".format(num=rebincount)
	    			titolohisto2=" BSM New {num}".format(num=rebincount)
	    			
	    			formerbins=newbins
	    			
				if (k>1 and (formerbins-k)%2)==0:
					index=k-2
					while( (xbins[k-1]-xbins[index]) != (newrange/2) and index>=0 ):
						index=index-1
					k=index+1
					
				newbins = (k-1) + (formerbins+1-k)/2
	    			
	    			del xbins[k:formerbins+1]
	    			
	    			newbincont=xbins[k-1]+newrange
	    			xbins.append(newbincont)
	    			
	    			for h in range(k,newbins):
					newbincont=newbincont+newrange
					xbins.append(newbincont)
				
				xbinsd = array('d',xbins)
				histo1.Rebin(newbins,titolohisto1,xbinsd)
				histo2.Rebin(newbins,titolohisto2,xbinsd)
				histlistSM=[]
				histlistBSM=[]
				histlistSM.append(histo1)
				histlistBSM.append(histo2)
					    	
	    			break
	    		
	    		else: 	
	    			if (k==newbins): rebincheck=False
	    			continue
	    		
	    		
	    	newrange = newrange*2
	 
	
	
	print "Ratios have been rebinned with this array"
	print xbins
	print "Please change rebin from False to True in plotterAndTemplateMaker.C and copy this array"
	
	entriesBSM=histlistBSM[i].GetEntries()
    	entriesSM=histlistSM[i].GetEntries()
    	histlistBSM[i].Scale(XSBSM/entriesBSM)
    	histlistSM[i].Scale(XSSM/entriesSM)
	
	histlistRAPP.append(TH1F("BSM/SM new","BSM/SM new",newbins,xbinsd))
	
	print "float weightBSM[]={"
    	for x in range(1,newbins+1): 
    		aBSM = histlistBSM[i].GetBinContent(x)
    		bSM = histlistSM[i].GetBinContent(x)
    		r = aBSM/bSM
    		histlistRAPP[i].SetBinContent(x,r)
    		print histlistRAPP[i].GetBinContent(x),","
    	print "}"
	
	 
	
	
	







def fillHHMass(histo,filename): 
    
    secondPart=False
    p1 = [1,2,3,4]
    
    checkl=False #True only if all cuts are satisfied
    checke=False
    checkmu=False
    checkj=False
    checkz=False
    
    cond1=0
    cond2=0
        
    firste=True
    seconde=False        
    firstmu=True
    secondmu=False
    
    firstj=True
    secondj=False
    thirdj=False
    fourthj=False 
    
    
    for line in open(filename,"r"): 
        words = line.split()
        
        if len(words)<10 : #Reset of all variables when the program reads "<event>" 
        	secondPart=False
    		p1 = [1,2,3,4]
   
    		checkl=False
    		checke=False
    		checkmu=False #True only if all cuts are satisfied
    		checkj=False
    		checkz=False
    		
    		cond1=0
    		cond2=0
        
    		firste=True
    		seconde=False        
    		firstmu=True
    		secondmu=False
    		
    		firstj=True
    		secondj=False
    		thirdj=False
    		fourthj=False
    		
        	continue 
        
        #CUTS
    
        
        #LEPTONS
        if (words[0] == "11" or words[0] == "13" or words[0] == "-11" or words[0] == "-13") :
        
        
        	if (words[0]=="13" or words[0]=="-13") : #Muon
        
			if secondmu:
				mu2=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
				if mu2.Pt()>10 : cond1+=1
				if mu2.Pt()>20 : cond2+=1
				if (mu2.Pt()<=7): continue
				if abs(mu2.Eta())>=2.5 : continue
				secondmu=False
				checkmu=True
				
			
        	
			if firstmu:
				mu1=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
				if mu1.Pt()>10 : cond1+=1
				if mu1.Pt()>20 : cond2+=1
				if (mu1.Pt()<=7): continue
				if abs(mu1.Eta())>=2.5 : continue
				firstmu=False
				secondmu=True
        	
        	
        	
        	if (words[0]=="11" or words[0]=="-11") :
        	
        		
			if seconde:
				e2=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
				if e2.Pt()>10 : cond1+=1
				if e2.Pt()>20 : cond2+=1
				if (e2.Pt()<=5): continue
				if abs(e2.Eta())>=2.5 : continue
				seconde=False
				checke=True
				
			if firste:
			
				e1=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
				if e1.Pt()>10 : cond1+=1
				if e1.Pt()>20 : cond2+=1	
				if (e1.Pt()<=5): continue
				if abs(e1.Eta())>=2.5 : continue
				firste=False
				seconde=True
				
				
		if (checkmu==True and checke==True): 
			
			if cond1<2 : continue #there are no more than one lepton with pT>10
			if cond2<1 : continue
				
			if ( (e1+e2+mu1+mu2).M() < 180 ) : continue
			
			if ( (e1+e2).M() < 4 ) : continue
			if ( (mu1+mu2).M() < 4 ) : continue
			 
			#if ( (l1+l4).M() < 4 ) : continue
			#if ( (l3+l4).M() < 4 ) : continue
				
			if ( (e1+e2).M()<60 or (e1+e2).M()>120 ): continue
			if ( (mu1+mu2).M()<60 or (mu1+mu2).M()>120 ): continue
			
			checkl=True
				
        	
        	
        		
        #JETS
        		
        if ( (words[0] == "1" or words[0] == "2" or words[0] == "3" or words[0] == "4" or words[0] == "5" or words[0] == "6" or words[0] == "7" or words[0] == "8") and (words[4]=="501" or words[4]=="-501" or words[4]=="502" or words[4]=="-502") ) :	
        
        	if fourthj : 
        		
        		c4=[float(words[6]),float(words[7]),float(words[8]),float(words[9])]
        		j4=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
        		
        		if (jmax.Pt()<j4.Pt()): 
        			cmax=c4[:]
        		if (j2max.Pt()<j4.Pt() and j4.Pt()<jmax.Pt()): c2max=c4[:]
        		
        		jmax=TLorentzVector(cmax[0],cmax[1],cmax[2],cmax[3])
        		j2max=TLorentzVector(c2max[0],c2max[1],c2max[2],c2max[3])
        		
        		if jmax.Pt()<30 : continue	
        		if abs(jmax.Eta())>=4.7 : continue
        		
        		if j2max.Pt()<30 : continue	
        		if abs(j2max.Eta())>=4.7 : continue
        		
        		if ((jmax+j2max).M()<100): continue
        		
        		checkj=True
        		
        	if thirdj : 
        		c3=[float(words[6]),float(words[7]),float(words[8]),float(words[9])]
        		j3=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
        		#if j3.Pt()<30 : continue
        		#if abs(j3.Eta())>=4.7 : continue
        		if (jmax.Pt()<j3.Pt()): 
        			cmax=c3[:]
        		if (j2max.Pt()<j3.Pt() and j3.Pt()<jmax.Pt()): c2max=c3[:]
        		
        		jmax=TLorentzVector(cmax[0],cmax[1],cmax[2],cmax[3])
        		j2max=TLorentzVector(c2max[0],c2max[1],c2max[2],c2max[3])
        		
        		fourthj=True
        		firstj=False
        		
        	if secondj : 
        		c2=[float(words[6]),float(words[7]),float(words[8]),float(words[9])]
        		j2=TLorentzVector(c2[0],c2[1],c2[2],c2[3])
        		#if j2.Pt()<30 : continue
        		#if abs(j2.Eta())>=4.7 : continue
        		
        		if (jmax.Pt()<j2.Pt()): 
        			cmax=c2[:]
        			c2max=c1[:]
        		else: c2max=c2[:]
        		
        		jmax=TLorentzVector(cmax[0],cmax[1],cmax[2],cmax[3])
        		j2max=TLorentzVector(c2max[0],c2max[1],c2max[2],c2max[3])
        		
        		thirdj=True
        		secondj=False
        		
        
        	if firstj : 
        		
        		c1=[float(words[6]),float(words[7]),float(words[8]),float(words[9])]
        		j1=TLorentzVector(c1[0],c1[1],c1[2],c1[3])
        		cmax=c1[:]
        		jmax=TLorentzVector(cmax[0],cmax[1],cmax[2],cmax[3])
        		secondj=True
        		firstj=False
        		
        	#if checkj==True : print "checkj ok"
        		
        
        
        # FILL
        if words[0] == idPart : 
        	if secondPart: 
        		checkz=True
            		h1=TLorentzVector(float(words[6]),float(words[7]),float(words[8]),float(words[9]))
            		h2=TLorentzVector(p1[0],p1[1],p1[2],p1[3]) 
            		secondPart = False
        	else : 
            		p1 = [float(words[6]),float(words[7]),float(words[8]),float(words[9])]
            		secondPart = True
            		
            		
   	if ( checkl and checkj and checkz ) : 
   		
   		if fillVar == 0 : 
            		histo.Fill((h1+h2).M()) 
            	elif fillVar == 1 : 
                	histo.Fill(h1.Pt()) 
                	histo.Fill(h2.Pt())

#MAIN
names = ["1"] 
runlist = ["01"] 
outName="lin_ratio_cuts" 
colors = [kBlue,kGreen,kBlack,kYellow,kRed]
styles = [1,1,1] 
fills = [3003] 
fillVar=1 #0=mass, 1=Pt 
idPart = "23" #Z Boson Code
gStyle.SetOptTitle(1) 
gStyle.SetOptStat(0)

#NORMALIZATION
XSBSM=0.00792835092197 #fb
XSSM=0.229339569702

nBins=20
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
    if fillVar == 0: 
        appendLeg = " ZZ Mass " 
        start=180 #Range
        end =2180
        nBins=40  
    elif fillVar == 1 :
        appendLeg = " Z Transverse Momentum "
        start=0 
        end=1000
        nBins=20
    histlistBSM.append(TH1F(appendLeg+" BSM",appendLeg+" BSM",nBins,start,end))
    histlistSM.append(TH1F(appendLeg+" SM",appendLeg+" SM",nBins,start,end))
    for j in range (1,2000):
    	if (os.path.isfile("<path>/ZZ2e2mu_SM/unweighted_events_"+str(j)+".lhe")): 
   		fillHHMass(histlistBSM[i],"<path>/ZZ2e2mu/unweighted_events_"+str(j)+".lhe"")
    if(histlistBSM[i].GetBinContent(nBins+1)>0.):
    	histlistBSM[i].SetBinContent(nBins,histlistBSM[i].GetBinContent(nBins+1)+histlistBSM[i].GetBinContent(nBins))
    for j in range (0,500):
    	 if (os.path.isfile("<path>/ZZ2e2mu_SM/unweighted_events_"+str(j)+".lhe"")):
    		fillHHMass(histlistSM[i],"<path>/ZZ2e2mu_SM/unweighted_events_"+str(j)+".lhe"")
    if(histlistSM[i].GetBinContent(nBins+1)>0.):
    	histlistSM[i].SetBinContent(nBins,histlistSM[i].GetBinContent(nBins+1)+histlistSM[i].GetBinContent(nBins))#OVERFLOW
    	
    
    rebin=False
    
    for j in range(1,nBins+1):
    	if ((histlistSM[i].GetBinContent(j)) < 5 or (histlistBSM[i].GetBinContent(j)) < 5) : 
    		rebin=True
    		rebinning(histlistSM[i],histlistBSM[i],j,fillVar) 
    		break	
  
    
    
    print "nentries BSM lambda ",names[i]," = ",histlistBSM[i].GetEntries() 
    histlistBSM[i].SetLineColor(colors[i]) 
    histlistBSM[i].SetLineStyle(styles[i]) 
    histlistBSM[i].SetFillStyle(fills[i]) 
    print "nentries SM lambda ",names[i]," = ",histlistSM[i].GetEntries() 
    histlistSM[i].SetLineColor(colors[i]) 
    histlistSM[i].SetLineStyle(styles[i]) 
    histlistSM[i].SetFillStyle(fills[i])
    
    if (rebin==False): 
			   
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
    	print "}"
    	
    	
if fillVar == 0 : outName+="_M" 
elif fillVar == 1 : outName+="_Pt"

   
c = TCanvas("c","c") 
c.cd(1)

for i in range(len(runlist)): 
    histlistRAPP[i].Draw("SAME")
    if fillVar == 0 : histlistRAPP[i].SetTitle("ZZ Mass Distribution LIN/SM") 
    else : histlistRAPP[i].SetTitle("Z P_{t} Distribution LIN/SM")  
    histlistRAPP[i].GetYaxis().SetRangeUser(0,10)
    histlistRAPP[i].GetYaxis().SetTitle(" LIN Events / SM Events ")
    if fillVar == 0 : histlistRAPP[i].GetXaxis().SetTitle(" ZZ Mass [GeV] ")
    else : histlistRAPP[i].GetXaxis().SetTitle(" Z p_{t} [GeV] ")
        
      
c.SaveAs(outName+".pdf")
c.SaveAs(outName+".root")
                                           


    
	    
                                           
