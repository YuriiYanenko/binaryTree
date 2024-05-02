#include <stdio.h>
#include "binaryTree.h"

int main(int argc, char** argv){
	node* root = generateNode(5);
	add(root, 2);
	add(root, 7);
	add(root, 1);
	add(root, 4);
	add(root, 6);
	add(root, 8);

	printf("start tree:\n");
	print2D(root, 0);
	root = delete(root, 8);

	printf("delete 8:\n");
	print2D(root, 0);
	add(root, 10);
	add(root, -5);
	add(root, -1);
	add(root, -8);

	printf("Add some new numbers:\n");
	print2D(root, 0);
	root = 	delete(root, -5);
	
	printf("delete -5:\n");
	print2D(root, 0);
	return 0;
}
