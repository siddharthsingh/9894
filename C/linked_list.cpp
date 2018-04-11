/*

Simple linked list implementation 

Created by: Siddharth Singh
Date: 4/11/2018


*/

#include<stdio.h>
#include<stdlib.h>
#define null 0

//structure of each linked list node 
struct node
{
	int data;
	struct node *next;
};

//push data into the front of the list 
node * push(node *head , int data){
	struct node *temp = (node *)malloc(sizeof(node));
	//check if memory allocated
	if(!temp){
		//memory allocation failed. show error and exit
		printf("Memory allocation failed, Exiting.\n");
		exit(EXIT_FAILURE);
	}
	//insert data into new node
	temp->data = data;
	//update the next node of new node to be head
	temp->next = head;
	//update head to point to new node
	head = temp;
	//return the new head of the list
	return head;
}


//pop nodes from the head of the list
node * pop(node *head){
	if(!head){
		//if head is null, nothing in list
		printf("Empty list \n");
		return null;
	}
	//create a temp pointer to head node, as we will need it to free its memory
	node * temp = head;
	//update the head to point to the second node in list
	head = head->next;
	//free the original head node
	free(temp);
	//return the new head of the list
	return head;
}


int main(){
	struct node * head = null;
	int i=0;
	//inserting data into linked list
	for(i;i<100;i++){
		head = push(head, i);
	}
	i=0;

	struct node * temp_node = head;
	int temp_data;
	//printing linked list
	for(i;i<100;i++){
		temp_data = temp_node->data;
		temp_node = temp_node->next;
		printf("%d\n",temp_data);
	}
	//removing nodes from linked list
	for(i;i<50;i++){
		head = pop(head);
	}	
	return 0;
}