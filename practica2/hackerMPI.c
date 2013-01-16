#include <stdlib.h>
#include <stdio.h>
#include "hackerMachine.h"

#define TAG 1
#define DEBUG 0

#define MAXCOLS 3
#define MAXROWS 3
#define NUMCORES 3


int main(int argc, char* argv[]) {

	/*
	int size, rank;
	int data[3];
	int ok[3] = {1,1,1};
	int res[3][3] = {{0,0,0},
					{0,0,0},
					{0,0,0}};

	*/

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
		for(int i = 1;i < MAXCOLS; i++)
		{
			if(auxFin == 0) auxFin = bitMap[i];
			Matrix[rank] = Matrix[rank][i] + bitMap[i];
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

	/*

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

	*/
	MPI_Finalize();
	exit(0);
}



