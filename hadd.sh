for chan in 2e2mu 4mu 4e
do
    for year in 2016 2017 2018
    do
	hadd -f tot_1D_vbs4lSyst_"$chan"1S_"$year".input_func.root 1D_vbs4lSyst_"$chan"1S_"$year".input_func.root newlin_1D_vbs4lSyst_"$chan"1S_"$year".input_func.root newquad_1D_vbs4lSyst_"$chan"1S_"$year".input_func.root
    done
done


    
