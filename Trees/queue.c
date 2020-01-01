#include"queue.h"

//enum{
//    ENQUEUE=1,
//    DEQUEUE,
//    DISPLAY,
//    EXIT=100
//};
//
//int main()
//{
//
//	int choice = 0, data = 0;
//	Queue *Qhead = NULL;
//	do{
//		printf("............Enqueue : Press 1..............\n");
//		printf("............Dequeue      : Press 2..............\n");
//		printf("............Display Queue   : Press 3..............\n");
//		printf("Enter choice:\n");
//		scanf("%d",&choice);
//		switch(choice)
//		{
//			case ENQUEUE:
//			{
//				printf("Enter data\n");
//				scanf("%d",&data);
//				Qhead = Enqueue(Qhead,data);
//				break;
//			}
//			case DISPLAY:
//			{
//				DisplayQueue(Qhead);
//				break;
//			}
//			case DEQUEUE:
//			{
//				data = Dequeue(&Qhead);
//				if (data != INT_MIN)
//					printf("Deleted : %d\n",data);
//				break;
//			}
//			
//			default:
//				printf("Get lost!! \n");
//		}
//	} while(choice != EXIT);
//
//
//
//	return 0;
//}

struct Qnode* QueueNode(int val)
{
	struct Qnode *q = (struct Qnode *)malloc(sizeof(struct Qnode));
	q->data = val;
	q->next = NULL;
	
	return q;						
}

void Enqueue(Queue **q, int newdata)
{
	struct Qnode *qnode;
	qnode = QueueNode(newdata);
		
	if (*q==NULL) {
		*q = (Queue*)malloc(sizeof(Queue));
		(*q)->rear = (*q)->front = NULL;
	}
	
	if (NULL == (*q)->rear) {
		(*q)->rear = (*q)->front = qnode;
		//return *q;
	}

	(*q)->rear->next = qnode;
	(*q)->rear = (*q)->rear->next;

	//return q;
}

int Dequeue(Queue **q)
{
	// if (NULL == (*q)->front) {
	// 	printf("Queue is empty now!\n");
	// 	return INT_MIN;
	// }
	if (IsQueueEmpty(*q))
		return 1;

	int data = (*q)->front->data;
	struct Qnode* temp = (*q)->front;
	(*q)->front = (*q)->front->next;

	free(temp);
	
	if (NULL == (*q)->front) {
		(*q)->rear = NULL;
	}
	
	return data;
}

int IsQueueEmpty(Queue *q)
{
	if (NULL == q->front)
		return 1;

	return 0;
}

void DisplayQueue(Queue *q)
{
	struct Qnode *ql = q->front;
	while(ql != NULL) {
		printf("%d ---> ",ql->data);
		ql = ql->next;
	}
	printf("NULL\n");
}
