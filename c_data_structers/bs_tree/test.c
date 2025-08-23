#include <stdio.h>
#include "bs_tree.h"


int main(){



node * root = create_node(100);


for (int i=0; i<=10; i++) {
printf("%dAdd_item %d\n",i*10,add_item(&root, i*10));
}

printf("%d\n",max(root)->value);
}
