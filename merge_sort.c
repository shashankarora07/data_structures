#include<stdio.h>
#include<stdlib.h>

#define own_sizeof(type) (char *)(&type+1) - (char *)(&type)

void mergeArray(int *a, int start, int mid, int end)
{
	int len1 = mid-start+1;
	int len2 = end-mid;
	int left[len1], right[len2];
	int i = 0,j = 0,k = start;
	
	for (i = 0; i < len1; i++)
		left[i] = *(a+start+i);
	
	for (i = 0; i < len2; i++)
		right[i] = *(a+mid+i+1);
	
	i = 0;
	while((i < len1) && (j < len2)) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		}
		else {
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while(j < len2) {
		a[k] = right[j];
		k++;
		j++;
	}
	while(i < len1) {
		a[k] = left[i];
		k++;
		i++;
	}
	
}

void mergeSort(int *a, int start, int end)
{
	int mid;
	if (start < end) {
		mid  = (start + end)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		mergeArray(a,start,mid,end);	
	}

}

int printArray(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d   ",*(a+i));
	}
	printf("\n");
}

int main()
{
	int arr[] = {4,2,1,6,8,5,7,3};
	int len = (own_sizeof(arr))/(own_sizeof(arr[0]));
	mergeSort(arr,0,len-1);
	printArray(arr,len);
	
	
	return 0;
}
