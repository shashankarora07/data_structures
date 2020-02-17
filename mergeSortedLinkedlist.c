#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node *mergeSorted_Linkedlist(Node **a, Node **b)
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

	//if(*a == NULL)
	if(!(*a))
		newL->next = *b;

	//if(*b == NULL)
	if(!(*b))
		newL->next = *a;
	
	
	return newlist->next;
}


int main()
{
    Node *a = NULL;
    Node *b = NULL;
	Node *newL = NULL;
    int dataA = 0;
    int dataB = 1;
    for (int i = 1; i < 6; i++) {
		dataA = dataA + 2;
        if (i == 1)
            Insert_linkedlist(&a,dataA,1);
        else
            Insert_linkedlist(&a,dataA,2);
    }

    Display_linkedlist(a);
    
	for (int i = 1; i <= 7; i++) {
		dataB = dataB + 2;
        if (i == 1)
            Insert_linkedlist(&b,dataB,1);
        else
            Insert_linkedlist(&b,dataB,2);
    }

    Display_linkedlist(b);
	
	newL = mergeSorted_Linkedlist(&a,&b);
    Display_linkedlist(newL);

    return 0;
}

