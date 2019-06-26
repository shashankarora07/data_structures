#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"


void removeDuplicates_FromSortedlist(Node **head)
{
	Node *start = *head;
	Node *temp = NULL;

	while (start != NULL && start->next != NULL) {
		if (start->data == start->next->data) {
			temp = start->next;
			//if(temp->next)
				start->next = temp->next;
			//else
			//	start->next = NULL;
			free(temp);
		} else {
			start = start->next;
		}
	}

}

int main()
{
	Node *head = NULL;
	int no = 0;

	printf("enter no:\n");
	do {
		scanf("%d",&no);
		if (no != 100) {
		if (no == 1) 
			Insert_linkedlist(&head,no,1);
		else
			Insert_linkedlist(&head,no,2);
		}
	} while(no != 100);
	
	Display_linkedlist(head);
	removeDuplicates_FromSortedlist(&head);
	Display_linkedlist(head);

	return 0;
}
