#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

typedef struct Entry{
   int data;   
   struct Entry * next;
}Entry_t;
Entry_t *insert(Entry_t *head, int value);
int *search(Entry_t *head, int value);

Entry_t *insert(Entry_t *head, int value){
	if (head == NULL){
		head = (Entry_t *)malloc(sizeof(Entry_t));
		head->data =value;
		head->next = NULL;
		printf("inserted\n");
		return head;
	}else{
		if (search(head, value) == (int *)1){
			printf("duplicate\n");
			return head;
		}
		Entry_t *newEntry;
		Entry_t *tmp = head;
		while (tmp->next != NULL){
			tmp = tmp->next;
		}
		newEntry = malloc(sizeof(Entry_t));
		newEntry->data = value;
		tmp->next = newEntry;
		newEntry->next = NULL;
		printf("inserted\n"); 
		return head; 
	}
}

int *search(Entry_t *head, int value){
	if (head == NULL){
		return 0;
	}
	Entry_t *tmp = head;
	while (tmp != NULL){
   		if(tmp->data == value){
   			return (int *)1;
   		}
   		tmp = tmp->next;
	}
	return 0;
}
