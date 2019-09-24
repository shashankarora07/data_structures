#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node* reverseList(Node *head)
{
	Node *current = head, *start = head;
	Node *prev = NULL, *next = head;

	
	while(current != NULL) 
	{
		next = current->next;
		current->next = prev;
		prev = current;	
		current = next;
	}
	
	head = prev;

	return head;
}


//int main(int argc, char *argv[])
//{
//	Node *head = NULL;
//    int flag = 1, no = 0;
//	
//	printf("Enter linkedlist data:\n");
//    do {
//        scanf("%d",&no);
//        if (no != 100) {
//            if (flag) {
//                Insert_linkedlist(&head,no,1);
//                flag = 0;
//        } else {
//            Insert_linkedlist(&head,no,2);
//        }
//      }
//    } while(no != 100);
//	
//	Display_linkedlist(head);
//	head = reverseList(head);
//	Display_linkedlist(head);
//
//	return 0;
//}
