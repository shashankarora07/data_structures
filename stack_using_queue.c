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

void Push(struct stack *, int);
int Pop(struct stack *);
Queue * CreateQueue();
int Enqueue(Queue *, int);
int Dequeue(Queue **);
void Display(Queue *);
int IsQueueEmpty(Queue **);

int main()
{
	int data = 0, choice = 0, ret = 0;
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
			case CREATEQUEUE: 
				if (q != NULL) {
					printf("Queue is present\n");
					break;
				}
				q = CreateQueue();
			break;
			case PUSH: 
			{	
				if (q == NULL) {
					printf("Queue is not present. First create it\n");
					break;
				}
				printf("Enter data : \n");
				scanf("%d",&data);
				Push(q, data);
				//Enqueue(q,data);
			}
			break;
			case POP:
				{
					if (IsQueueEmpty(&q)) {
						printf("Queue Is empty\n");
						break;
					}
					ret = Dequeue(&q);
					printf("POP Item = %d\n",ret);
				}
			break;
			case DISPLAY: 
			{
				if (q == NULL) {
					printf("Queue is empty\n");
					break;
				}
				Display(q);
			}
			break;
		}
	}while(choice != EXIT);

	
	return 0;
}


Queue * CreateQueue()
{
	Queue *Q = (Queue *)malloc(sizeof(Queue));
	if (!Q) {
		perror("Malloc failed:");
		return NULL;
	}
	Q->rear = Q->front = NULL;
	
	return Q;
}

int Enqueue(Queue *q, int newdata)
{
	QNode *Qnewnode = (QNode *)malloc(sizeof(QNode));
	Qnewnode->data = newdata;
	Qnewnode->next = NULL;
	
	
	if (NULL == q->rear) {
		printf("Also comes in this first time\n");
		q->front = q->rear = Qnewnode;
		return 0;		
	}	
			
	q->rear->next = Qnewnode;
	q->rear = q->rear->next;
}

int Dequeue(Queue **q)
{
	QNode *temp = (*q)->front;
	int data = (*q)->front->data;
	(*q)->front = (*q)->front->next;
	free(temp);
	temp = NULL;	
	
	if ((*q)->front == NULL) {
			(*q)->rear = NULL;
	}
	return data;
}

int IsQueueEmpty(Queue **Q)
{
		return (NULL == (*Q)->front);
}


void Display(Queue *q)
{
	QNode *Dp = q->front;
	while(Dp != NULL) {
		printf("%d ->",Dp->data);
		Dp = Dp->next;
	}
	printf("NULL\n");
}	
