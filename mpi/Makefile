
#Uncomment your choice of compiler
CC    =   mpicc
#CC    =   mpigcc
#CC    =   mpipgcc

#Add your choice of flags
FLAGS   =   -O1 -w

all:    hello       \
        mpi_helloBsend \
        mpi_ringtopo


clean: 
	find . -executable -type f -exec rm -rf {} \;
	find . -iname "*~" -exec rm -rf {} \;

hello:  hello.c
	$(CC) $(FLAGS) hello.c -o hello

helloBsend:  mpi_helloBsend.c
	$(CC) $(FLAGS) mpi_helloBsend.c -o mpi_helloBsend

mpi_bandwidth: mpi_ringtopo.c 
	$(CC) $(FLAGS) mpi_ringtopo.c -o mpi_ringtopo

mpi_omp:  mpi_omp.c 
	$(CC) $(FLAGS) mpi_omp.c -o  mpi_omp
	
