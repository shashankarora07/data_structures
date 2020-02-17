#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TOTAL_SIZE (26)

/* typedef struct TrieNode {
	char *s[TOTAL_SIZE];
	struct TrieNode *next;
}trieNode;
*/ /* why this one will not work?  */

typedef struct TrieNode {
	struct TrieNode *s[TOTAL_SIZE];
	int endofWord;
}trieNode;

trieNode *createTrieNode()
{
	trieNode *newnode = (trieNode *)malloc(sizeof(trieNode));

	int i = 0;

	newnode->endofWord = 0;

	for (i = 0; i < TOTAL_SIZE; i++)
		newnode->s[i] = NULL;
	

	return newnode;
}

void Insert_linkedlist(trieNode **head, const char *c)
{
	int len = strlen(c);
	int index = 0, i = 0;
	printf("len of %s is %d\n",c , len);

	trieNode *start = *head;

	for (i = 0; i < len; i++) {
		index = *(c+i) - 'a';
		printf("index: %d\n",index );
		if (!start->s[index]) {
			start->s[index] = createTrieNode();
		}
		start = start->s[index];
	}

	start->endofWord = 1;
}

void Display_linkedlist(trieNode *node)
{

}

int SearchStringInLinkedlist(trieNode *head, char str[])
{
	trieNode *start = head;
	int len = strlen(str);
	int i = 0, index = 0;

	for (i = 0; i < len; i++) {
		index = (*(str+i) - 'a');
		printf(" check index : %d\n",index );

		/*if (start->s[index]) {
			start = start->s[index];
		}*/

		if (!start->s[index]) {
			return 0;
		}

		start = start->s[index];
	}

	if (start->endofWord && start != NULL) {
		return 1;
	} else {
		return 0;
	}

	//return 0;
}

int main()
{
	trieNode *head = createTrieNode();
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

	char *key_str = "beb";

	ret = SearchStringInLinkedlist(head,key_str);
	if(ret)
		printf("String exist\n");
	else
		printf("String doesn't exist\n");

	return 0;
}
