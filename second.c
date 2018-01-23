//Author: Baljit Kaur#include "second.h"

int main(int argc, char *argv[]) {
	int n;
	int i = 0;
	int flag = 0;
	if (argc != 2){
		printf("error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	for (i = 2; i < (n/2); i++){
		if(n % i == 0){
			flag = 1;
			break;
		}
	}
	if (flag == 0){
	  printf("yes\n");
	}
	else{
	  printf("no\n");
	}
	return 0;
}
