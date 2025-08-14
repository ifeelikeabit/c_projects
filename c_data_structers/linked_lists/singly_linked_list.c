/*
SINGLY LINKED LIST 
! Sentinel value = NULL
! value değeri gösterim amaçlıdır gerçek senaryolar için fonksiyonları mutlaka revize etmelisiniz.

*/



#include <stdio.h>
#include <stdlib.h>



typedef struct n{
	int value;
	struct n * next;
}node;




node *create_node(int value){ //Başka bir node göstermeyen, sahipsiz bir boş node oluşturur.
	node *n = (node*)malloc(sizeof(node));
	if (!n) { fprintf(stderr, "Bellek yetersiz\n"); exit(1); };
	n->value = value;
	n->next = NULL;
	return n;
}



void print_list(node *root){//Tüm listeyi root null olana kadar yazdırır.
	if(root==NULL){
		printf("NULL\n");
		return;
	}

	while(root!=NULL)
	{
		printf("%d->",root->value);
		root = root->next;
	}
	printf("NULL\n");
}


void link(node *root, node* n){ //Herhangi bir node'u istenilen root'un sonuna bağlar.
	if(root==NULL){fprintf(stderr,"Root bir deger ifade etmiyor"); return;} 
	if(n==NULL) {fprintf(stderr,"Eklenecek node bir deger ifade etmiyor"); return;}
	while(root->next!=NULL){
		root = root->next;
	}
	root->next = n;
	n->next = NULL;
}

void wipe(node **root){ //Tüm listeyi baştan sona siler.
	if(root==NULL){fprintf(stderr,"Wipe calismadi: Root bir deger ifade etmiyor"); return;} 
	node *tmp;
	while(*root!=NULL){

		tmp = *root; 
		*root = (*root)->next;
		free(tmp);

	}
*root = NULL;
}



void delete_node(node **root , node *n){ //Node'un root olup olmama durumuna bakar ve node u siler.
		
	if(*root==NULL){
		fprintf(stderr,"delete_node: Root bir deger ifade etmiyor\n");
		return;
	}
	if(n==NULL){
		fprintf(stderr,"Silinecek node bir deger ifade etmiyor\n");
		return;
	}
	if(*root==n){ //İlk değer silinecekse.
		*root = (*root)->next;
		free(n);
		return;
	}

node *iter = *root;

while (iter->next != NULL && iter->next != n)iter=iter->next;
if(iter->next == NULL) {// Listenin sonua geldi ise;
	fprintf(stderr,"Silinecek node bulunamadi\n");
	return;
}

iter->next = n->next;
free(n);
return;
}



node * add_new(node **root, int value){ //Rootun sonuna yeni bir node oluşturup bağlar. Eklenen node'u döndürür. 
	node * n = create_node(value);
	if(*root==NULL){
		*root=n; 
		return *root;

	}
	link(*root,n);
	return n;
}

//SIRALI EKLEME KÜÇÜKTEN BÜYÜĞE
node * add_new_sorted(node **root, int value){//Kucukten buyuge eleman ekler. Eklenen node'u döndürür. 
	node * n = create_node(value);
	if(*root==NULL) {//Root yoksa.
		*root=n; 
		return *root;
	}
	if((*root)->next == NULL && (*root)->value <= value){ //1 node varsa ve value roottan büyük ve eşitse.
		(*root)->next = n;
		return n;
	}
	if((*root)->value >= value) { //Eklenen değer en küçükse ve eşitse.
		n->next = *root;
		*root = n;
		return n;
	}
	node *iter = *root;

	while(iter->next != NULL && iter->next->value <= value)
		iter=iter->next;
	if(iter->next == NULL) //Son değere ulaştıysa.
	{
		iter->next= n;
		return n;
	}
	n->next = iter->next; //Son değere ulaşmadan durdu.
	iter->next = n;


	return n;

}




int main(){
	//örnek
	node * root = create_node(0);
	node * a = create_node(1);
	for(int i=0;i<10;i++){
		add_new_sorted(&root,i*10);
	}
	delete_node(&root, a);

	print_list(root);

	wipe(&root);
}
