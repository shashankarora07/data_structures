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
struct stack * CreateStack();
Queue * CreateQueue(Queue *);
int Enqueue(Queue *, int);
int Dequeue(Queue **);
void Display(Queue *);
int IsQueueEmpty(Queue **);

int main()
{
	int data = 0, choice = 0, ret = 0;
	Queue *q = NULL;
	struct stack *s = NULL;
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
				if (s != NULL) {
					printf("Stack is present\n");
					break;
				}
				s = CreateStack();
				//q = CreateQueue();
			break;
			case PUSH: 
			{	
				if (s == NULL) {
					printf("Stack is not present. First create it\n");
					break;
				}
				printf("Enter data : \n");
				scanf("%d",&data);
				Push(s, data);
				//Enqueue(q,data);
			}
			break;
			case POP:
				{
			    if ((IsQueueEmpty(&s->q1)) && (IsQueueEmpty(&s->q2))) {
             	    printf("Stack is empty\n");
                	break;
            	}
					ret = Pop(s);
					printf("POP Item = %d\n",ret);
				}
			break;
			case DISPLAY: 
			{
				if (s == NULL) {
					printf("stack is empty\n");
					break;
				}
				if (IsQueueEmpty(&s->q1))
					Display(s->q2);
				else
					Display(s->q1);
			}
			break;
		}
	}while(choice != EXIT);

	
	return 0;
}


struct stack * CreateStack()
{
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	Queue *Q;
    if (!s) {
        perror("Malloc failed:");
        return NULL;
    }
	s->q1 = NULL;
	s->q2 = NULL;

	return s;
}

void Push(struct stack *s, int newdata)
{
/*	if (s->q1 != NULL) {
		printf("Queue is present already\n");
		
	}
*/
	if (!s->q1) {
		printf("Create 1st Queue\n");
		s->q1 = CreateQueue(s->q1);
	}
	if (!s->q2) {
		printf("Create 2nd Queue\n");
		s->q2 = CreateQueue(s->q2);
	}
	if (IsQueueEmpty(&s->q2)) {
		printf("Added in queue1\n");
		Enqueue(s->q1, newdata);
	}
	else {
		printf("Added in queue2\n");
		Enqueue(s->q2, newdata);
	}			
}

int Pop(struct stack *s)
{
    if (IsQueueEmpty(&s->q2)) {
        printf("Moved from queue1 to queue2 except last\n");
		while(s->q1->front->next)
        	Enqueue(s->q2,Dequeue(&s->q1));
	
		return Dequeue(&s->q1);
    }
    else {
        printf("Moved from queue2 to queue1 except last\n");
        while(s->q2->front->next)
            Enqueue(s->q1,Dequeue(&s->q2));

        return Dequeue(&s->q2);
    }
}

Queue * CreateQueue(Queue *Q)
{
	Q = (Queue *)malloc(sizeof(Queue));
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
