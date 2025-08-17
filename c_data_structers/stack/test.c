#include "stack_arr.h"



int main(){

	stack * depo = init_stack();
	push(depo,1);
	push(depo,2);
	push(depo,3);
	push(depo,4);
	push(depo,5);
	push(depo,6);
	pop(depo);
	stack_info(depo,1);
}
