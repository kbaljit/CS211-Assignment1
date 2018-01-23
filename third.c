#include "third.h"

int main(int argc, char *argv[]) {
	if (argc != 2){
		printf("error");
		return 0;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == 0){
		printf("error");
		return 0;
	}
	else{
        char c;
        int data = -1;
        while(fscanf(file,"%c %d \n", &c, &data) == 2){
			if(c == 'i'){
            	node_t *newNode = (node_t *)malloc(sizeof(node_t));
            	newNode->value = data;
            	newNode->next = NULL;
            	sortedInsert(newNode);
        	}
			else if(c == 'd'){
           		deleteNode(data);
        	}
        	else if((c != 'i') || (c != 'd') || (data == -1)){
        		printf("error");
        		return 0;
			}
        }
        fclose(file);
	}
	printList();
	return 0;
}
