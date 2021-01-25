! gfortran main.f90 -o out -fopenmp
program omp_hw
	use omp_lib

	OMP_NUM_THREADS=8
	
	!$OMP PARALLEL
		print *, "from process: ", OMP_GET_THREAD_NUM()
	!$OMP END PARALLEL

end program omp_hw
