#ifndef stack_h
#define stack_h


typedef struct stack{ 
int *array;
int top; //index of top value.
int capacity; // capacity of stack.

}stack;

stack *init_stack();
void pop(stack*);
void push(stack*,int);
void stack_info(stack*,int mode);




#endif
