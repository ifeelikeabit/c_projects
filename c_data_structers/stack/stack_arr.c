#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

stack* init_stack(){
	stack *s = (stack*)malloc(sizeof(stack));
	s->array = (int*)malloc(sizeof(int));
	s->top = -1;
	s->capacity = 2; 
	stack_info(s,0);
	return s;
}

void push(stack* x,int value){
	if(!x->array){  //If array not initilazed.
		x->array  = (int*)malloc(sizeof(int)*2);
	}
	if(x->capacity==x->top+1){//when the capacity reach full.
		fprintf(stdout,"capacity is full: %d\n",x->capacity);
		int *new = (int*)malloc(sizeof(int)*2*(x->capacity));
		for(int i=0; i<=x->top; i++)
			new[i]=x->array[i];
		free(x->array);
		x->array = new; //Transfering new array adress from new array pointer.
		x->capacity *=2;
		fprintf(stdout,"capacity increased to: %d\n",x->capacity);
	}
	x->top++;
	x->array[x->top] = value;
	fprintf(stdout,"pushed value: %d\n",value);
}

void pop(stack* x){
	if(x->top<0 || !x->array){
		fprintf(stderr,"Pop error: this stack not have a value!\n");
		return;
	}
	if(x->top+1 <= x->capacity/4 && x->capacity > 2){ //when the elements less than capacity / 4.
		fprintf(stdout,"capacity is too large for it haved values: %d\n",x->capacity);
		int *new = (int*)malloc(sizeof(int)*(x->capacity)/2);
		for(int i=0; i<=x->top; i++)
			new[i]=x->array[i];
		free(x->array);
		x->array = new; //Transfering new array adress from new array pointer.
		x->capacity /=2;
		fprintf(stdout,"capacity is decreased to: %d\n",x->capacity);

	}
	int out = x->array[x->top];
	x->top--;
	fprintf(stdout,"popped value: %d\n",out);
}


void stack_info(stack* x, int mode)
{
	if(mode == 0){
		fprintf(stdout,"STACK INFO m1\n capacity: %d\n top: %d\n",x->capacity,x->top);
		return;
	}
	else if(mode == 1){
		fprintf(stdout,"STACK INFO m1\n capacity: %d\n top: %d\n",x->capacity,x->top);

		for(int i=0;i<=x->top;i++){
			fprintf(stdout,"%d ",x->array[i]);
		}
		fprintf(stdout,"\n");
	}
}


