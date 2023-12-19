#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};


struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum()
{
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr -> data; ptr = ptr -> next;
	}
	return s;
}

int evenCount() {
	struct Node* ptr = first;
	int c = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			c += 1; 
		}
		ptr = ptr->next;
	}
	return c;
}

 void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 != 0) {
			ptr->data *= 10;
		}
		ptr = ptr->next;
	}
}

 void elementIx100(int i) 
 { 
	 struct Node* ptr = first;
	 int index = 0;
	 while (ptr != NULL) {
		 if (index == i) {
			 ptr->data = ptr->data * 100;
			 return;
		 }
		 ptr = ptr->next;
		 index++;
	 }
 }

 void elementLeftIx10(int i)
 {
	 struct Node* ptr = first;
	 int index = 0;
	 while (ptr != NULL) {
		 if (index < i) {
			 ptr->data = ptr->data * 10;
		 }
		 ptr = ptr->next;
		 index++;
	 }
 }

void main() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementLeftIx10(1);
	printList();

	elementLeftIx10(2);
	printList();

	elementLeftIx10(4);
	printList();

	clearList();
	printList();
	{
		int x;
		scanf("%d", &x);
	}
}
