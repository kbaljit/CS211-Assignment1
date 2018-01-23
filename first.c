//Author: Baljit Kaur
#include "first.h"

int main(int argc, char *argv[]) {
        int a;
	if (argc != 2){
		printf("error\n");
		exit(1);
	}
	a = atoi(argv[1]);
	if (a % 2 == 1){
		printf("odd\n");
	}
	else if (a % 2 == 0){
		printf("even\n");
	}
	return 0;
}
