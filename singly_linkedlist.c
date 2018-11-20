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
	DELETE_BEG,
	DELETE_LAST,
	DELETE_POS,
	EXIT=100

};

void Insert_linkedlist(Node **, int, int);
void Delete_fromLinked_list(Node **, int);
void Display_linkedlist(Node *);

int main()
{

	int choice = 0, data = 0;
	Node *head = NULL;
	do{
		printf("............Insert at the Begining : Press 1..............\n");
		printf("............Insert at the END      : Press 2..............\n");
		printf("............Insert at any Position : Press 3..............\n");
		printf("............Display Linked list    : Press 4..............\n");
		printf("............Delete first node      : Press 5..............\n");
		printf("............Delete last node       : Press 6..............\n");
		printf("............Delete any node        : Press 7..............\n");
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
			case DELETE_BEG:
			case DELETE_LAST:
			case DELETE_POS:
			{
				Delete_fromLinked_list(&head,choice);
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
		while((start != NULL) && (count < position - 1)) {
			count++;
			start = start->next;
	        }
	      if (start == NULL) {
			printf("position is out of scope\n");
			return;
		}
	} else {
		while(start->next != NULL)
			start = start->next;
	}
	newnode->next = start->next;
	start->next = newnode;
	
}

void Delete_fromLinked_list(Node **head, int option)
{
	int count = 1;
		int position = 0;
	Node *temp = *head, *temp2 = NULL;
	if (*head == NULL) {
		printf("List is already empty\n");
		return;
	}
	if (option == DELETE_POS) {
		printf("Enter position: \n");
		scanf("%d",&position);
		while((temp != NULL) && (count < position)) {
			count++;
			temp2 = temp;
			temp = temp->next;
	        }
	      if (temp == NULL) {
			printf("position is out of scope\n");
			return;
		}
	} 
	if (option == DELETE_BEG || (position == 1)) {
		*head = (*head)->next;
		free(temp);
		return;	
	}
	else {
		while (temp->next != NULL) {
			temp2 = temp;
			temp = temp->next;
		}
	}
	temp2->next = temp->next;
	free(temp);

}

void Display_linkedlist(Node *node)
{
	while(node != NULL) {
		printf("%d ---> ",node->data);
		node = node->next;
	}
	printf("NULL\n");
}
