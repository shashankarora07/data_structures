#include <stdio.h>
#include <stdlib.h>


struct ListNode{
    int data;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct Queue {
	Node *rear;
	Node *front;
};

enum{
	CREATEQUEUE = 1,
	ENQUEUE,
	DEQUEUE,
	DISPLAY,
	DELETEQUEUE,
    EXIT=100
};

struct Queue *CreateQueue();
int Enqueue(struct Queue *,int);
int Dequeue(struct Queue **);
int IsQueueEmpty(struct Queue **);
void Display_Queue(struct Queue *);
int Delete_Queue(struct Queue **);

int main()
{

    int choice = 0, data = 0, ret = 0;
    struct Queue *Q = NULL;
    do{
        printf("............CREATEQUEUE : Press 1..............\n");
        printf("..............ENQUEUE   : Press 2..............\n");
        printf("..............DEQUEUE   : Press 3..............\n");
        printf("..............Display   : Press 4..............\n");
        printf("............DELETEQUEUE : Press 5..............\n");
        printf("Enter choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
			case CREATEQUEUE: 
				if (Q != NULL) {
					printf("Queue is present\n");
					break;
				}
				Q = CreateQueue();
			break;
            case ENQUEUE:
            {
				if (Q == NULL) {
					printf("Queue memory is NULL. First create the queue\n");
					break;
				}
                printf("Enter data\n");
                scanf("%d",&data);
                Enqueue(Q,data);
            }
            break;
            case DISPLAY:
            {
				if (NULL == Q->front){
					printf("Queue is empty\n");
					break;
				}
                Display_Queue(Q);
            }
            break;
            case DEQUEUE:
            {
			if (IsQueueEmpty(&Q)) {
				printf("Queue is empty\n");
				break;
			}
                ret = Dequeue(&Q);
				printf("Dequeued Item : %d\n",ret);
            }
            break;
			case DELETEQUEUE:
			{
			if (IsQueueEmpty(&Q)) {
				printf("Queue is empty\n");
				break;
			}
				Delete_Queue(&Q);
			}
			break;
        }
    } while(choice != EXIT);

    return 0;
}

struct Queue * CreateQueue()
{
	
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
//	Node *temp = (Node *)malloc(sizeof(Node));
	if (!q) {
		perror("malloc failed");
		return -1;
	}
	q->rear = q->front = NULL;
	
	return q;
}

int Enqueue(struct Queue *Q,int newdata)
{
	
	Node *newnode = (Node *) malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->next = NULL;
	if (Q->rear == NULL) {
		Q->front = Q->rear = newnode;
		return 0;
	}	
	Q->rear->next = newnode;
	Q->rear = newnode;
}

int Dequeue(struct Queue **Q)
{
	Node *temp = (*Q)->front;
	int data = (*Q)->front->data;
	(*Q)->front = (*Q)->front->next;	
	free(temp);
	temp = NULL;

    if ((*Q)->front == NULL) {
            (*Q)->rear = NULL;
    }

	return data;		
}

int Delete_Queue(struct Queue **Q)
{
	while ((*Q)->front != NULL) {
		Dequeue(Q);
	}
	*Q = NULL;

	return 0;
}
int IsQueueEmpty(struct Queue **Q)
{
	return (NULL == (*Q)->front);
}

void Display_Queue(struct Queue *Q)
{
	Node *Dp = Q->front;
	do {
		printf("%d ->", Dp->data);
		Dp = Dp->next;
	} while (Dp != NULL);
	printf("NULL\n");
}
