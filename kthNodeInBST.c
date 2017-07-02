#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	int lcount;

	struct node* left;
	struct node* right;
};

void inorder(struct node* root){
	if(root!=NULL){
		printf("%d %d\n", root->val, root->lcount);
		inorder(root->left);
		inorder(root->right); 
	}
}

struct node* initialize(){
	struct node* root = (struct node*)(malloc(sizeof(struct node)));
	root->val = 0;
	root->lcount = 0;
	root->left = NULL;
	root->right = NULL;
}

struct node* add(struct node* root, int num){
	if(root==NULL){
		root = initialize();
		root->val = num;
		return root;
	}
	else{
		if(root->val>=num){
			root->lcount = root->lcount + 1;
			root->left = add(root->left, num);
		}
		else{
			root->right = add(root->right, num);
		}
		return root;
	}
}

struct node* createTreeFromArray(int* arr, int size){
	struct node* root = NULL;
	for(int i=0; i<size; i++){
		root = add(root, arr[i]);
	}
	return root;
}

struct node* getKthNodeInBST(struct node* root, int k){
	if(root!=NULL){
		if(k==(root->lcount)+1){
			return root;
		}	
		else{
			if(k < (root->lcount)+1){
				return getKthNodeInBST(root->left, k);
			}
			else{
				return getKthNodeInBST(root->right, k-((root->lcount)+1));
			}
		}
	}
	else{
		return NULL;
	}
}

void main(){
	int arr[] = {5,4,3,8,7,6,9};
	struct node* root = createTreeFromArray(arr, sizeof(arr)/sizeof(int));
	//inorder(root);
	struct node* kthNode = getKthNodeInBST(root, 4);
	printf("val: %d\n", kthNode->val);
}
