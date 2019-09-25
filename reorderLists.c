#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

/* 
Input: 90 -> 94 -> 25 -> 51 -> 45 -> 29 -> 55 -> 63 -> 48 -> 27 -> 72 -> 10 -> 36 -> 68 -> 16 -> 20 -> 31 -> 7 -> 95 -> 70 -> 89 -> 23 -> 22 -> 9 -> 74 -> 71 -> 35 -> 5 -> 80 -> 11 -> 49 -> 92 -> 69 -> 6 -> 37 -> 84 -> 78 -> 28 -> 43 -> 64 -> 96 -> 57 -> 83 -> 13 -> 73 -> 97 -> 75 -> 59 -> 53 -> 52 -> 19 -> 18 -> 98 -> 12 -> 81 -> 24 -> 15 -> 60 -> 79 -> 34 -> 1 -> 54 -> 93 -> 65 -> 44 -> 4 -> 87 -> 14 -> 67 -> 26 -> 30 -> 77 -> 58 -> 85 -> 33 -> 21 -> 46 -> 82 -> 76 -> 88 -> 66 -> 101 -> 61 -> 47 -> 8

Output: 90 -> 8 -> 94 -> 47 -> 25 -> 61 -> 51 -> 101 -> 45 -> 66 -> 29 -> 88 -> 55 -> 76 -> 63 -> 82 -> 48 -> 46 -> 27 -> 21 -> 72 -> 33 -> 10 -> 85 -> 36 -> 58 -> 68 -> 77 -> 16 -> 30 -> 20 -> 26 -> 31 -> 67 -> 7 -> 14 -> 95 -> 87 -> 70 -> 4 -> 89 -> 44 -> 23 -> 65 -> 22 -> 93 -> 9 -> 54 -> 74 -> 1 -> 71 -> 34 -> 35 -> 79 -> 5 -> 60 -> 80 -> 15 -> 11 -> 24 -> 49 -> 81 -> 92 -> 12 -> 69 -> 98 -> 6 -> 18 -> 37 -> 19 -> 84 -> 52 -> 78 -> 53 -> 28 -> 59 -> 43 -> 75 -> 64 -> 97 -> 96 -> 73 -> 57 -> 13 -> 83*/

    
Node* mergeLists(Node *headA, Node *headB)
{
    Node *new = NULL;
    Insert_linkedlist(&new,0,1);
    Node *start = new;
    int flag = 1;
    while (headA || headB) {
        if (flag && headA) {
            new->next = headA;
            headA = headA->next;
            flag = 0;
        } else {
            new->next = headB;
            headB = headB->next;
            flag = 1;
        }
        new = new->next;
    }


    return start->next;
}

Node* reorderLists(Node *head)
{
    Node *ptr1 = NULL, *ptr2 = NULL;
    Node *temp = NULL, *temp2 = NULL;
    
	ptr1 = temp = head;
	temp2 = head;
	while(temp2->next && temp2->next->next) {
		temp = temp->next;
		temp2 = temp2->next->next;
	}

	Node *mid = temp->next;
	temp->next = NULL;

    
    Display_linkedlist(ptr1);
    
    ptr2 = reverseList(mid);
    Display_linkedlist(ptr2);

    temp = NULL;
    temp = mergeLists(ptr1,ptr2);
    printf("__________________\n");
    Display_linkedlist(temp);

    return temp;
}

int main()
{
    Node *headA = NULL;
    
    int no = 0, flag = 1;

    printf("enter data for linkedlist:\n");

    do {
        scanf("%d",&no);
        if (no != 100) {
            if (flag) {
                Insert_linkedlist(&headA,no,1);
		        flag = 0;
	    } else {
            Insert_linkedlist(&headA,no,2);
		}
      }
    } while(no != 100);

    headA = reorderLists(headA);
    printf("Display OUTPUT:\n");
    Display_linkedlist(headA);

    return 0;
}

