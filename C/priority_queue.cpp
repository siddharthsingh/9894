#include<stdlib.h>
#include<stdio.h>
#define null NULL

struct node{
  int data;
  int priority;
  struct node * previous;
  struct node * next;
};

struct node * head = null;
struct node * tail = null;

node * create_node(int data, int priority){
	struct node * temp = (node *)malloc(sizeof(node));
	if(temp == null){
		printf("Memory allocation error\n");
		exit(0);
	}
	temp->data = data;
	temp->priority = priority;
	temp->previous = null;
	temp->next = null;
}

void queue(int data, int priority){

	struct node * temp = create_node(data, priority);
	if(head == null){
	head = tail= temp;
	printf("Inserted\n");
	return;
	}

	struct node * temp2 = head;

	while(temp2->priority < priority && temp2->next != null){
	printf("working\n");

		temp2 = temp2->next;
	}

	if(temp2->next == null){
		tail = temp;
		temp2->next = temp;
		temp->previous = temp2;
		return;
	}
	if(temp2->previous != null){
		temp2->previous->next = temp;
	}else{
		head = temp;
	}

	temp->previous = temp2->previous;

	temp->next = temp2;

	temp2->previous = temp;


	
}

int deque(){
	if(head == null){
		printf("Empty Queue!!\n");
		return -1;
	}
	int data = tail->data;
	struct node * temp = tail;
	tail = tail->previous;
	if(tail == null){
		head = null;
	}else{
		tail->next = null;
	}

	free(temp);
	return data;
}

bool is_empty(){
	if(head == null){
		return true;
	}
	return false;
}

void print_queue(){

	
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


int main(){
	queue(1, 1);
	queue(2, 1);
	queue(3,2);
	queue(4,3);
	// print_queue();
	printf("%d",deque());
	printf("%d",deque());
	
	// deque();
	// print_queue();


}
