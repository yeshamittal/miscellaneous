#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node* next;
};

struct node* initialize(){
	struct node* head = (struct node*)(malloc(sizeof(struct node)));
	return head;
}

struct node* arrayToLinkedList(int* arr, int size){
	if(size>0 && arr!=NULL){
		struct node* head = NULL;
		struct node* tail = NULL;
		for(int i=0; i<size; i++){
			struct node* current = initialize();
			current->val = arr[i];
			current->next = NULL;
			if(head==NULL){
				head = current;
				tail = current;
			}
			else{
				tail->next = current;
				tail = current;
			}
		}
		return head;
	}
	else{
		return initialize();
	}
}

void print(struct node* head){
	struct node* current = head;
	while(current!=NULL){
		printf("%d\n", current->val);
		current = current->next;
	}
}

struct node* addElement(struct node* head, int ele){
	struct node* new = initialize();
	new->val = ele;
	new->next = NULL;
	if(head!=NULL){
		struct node* current = head;
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = new;
	}else{
		head = new;
	}
	return head;
}

struct node* addElementInFront(struct node* head, int num){
	struct node* current = initialize();
	current->val = num;
	current->next = NULL;
	if(head!=NULL){
		current->next = head;
	}
	head = current;
	return head;
}

int getLength(struct node* head){
	struct node* current = head;
	int size = 0;
	while(current!=NULL){
		size++;
		current = current->next;
	}
	return size;
}

void addElementAtIndex(struct node** head, int num, int ind){
	if(*head!=NULL){
		int length = getLength(*head);
		struct node* new = initialize();
		new->val = num;
		new->next = NULL;
		if(ind==0){ //the new element should become head
			new->next = *head;
			*head = new;
		} 
		if(length-ind>0){//has to be added somewhere in middle
			struct node* current = *head;
			int count = 0;
			while(count<(ind-1)){
				count++;
				current = current->next;
			}
			struct node* temp = current->next;
			current->next = new;
			new->next = temp; 
		}
		else{//add at the end. If ind is greater than length, just add at the end
			struct node* current = *head;
			while(current->next!=NULL){
				current = current->next;
			}
			current->next = new;
		}
	}
	else{
		struct node* new = initialize();
		new->val = num;
		new->next = NULL;
		*head = new;
	}	
}

void removeEle(struct node** head){
	struct node* current = *head;
	if(*head!=NULL){//remove last
		if((*head)->next==NULL){
			*head = NULL;
			free(head);
		}
		else{
			while(current->next->next!=NULL){
				current = current->next;	
			}	
			current->next = NULL;
			free(current->next);
		}
	}
}

struct node* removeByValue(struct node* head, int num){ //first occurence of num is removed
	if(head!=NULL){
		if((head)->val==num){
			struct node* temp = head;
			head = (head)->next;
			free(temp);
		}
		else{
			struct node* current = head;
			while(current->next!=NULL){
				if(current->next->val==num){
					struct node* temp = current->next;
					current->next = temp->next;
					free(temp);
					break;
				}
				current = current->next;
			}
		}
		return head;
	}
}

struct node* removeByIndex(struct node* head, int ind){
	if((head)!=NULL){
		if(ind==0){
			struct node* temp = head;
			(head) = (head)->next;
			free(temp);
		}
		else{
			int length = getLength(head);
			if(length-ind>0){
				int count=0;
				struct node* current = head;
				while(count<(ind-1)){
					current = current->next;
					count++;
				}
				struct node* temp = current->next;
				if(temp!=NULL){
					current->next = temp->next;	
					free(temp);
				}
				else{
					current->next = NULL;
				}
			}	
			else{//removeFromLast
				removeEle(&head);
			}			
		}
		return head;
	}
}

int search(struct node** head, int num){ //return first occurence as the index
	struct node* current = *head; 
	int count=0;
	while(current!=NULL){
		if(current->val==num){
			return count;
		}
		current = current->next;
		count++;
	}
	return -1; //element not found
}

int searchLastOccurence(struct node** head, int num){
	if(*head!=NULL){
		struct node* current = *head;
		int maxInd=0,count = 0;
		while(current!=NULL){
			if(current->val==num){
				if(count>=maxInd){
					maxInd = count;
				}
			}
			current = current->next;
			count++;
		}
		return maxInd;
	}else{
		return -1;
	}	
}

struct array{
	int* arr;
	int size;
}; 

struct array searchAllOccurrences(struct node** head, int num){
	struct array occurences;
	if(*head!=NULL){
		struct node* current = *head;
		int i=0, count=0;
		while(current!=NULL){
			printf("val: %d\n", current->val);
			if(current->val==num){
				occurences.size += 1;
				occurences.arr = (int*)(realloc(occurences.arr, occurences.size));
				occurences.arr[i] = count;
				i++;
				printf("count: %d\n", count);
			}
			current = current->next;
			count++;
		}
		for(int i=0; i<1; i++){
			printf("func %d\n", occurences.arr[i]);
		}

		occurences.size = i;
		return occurences;
	}else{
		occurences.arr = NULL;
		occurences.size = 0;
		return occurences;
	}
}

void printArray(int* arr, int size){
	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

struct node* concatLinkedLists(struct node** linked, struct node** newLinked){
	struct node* current = *linked;
	while(current->next!=NULL){
		current = current -> next;
	}
	current->next = *newLinked;
	return *linked;
}

void swap(struct node* a, struct node* b){
	int temp = (int)(a)->val;
	(a)->val = (b)->val;
	(b)->val = temp;
}

struct node* bubbleSort(struct node* head){
	struct node* current = head;
	int length = getLength(head);
	int flag = 0;
	for(int i=0; i<length; i++){
		while(current->next!=NULL){
			if(current->val>current->next->val){
				swap(current, (current->next));
				flag = 1;
			}
			current = current->next;
		}
		if(flag==0){
			break;
		}
		current = head;
	}
	return head;
}

struct node* mergeSortedLinkedList(struct node* a, struct node* b){
	struct node* head = NULL;
	struct node* aPtr = a;
	struct node* bPtr = b;
	while (aPtr != NULL && bPtr != NULL) {
		if (aPtr->val > bPtr->val) {
			head = addElement(head, bPtr->val);
			bPtr = bPtr->next;
		}
		else if(aPtr->val < bPtr->val){
			//printf("ab: %d %d\n", aPtr->val, bPtr->val);
			head = addElement(head, aPtr->val);
			aPtr = aPtr->next;
		}
		else{
			head = addElement(head, aPtr->val);
			head = addElement(head, aPtr->val);
			aPtr = aPtr->next;
			bPtr = bPtr->next;
		}	
	}
	struct node* current;
	if(aPtr!=NULL){
		current = aPtr;	
	}
	else{
		current = bPtr;
	}
	while(current!=NULL){
		head = addElement(head, current->val);
		current = current->next;
	}
	return head;
}
	
struct node* diffSortedLinkedList(struct node* a, struct node* b){
	struct node* aPtr = a;
	struct node* bPtr = b;
	struct node* head = a;
	while(aPtr!=NULL){
		int ind = search(&bPtr, aPtr->val);
		if(ind!=-1){
			printf("ind: %d %d\n", ind, aPtr->val);
			head = removeByIndex(head, ind);
		}
		aPtr = aPtr->next;
	}
	return head;
}

struct node* intersectSortedLinkedList(struct node* a, struct node* b){
	int aLen = getLength(a);
	int bLen = getLength(b);
	struct node* current = NULL;
	struct node* searchList;
	if(aLen>bLen){
		current = a;
		searchList = b;
	}else{
		current = b;
		searchList = a;
	}
	struct node* head = NULL;
	while(current!=NULL){
		int ind = search(&searchList, current->val);
		if(ind!=-1){
			head = addElement(head, current->val);
		}
		current = current->next;
	}
	return head;
}

struct linkedListSplits{
	struct node* left;
	struct node* right;
};

struct linkedListSplits splitLinkedList(struct node* head, int ind){
	struct linkedListSplits splitList;
	if(head!=NULL){
		struct node* current = head;
		int count = 0;
		while(count<ind){
			count++;
			current = current->next;
		}
		struct node* newList = current->next;
		current->next = NULL;
		splitList.left = head;	
		splitList.right = newList;
	}else{
		splitList.left = NULL;	
		splitList.right = NULL;
	}
	return splitList;
}

struct linkedListSplits splitLinkedListByValue(struct node* head, int num){
	struct linkedListSplits splitList;
	if(head!=NULL){
		struct node* current = head;
		while(current!=NULL){
			if(current->val==num){
				break;
			}
			current = current->next;
		}
		struct node* temp = current->next;
		current->next = NULL;
		splitList.left = head;
		splitList.right = temp;
	}
	else{
		splitList.left = NULL;	
		splitList.right = NULL;
	}
	return splitList;
}

struct node* mergeSort(struct node* head){
	if(head!=NULL){
		if(getLength(head)==1){
			return head;
		}else{
			int mid = 0, length=0;
			length = getLength(head);
			if((length%2)==0){
				mid = (length/2)-1;
			}
			else{
				mid = length/2;
			}
			struct linkedListSplits splitList = splitLinkedList(head, mid);
			struct node* leftList = mergeSort(splitList.left);
			struct node* rightList = mergeSort(splitList.right);
			struct node* sortedHead = mergeSortedLinkedList(leftList, rightList);
			return sortedHead;
		}
	}
	else{
		return head;
	}
}

struct array linkedListToArray(struct node* head){
	struct array arrayList;
	if(head!=NULL){
		int i=0;
		struct node* current = head;
		int length = getLength(head);
		arrayList.arr = (int*)(malloc(length*sizeof(int)));
		while(current!=NULL){
			arrayList.arr[i] = current->val;	
			current = current->next;
			i++;
		}
		arrayList.size = length;
	}
	else{
		arrayList.arr = NULL;
		arrayList.size = 0;
	}
	//printArray(arrayList.arr, arrayList.size);
	return arrayList;
}

struct node* reverseLinkedList(struct node* head){
	if(head!=NULL){
		struct node* newHead = head;
		struct node* current = head->next;
		newHead->next = NULL;
		while(current!=NULL){
			struct node* temp = current;
			current = current->next;
			temp->next = newHead;
			newHead = temp;
			//print(newHead);
			//printf("%d\n", current->val);
		}
		return newHead;
	}
	else{
		return head;
	}
}

struct node* insertInSortedWayToLinkedList(struct node* head, int num){
	if(head!=NULL){
		struct node* current = NULL;
		if(head->val > num){
			current = initialize();
			current-> val = num;
			current-> next = head;
			head = current;
			print(head);
			printf("******\n");
		}
		else{
			struct node* current = head;
			while(current->next!=NULL){
				if(current->val<num && current->next->val>num){
					break;
				}
				current = current->next;
			}
			struct node* newNode = initialize();
			newNode->val = num;
			struct node* temp = current->next;
			current->next = newNode;
			newNode->next = temp;
		}
	}
	else{
		head = initialize();
		head->val = num;
		head->next = NULL;
	}
	return head;
}

struct node* removeDuplicatesFromSortedLinkedList(struct node* head){
	if(head!=NULL){
		struct node* current = head;
		while(current!=NULL && current->next!=NULL){
			if(current->val == current->next->val){
				current = removeByIndex(current, 1);
			}
			current = current->next;
		}
	}
	return head;
}

void getDigits(int num){
	while(num>0){
		printf("num: %d\n", num);
		printf("%d\n", num%10);
		num = num/10;
	}
}

struct node* getSumOfLinkedLists(struct node* a, struct node* b){	
	struct node* aptr = reverseLinkedList(a);
	struct node* bptr = reverseLinkedList(b);
	int carry = 0;
	struct node* head = NULL;
	while(aptr!=NULL && bptr!=NULL){
		int first = aptr->val;
		int second = bptr->val;	
		int res = first+second+carry;
		head = addElementInFront(head, res%10);
		if(res-10>=0){
			carry = res/10;
		}
		aptr = aptr->next;
		bptr = bptr->next;	
	}
	struct node* current = NULL;
	if(aptr!=NULL){
		current = aptr;
	}
	else{
		current = bptr;
	}
	if(carry!=0 && current!=NULL){
		current->val = (current->val)+carry;
	}
	int flag = 0;
	while(current!=NULL){
		flag = 1;
		head = addElementInFront(head, current->val);
		current = current->next;
	}
	if(flag==0 && carry!=0){
		head = addElementInFront(head, carry);
	}
	return head;
}

void printRecursive(struct node* head){
	if(head!=NULL){
		printf("%d\n", head->val);
		printRecursive(head->next);
	}
}

struct node* reverseLinkedListRecursive(struct node* head){
	if(head==NULL || head->next==NULL){
		//printf("head: %d\n", head->val);
		return head;
	}
	else{
		struct node* newHead = head;
		struct node* current = head->next;
		newHead->next = NULL;
		//printf("val: %d %d\n", newHead->val, current->val);
		struct node* newNode = reverseLinkedListRecursive(current);
		if(newNode->next==NULL){
			newNode->next = newHead;
		}
		else{
			struct node* temp = newNode;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newHead;
		}
		
		//printf("new: %d\n", newNode->next->val);
		//newHead = newNode;
		//return newHead;
		return newNode;
	}
}

void main(){

//	struct node* init = initialize();
	//printf("%d\n", init->val);

	int arr[] = {1,2,3,4,5,6};
	//&arr = NULL;
	struct node* linked = arrayToLinkedList(arr, sizeof(arr)/sizeof(int));
	//printRecursive(linked);
	//print(linked);
	//linked = NULL;
	//addElement(&linked, 9); //default last
	//print(linked);
	//linked = NULL;
	//linked = addElementInFront(linked, 20); //default from last
	//print(linked);
	//addElementAtIndex(&linked, 11, 10);
	//print(linked);
	//linked=NULL;
	//removeEle(&linked);
	//print(linked);
	//removeByValue(&linked, 1);
	//print(linked);
	//struct node* remByIndHead = removeByIndex(linked, 1);
	//print(linked);
	//printf("search: %d\n",search(&linked, 4));
	//printf("searchLast: %d\n", searchLastOccurence(&linked, 5));
	//linked = NULL;
	//struct array allOccurrences = searchAllOccurrences(&linked, 10);
	//printArray(allOccurrences.arr, allOccurrences.size);
	int arr1[] = {1, 2, 3};
	struct node* newLinked = arrayToLinkedList(arr1, sizeof(arr1)/sizeof(int));
	//struct node* newHead = concatLinkedLists(&linked, &newLinked);
	//print(newHead);
	//struct node* bubbleHead = bubbleSort(linked);
	//struct node* bubbleHeadNew = bubbleSort(newLinked);
	//struct node* mergeSortedHead = mergeSortedLinkedList(linked, newLinked);
	//print(mergeSortedHead);

	//struct node* diffSortedHead = diffSortedLinkedList(bubbleHead, bubbleHeadNew); //(A-B)
	//print(diffSortedHead);

	//struct node* intersectHead = intersectSortedLinkedList(bubbleHead, bubbleHeadNew);
	//print(intersectHead);

	//struct linkedListSplits splitList = splitLinkedList(linked, 2);
	//struct linkedListSplits splitList = splitLinkedListByValue(linked, 3);
	//print(splitList.left);
	//printf("**************\n");
	//print(splitList.right);

	//struct node* mergeSortHead = mergeSort(linked);
	//print(mergeSortHead);

	//struct array a = linkedListToArray(linked);
	//printArray(a.arr, a.size);

	//struct node* revereseHead = reverseLinkedList(linked);
	//print(revereseHead);

	//struct node* sortedHead = insertInSortedWayToLinkedList(linked, 100);
	//print(sortedHead);

	//struct node* noDuplicatesHead = removeDuplicatesFromSortedLinkedList(linked);
	//print(noDuplicatesHead);

	//getDigits(13);
	//struct node* linkedListsSum = getSumOfLinkedLists(linked, newLinked);
	//print(linkedListsSum);
	struct node* head = reverseLinkedListRecursive(linked);
	printRecursive(head);
}

