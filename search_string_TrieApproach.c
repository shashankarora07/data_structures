#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int TOTAL_SIZE = 26;

/* typedef struct TrieNode {
	char *s[TOTAL_SIZE];
	struct TrieNode *next;
}trieNode;
*/ /* why this one will not work?  */

typedef struct TrieNode {
	struct TrieNode *s[TOTAL_SIZE];
	int endofWord:1;
}trieNode;

trieNode *createTrieNode()
{
	trieNode *newnode = (trieNode *)malloc(sizeof(trieNode));

	int i = 0;

	for (i = 0; i < TOTAL_SIZE; i++)
		newnode->s[i] = NULL;

	newnode->endofWord = 0;

	return newnode;
}

void Insert_linkedlist(trieNode *head, const char *c)
{
	int len = strlen(c);
	int index = 0, i = 0;

	trieNode *start = head;

	for (i = 0; i < len; i++) {
		index = *(c+i) - 'a';
		if (!start->s[index]) {
			start->s[index] = createTrieNode();
		}
		start = start->s[index];
	}


}

void Display_linkedlist(trieNode *node)
{
	while(node != NULL) {
		printf("%s ---> ",node->s);
		node = node->next;
	}
	printf("NULL\n");
}

int SearchStringInLinkedlist(Node *head, char str[])
{
	Node *start = head;

	while (start) {
		if (strcmp(start->s,str) == 0) {
			return 1;
		}
		
		start = start->next;
	}
	
	return 0;
}

int main()
{
	trieNode head = NULL;
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
	char *key_str = "bea";
	ret = SearchStringInLinkedlist(head,key_str);
	if(ret)
		printf("String exist\n");
	else
		printf("String doesn't exist\n");

	return 0;
}
