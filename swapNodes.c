#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node* swapPairs(Node *head)
{
	Node *current = head;

	while(current != NULL && current->next != NULL)
	{
		int temp = current->data;
		current->data = current->next->data;
		current->next->data = temp;

		current = current->next->next;
	}


	return head;
}


int main()
{
	Node *head = NULL;
	int data = 0, flag = 1;
	printf("Enter linkedlist data:\n");
	printf("Press 100 to exit\n");
	do {
		scanf("%d",&data);
		if (data != 100) {
		if (flag) { 
			Insert_linkedlist(&head,data,1);
			flag = 0;
		}
		else
			Insert_linkedlist(&head,data,2);
		}
	} while(data != 100);
	
	Display_linkedlist(head);
	head = swapPairs(head);
	Display_linkedlist(head);

	return 0;
}
