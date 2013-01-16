#include <stdlib.h>
#include <stdio.h>
#include "hackerMachine.h"

#define TAG 1
#define DEBUG 0

//#define MAXCOLS 3
//#define MAXROWS 3
//#define NUMCORES 3


int main(int argc, char* argv[]) {

	/*
	int size, rank;
	int data[3];
	int ok[3] = {1,1,1};
	int res[3][3] = {{0,0,0},
					{0,0,0},
					{0,0,0}};

	*/
/*
	int size, rank;
	int Matrix[MAXROWS][MAXCOLS];
	int bitMap[MAXCOLS];

	int i,j;
	for(i = 0; i < MAXROWS; i++)
		for(j = 0; j < MAXCOLS; j++)
			Matrix[i][j] = 0;

	for(i = 0; i < MAXCOLS; i++)
		bitMap[i] = 1;

	// Init
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0)
	{
		for(i = 1;i < NUMCORES-1; i++)
			MPI_send();
	}

	initSystem(rank);

	int fin = 0;
	do
	{
		compareMatrixRow(Matrix[rank],bitMap,rank);
		int auxFin = 0;

		for( i = 1;i < MAXCOLS; i++)
		{
			if(auxFin == 0) auxFin = bitMap[i];
			Matrix[rank][i] = Matrix[rank][i] + bitMap[i];
		}

		if(auxFin == 0) fin = 1;

	}while(fin == 0);

	if(rank != 0)
		MPI_send();
	else
	{
		for(i = 1; i < MAXCOLS; i++)
			MPI_receive();

		//comparar la matriz final
	}
*/

	int size, rank;
	int data[MAX_COLS];
	int ok[MAX_COLS];
	int res[MAX_ROWS][MAX_COLS];

	int i,j = 0;
	for(i = 0; i < MAX_ROWS;i++){
		for(j=0;j < MAX_COLS; j++){
			res[i][j] = 0;
		}
		ok[i] = 1;
		data[i] = 0;
	}
	// Init
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);


	initSystem(rank);

	int block = MAX_ROWS/size;
	int frag_res[size][MAX_COLS];
	int num_data_send = size;
	int num_data_recive = MAX_COLS;


	int num;
	for(num = 0; num < block;num++){

		for(i = 0; i < size;i++){
			for(j=0;j < MAX_COLS; j++){
				frag_res[i][j] = 0;
			}
		}

		MPI_Scatter(frag_res,num_data_send,MPI_INT,data,num_data_recive,MPI_INT,0,MPI_COMM_WORLD);


		int end = 0,aux_ok = 1;
		//int i;
		while(end == 0){
			compareMatrixRow(data,ok,rank);
			aux_ok = 1;
			for(i = 0;i<MAX_COLS;i++){
				if(ok[i] == 1){
					data[i]++;
					aux_ok = 0;
				}

			}

			if(aux_ok == 1){
				end = 1;
			}
		}



		MPI_Gather(data,num_data_recive,MPI_INT,&frag_res,num_data_recive,MPI_INT,0,MPI_COMM_WORLD);


		if(rank == 0){
			int aux_i = 0;
			for(i = num*size; i < (num*size)+size;i++){
				for(j=0;j < MAX_COLS; j++){
					res[i][j] = frag_res[aux_i][j];
				}
				aux_i++;
			}
		}
	}


	if(rank == 0){
		printMatrix(res);

		int finish_him = checkCurrentKey(res);


		if(finish_him == 1){
			printf("Conseguido\n");
		}
		else{
			printf("FAIL\n");
		}
	}
	MPI_Finalize();
	exit(0);
}



