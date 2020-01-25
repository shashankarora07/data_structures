#include <stdio.h>
#include <stdlib.h>


struct CircularListNode{
        int data;
        struct CircularListNode *next;
};

typedef struct CircularListNode CircularNode;

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

void Insert_circular_linkedlist(CircularNode **, int, int);
void Delete_from_circular_linkedlist(CircularNode **, int);
void Display_circular_linkedlist(CircularNode *);

int main()
{

        int choice = 0, data = 0;
        CircularNode *head = NULL;
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
                                Insert_circular_linkedlist(&head,data,choice);
                                break;
                        }
                        case DISPLAY:
                        {
                                Display_circular_linkedlist(head);
                                break;
                        }
                        case DELETE_BEG:
                        case DELETE_LAST:
                        case DELETE_POS:
                        {
                                Delete_from_circular_linkedlist(&head,choice);
                                break;
                        }

                        default:
                                printf("Get lost!! \n");

                }
        } while(choice != EXIT);



        return 0;
}


void Insert_circular_linkedlist(CircularNode **head, int newdata, int option)
{
	CircularNode *newnode, *current = *head;
	newnode = (CircularNode *)malloc(sizeof(CircularNode));
	newnode->data = newdata;
	if (option == INSERT_BEG) {
		newnode->next = newnode;
		if (*head == NULL) {
			*head = newnode;
		} else {
			while (current->next != *head)
				current = current->next;
			newnode->next = *head;
			current->next = newnode;
			*head = newnode;
		}
		return;	
	} else {
		while (current->next != *head)
			current = current->next;
		newnode->next = newnode;
		if (*head == NULL)
			*head = newnode;
		else {
			newnode->next = *head;
			current->next = newnode;
		}
		return;
	}	

}

void Delete_from_circular_linkedlist(CircularNode **head, int option)
{
	CircularNode *temp = *head;
	CircularNode  *current = *head;
	if (NULL == *head) {
		printf("List is empty\n");
		return;
	}
	if (option == DELETE_BEG) {
		while (current->next != *head) {
			current = current->next;
		}
		current->next = (*head)->next;
		if (*head == (*head)->next) {
				*head = NULL;
		} else {
			*head = (*head)->next;
		}
		//*head = (*head)->next;
		free(temp);
		//temp = NULL;		
		return;
	} else {
		if (current->next == *head) {
			*head = NULL;
			free(current);
			return;
		}
		while (current->next != *head) {
			temp = current;
			current = current->next;
		}
		temp->next = current->next;
		free(current);
		//current = NULL;
		return;	
	}
}

void Display_circular_linkedlist(CircularNode *head)
{
	CircularNode *node = head;
	
 	do {
		if (node == NULL)
			break;
		printf("%d-->",node->data);
		node = node->next;
	} while (node != head);
	printf("NULL\n");
}
