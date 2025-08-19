#include "queue.h"




int main(){

node * root = create_node(0);
int out;

enqueue(&root,1);
enqueue(&root,2);
enqueue(&root,3);
enqueue(&root,4);

show_queue(root);
dequeue(&root, &out);
dequeue(&root, &out);
dequeue(&root, &out);
dequeue(&root, &out);
dequeue(&root, &out);
dequeue(&root, &out);
show_queue(root);


}
