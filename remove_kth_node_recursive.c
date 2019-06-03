#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node* Remove_kthNode_FromLast_recursive(Node **head, int kPos)
{
	static int aPos = 0;

	if (*head == NULL) {
		printf("List is empty Now\n");
		return NULL;
	}
//	Node *start = *head, *temp = *head, *temp2 = NULL;
	
	Remove_kthNode_FromLast_recursive((*head)->next, kPos);
	

	if (++aPos == kPos) {
//		temp2->next = temp->next;	
//		free(temp);
	}
	
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
	
	Remove_kthNode_FromLast_recursive(&head,3);
	Display_linkedlist(head);

	return 0;
}
