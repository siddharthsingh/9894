#include<stdio.h>
#include <stdlib.h>
#include <string.h>


 
int * vector_head;
int vector_size = 0;
int current_position = -1;

void mem_alloc_error(){
	printf("Error allocating memory\n");
	exit(0);
}

void create_vector(){

	//initialize with the size = 2
	vector_head = (int * )malloc(2*sizeof(int));
	if(!vector_head){
			mem_alloc_error();
	}
	vector_size = 2;

}


void push(int value){

	if(!value){
		printf("value cannot be null\n");
		return;
	}
	if(++current_position==vector_size-1){
		//we have a full array
		//allocate more memory and copy data
		int * vector_temp;
		vector_temp = (int * )malloc(2*vector_size*sizeof(int));
		if(!vector_temp){
			mem_alloc_error();
		}
		
		memcpy(vector_temp, vector_head, vector_size * sizeof(int));
		vector_size *=2;
		free(vector_head);
		vector_head = vector_temp;
	}

	vector_head[current_position] = value;

}

int pop(){
	if(current_position = -1){
		printf("vector empty\n" );
	}
	int value  = vector_head[current_position--];
	if(current_position< vector_size/2){
		//free up space
	}
	return value;
	//use fork to free space

}

void insert(int value, int position){
	if(position<0 or position>current_position+1){
		printf("Invalid position\n");
		return;
	}
	if(position == current_position+1){
		push(value);
	}
	

	int i = position;	
	int temp;
	for(i;i<current_position+1;i++){
		if(i==position){
			temp = vector_head[position];
			vector_head[position] = value;
		}else{
			int temp2;
			temp2 = vector_head[i];
			vector_head[i] = temp;
			temp = temp2;
		}
	}
	push(temp);

}

void print_vector(){
int i=0;
	printf("\n");

	for(i;i<=current_position;i++){

		printf("%d\n", vector_head[i]);
	}
}

int main(){


	printf("Vector implementation\n");
	create_vector();
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	print_vector();
	insert(8,2);

	print_vector();



}



