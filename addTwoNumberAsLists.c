#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"

Node *addTwonumberAsLists(Node **a, Node **b)
{
	Node *newlist;
	newlist = (Node *)malloc(sizeof(Node));
	newlist->next = NULL;
	//Display_linkedlist(newlist);
	Node *newL = newlist;
	int dataA = 0, dataB = 0, count = 0, dataF = 0, carry = 0;
	newL = NULL;
	
//	dataA = (*a)->data;   
//	dataB = (*b)->data; 
//	*a = (*a)->next;
//	*b = (*b)->next;
//	count = 1;
//	while(*a != NULL && *b != NULL) {
//			dataA += (*a)->data * count * 10;  
//			dataB += (*b)->data * count * 10; 
//			printf("coming a: (*a)->data = %d\n",dataA);
//			printf("coming b: (*b)->data = %d\n",dataB);
//			*a = (*a)->next;
//			*b = (*b)->next;
//			count *= 10;
//		}
//
//	if(*a == NULL) {
//		while(*b != NULL) {
//			dataB += (*b)->data * count * 10; 
//			*b = (*b)->next;
//			count *= 10;
//		}
//	}
//
//	if(*b == NULL) {
//		while(*a != NULL) {
//			dataA += (*a)->data * count * 10;  
//			*a = (*a)->next;
//			count *= 10;
//		}
//	}
//
//	dataF = dataA + dataB;
//	printf("dataF = %d\n",dataF);
//	printf("count = %d\n",count);
//
//	int flag = 1;
//	while(count > 1) {
//        if (flag) {
//            Insert_linkedlist(&newL,dataF%10,1);
//            flag = 0;
//        }
//        else {
//            Insert_linkedlist(&newL,dataF%10,2);
//        }
//		count /=10;
//		dataF /= 10;		
//	}	
	
	dataA = (*a)->data;
	dataB = (*b)->data;

	*a = (*a)->next;
	*b = (*b)->next;
	int sum = dataA + dataB + carry;
	Insert_linkedlist(&newL,sum%10,1);
	carry = sum/10;
	
	
	Node* start = newL;
	Node *temp = NULL;
	while(*a != NULL || *b != NULL) {
		sum = (*a ? (*a)->data : 0)  + (*b ? (*b)->data : 0) + carry;
		Insert_linkedlist(&temp,sum%10,1);
		carry = sum/10;
		newL->next = temp;
		newL = temp; // Alternate of newL = newL->next;
		//newL = newL->next; // This is also working. no need to use temp = NULL and newL = temp; 
		temp = NULL;
		
		if (*a)
			*a = (*a)->next;
		if (*b)
			*b = (*b)->next;
	}
		
	return start;
}


int main()
{
    Node *headA = NULL;
    Node *headB = NULL;
	Node *newL = NULL;
    int no = 0, flag = 1;

    printf("enter data for 1st linkedlist:\n");

    do {
        scanf("%d",&no);
        if (no != 100) {
        if (flag) {
            Insert_linkedlist(&headA,no,1);
			flag = 0;
		}
        else {
            Insert_linkedlist(&headA,no,2);
		}
      }
    } while(no != 100);

    Display_linkedlist(headA);
    
	flag = 1;
    printf("enter data for 2nd linkedlist:\n");
    do {
        scanf("%d",&no);
        if (no != 100) {
        if (flag) { 
            Insert_linkedlist(&headB,no,1);
			flag = 0;
		}
        else {
            Insert_linkedlist(&headB,no,2);
		}
      }
    } while(no != 100);

    Display_linkedlist(headB);
	
	newL = addTwonumberAsLists(&headA,&headB);
	
	printf("Display OUTPUT:\n");
    Display_linkedlist(newL);

    return 0;
}

