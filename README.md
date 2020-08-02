# EFTD6Limits
Limits on EFT Operators with Dim 6 Warsaw Basis 
## Generation
To generate quadratic, linear and SM events follow these [instructions](https://github.com/giacomoortona/D6EFTStudies/blob/master/README.md)
When the jobs are finished there will be a folder named ZZ2e2mu_coefficient_QU/LI/SM_results.
- Launch:
```bash
python postProcess.py ZZ2e2mu_<coeff>_<QU/LI/SM>_results
head -n 3 ZZ2e2mu_<coeffic>_<QU/LI/SM>_results/postProcess.txt > /<path>/<directory>/crossSection.txt
```
- Change the path inside the file copyToDir.sh and launch:
```bash
source copyToDir.sh ZZ2e2mu_<coeff>_<QU/LI/SM> <condor_cluster_number> <directory>
```
Now there will be a directory with a .txt file and many .lhe files.
## Variables
Note: these files were written for a VBS ZZ event. The limits were obtained in terms of ZZMass and Z pT.
If you whish to use another variable you will need to refill the templates in plotterAndTemplateMaker.c and launch again bkgWorkspace1d.c.
You will find the instructions [here](https://github.com/covarell/vbs_analysis)
## Workspace
In the given folder "workspace_pT" there are the SM shapes for Z pT. 
The same applies for "workspace_M", with respect to ZZ Mass.
## Quadratic And Linear Ratio
To obtain weights for the quadratic events with respect to SM events launch:
## Quadratic And Linear Workspace
## Cards Analysis
