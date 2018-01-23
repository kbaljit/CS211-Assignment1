#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * next;
}node_t;
void sortedInsert(node_t* newNode);
void deleteNode(int val);
void printList();
node_t * head = NULL;

void sortedInsert(node_t* newNode){
    if (head == NULL)
    {
        head = newNode;
    }
	else if(head->value > newNode->value){
    	newNode->next = head;
        head = newNode;
	}
    else
    {
    	node_t* ptr;
        ptr = head;
       	if(ptr->value == newNode->value){
        	return;
		}
        while (ptr->next != NULL && ptr->next->value < newNode->value)
        {
            ptr = ptr->next;
        }
 	    newNode->next = ptr->next;
  	    ptr->next = newNode;
    }
}

void deleteNode(int val){
	node_t *tmp = head;
	node_t *prev;
    if (tmp != NULL && tmp->value == val)
    {
        head = tmp->next;
        free(tmp);
        return;
    }
 
    while (tmp != NULL && tmp->value != val)
    {
        prev = tmp;
        tmp = tmp->next;
    }
 
    if (tmp == NULL) return;
    
    prev->next = tmp->next;
    free(tmp);

}

void printList(){
	node_t *ptr = head;
	if(ptr == NULL){
		printf("\n");
		return;
	}
	do{
		if(ptr->next == NULL){
			printf("%d", ptr->value);
			free(ptr);
		}
		else{
			printf("%d\t", ptr->value);
			free(ptr);
		}
		ptr = ptr->next;
	}while(ptr != NULL);
}
