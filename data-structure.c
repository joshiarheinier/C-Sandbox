/*
Linked List Implementation
By Joshia Rheinier Pardamean
This is a free software; feel free to use the codes.
2016/12/11
*/

#include <sys/wait.h> //For wait
#include <stdio.h>
#include <stdlib.h> //For malloc
#include <unistd.h> //For fork


//Make structure for Linked List
//Linked List can be used for Stack and Queue
typedef struct node {
	int value;
	struct node *next;
} node_t;

void pushLinkedList(node_t *list, int num) {
	node_t *current = list;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = malloc(sizeof(node_t));
	current = current->next;
	current->value = num;
	current->next = NULL;
}

int popLinkedList(node_t *list) {
	node_t *current = list;
	while(current->next->next != NULL) {
		current = current->next;
	}
	int tmp = current->next->value;
	current->next = NULL;
	return tmp;
}


void printLinkedList(node_t *list) {
	printf("Data of the Linked List:\n");
	node_t *current = list;
	while(current != NULL) {
		printf("Value :%d\n",current->value);
		current = current->next;
	}
}

//Functions for Stack
void push(node_t *list, int num) {
	pushLinkedList(list, num);
}

int pop(node_t *list) {
	popLinkedList(list);
}


//Functions for Queue
node_t *enqueue(node_t *list, int num) {
	node_t *current = malloc(sizeof(node_t));
	current->value = num;
	current->next = list;
	return current;
}

int dequeue(node_t *list) {
	return popLinkedList(list);
}



//Put testcase(s) here
int main() {
	int outData;
	char *dataType;
	node_t *mynode = malloc(sizeof(node_t));
	mynode->value = 3;
	mynode->next = NULL;
	if (!fork()) {	//If child process, use stack
		dataType = "Stack";
		push(mynode, 4);
		push(mynode, 5);
		outData = pop(mynode);
		push(mynode, 6);
	}
	else { //If parent process, use queue
		dataType = "Queue";
		mynode = enqueue(mynode, 4);
		mynode = enqueue(mynode, 5);
		outData = dequeue(mynode);
		mynode = enqueue(mynode, 6);
	}
	wait(NULL);
	printf("=============================\n");
	printf("%s data structure:\n",dataType);
	printLinkedList(mynode);
	printf("Data out: %d\n",outData);
	printf("=============================\n");
}