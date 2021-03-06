# EFTD6Limits
Limits on EFT Operators with Dim 6 Warsaw Basis 
## Generation
To generate quadratic, linear and SM events follow these [instructions](https://github.com/giacomoortona/D6EFTStudies/blob/master/README.md)\
When the jobs are finished there will be a directory named ZZ2e2mu_coefficient_QU/LI/SM_results.
- Go to .../D6EFTStudies/generation/
- There should be a python file called postProcess.py . If there isn't download it from this [link](https://github.com/giacomoortona/D6EFTStudies/tree/master/generation)
- Launch:
```bash
python postProcess.py ZZ2e2mu_<coeff>_<QU/LI/SM>_results
head -n 3 ZZ2e2mu_<coeffic>_<QU/LI/SM>_results/postProcess.txt > /<path>/<directory>/crossSection.txt
```
- Download copyToDir.sh from this repository
- Change the path inside the file copyToDir.sh and launch:
```bash
source copyToDir.sh ZZ2e2mu_<coeff>_<QU/LI/SM> <condor_cluster_number> <directory>
```
Now there will be a directory with a txt file and many lhe files.
## Variables
#### Note: these files were written for a VBS ZZ event. The limits were obtained in terms of ZZMass and Z pT.
If you want to use another variable you will need to refill the templates in plotterAndTemplateMaker.c and launch again bkgWorkspace1d.c.\
You will find the instructions [here](https://github.com/covarell/vbs_analysis)
## Workspace
You will find the SM shapes for Z pT (and ZZMass) in pT/workspace/1D_...input_func.root (or Mass/workspace/1D_...input_func.root)
## Quadratic And Linear Workspace
- For this section use a **CMSSW_8_0_26_patch1** environment
```bash
export SCRAM_ARCH=slc7_amd64_gcc530
cmsrel CMSSW_8_0_26_patch1
cd CMSSW_8_0_26_patch1/src/
```
- To obtain weights for the quadratic events with respect to SM events download quad_ratio.py.
- My recommendation is to create a directory for each operator, because there will be a lot of output files.
- For example, if you are using cW:
```bash
cd .../CMSSW_8_0_26_patch1/src/
git clone https://github.com/lolivi/EFTD6Limits.git
mkdir weights
cd weights
mkdir cW
cd cW
mkdir Mass
mkdir pT
cp .../CMSSW_8_0_26_patch1/src/EFTD6Limits/lin_ratio.py ./pT/
cp .../CMSSW_8_0_26_patch1/src/EFTD6Limits/lin_ratio.py ./Mass/
cp .../CMSSW_8_0_26_patch1/src/EFTD6Limits/quad_ratio.py ./pT/
cp .../CMSSW_8_0_26_patch1/src/EFTD6Limits/quad_ratio.py ./Mass/
```
- Change the path and write 0 if you are using the boson mass or 1 for the transverse momentum.
- In line 49 you can change the binning. **Note: I used 40 bins for ZZMass with a range of (180,2180) GeV and 20 bins for Z pT with a range of (0,1000) GeV**.
- If you are using another boson, change the PDG code in line 41 (23 is for Z, 24 is for positive charged W and so on...)
- Change the cross sections in line 46 and 47, which are used to normalize the plots. You will find them in the txt file obtained in the generation section.
- Then launch:
```bash
python quad_ratio.py
```
- You should get on screen "float weightBSM = {...};" and a pdf file for the plot. Copy it and save it for later.
- You can also use quad_ratio_cuts.py, a file which cointains all the cuts from the ZZjj inclusive selection. It also has a function which rebins all the histograms from SM and BSM, so that there are no less than 5 events per bin.
- You should get on screen the array used for the rebinned histograms, copy it and save it for later. 
- Now return to .../CMSSW_8_0_26_patch1/src/
```bash
cd .../CMSSW_8_0_26_patch1/src/
mkdir Mass
mkdir pT
cp -r EFTD6Limits/Mass/Backup/* Mass/
cp -r EFTD6Limits/Mass/workspace/ Mass/
cp -r EFTD6Limits/pT/Backup/* pT/
cp -r EFTD6Limits/pT/workspace/ pT/
```
- You need to create some empty directories:
```bash
cd .../vbs_analysis/4l_channel/
mkdir error
mkdir log
mkdir noScaleZX
mkdir output
```
- Almost every file in vbs_analysis/4l_channel/ has a keyword ```<path>```. If you find it on a file you have to change it. The files you have to change are plotterAndTemplateMaker.c, plotterAndTemplateMakerQUAD.c and LIN, condor.sub, runAll.sh, job_bkg.sh, job_bkg_QUAD.sh and job_bkg_LIN.sh.
```bash
emacs -nw plotterAndTemplateMakerQUAD.c
C-s 
<path>
```
- Delete ```<path>``` and write your own path
- Now, if you are using pT:
```bash
cd .../CMSSW_8_0_26_patch1/src/pT
cmsenv
cd data_driven_MC/ext/
sh compile_ext.sh
cd ..
source set_library.sh
cd ..
cd vbs_analysis/4l_channel/
emacs -nw plotterAndTemplateMakerQUAD.c
```
- Copy "float weightBSM = {..};" in plotterAndTemplateMakerQUAD.c
- If you used quad_ratio_cuts.py and the histograms have been rebinned, you have to change the variable "rebin" from False to True and paste the array used for the rebinning.
- Do the same for the linear events with plotterAndTemplateMakerLIN.c
- If the histograms have been rebinned, you have to change also plotterAndTemplateMaker.C to get the rebinned SM shapes.
- Check that everything is okay:
```bash
root -l
.L plotterAndTemplateMakerQUAD.c
.L plotterAndTemplateMakerLIN.c
.q
```
- If you have rebinned your histograms, change runAll.c and add plotterAndTemplateMaker.C.
- If everything is okay launch:
```bash
condor_submit condor.sub
```
- When the jobs are finished you will get two txt files named lin_MCyields_2016(17/18).txt and quad_MCyields_2016(17/18).txt
- These contain the integrals of the processes divided by channel. So number 1 is the weighted vbs process for 4mu. Then number 2 will be the weighted vbs process for 4e and 3 for 2e2mu.
- You will also get root files called quad_vbs_Moriond_2016.root and lin_vbs_Moriond_2016.root. These are used to create the workspace.
- Now launch:
```bash
root -l
.L bkgWorkspace1dQUAD.c
.q
source runbkg_QUAD.sh
```
- Do the same for the linear events
- You will find in the directory "workspace" new root files named "quad_1D_vbs4lSyst_4e1S_2016.input_func.root" and "lin_1D_vbs4lSyst_4e1S_2016.input_func.root".
- These need to be added to the SM shapes. Go to the directory where shapes are stored and launch:
```bash
cd vbs_analysis/4l_channel/workspace/
cp .../CMSSW_8_0_26_patch1/src/EFTD6Limits/hadd.sh .
source hadd.sh
```
- Now you should have the complete set of shapes named "tot_...input_func.root".
- If you have a negative linear interfernce term, you need to change in histo3.c the name of the operator.
- Do the same in newhisto.lsf
- Then launch
```bash
source runnewhisto.sh
source haddnew.sh
```
## Analysis
For this section use CMSSW_10_2_13 and Combine. To download Combine go [here](http://cms-analysis.github.io/HiggsAnalysis-CombinedLimit/).
```bash
export SCRAM_ARCH=slc7_amd64_gcc700
cmsrel CMSSW_10_2_13
cd CMSSW_10_2_13/src/
```
- Copy the workspace from the previous section in the directory used for the analysis. For example, for cW:
```bash
mkdir cW
cd cW
mkdir pT
mkdir Mass
cd pT
cp -r .../CMSSW_8_0_26_patch1/src/pT/vbs_analysis/4l_channel/workspace/ .
cd ..
cd Mass
cp -r .../CMSSW_8_0_26_patch1/src/Mass/vbs_analysis/4l_channel/workspace/ .
```
- Download the cards from pT/cards/... (or Mass/cards/...)
```bash
cd .../CMSSW_10_2_13/src/cW/
cp -r .../EFTD6Limits/pT/cards/* ./pT/
cp -r .../EFTD6Limits/Mass/cards/* ./Mass/
```
- Open the files named lin_MCyields_2016(17/18).txt and quad_MCyields_2016(17/18).txt 
- If the linear interference is positive copy number 1, 2 and 3 and paste in the cards in the processes named "linear_1" (or "quadratic_1")
- If the interference is negative the linear process becomes sm_lin_quad_<opname> and the quadratic becomes quad_<opname>
- Copy the SM+LIN+QUAD integral in sm_lin_quad, and the QUAD integral in quad
- Now the cards should be ready
- You can download the physics model from [here](https://github.com/amassiro/AnalyticAnomalousCoupling/tree/master/python) for the positive analysis
- Download AnomalousCouplingEFTNegative.py for the negative analysis
- Copy in ".../CMSSW_10_2_13/src/HiggsAnalysis/CombinedLimit/python"
### Combine
Finally launch for the positive:
```bash
combineCards.py -S card_all_2016_1D.txt card_all_2017_1D.txt card_all_2018_1D.txt > card_all_2016-18.txt 
text2workspace.py card_all_2016-18.txt -P HiggsAnalysis.CombinedLimit.AnomalousCoupling:analiticAnomalousCoupling -o model_test.root --PO=k_cW,r
```
- For the observed:
```bash
combine -M MultiDimFit model_test.root --freezeParameters r --redefineSignalPOIs k_cW --setParameters r=1 --algo singles --cl=0.95 -n singles_95_observed --robustFit=1 --do95=1
```
If it doesn't find the 95% crossing add "--setCrossingTolerance=0.0000000000001"
- If you want to plot the likelihood launch:
```bash
combine -M MultiDimFit model_test.root --algo grid --points 1000 --redefineSignalPOIs k_cW --freezeParameters r --setParameters r=1 -n grid_observed --setParameterRanges k_cW=-2.5,2.5
```
- For the expected launch:
```bash
combine -M MultiDimFit model_test.root --freezeParameters r --redefineSignalPOIs k_cW --setParameters r=1,k_cW=0 --algo singles --cl=0.95 -n singles_95_expected --do95=1 --robustFit=1 -t-1 
combine -M MultiDimFit model_test.root --algo grid --points 1000 --redefineSignalPOIs k_cW --freezeParameters r --setParameters r=1,k_cW=0 -n grid_expected --setParameterRanges k_cW=-2.5,2.5 -t -1 
```
- For the negative launch:
```bash
combineCards.py -S card_all_2016_1D.txt card_all_2017_1D.txt card_all_2018_1D.txt > card_all_2016-18.txt 
text2workspace.py card_all_2016-18.txt -P HiggsAnalysis.CombinedLimit.AnomalousCouplingEFTNegative:analiticAnomalousCouplingEFTNegative -o model_test.root --X-allow-no-signal --PO eftOperators=cW
combine -M MultiDimFit model_test.root --freezeParameters r --redefineSignalPOIs k_cW --setParameters r=1 --algo singles --cl=0.95 -n singles_95_observed --robustFit=1 --do95=1
combine -M MultiDimFit model_test.root --algo grid --points 1000 --redefineSignalPOIs k_cW --freezeParameters r --setParameters r=1 -n grid_observed --setParameterRanges k_cW=-2.5,2.5
combine -M MultiDimFit model_test.root --freezeParameters r --redefineSignalPOIs k_cW --setParameters r=1,k_cW=0 --algo singles --cl=0.95 -n singles_95_expected --do95=1 --robustFit=1 -t-1 
combine -M MultiDimFit model_test.root --algo grid --points 1000 --redefineSignalPOIs k_cW --freezeParameters r --setParameters r=1,k_cW=0 -n grid_expected --setParameterRanges k_cW=-2.5,2.5 -t -1
```
- Finally, if you want the complete plot of both the expected and observed launch:
```bash
cp .../EFTD6Limits/plotCombine.py .
python plotCombine.py
```
- You can now remove the EFTD6Limits directory.
```bash
rm -rf EFTD6Limits
```
