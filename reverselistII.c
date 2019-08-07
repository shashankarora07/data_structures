#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node* reverseListII(Node *head, int m, int n)
{
	Node *current = head, *start = head;
	Node *prev = NULL, *next = head;
	int count = 1;

	while(current != NULL && count < m)
	{
		start = current;
		current = current->next;
		count++;
	}
	
	Node *tail = current;
	while(current != NULL && count <= n) 
	{
		next = current->next;
		current->next = prev;
		prev = current;	
		current = next;
		count++;
	}
	
	if (m > 1)
		start->next = prev;
	else
		head = prev;

	if (current != NULL)
		tail->next = current;



	return head;
}


int main(int argc, char *argv[])
{
	Node *head = NULL;
	int data = 0, k = 0;
	
	if (argc != 3) {
		perror("Usage: give minimum 2 arguments");
		exit(1);
	}


	int m = atoi(argv[1]);
	int n = atoi(argv[2]);

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
	head = reverseListII(head,m,n);
	Display_linkedlist(head);

	return 0;
}
