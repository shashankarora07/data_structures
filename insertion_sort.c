#include<stdio.h>

#define SIZE 5

int Insertion_sort(int *, int);

int main()
{
	int arr[SIZE];
	int len = sizeof(arr)/sizeof(arr[0]);
	
	for(int i = 0; i < len; i++)
		scanf("%d",&arr[i]);	

	Insertion_sort(arr,len);

	printf("*** Sorted array ***\n");		
	for(int i = 0; i < len; i++)
		printf("%d\n",arr[i]);

	return 0;
}

int Insertion_sort(int *arr, int N)
{
	int key, i, k;
	
	for (i = 1; i < N; i++) {
		key = arr[i];
		k = i;
		while(k >= 1 && arr[k-1] > key) {
			/*Insert the element and move to the next position*/
			arr[k] = arr[k-1];
			k--;
		}
		arr[k] = key;
	}
}
