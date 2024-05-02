#ifndef BINARYTREE_H
#define BINARYTREE_H
	typedef struct node {
		int item;
		struct node* leftChild;
		struct node* rightChild;
	} node;

	node* generateNode(int);
	void add(node*, int);
	void print2D(node*, int);
	int search(node*, int);
	node* delete(node*, int);
#endif
