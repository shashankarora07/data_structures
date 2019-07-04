#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node* kth_reverselistII(Node *head, int k)
{
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	if (head->next == NULL || k == 1 || k == 0)
		return head;

	Node *current = head, *next = NULL, *prev = NULL, *tmphead = head;
	Node *start = NULL;
	int count = k;

	while(current != NULL && count--) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;

	while(current) {
		
		prev = NULL;
		count = k;
		start = current;
		while(current != NULL && count--) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
	
		tmphead->next = prev;
		tmphead = start;
	}


	return head;
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
	head = kth_reverselistII(head,k);
	Display_linkedlist(head);

	return 0;
}
