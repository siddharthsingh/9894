#include<stdlib.h>
#include<stdio.h>
#define null NULL

struct node{
  int data;
  struct node * previous;
  struct node * next;
};

struct node * head = null;
struct node * tail = null;

node * create_node(int data){
	struct node * temp = (node *)malloc(sizeof(node));
	if(temp == null){
		printf("Memory allocation error\n");
		exit(0);
	}
	temp->data = data;
}

void queue(int data){
	struct node * temp = create_node(data);
	if(head == null){
	head = tail= temp;
	return;
	}
	head->previous = temp;
	temp->next = head;
	head = temp;
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
int dequeue_head(){
	if(head == null){
		printf("Empty queue\n");
		return -1;
	}
	int data = head->data;
	struct node * temp = head;
	head = head->next;
	if(head == null){
		tail = null;
	}else{
		head->previous = null;
	}

	free(temp);
	return data;

}

void queue_tail(int data){
	struct node * temp = create_node(data);
	if(tail == null){
	tail = head= temp;
	return;
	}
	tail->next = temp;
	temp->previous = tail;
	tail = temp;
}

int main(){
	queue(1);
	queue(2);
	queue(3);
	queue(4);
	print_queue();
	deque();
	deque();
	print_queue();


}
