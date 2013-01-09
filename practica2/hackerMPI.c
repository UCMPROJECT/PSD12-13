#include <stdlib.h>
#include <stdio.h>
#include "hackerMachine.h"

#define TAG 1
#define DEBUG 0


int main(int argc, char* argv[]) {

  int size, rank;
 

  	  // Init
  	  MPI_Init(&argc, &argv);
  	  MPI_Comm_size(MPI_COMM_WORLD, &size);
  	  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  	  // Some code here!!!


  MPI_Finalize();
  exit(0);
}



