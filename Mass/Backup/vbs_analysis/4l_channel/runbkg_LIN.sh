for chan in 2e2mu 4mu 4e
	do
	for year in 2016 2017 2018 
		do
		  	      
	
			./job_bkg_LIN.lsf "$chan" $year
			done
			done

