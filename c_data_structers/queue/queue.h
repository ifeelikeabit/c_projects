#ifndef queu_h
#define queu_h

typedef struct node{

int value; //This integer value is peresent of any value of queue for showing how proccess happens.
struct node * next;


}node;

node * create_node(int value); //It is assign a null to node->next.

void enqueue ( node ** queue, int value); //New nodes are added at the end.

void dequeue (node **queue, int *out); //You can read values from out pointer. Be sure create a ptr or pass var addr.


void show_queue(node *queue);

#endif
