#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node *addTwonumberAsLists(Node **a, Node **b)
{
	Node *newlist;
	newlist = (Node *)malloc(sizeof(Node));
	newlist->next = NULL;
	Display_linkedlist(newlist);
	Node *newL = newlist;

	while(*a != NULL && *b != NULL) {
		if((*a)->data <= (*b)->data) {
			newL->next = *a;
			*a = (*a)->next;
			printf("coming a: newL->data = %d\n",newL->data);
		}
		else {
			newL->next = *b;
			*b = (*b)->next;
			printf("coming b: newL->data = %d\n",newL->data);
		}
		newL = newL->next;
	}

	if(*a == NULL)
		newL->next = *b;

	if(*b == NULL)
		newL->next = *a;
	
	
	return newlist->next;
}


int main()
{
    Node *headA = NULL;
    Node *headB = NULL;
	Node *newL = NULL;
    int no = 0;

    printf("enter data for 1st linkedlist:\n");

    do {
        scanf("%d",&no);
        if (no != 100) {
        if (no == 1) 
            Insert_linkedlist(&headA,no,1);
        else
            Insert_linkedlist(&headA,no,2);
        }
    } while(no != 100);

    Display_linkedlist(headA);
    
    printf("enter data for 2nd linkedlist:\n");
    do {
        scanf("%d",&no);
        if (no != 100) {
        if (no == 1) 
            Insert_linkedlist(&headA,no,1);
        else
            Insert_linkedlist(&headA,no,2);
        }
    } while(no != 100);

    Display_linkedlist(headB);
	
	newL = addTwonumberAsLists(&headA,&headB);
    Display_linkedlist(newL);

    return 0;
}

