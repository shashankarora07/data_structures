#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node *removeAllDuplicatesFromSortedList(Node *start)
{
    Node *head = start;
    Node *dummynode;
    Insert_linkedlist(&dummynode,0,1);
    dummynode->next = start;
    Node *prev = dummynode;

    while (head) {
        while(head->next != NULL && prev->next->data == head->next->data) {
            head = head->next;
        }
        if (prev->next == head) {
            prev = prev->next;
        }
        else {
            prev->next = head->next;
        }
        head = head->next;
    }

    return dummynode->next;
}

int main(int argc, char *argv[])
{
	Node *head = NULL;
    int flag = 1, no = 0;
	
	printf("Enter linkedlist data:\n");
    do {
        scanf("%d",&no);
        if (no != 100) {
            if (flag) {
                Insert_linkedlist(&head,no,1);
                flag = 0;
        } else {
            Insert_linkedlist(&head,no,2);
        }
      }
    } while(no != 100);
	
	Display_linkedlist(head);
	head = removeAllDuplicatesFromSortedList(head);
    Display_linkedlist(head);

	return 0;
}
