from ROOT import *

##START CONFIG
files = ["higgsCombinegrid_observed.MultiDimFit.mH120.root","higgsCombinegrid_expected.MultiDimFit.mH120.root"]
graphNames = ["Observed","Expected"]
poiname = "k_my_1" 
outputFileName = "outPlot"
##END CONFIG


graphs = []
for i in range(len(files)) :
	print i 
	infile = TFile.Open(files[i])
	graphs.append(TGraph())
	graphs[i].SetFillStyle(0)
	graphs[i].SetName(graphNames[i])
	tree = infile.Get("limit")
	ipoint =0
	for event in tree :
		if event.deltaNLL > 10 : continue
		if poiname == "k_my_1" : graphs[i].SetPoint(ipoint,event.k_my_1, 2*event.deltaNLL)
		elif poiname == "r " : graphs[i].SetPoint(ipoint,event.r, 2*event.deltaNLL)
		else : print "POI not recognized", poiname
		#return
		ipoint = ipoint + 1
	graphs[i].Sort()
	graphs[i].SetTitle("")
	graphs[i].GetXaxis().SetTitle(poiname)
	graphs[i].GetYaxis().SetTitle("-2#Delta NLL")
	graphs[i].SetLineWidth(3)
	print graphs[i]

c = TCanvas("c","c",600,600)
c.SetTicks(1,1)
c.SetLeftMargin(0.14)
c.SetRightMargin(0.08)
graphs[0].SetLineColor(kBlue)
graphs[1].SetLineColor(kRed+1)

graphs[0].GetXaxis().SetTitleOffset(1.1)

graphs[0].Draw("AL")
graphs[1].Draw("LSAME")

leg = c.BuildLegend()
leg.SetLineColor(0)
leg.SetFillColor(0)

xmin = graphs[0].GetXaxis().GetXmin()
xmax = graphs[0].GetXaxis().GetXmax()
line = TLine(xmin,3.96,xmax,3.96)
line.SetLineColor(kBlack)
line.SetLineStyle(3)
line.SetLineWidth(3)
line.Draw("SAME")


#Text.DrawLatex(0.18, 0.78, rightText[1])
c.RedrawAxis()
#c.Update()
c.GetFrame().SetBorderSize( 12 )
c.Modified()
c.Update()

#c.SaveAs(titles[whichplot]+appString+variable+opt.options+".pdf")
#c.SaveAs(titles[whichplot]+appString+variable+opt.options+".root")
c.SaveAs(outputFileName+".pdf")
c.SaveAs(outputFileName+".root")

raw_input
