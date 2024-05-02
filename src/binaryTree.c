#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#define COUNT 5

node* generateNode(int item){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->item = item;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

int isNull(node* root){
	return root == NULL;
}

void insertLeft(node* root, int item){
	if(isNull(root->leftChild))
		root->leftChild = generateNode(item);
	else add(root->leftChild, item);
}

void insertRight(node* root, int item){
	if(isNull(root->rightChild))
		root->rightChild = generateNode(item);
	else add(root->rightChild, item);
}

void print2D(node* root, int space){
	if(isNull(root)) return;
	space += COUNT;

	print2D(root->rightChild, space);

	printf("\n");

	for(int i = 0; i < space; i++)
		printf(" ");
	printf("%d\n", root->item);

	print2D(root->leftChild, space);

}

void add(node *root, int item){
	if(isNull(root)) return;
	if(item > root->item)
		insertRight(root, item);
	else insertLeft(root, item);
}

int search(node *root, int key){
	if(isNull(root))
		return 0;
	if(root->item == key)
		return 1;
	else if(key < root->item)
		return search(root->leftChild, key);
	else return search(root->rightChild, key);
}

node * delete(node *root, int key){
	if(isNull(root)) return root;

	if(key > root->item){
		root->rightChild =  delete(root->rightChild, key);
		return	root;
	}
	
	else if(key < root->item){
		root->leftChild =  delete(root->leftChild, key);
		return	root;
	}
	if(isNull(root->leftChild)){
		node* temp = root->rightChild;
		free(root);
		return temp;
	}
	else if(isNull(root->rightChild)){
		node* temp = root->leftChild;
		free(root);
		return temp;
	}

	node* succParent = root;
	node* succ = root->rightChild;
	while(!isNull(succ->leftChild)){
		succParent = succ;
		succ = succParent->leftChild;
	}

	root->item = succ->item;

	if(succParent->leftChild == succ)
		succParent->leftChild = succ->rightChild;
	else succParent->rightChild = succ->rightChild;

	free(succ);
	return root;
}
