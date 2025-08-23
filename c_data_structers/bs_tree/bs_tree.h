#ifndef bs_tree_h
#define bs_tree_h
//If the next pointer of any node is null then we call that node as leaf(Execpt root). 

typedef struct node {
int value;
struct node* right;
struct node* left;

}node;

node *create_node(int);

node** search_item(node**,int); //Search item by value. Finded: 1 .Nothing: 0, Error: -1.

int del_item(node **, int); //Delete searched value and fixs tree shifts if we need.

int add_item(node**, int); 

node *max(node*);
node *min(node*);



//We can easly make a switch case but i want to show different algorithms with specific name.
void print_rnl(node*); // Prints tree from big to small (Right Node Left)
void print_lnr(node*); // Prints tree from small to big (Right Node Left)
void print_nrl(node*);

void wipe(node*);


#endif
