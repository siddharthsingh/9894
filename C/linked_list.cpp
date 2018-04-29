/*

Simple linked list implementation 

Created by: Siddharth Singh
Date: 4/11/2018


*/

#include<stdio.h>
#include<stdlib.h>
#define null NULL

//structure of each linked list node 
struct node
{
	int data;
	struct node *next;
};


struct node * head = null;

void print_linked_list(){

	
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


//push data into the front of the list 
void push(int data){
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
}


//pop nodes from the head of the list
int pop(){
	if(!head){
		//if head is null, nothing in list
		printf("Empty list \n");
		return 0;
	}
	//create a temp pointer to head node, as we will need it to free its memory
	node * temp = head;
	int data = head->data;
	//update the head to point to the second node in list
	head = head->next;

	//free the original head node
	free(temp);
	//return the new head of the list
	return data;
}

void push_back(int data)
{
	//when head->next = null , insert the node


	node *temp = (node *)malloc(sizeof(node));
	//check if memory allocated
	if(!temp)
	{
		//memory allocation failed. show error and exit
		printf("Memory allocation failed, Exiting.\n");
		exit(EXIT_FAILURE);
	}
	
	temp->data = data;
	temp->next = null;	
	
	if(!head)
	{
		head=temp;
		return;

	}else
	{
		node * last = head;
		//temp->next will be null for last node
		while(last->next) last = last->next;
		last->next = temp;


	}

}

int pop_back(){


	if(!head){
		printf("Empty List\n");
		return 0;

	}else{


		node * last = head;
		int temp_data;
		if(!last->next){
			temp_data = head->data;
			free(head);
			return temp_data;
		}
		while(last->next->next)last = last->next;
		temp_data = last->next->data;
		free(last->next);
		last->next=null;
		return temp_data;
	}


}

bool is_value_in_list(int data){
	node * temp = head;
	while(temp){
		if(temp->data == data) return true;
		temp = temp->next;
	}
	return false;
}


void insert_at(int position , int data){

	int current_pos = 0;
	node * last = head;

	node *temp = (node *)malloc(sizeof(node));
	//check if memory allocated
	if(!temp)
	{
		//memory allocation failed. show error and exit
		printf("Memory allocation failed, Exiting.\n");
		exit(EXIT_FAILURE);
	}
	
	temp->data = data;
	temp->next = null;	
	if(position==0){
		temp->next = head;
		head = temp;
		return;
	}
	while(current_pos++!=position-1)last = last->next;
	temp->next = last->next;
	last->next = temp;


}

int get_nth_item(int n){
	if(n<0){
		printf("Index can't be less than zero!\n");
		exit(EXIT_FAILURE);
	}
	int current_pos = 0;
	node * last = head;
	while(current_pos++!=n){
		last=last->next;
		if(!last){
			printf("Index can't be greater than the size of linked list\n");
		}
	}
	return last->data;

}

void remove_node(int position){
	int current_pos = 0;
	node * last = head;

	if(position==0){
		head = head->next;
		free(last);
		return;
	}
	while(current_pos != position-1){
		current_pos++;
		last = last->next;
	}
	node *temp = last->next;
	last->next = last->next->next;
	free(temp);

}




int main(){
	
	int i=0;
	
	//inserting data into linked list
	for(i;i<10;i++){
		push(i);
	}
	printf("\n\nLinked list after inserting data: \n");
	print_linked_list();
	i=0;
	
	//removing nodes from linked list
	for(i;i<5;i++){
		pop();
	}	
	printf("\n\nLinked list after poping data: \n");
	print_linked_list();

	//Push back data
	push_back(11);
	push_back(12);
	push_back(13);
	push_back(14);
	push_back(15);
	push_back(16);
	printf("\n\nLinked list after push back data: \n");
	print_linked_list();



	printf("\n\nPoping last node, value : %d \n", pop_back());


	printf("\n\nLinked list: \n");
	print_linked_list();
	printf("\n\nIs 15 in the list?\n");
	printf(is_value_in_list(15) ? "True\n"  : "False\n" );

	printf("\n\nIs 16 in the list?\n");
	printf(is_value_in_list(16) ? "True\n"  : "False\n" );

	printf("\n\nLinked list: \n");
	print_linked_list();

	insert_at(0,20);
	printf("\n\nLinked list after inserting 20 at position 0 : \n");
	print_linked_list();

	insert_at(3,23);
	printf("\n\nLinked list after inserting 23 at position 3 : \n");
	print_linked_list();


	remove_node(3);
	printf("\n\nLinked list after removing node at position 3 : \n");
	print_linked_list();

	remove_node(0);
	printf("\n\nLinked list after removing node at position 0 : \n");
	print_linked_list();

	printf("data at 3rd position is %d\n", get_nth_item(3));
		

	return 0;
}