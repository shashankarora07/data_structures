#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Qnode
{
	int data;
	struct Qnode *next;
};

typedef struct QueueList
{
	struct Qnode *rear;
	struct Qnode *front;
}Queue;

void Enqueue(Queue **, int);
void DisplayQueue(Queue *);
int Dequeue(Queue **);
struct Qnode *QueueNode(int);
int IsQueueEmpty(Queue *q);
