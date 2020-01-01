#include "stack.h"


Stack* StackNode(int val)
{
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	s->data = val;
	s->next = NULL;
	
	return s;						
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

int Top(Stack *s)
{
	if (IsStackEmpty(s))
		return NULL;

	return s->data;
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
