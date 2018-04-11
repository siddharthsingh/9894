/* 
Dynamic array


*/

#include<stdio.h>
#include<stdlib.h>

//holds the position at which we will insert the data into array next and also is the size till which the array is full
int size = 0;
int capacity = 2;
int *arr = (int *)malloc(sizeof(int)*capacity);


void addValue(int value, int array[]){
	if(size<0 || size>capacity){
		//show error
		printf("An error occured. Position at which you enter the value must be between 0 and max size\n");
	}
	if(!array){
		//null pointer, show error
		printf("Null array pointer passed.\n");
		return;
		}
	if(size>=capacity){
		//allocate new memory
		//increase the memory by 2 times
		capacity *=2;
		int *new_arr = (int *)realloc(arr , capacity*sizeof(int));
		//check if the new pointer is not null 
		if(!new_arr){
			//realloc returned a null pointer. show error
			printf("Error allocating memory.\n" );
			return;

		}
		arr = new_arr;
		arr[size++] = value;
		
	}else{
		array[size++] = value;
	}

}


int main(){

	int i = 0;
	//add values to the array to see if it dynamically increases
	for(i;i<100000;i++){
		addValue(i,arr);
	}
	
	//print value to see if it is storing values properly
	printf("value added %d\n" , arr[i-1]);

	return 0;
}