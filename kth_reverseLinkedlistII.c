#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

//Node *reverse(Node *head, int k)
//{
//	Node *current = head, *next = NULL, *prev = NULL;
//	int count = 0;
//
//	while(current != NULL && count < k) {
//		next = current->next;
//		current->next = prev;
//		prev = current;
//		current = next;
//		count++;
//	}
//
//	return prev; 	
//}


Node* kth_reverseLinkedlist(Node *head, int k)
{
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	Node *current = head, *next = NULL, *prev = NULL, *start = head, *last = NULL;
	Node *newhead = NULL;
	int count = 0;


	while (current) {
		count = k;
		prev = NULL;
		start = current;

		while(current != NULL && count-- ) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		
		if (!newhead) {
			newhead = prev;
		}

		if (last) {
			last->next = prev;
		}
	
		last = start;
	}


	return newhead;
}

int main()
{
	Node *head = NULL;
	int data = 0, k = 0;
	printf("Enter linkedlist data:\n");
	do {
		scanf("%d",&data);
		if (data != 100) {
		if (data == 1) 
			Insert_linkedlist(&head,data,1);
		else
			Insert_linkedlist(&head,data,2);
		}
	} while(data != 100);
	
	Display_linkedlist(head);
	printf("Enter kth element : \n");
	scanf("%d",&k);
	head = kth_reverseLinkedlist(head,k);
	Display_linkedlist(head);

	return 0;
}
