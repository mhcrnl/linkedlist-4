#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node* next;
}NODE;

NODE* head;
NODE* tail;//마지막 노드, NULL아님
NODE* prevNode;

void init();
void push(NODE* prev, int value);
void pop(NODE* target);
NODE* node_search_target(int value);
void destroy();

void init(){
	if(head != NULL){
		printf("list does not empty\n");
		return;
	}
	head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	head->value = 0;
	tail = head;
	return ;
}

void push(NODE* prev, int value){
	NODE* temp;
	
	temp = (NODE*)malloc(sizeof(NODE));
	temp->value = value;
	if(prev->next == NULL){
		tail = temp;
		temp->next = NULL;
		prev->next = temp;
	}
	else{
		temp->next = prev->next;
		prev->next = temp;
	}
	return ;
}

void pop(NODE* target){
	
	if(target->next != NULL){
		prevNode->next = target->next;
	}
	else{
		prevNode->next = NULL;
		tail = prevNode;
	}
	free(target);
	return ;
}

NODE* node_search_target(int value){
	NODE* temp;
	temp = head;
	while(1){
		if(temp->next == NULL) return NULL;
		prevNode = temp;
		temp = temp->next;
		if(temp->value == value){
			return temp;
		}
	}
}

void node_all_print(){
	NODE* temp;
	temp = head;
	while(1){
		if(temp->next == NULL) return ;
		printf("->");
		temp = temp->next;
		printf("%d", temp->value);
	}
}

void destroy(NODE* start){
	if(start->next != NULL){
		destroy(start->next);
		start->next == NULL;
	}
	free(start);
	return ;
}

int main(){
	int select;
	int prev;
	int value;
	int testint;
	NODE* tempNode;

	testint = 1;
	head = tail = prevNode = NULL;
	select = 0;
	while(1){		
		printf("1. init\n2. push\n3. push(end)\n4. pop\n5. destroy\n");
		scanf("%d",&select);
		switch(select){
		case 1:
			testint = 0;
			init();
			break;
		case 2:
			if(testint == 1) break;
			printf("input previous value: ");
			scanf("%d", &prev);
			tempNode = node_search_target(prev);
			if(tempNode == NULL){
				printf("does not exist\n");
				break;
			}
			printf("input push value: ");
			scanf("%d", &value);
			push(tempNode,value);
			break;
		case 3:
			if(testint == 1) break;
			printf("input push value: ");
			scanf("%d", &value);
			push(tail, value);
			break;
		case 4:
			if(testint == 1) break;
			printf("input pop value: ");
			scanf("%d", &value);
			tempNode = node_search_target(value);
			if(tempNode == NULL){
				printf("does not exist\n");
			}
			else{
				pop(tempNode);
			}
			   
			break;
		case 5:
			if(head != NULL) destroy(head);
			break;
		default:
			printf("invalid input\n");
			continue;
			break;
		}
		if(select == 5)	break;
		if(testint == 1)
			printf("list must be initialized\n");
		else
			node_all_print();
		
		printf("\n\n");
	}

	return 0;
}