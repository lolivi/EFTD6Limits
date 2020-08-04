for chan in 2e2mu 4mu 4e
	do
	for year in 2016 2017 2018 
		do
		  	      
		#bsub -C 0 -q cmscaf1nd job_bkg.lsf "$chan" $cate $highmass 0
		#bsub -C 0 -q cmscaf1nd job_bkg.lsf "$chan" $cate $highmass 0
			./job_bkg.lsf "$chan" $year
			done
			done

