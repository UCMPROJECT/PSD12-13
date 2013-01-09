#include <stdlib.h>
#include <stdio.h>
#include "hackerMachine.h"

#define TAG 1
#define DEBUG 0


int main(int argc, char* argv[]) {

	int size, rank;
	int data[3];
	int ok[3] = {1,1,1};
	int res[3][3] = {{0,0,0},
					{0,0,0},
					{0,0,0}};

	// Init
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);



	MPI_Scatter(res,9,MPI_INT,data,3,MPI_INT,0,MPI_COMM_WORLD);

	int end = 0,aux_ok = 1;
	int i;
	while(end == 0){
		compareMatrixRow(data,ok,rank);
		for(i = 0;i<=3;i++){
			if(ok[i] == 1){
				data[i]++;
				aux_ok = 0;
			}
		}
		if(aux_ok == 1){
			end = 1;
		}
	}
	MPI_Gather(res,9,MPI_INT,data,3,MPI_INT,0,MPI_COMM_WORLD);

	int finish_him = checkCurrentKey(res);

	if(finish_him == 1){
		printf("Conseguido");
	}
	else{
		printf("FAIL");
	}


	MPI_Finalize();
	exit(0);
}



