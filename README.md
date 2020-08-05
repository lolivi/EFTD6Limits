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
- Download copyToDir.sh from this repository:
```bash
wget https://github.com/lolivi/EFTD6Limits/blob/master/copyToDir.sh
```
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
mkdir weights
cd weights
mkdir cW
cd cW
mkdir Mass
cd Mass
wget https://github.com/lolivi/EFTD6Limits/blob/master/quad_ratio.py
wget https://github.com/lolivi/EFTD6Limits/blob/master/lin_ratio.py
```
- Change the path and write 0 if you are using the boson mass or 1 for the transverse momentum.
- In line 49 you can change the binning. **Note: I used 27 bins for ZZMass with a range of (180,1530) GeV and 30 bins for Z pT with a range of (0,1500) GeV**.
- If you are using another boson, change the PDG code in line 41 (23 is for Z, 24 is for positive charged W and so on...)
- Change the cross sections in line 46 and 47, which are used to normalize the plots. You will find them in the txt file obtained in the generation section.
- Then launch:
```bash
python quad_ratio.py
```
- You should get on screen "float weightBSM = {...};" and a pdf file for the plot. Copy it and save it for later.
- Now return to .../CMSSW_8_0_26_patch1/src/
```bash
cd .../CMSSW_8_0_26_patch1/src/
mkdir Mass
mkdir pT
git clone https://github.com/lolivi/EFTD6Limits.git
cp -r EFTD6Limits/Mass/Backup/* Mass/
cp -r EFTD6Limits/Mass/workspace/ Mass/
cp -r EFTD6Limits/pT/Backup/* pT/
cp -r EFTD6Limits/pT/workspace/ pT/
rm -rf EFTD6Limits
```
- You need to create some empty directories:
```bash
cd .../vbs_analysis/4l_channel/
mkdir error
mkdir log
mkdir noScaleZX
mkdir output
```

- Almost every file in vbs_analysis/4l_channel/ has a keyword ```<path>```. If you find it on a file you have to change it. The files you have to change are plotterAndTemplateMakerQUAD.c and LIN, condor.sub and runAll.sh.
```bash
emacs -nw plotterAndTemplateMakerQUAD.c
C-s 
<path>
```
- Delete ```<path>``` and write your own path
- Now, if you are using pT:
```bash
cd pT
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
- Do the same for the linear events with plotterAndTemplateMakerLIN.c
- Check that everything is okay:
```bash
root -l
.L plotterAndTemplateMakerQUAD.c
.L plotterAndTemplateMakerLIN.c
.q
```
- If everything is okay launch:
```bash
condor_submit condor.sub
```
- When the jobs are finished you will get two txt files named lin_MCyields_2016(17/18).txt and quad_MCyields_2016(17/18).txt
- These contain the integrals of the processes divided by year. So number 1 is the weighted vbs process for 2016 while the other 4 are just the SM processes. Then number 6 will be the weighted vbs process for 2017 and so on.
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
wget https://github.com/lolivi/EFTD6Limits/blob/master/hadd.sh
source hadd.sh
```
- Now you should have the complete set of shapes named "tot_...input_func.root"
## Analysis
For this section use CMSSW_10_2_13 and Combine. To download Combine go [here](http://cms-analysis.github.io/HiggsAnalysis-CombinedLimit/).
- Copy the workspace from the previous section in the directory used for the analysis.
- Download the cards from pT/cards/... (or Mass/cards/...)
- Open the files named lin_MCyields_2016(17/18).txt and quad_MCyields_2016(17/18).txt 
- Copy number 1, 6 and 11 and paste in the cards in the processes named "linear_1" (or "quadratic_1")
- Now the cards should be ready
- You can download the physics model from [here](https://github.com/amassiro/AnalyticAnomalousCoupling/tree/master/python)
- Copy AnomalousCoupling.py in ".../CMSSW_10_2_13/src/HiggsAnalysis/CombinedLimit/python"
### Combine
Finally launch:
```bash
combineCards.py -S card_all_2016_1D.txt card_all_2017_1D.txt card_all_2018_1D.txt > card_all_2016-18.txt 
text2workspace.py card_all_2016-18.txt -P HiggsAnalysis.CombinedLimit.AnomalousCoupling:analiticAnomalousCoupling --PO=k_cW,r -o model_test.root
```
- For the observed:
```bash
combine -M MultiDimFit model_test.root --freezeParameters r --redefineSignalPOIs k_my_1 --setParameters r=1 --algo singles --cl=0.95 -n singles_95_observed --robustFit=1 --do95=1
```
If it doesn't find the 95% crossing add "--setCrossingTolerance=0.0000000000001"
- If you want to plot the likelihood launch:
```bash
combine -M MultiDimFit model_test.root --algo grid --points 1000 --redefineSignalPOIs k_my_1 --freezeParameters r --setParameters r=1 -n grid_observed --setParameterRanges k_my_1=-2.5,2.5
```
- For the expected launch:
```bash
combine -M MultiDimFit model_test.root --freezeParameters r --redefineSignalPOIs k_my_1 --setParameters r=1,k_my_1=0 --algo singles --cl=0.95 -n singles_95_expected --do95=1 --robustFit=1 --expectSignal=1 -t-1
combine -M MultiDimFit model_test.root --algo grid --points 1000 --redefineSignalPOIs k_my_1 --freezeParameters r --setParameters r=1,k_my_1=0 -n grid_expected --setParameterRanges k_my_1=-2.5,2.5 --expectSignal=1 -t -1 
```
- Finally, if you want the complete plot launch:
```bash
wget https://github.com/lolivi/EFTD6Limits/blob/master/plotCombine.py
python plotCombine.py
```
- You will find my results here (link mancante). They are for VBS ZZ with ZZMass and Z pT. The operators are cHDD, cW and cHWB.   
