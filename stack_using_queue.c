#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode *next;
}QNode;

typedef struct QueueList{
	struct QueueNode *rear;
	struct QueueNode *front;
}Queue;

struct stack{
	Queue *q1;
	Queue *q2;
};

enum operations {
	CREATEQUEUE = 1,
	PUSH,
	POP,
	DISPLAY,
	EXIT = 100
};

void push();
void pop();
Queue * CreateQueue();
int enqueue(Queue *, int);
void dequeue(Queue **);
void Display(Queue *);

int main()
{
	int data = 0, choice = 0;
	Queue *q = NULL;
	do {
		printf("......IMPLEMENTATION OF STACK USING QUEUES OPERATIONS........\n");
		printf("............CREATEQUEUE : Press 1..........\n");
		printf("............PUSH : Press 2..........\n");
		printf("............POP : Press 3............\n");
		printf("............DISPLAY : Press 4..........\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case CREATEQUEUE: q = CreateQueue();
			break;
			case PUSH: 
			{	
				printf("Enter data : \n");
				scanf("%d",&data);
				q = enqueue(q,data);
			}
			break;
		}
	}while(choice != EXIT);

	
	return 0;
}

Queue * CreateQueue()
{
	
}
Queue * enqueue(Queue *q, int newdata)
{
	QNode *Qnewnode = (QNode *)malloc(sizeof(QNode));
	Qnewnode->data = newdata;
	Qnewnode->next = NULL;
	
	if (NULL == q) {
		printf("First time it will come in this ONLY\n");
		printf("Queue is not present. Now created..\n");
		q = (Queue *)malloc(sizeof(Queue));
		q->rear = q->front = NULL;
	}
	
	if (NULL == q->rear) {
		printf("Also comes in this first time\n");
		q->front = q->rear = Qnewnode;
		return q;		
	}	
			
	q->rear->next = Qnewnode;
	q->rear = q->rear->next;
}

void Display(Queue *q)
{
	QNode *Dp = q->front;
	while(Dp != NULL) {
		printf("%d ->",Dp->data);
		Dp = Dp->next;
	}
	printf("NULL");
}	
