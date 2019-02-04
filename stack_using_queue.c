#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode *next;
}QNode;

typedef struct QueueList{
	struct QueueList *rear;
	struct QueueList *front;
}Queue;

struct stack{
	Queue *q1;
	Queue *q2;
};

enum operations {
	PUSH = 1,
	POP,
	DISPLAY,
	EXIT = 100
};

void push();
void pop();
void enqueue(Queue **, int);
void dequeue(Queue **);
int main()
{
	int data, choice;
	Queue *q = NULL;
	do {
		printf("......IMPLEMENTATION OF STACK USING QUEUES OPERATIONS........\n");
		printf("............PUSH : Press 1..........\n");
		printf("............POP : Press 2............\n");
		printf("............DISPLAY : Press 3..........\n");
		scanf("%d",&choice);
		switch(choice)
		{
			printf("Enter data : \n");
			scanf("%d",&data);
			case PUSH: enqueue(&q,data);
			break;
		}
	}while(choice != EXIT);

	
	return 0;
}

void enqueue(Queue **q, int newdata)
{
	QNode *Qnewnode = (QNode *)malloc(sizeof(QNode));
	Qnewnode->data = newdata;
	Qnewnode->next = NULL;
	
	if (NULL == (*q)) {
		printf("First time it will come in this ONLY\n");
		printf("Queue is not present. Now created..\n");
		q = (Queue **)malloc(sizeof(Queue *));
		(*q)->rear = (*q)->front = NULL;
	}
	
	if (NULL == (*q)->rear) {
		(*q)->front = (*q)->rear = Qnewnode;
		return;		
	}	
			
	(*q)->rear->next = Qnewnode;
	(*q)->rear = (*q)->rear->next;
}	
