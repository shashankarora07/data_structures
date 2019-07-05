#include <stdio.h>
#include <stdlib.h>

struct DoublyListnode {
	int data;
	struct DoublyListnode *next;
	struct DoublyListnode *prev;
};

typedef struct DoublyListnode DLLNode;

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


void Insert_doubly_linkedlist(DLLNode **, int, int);
void Delete_from_doubly_linkedlist(DLLNode **, int);
void Display_doubly_linkedlist(DLLNode *);

int main()
{
     int choice = 0, data = 0;
        DLLNode *head = NULL;
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
                                Insert_doubly_linkedlist(&head,data,choice);
                                break;
                        }
                       case DISPLAY:
                        {
                                Display_doubly_linkedlist(head);
                                break;
                        }
                        case DELETE_BEG:
                        case DELETE_LAST:
                        case DELETE_POS:
                        {
                                Delete_from_doubly_linkedlist(&head,choice);
                                break;
                        }

                        default:
                                printf("Get lost!! \n");

                }
        } while(choice != EXIT);


	return 0;
}

void Insert_doubly_linkedlist(DLLNode **head, int newdata, int option)
{
	DLLNode *temp = *head;
	DLLNode  *newnode;
	int count = 1, position = 0;
	newnode = (DLLNode *)malloc(sizeof(DLLNode));
	newnode->data = newdata;
	if (!newnode) {
		printf("malloc failed\n");
		return;
	}
	if (option == INSERT_POS) {
		printf("Enter position: \n");
		scanf("%d",&position);
		while ((temp->next != NULL) && (count < position-1)) {
			count++;
			temp = temp->next;
		}
		if (!temp) {
			printf("position is out of scope\n");
			return;
		}	
	}
	if (option == INSERT_BEG || position == 1) {
		newnode->next = *head;
		newnode->prev = NULL;
		if (*head)
			(*head)->prev = newnode;
		*head = newnode;
		return;		
	} else {
		while (temp->next != NULL)
			temp = temp->next;
	}
	if (*head == NULL){
		printf("No node is present\n");
		return;
	}
	newnode->next = temp->next;
	newnode->prev = temp;
	if (temp->next)
		temp->next->prev = newnode;
	temp->next = newnode;
	return;
}


void Delete_from_doubly_linkedlist(DLLNode **head, int option)
{
	DLLNode *temp = *head, *temp2;
	int count = 1, position = 0;

	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}
	if (option == DELETE_POS) {
		printf("Enter position\n");
		scanf("%d",&position);
		while((temp->next != NULL) && (count < position))
			temp = temp->next;
		
	}
	if (option == DELETE_BEG || position == 1) {
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return;					
	} else {
		while(temp->next != NULL)
			temp = temp->next;
	}
	temp2 = temp->prev;
	temp2->next = temp->next;
	if (temp->next)
		temp->next->prev = temp2;
	free(temp);
	return;
	
}

void Display_doubly_linkedlist(DLLNode *head)
{
	DLLNode *node = head;
	while (node != NULL) {
		printf("%d-->",node->data);
		node = node->next;
	}
	printf("NULL\n");
}

