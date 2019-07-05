#include<stdio.h>
#include<stdlib.h>

//#define SIZE 9

int partition(int *, int, int);
int QuickSort(int *, int, int);
void swap(int *, int *);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("Usage: input size required for array");
		exit(0);
	}

	int size = atoi(argv[1]);	

    int arr[size], start, end;
    int len = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < len; i++)
        scanf("%d",&arr[i]);

	start = 0;
	end = len - 1;
    QuickSort(arr,start,end);

    printf("*** Sorted array ***\n");
    for(int i = 0; i < len; i++)
        printf("%d\n",arr[i]);	


	return 0;
}

int QuickSort(int *arr, int start, int end)
{
	int pIndex;
	if (start < end) {
		pIndex = partition(arr,start,end);
		QuickSort(arr,start,pIndex-1);
		QuickSort(arr,pIndex+1,end);
	}

}

int partition(int *arr, int start, int end)
{
	int pivot = arr[end];
	int pIndex = start;

	for (int i = start; i <= end - 1; i++) {
		if (arr[i] <= pivot){
			swap(&arr[i],&arr[pIndex]);
			pIndex++;
		}		
	}
	swap(&arr[pIndex],&arr[end]);
	
	return pIndex;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
