#include<stdio.h>
#include<stdlib.h>
#include "bs_tree.h"

node * create_node(int value) {
	node * n = (node*)malloc(sizeof(node));
	if(!n){
		fprintf(stderr,"Memory allocation failed\n");
		exit(1);
	}
	n-> value = value;
	n-> right = NULL;
	n-> left = NULL;
	return n;
}
node** search_item(node* root, int value){
	if(!root)
		return NULL;



	if(root->value == value){
		node** n = &root;
		return n;
	}

	if(root->value < value) //If the value greater than root value then we continue search recursivly with right child.
		return search_item(root->right,value);


	if(root->value > value)//If the value less than root value then we continue search recursivly with left child.
		return search_item(root->left,value);

	fprintf(stderr, "Unexpected case in search_item\n");
	return NULL;
}


int add_item(node** root, int value){
	if(!(*root)){ //We check nullable for every recursive deep level. 
		      //If we find any leaf showen null child then we assign a valid values.
		*root = create_node(value);
		return 0;
	}	
	if( (*root)->value == value) 
		return 1;

	if( (*root)->value < value)
			return add_item( &((*root)->right) , value);

	if( (*root)->value > value)
			return add_item( &((*root)->left) , value);

	fprintf(stderr, "Unexpected case in add_item\n");
	return -1;
}

node *max(node* root){
	if(!root)
		return NULL;

	while(root->right) //While root->right not NULL
		root = root->right;

	return root;

}

int del_item(node** root, int value){
	if(!(*root)) 
		return 1;
	
	node ** temp = search_item(*root, value);
	if(!(*temp))
		return 1;

	if((*temp)->left){
		max((*temp)->left)->right = (*temp)->right;
		free(*temp);
		(*temp) = (*temp)->left;
		return 0;
	}

}
