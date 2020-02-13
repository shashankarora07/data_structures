#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	char s[50];
	struct Listnode *next;
}Node;

void Insert_linkedlist(Node **head, char c[])
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	Node *start = *head;
	if (!newnode) {
		printf("malloc failed\n");
		return;
	}
	strcpy(newnode->s,c);
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return;
	} else {
		while (start->next != NULL) 
			start = start->next;
	}
	newnode->next = start->next;
	start->next = newnode;
}

void Display_linkedlist(Node *node)
{
	while(node != NULL) {
		printf("%s ---> ",node->s);
		node = node->next;
	}
	printf("NULL\n");
}

int SearchStringInLinkedlist(Node **head)
{

}

int main()
{
	Node *head = NULL;
	char data[50];
	int ret = 0, i = 0;

	printf("Enter linkedlist data:\n");
	do { do {
		//scanf("%[^\n]%*c",data);
		scanf("%c",&data[i]);
		i++;
		//printf("input string = %s\n",data);

	} while((i < sizeof(data)) && (data[i-1] != '\n'));
	data[i-1] = '\0';
	i = 0;
	printf("input string = %s\n",data);
	if (data[0] != '0') {
		Insert_linkedlist(&head,data);
	}
	} while (data[0] != '0');
	
	Display_linkedlist(head);
	ret = SearchStringInLinkedlist(head);
	if(ret)
		printf("String exist\n");
	else
		printf("String doesn't exist\n");

	return 0;
}
