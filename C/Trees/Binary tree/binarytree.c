

#include<stdlib.h>
#include<stdio.h>
#define null 0

struct BSTnode
{
	int data;
	struct BSTnode *left;
	struct BSTnode *right;
		
};

struct BSTnode * BSTroot = null;

int smallest_element(){
	struct BSTnode * node = BSTroot;
	if(!node){
		printf("empty binary tree\n");
		return 0;
	}
	while(node->left)node = node->left;
	return node->data;

}

int largest_element(){
	struct BSTnode * node = BSTroot;
	if(!node){
		printf("empty binary tree\n");
		return 0;
	}
	while(node->right)node = node->right;
	return node->data;

}

void inorder_traversal(BSTnode * node){
	if(!node)return;
	inorder_traversal(node->left);
	printf("%d\n", node->data);
	inorder_traversal(node->right);

}
void preorder_traversal(){

	if(!node)return;
	printf("%d\n", node->data);
	inorder_traversal(node->left);
	inorder_traversal(node->right);

}

void postorder_traaversal(){
	
	if(!node)return;
	inorder_traversal(node->left);
	inorder_traversal(node->right);
	printf("%d\n", node->data);

}

int main(){

	BSTroot = (BSTnode *)malloc(sizeof(BSTnode));

	struct BSTnode * currentNode = BSTroot;
	scanf("%d", &currentNode->data);
	int temp;
	struct BSTnode * tempNode = null;
	int count=0;
	while(count++<9){

		scanf("%d", &temp);
		tempNode = (BSTnode *)malloc(sizeof(BSTnode));
		tempNode->data = temp;
		currentNode = BSTroot;

		while(1){
			if(temp>=currentNode->data){
				if(!currentNode->right){
					currentNode->right = tempNode;
					break;
				}else{
					currentNode = currentNode->right;
				}

			}else{
				if(!currentNode->left){
					currentNode->left = tempNode;
					break;
				}else{
					currentNode = currentNode->left;
				}
				
			}

		}
		
		
	}

printf("\n\n\n\n\n%d\n", smallest_element());

printf("%d\n", largest_element());

printf("\n\nrder traversal====\n\n");
inorder_traversal(BSTroot);

}


