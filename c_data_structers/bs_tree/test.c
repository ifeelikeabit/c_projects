#include <stdio.h>
#include <stdlib.h>
#include "bs_tree.h"
#include <time.h>

int main(){

srand(time(NULL));

node * root = create_node(100);


for (int i=0; i<=10; i++) {
	int random = (rand()%10000);
	printf("%d Add_item %d\n",random,add_item(&root,random));
}

del_item(&root, 100);
print_lnr(root); 



getchar();
wipe(&root);
getchar();
print_lnr(root); 

}
