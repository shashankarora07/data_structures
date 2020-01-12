#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"queue.h"


typedef struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode *left;	
	struct BinaryTreeNode *right;	
}Binarynode;

enum cases{
	INSERTBINARYSEARCHNODE=1,
	DISPLAY,
	PREORDER,
	INORDER,
	POSTORDER,
	LEVELORDER,
	INSERTBINARYTREENODE
};

Binarynode *createNode(int newdata)
{
	struct BinaryTreeNode *node = (Binarynode *)malloc(sizeof(Binarynode));
	
	node->data = newdata;
	node->left = node->right = NULL;
	
	return node;
}

void InsertBinarySearchTreeNode(Binarynode **root,int newdata)
{
	struct BinaryTreeNode *start, *prev;
	start = *root;
	if (NULL == start) {
		printf("1st time come\n");
		*root = createNode(newdata);
		return;
	}

	printf("Next time coming!\n");
	while (start != NULL) {
			prev = start;
		if (newdata < start->data) {
			start = start->left;
		} else {	
			start = start->right;
		}
	}

	if (prev->data > newdata) {
		prev->left = createNode(newdata);
	} else {
		prev->right = createNode(newdata);
	}
	
}

void Display(Binarynode *root)
{
	if (root != NULL) {
		printf("%d ->",root->data);
		Display(root->left);
		Display(root->right);
	}

}

void PreOrder(Binarynode *root)
{
	Stack *S = NULL;	
	
	while(1) {
		while(root) {
			printf("%d ->",root->data);
			Push(&S,root);
			root = root->left;		 
		}
		if(IsStackEmpty(S))
			break;
		root = Pop(&S);
		root = root->right;
	}
	printf("NULL\n");
}

void InOrder(Binarynode *root)
{
	Stack *S = NULL;

	while(1) {
		while(root) {
			Push(&S,root);
			root = root->left;
		}
		//printf("root = %d\n",root);
//		while(1) {
			if(IsStackEmpty(S))
				break;
			root = Pop(&S);
			printf("%d ->",root->data);
		//	if(root->right != NULL)
		//		break;
//		}
		root = root->right;
	}
	printf("NULL\n");
}

void PostOrder(Binarynode *root)
{
	Stack *S = NULL;
	Binarynode *prev = NULL;

	while(1) {
		while (root) {
			Push(&S,root);
			root = root->left;
		}

		while((root == NULL) && (!IsStackEmpty(S))) {
				root = Top(S);
			if (root->right == NULL) {
				printf("%d ->",root->data);
				Pop(&S);
				prev = root;
				root = NULL;
			}
			else if (root->right != NULL && root->right != prev) {
				root = root->right;
			}
			else {
				printf("%d ->",root->data);
				Pop(&S);
				prev = root;
				root = NULL;
			}
		}
		//sleep(1);
		if(IsStackEmpty(S))
			break;
	}	
	printf("NULL\n");
}	

void LevelOrder(Binarynode *root)
{
	Queue *Q = NULL;
	Binarynode *temp = NULL;

	if (root == NULL)
		return;
	Enqueue(&Q,root);
	printf("%d\n",root->data);
	while(!IsQueueEmpty(Q)) {
		temp = Dequeue(&Q);
		printf("%d ->", temp->data);

		if(temp->left) {
			Enqueue(&Q,temp->left);
		}
		if(temp->right) {
			Enqueue(&Q,temp->right);
		}
	}
	printf("NULL\n");
}

void InsertBinaryTreeNode(Binarynode **root, int newdata)
{
	Queue *Q = NULL;
	Binarynode *start = *root, *temp = NULL;
	Binarynode *newnode = createNode(newdata);

	if (!newnode) {
		perror("malloc failed\n");
		return;
	}
	if (NULL == *root) {
		*root = newnode;
		return;
	}

	Enqueue(&Q,start);
	while (!IsQueueEmpty(Q)) {
			temp = Dequeue(&Q);

			if (temp->left) {
				Enqueue(&Q,temp->left);
			}
			else {
				temp->left = newnode;
				DeleteQueue(&Q);
				return;
			}
			if (temp->right) {
				Enqueue(&Q,temp->right);
			}
			else {
				temp->right = newnode;
				DeleteQueue(&Q);
				return;
			}
	}
	DeleteQueue(&Q);
}

int main()
{		
	Binarynode *head = NULL;
	
	int data, choice;
	
	do {
		printf("Press 1 for insert binary search node \n");
		printf("Press 2 for display \n");
		printf("Press 3 for Preorder \n");
		printf("Press 4 for Inorder \n");
		printf("Press 5 for Postorder \n");
		printf("Press 6 for Levelorder \n");
		printf("Press 7 for insert binaryTree node \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case INSERTBINARYSEARCHNODE:
			{
					printf("Enter data:");
					scanf("%d",&data);
					InsertBinarySearchTreeNode(&head,data);
					break;
			}
			case INSERTBINARYTREENODE:
			{
					printf("Enter data:");
					scanf("%d",&data);
					InsertBinaryTreeNode(&head,data);
					break;				
			}
			case PREORDER:
			{
					PreOrder(head);
					break;
			}
			case INORDER:
			{
					InOrder(head);
					break;
			}
			case POSTORDER:
			{
					PostOrder(head);
					break;
			}
			case LEVELORDER:
			{
					LevelOrder(head);
					break;
			}
			case DISPLAY: 
			{	
					Display(head);
					printf("NULL\n");
					break;
			}
		}
	}while(choice != 100);

	return 0;
}

