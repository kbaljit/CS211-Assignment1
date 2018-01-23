//Author: Baljit Kaur
#include "fourth.h"

int main(int argc, char *argv[]) {
	Entry_t *head = NULL;
	Entry_t *array[SIZE];
	if (argc != 2){
		printf("error\n");
		return 0;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == 0){
		printf("error\n");
		return 0;
	}
	else{
		int i;
		for(i = 0; i < SIZE; i++){
			array[i] = NULL;
		}
        char c;
        int data;
        while(fscanf(file,"%c %d \n", &c, &data) == 2){
        	int key;
			if (data >= 0){
				key = data % SIZE;
			}else{
				key = -(data % SIZE);
			}
			if(c == 'i'){
				if(array[key] == NULL){
					array[key] = insert(head, data);
				}else{
					Entry_t *tmp = array[key];
					array[key] = insert(tmp, data);
				}
        	}
			else if(c == 's'){
				if(array[key] == NULL){
					printf("absent\n");
				}else{
					Entry_t *tmp = array[key];
					if(search(tmp, data) == 0){
						printf("absent\n");
					}else{
						printf("present\n");
					}
				}
        	}
        	else if((c != 'i') || (c != 's')){
        		printf("error\n");
        	}
		}
    }
	fclose(file);
    return 0;
}
