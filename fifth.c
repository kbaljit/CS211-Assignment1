//Author: Baljit Kaur
#include "fifth.h"

int main(int argc, char *argv[]) {
	if (argc != 2){
		printf("error\n");
		return 0;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == 0){
		printf("error\n");
		return 0;
	}
	int row;
	int col;
	int i;
	int j;
	
	fscanf(file, "%d %d", &row, &col); 
	if(row == 0 || col == 0){ 
		printf("error\n"); 
			return 0; 
	}
	if (row == col){
		int matrix[row][col];	
		for(i = 0; i < row; i++){ 
			for(j = 0; j < col; j++){ 
				fscanf(file, "%d", &matrix[i][j]); 
			} 
			fscanf(file, "\t"); 
		} 

		int add; 
		for(i = 0; i < row; i++){ 
			for(j = 0; j < col; j++){ 
				fscanf(file, "%d", &add); 
				add = (int) add + matrix[i][j]; 
				matrix[i][j] = add; 
			} 
			fscanf(file, "\t"); 
		} 
		for(i = 0; i < row; i++){ 
			for(j = 0; j < col; j++){ 
				printf ("%d\t", matrix[i][j]); 
			}
			printf("\n");
		} 
	}
	return 0;
}
