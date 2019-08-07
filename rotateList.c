#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node* rotateList(Node *head, int k)
{
	Node *current = head, *last = NULL;
	int count = 0;

	while(current != NULL) {
		last = current;
		current = current->next;
		count++;
	}

	int pos = count - k%count;
	current = head;
	int apos = 1;

	while(current != NULL && apos < pos)
	{
		current = current->next;
		apos++;
	}
	Node *nexttmp = current->next;
	current->next = NULL;
	last->next = head;
	head = nexttmp;

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
	printf("Enter kth element to rotate: \n");
	scanf("%d",&k);
	head = rotateList(head,k);
	Display_linkedlist(head);

	return 0;
}
