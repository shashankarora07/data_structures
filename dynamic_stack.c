#include<stdio.h>
#include<stdlib.h>


struct DynamicArrayStack {
	int *array;
	int capacity;
	int top;
};

typedef struct DynamicArrayStack DynArrStack;

enum StackOperaton {
	CREATE = 1,
	PUSH,
	POP,
	DISPLAY,
	DELETE
};

DynArrStack *CreateStack(DynArrStack *);
int Push(DynArrStack *, int);
int Pop(DynArrStack *);
int IsStackEmpty(DynArrStack *);
int IsStackFull(DynArrStack *);
void DisplayStack(DynArrStack *);
void DeleteStack(DynArrStack *);

int main()
{
	DynArrStack *S;
	S = NULL;
	int choice = 0, data = 0;
	do {
		printf("....Dynamic Array Stack Implementations...\n");
		printf("...........Create Stack............Press 1\n");	
		printf(".......Push operation on Stack.....Press 2\n");	
		printf(".......Pop operation on Stack......Press 3\n");
		printf("...........Display Stack...........Press 4\n");
		printf("...........Delete Stack...........Press 5\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case CREATE: S = CreateStack(S);
				 break;
			case PUSH: 
			{
				 printf("Enter data:\n");
				 scanf("%d",&data);
				 Push(S,data);
				 break;
			}
			case POP: Pop(S);
				 break;
			case DISPLAY: DisplayStack(S);
				 break;
			case DELETE: DeleteStack(S);
				 break;
		}
	}while(choice != 100);

	return 0;
}

DynArrStack *CreateStack(DynArrStack *S)
{
	if (S == NULL) {
		S = (DynArrStack *)malloc(sizeof(DynArrStack));
		S->capacity = 1;
		S->top = -1;
		S->array = malloc(S->capacity * sizeof(int));
	}
	if (!S) {
		printf("CreateStack malloc failed..\n");
		return NULL;
	}
	if (!S->array) {
		printf("malloc failed in array\n");
		return NULL;
	}		
	return S;			
}

int Push(DynArrStack *S, int data)
{
	if (!S) {
		printf("NULL is in Stack Memory. Suggest you to CreateStack\n");	
		return -1;
	}
	if (IsStackFull(S)) {
		S->capacity += 1;
		S->array = realloc(S->array,S->capacity * sizeof(int));
	}
	S->array[++S->top] = data;
	
}

int Pop(DynArrStack *S)
{
	if (IsStackEmpty(S))
		printf("Stack is empty\n");
		return -1;
	S->top -= 1;
	return S->array[S->top];
}

void DeleteStack(DynArrStack *S)
{
	if (S) {
		free(S->array);
		free(S);
	}
	S->array[S->top] = 0;
	S = NULL;
}

int IsStackFull(DynArrStack *S) {
	return (S->top == S->capacity-1);
}

int IsStackEmpty(DynArrStack *S) {
	return (S->top == -1);
}
void DisplayStack(DynArrStack *S)
{
	for (int i = 0; i <= S->top; i++) {
		printf("%d \t",S->array[i]);
	}
	printf("\n");
}
