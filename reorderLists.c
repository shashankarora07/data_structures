#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"
    
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
    ptr1 = head;
    
    int count = 0, var = 1;
    
    while(ptr1 != NULL) {
        count++;
        ptr1 = ptr1->next;
    }

    printf("Count = %d\n",count);
    temp = head;
    ptr1 = temp;

    while(var != count/2) {
        var++;
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = NULL;
    
    Display_linkedlist(ptr1);
    //Display_linkedlist(temp2);
    
    ptr2 = reverseList(temp2);
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

