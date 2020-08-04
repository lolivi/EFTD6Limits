# HZZ4l-plotter
HZZ4l plotter

Please use CMSSW_8_0_24_patch1.

Download and execute the setup script:
```
cd $CMSSW_BASE/src
cmsenv
git init
git pull https://github.com/meng-xiao/HZZ4l-plotter.git
```

To update this package from the release
------------------------------------------
In the package directory, simply issue
```
git pull
```

Installation:
------------------------------
```
cd ext/
sh compile_ext.sh
cd ..
source set_library.sh
make run_makeZX 
```

Running:
------------------------------
```
./run_makeZX
```
Note that every time you add something in the code you need to recompile the code with make again.
