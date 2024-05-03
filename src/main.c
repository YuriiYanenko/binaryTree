#include <stdio.h>
#include "binaryTree.h"
#include  <string.h>
#include <stdlib.h>

char commands[3][4] = {"ins\0", "del\0", "prn\0"};

int isDigit(char symb){
	return symb == '1'||
		symb == '2'|| 
		symb == '3'||
		symb == '4'||
		symb == '5'||
		symb == '6'||
		symb == '7'||
		symb == '8'||
		symb == '9'||
		symb == '0';
}

int getNumber(char *input){
	long number = 0;
	char *str_num = input;
	while(*str_num){
		if(isDigit(*str_num)){
			number += strtol(str_num, &str_num, 10);
			number*=10;	
		}
		else str_num++;
	}
//	number = strtol(str_num, &str_num, 10);
	return number/10;
}

int main(int argc, char** argv){
	printf("Hello, is the binary tree program, you can INSERT number DELETE number and PRINT the tree, use commands:\nins [number_to_insert]\ndel [number_to_delete]\nprn\n");
	node* root = generateNode(5);
	char command[255];
	fgets(command, 128, stdin);
	int res = strcmp(command, "exit");
	while(res){
		if(!res) break;
		char txt[4];
		memcpy(txt, command, (sizeof(char)*3));
		if(!strcmp(txt, commands[0])){
			add(root, getNumber(command));
			printf("adding %d to tree...\n", getNumber(command));
		}
		else if(!strcmp(txt, commands[1])){
			printf("deleting %d from tree...\n", getNumber(command));
			delete(root, getNumber(command));
		}
		else if (!strcmp(txt, commands[2]))
			print2D(root, 0);
		memset(command, 0, sizeof(command));
		memset(txt, 0, sizeof(txt));
		fgets(command, 128, stdin);
	}

	return 0;
}
