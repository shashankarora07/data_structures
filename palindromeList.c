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

int IsitPalindrome(Node *slow, Node *rev)
{	
	while (rev != NULL) {
		if (rev->data != slow->data)
			return 0;
		slow = slow->next;
		rev = rev->next;	
	}

	return 1;
}

int palindromeList(Node *head)
{
	Node *slow = head, *prevSlow = NULL;
	Node *fast = head, *midofOddList = NULL;
	
	if (slow->next == NULL)
		return 1;

	while (slow && fast && fast->next) {
		prevSlow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}	

	if (fast) { // In case of odd
		midofOddList = slow; //required only when we need to restore the original list
		prevSlow->next = NULL;
		slow = slow->next;
	}
	else { // case of even
		prevSlow->next = NULL;
	}


	Node *rev = reverseList(slow);
	printf("displaying rev - \n");
	Display_linkedlist(rev);
	slow = head;
	printf("displaying slow - \n");
	Display_linkedlist(slow);
	int result = IsitPalindrome(slow,rev);

	fast = reverseList(rev);

	if (midofOddList) {
		prevSlow->next = midofOddList;
		midofOddList->next = fast;
	}
	else {
		prevSlow->next = fast;
	}

	printf("Restore original linkedlist\n");
	Display_linkedlist(head);

	return result;	

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
	no = palindromeList(head);
	printf("ret = %d\n", no);

	return 0;
}
