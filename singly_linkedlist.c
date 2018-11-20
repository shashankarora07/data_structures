#include <stdio.h>
#include <stdlib.h>


struct ListNode{
	int data;
	struct ListNode *next;
};

typedef struct ListNode Node;

enum{
	INSERT_BEG=1,
	INSERT_END,
	INSERT_POS,
	DISPLAY,
	EXIT=100

};

void Insert_linkedlist(Node **, int);
void Display_linkedlist(Node *);

int main()
{

	int choice = 0, data = 0;
	Node *head = NULL;
	do{
		printf("............Insert at the Begining : Press 1..............\n");
		printf("............Insert at the END      : Press 2..............\n");
		printf("............Insert at any Position : Press 3..............\n");
		printf(".......     Display Linked list......Press 4..............\n");
		printf("Enter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case INSERT_BEG:
			case INSERT_END:
			case INSERT_POS:
			{
				printf("Enter data\n");
				scanf("%d",&data);
				Insert_linkedlist(&head,data,choice);
				break;
			}
			case DISPLAY:
			{
				Display_linkedlist(head);
				break;
			}
			default:
				printf("Get lost!! \n");

		}
	} while(choice != EXIT);



	return 0;
}


void Insert_linkedlist(Node **head, int newdata, int option)
{
	int count = 1;
	Node *newnode = (Node *)malloc(sizeof(Node));
	Node *start = *head;
	if (!newnode) {
		printf("malloc failed\n");
		return;
	}
	newnode->data = newdata;
	if (option == INSERT_BEG) {
		newnode->next = *head;
		*head = newnode;
		return;
	}
	if (option == INSERT_POS) {
		int position = 0;
		printf("Enter position: \n");
		scanf("%d",&position);
		while( count < position - 1)
	} else {
		while(start->next != NULL)
			start = start->next;
	}
	newnode->next = start->next;
	start->next = newnode;
	
}

void Display_linkedlist(Node *node)
{
	while(node != NULL) {
		printf("%d ---> ",node->data);
		node = node->next;
	}
	printf("NULL\n");
}
