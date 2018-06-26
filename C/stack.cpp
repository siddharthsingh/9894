#include<stdlib.h>
#include<stdio.h>
#include <fstream>
using namespace std;

#define null NULL


struct node{
	struct node *next;
	int data;
};

struct node *head = null;

void push(int data){

	struct node *temp_node = (node *)malloc(sizeof(node));
	if(!temp_node){
		printf("Memory allocation error\n");
		exit(0);
	}
	temp_node->data = data;
	temp_node->next = head;
	head = temp_node;
}


void print_stack(){

	
	struct node * temp_node = head;
	int temp_data;
	//printing linked list
	while(temp_node){

		//doing this before the next line is imp, 
		temp_data = temp_node->data;
		temp_node = temp_node->next;
		printf("%d\n",temp_data);
	}


}




int pop(){
	if(!head){
		//if head is null, nothing in list
		printf("Empty list \n");
		return 0;
	}
	int data = head->data;
	struct node * temp = head;
	head = head->next;
	free(temp);
	return data;
}



int main(){


	char ch;
	fstream fin("balanced_paranthesis.txt", fstream::in);
	int bal = 1;
	// ( -> 1   , { -> 2 , [  -> 3   
	while (fin >> noskipws >> ch) {

		switch(ch){
			case '(':{
				push(1);
				break;
			}
			case '{':{

				push(2);
				break;
			}
			case '[':{
				
				push(3);
				break;
			}
			case ')':{
					

				if(pop() != 1){
					bal = 0;
					break;
				}
				break;
			}
			case '}':{

				if(pop() != 2){
					bal = 0;
					break;
				}
				
				break;
			}
			case ']':{

				if(pop() != 3){
					bal = 0;
					break;
				}
				break;
			}


		}

		if(!bal){
			break;
		}

	}

	printf(bal==1 && head==null?"Balanced":"not balanced");


}