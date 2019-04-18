#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node* Remove_kthNode_FromLast(Node **head, int kPos)
{
	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}
	Node *start = *head, *temp = *head, *temp2 = NULL;
	int len = 0;
	
	while(start != NULL) {
		start = start->next;
		len++;
	}
	
	int aPos = len - kPos + 1;
	
	while(temp != NULL && aPos != 1) {
		temp2 = temp;
		temp = temp->next;
		aPos--;
	}
	if (aPos == 1) {
		*head = temp->next;
		free(temp);
		return;
	}
	
	temp2->next = temp->next;	
	free(temp);
	return head;
}

int main()
{
	Node *head = NULL;
	int data = 1;
	for (int i = 1; i <= 6; i++) {
		if (i == 1) 
			Insert_linkedlist(&head,i,1);
		else
			Insert_linkedlist(&head,i,2);
	}
	
	Remove_kthNode_FromLast(&head,3);
	Display_linkedlist(head);

	return 0;
}
