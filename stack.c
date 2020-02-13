#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


enum{
	PUSH=1,
	POP,
	DISPLAY,
	EXIT=100
};

typedef struct stack
{
	int data;
	struct stack *next;
}Stack;

void Push(Stack **, int);
void DisplayStack(Stack *);
int Pop(Stack **);
int IsStackEmpty(Stack *);

struct stack *StackNode(int);

int main()
{

	int choice = 0, data = 0;
	Stack *sHead = NULL;
	do{
		printf("............Push : Press 1..............\n");
		printf("............Pop      : Press 2..............\n");
		printf("............Display Stack   : Press 3..............\n");
		printf("Enter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case PUSH:
			{
				printf("Enter data\n");
				scanf("%d",&data);
				Push(&sHead,data);
				break;
			}
			case DISPLAY:
			{
				DisplayStack(sHead);
				printf("NULL\n");
				break;
			}
			case POP:
			{
				data = Pop(&sHead);
				if (data != -1)
					printf("Deleted : %d\n",data);
				break;
			}
			
			default:
				printf("Get lost!! \n");
		}
	} while(choice != EXIT);



	return 0;
}

struct stack* StackNode(int val)
{
	struct stack *q = (struct stack *)malloc(sizeof(struct stack));
	q->data = val;
	q->next = NULL;
	
	return q;						
}

void Push(Stack **s, int newdata)
{
	struct stack *top;
	top = StackNode(newdata);
	
	top->next = *s;
	*s = top;
}

int Pop(Stack **s)
{
	if (IsStackEmpty(*s)) {
		printf("Stack is empty now!\n");
		return -1;
	}

	Stack *temp;
	
	temp = *s;
	int pop = temp->data;
	*s = (*s)->next;
	
	free(temp);
	
	return pop;
}

int IsStackEmpty(Stack *top)
{
	return !top;
}
void DisplayStack(Stack *s)
{
	struct stack *sd = s;
	if (sd == NULL) {
		return;
	}
	
	DisplayStack(sd->next);
	printf("%d ---> ",sd->data);
	
}
