program parallel_sum
	use omp_lib

	integer :: chunk, total
	
	OMP_NUM_THREADS=8

	!$omp parallel private(chunk) shared(total)
		chunk = 0;
		total = 0;

		!$omp do
			do i=1, 1000
				chunk = chunk + i
			end do
		!$omp end do

		!$omp critical
			total = total + chunk
		!$omp end critical

	!$omp end parallel

	call sleep(30) ! check threads: ~$ ps -T -p $(pidof out)

	print *, "Total sum: ", total
end program parallel_sum