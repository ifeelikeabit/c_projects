#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

node * create_node(int value){

	node * que = (node*)malloc(sizeof(node));
	que -> next = NULL;
	que -> value = value;
	return que;
}
void enqueue(node** queue,int value){
	if(*queue == NULL){
		*queue = create_node(value);
		return;
	} 
	node *iter = *queue; 
	while(iter -> next != NULL)
		iter = iter -> next;

	iter -> next = create_node(value);
}


void dequeue(node** queue, int *out){ //Everytime return head.
	if(*queue==NULL){
		fprintf(stderr,"dequeue error: Queue is null.\n");
		return;
	}
	*out = (*queue)->value;
	node *temp = *queue; //we copying old head addr to temp for do free.
	*queue = (*queue)->next;
	free(temp);
}


void show_queue(node *queue){
	if(queue==NULL){
	fprintf(stderr,"Queue is null.\n");
	return;
	}

	while(queue != NULL){
		fprintf(stdout, "%d ~ " , queue->value);
		queue = queue -> next;
	}
	fprintf(stdout,"tail\n");

}
