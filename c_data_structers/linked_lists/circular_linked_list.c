/*
CIRCULAR LINKED LIST 
! Sentinel value = Root
! value değeri gösterim amaçlıdır gerçek senaryolar için fonksiyonları mutlaka revize etmelisiniz.

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct n{
	int value;
	struct n * next;
}node;


node *root_init(int value) {
	node *n = (node*)malloc(sizeof(node));
	if (!n) { fprintf(stderr, "Bellek yetersiz\n"); exit(1); };
	n->value = value;
	n->next = n;
	return n;


}


node *create_node(int value){ //Başka bir node göstermeyen, sahipsiz bir boş node oluşturur.
	node *n = (node*)malloc(sizeof(node));
	if (!n) { fprintf(stderr, "Bellek yetersiz\n"); exit(1); };
	n->value = value;
	n->next = NULL;
	return n;
}
node * get_last(node *root){
if(root==NULL) {fprintf(stderr,"get_last calismadi : Root NULL bir deger\n"); return NULL;}

node *iter = root;
while(iter->next!=root){
iter = iter->next;
}
if(iter==NULL){fprintf(stderr,"get_last: Null değer bulundu. Listenin düzenini kontrol edin\n"); return NULL;}
return iter;
}



void print_list(node *root){//Tüm listeyi root null olana kadar yazdırır.
	if(root==NULL){
		printf("NULL\n");
		return;
	}

	if(root==root->next){
		printf("%d->\n",root->value);
		return;
	}
	node *iter= root;


	do{
	printf("%d->",iter->value);
		iter = iter->next;
	}while(iter!=root);
	printf("loop->%d ",root->value);
}


void link(node *root, node* n){ //Herhangi bir node'u istenilen root'un sonuna bağlar.
	if(root==NULL){fprintf(stderr,"Root bir deger ifade etmiyor"); return;} 
	if(n==NULL) {fprintf(stderr,"Eklenecek node bir deger ifade etmiyor"); return;}
	node *iter = root;
	while(iter->next!=root){
		iter= iter->next;
	}
	iter->next = n;
	n->next = root;
}

void wipe(node **root){ //Tüm listeyi baştan sona siler.
	if(*root==NULL){fprintf(stderr,"Wipe calismadı: Root bir deger ifade etmiyor\n"); return;}
	node *tmp;
	node *sentinel = *root;

	do{				//Kendisini gösterdiğinde duracak bundna dolayı ilk çalıştırmada sorgudan muaf tutuyoruz.
		tmp = *root; 		 
		*root = (*root)->next;
		memset(tmp, 0, sizeof(node));//Önce içeriğini silip hafızaya veriyorum, veriye göre önemsiz olabilir.
		free(tmp);
	}
	while(*root!=sentinel);

		*root = NULL;
	}



void delete_node(node **root , node *n){ //Node'un root olup olmama durumuna bakar ve node u siler.
		
	if(*root==NULL){
		fprintf(stderr,"Root bir deger ifade etmiyor\n");
		return;
	}
	if(n==NULL){
		fprintf(stderr,"Silinecek node bir deger ifade etmiyor\n");
		return;
	}
	node *temp = *root;
	if(*root==n){ //İlk değer silinecekse.
		if(*root==(*root)->next){
			*root=NULL;
			free(temp);
			return;
		}
		node *last = get_last(*root);
		if(last==NULL){
			fprintf(stderr,"Node silinemedi\n"); 
			return;
		}
		*root = (*root)->next;
		last->next = *root;
		free(temp);
		return;

	}

	node *iter = *root;

	while (iter->next != *root && iter->next != n)iter=iter->next;

	if(iter->next == *root) {// Listenin sonua geldi ise;
	fprintf(stderr,"Silinecek node bulunamadi\n");
	return;}

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
		(*root)->next = *root; 
		return *root;
	}
	if((*root)->next == *root && (*root)->value <= value){ //1 node varsa ve value roottan büyük ve eşitse.
		(*root)->next = n;
		n->next = *root;
		return n;
	}
	if((*root)->value >= value) { //Eklenen değer en küçükse ve eşitse.   yeni -> root a * * * *
		node *last = get_last(*root);
		n->next = *root;
		if(last!=NULL){
			*root = n;
			last->next = *root;
			return n;

		}
		fprintf(stderr,"add_new_sorted: Node eklenemedi: \n");
		return NULL;
	}
	node *iter = *root;

	while(iter->next != *root && iter->next->value <= value)
		iter=iter->next;
	if(iter->next == *root) //Son değere ulaştıysa.
	{
		iter->next= n;
		n->next = *root;
		return n;
	}
	n->next = iter->next; //Son değere ulaşmadan durdu.
	iter->next = n;


	return n;

}




int main(){
	node *root = root_init(0);
	add_new_sorted(&root, 289);
	add_new_sorted(&root, 289);
	add_new_sorted(&root, 289);
	add_new_sorted(&root, 289);
	node *b= add_new_sorted(&root, -1);
	add_new_sorted(&root, 289);
	add_new_sorted(&root, 289);
	delete_node(&root,root);

	print_list(root);
}
