#include <stdio.h>

void insert(int arr[], int n)
{
	int temp = arr[n];

	while(n > 1 && temp > arr[n/2])
	{
		arr[n] = arr[n/2];
		n = n/2;
	}
	arr[n] = temp;
}

void createHeap(int arr[], int n)
{
	for (int i = 2; i < n+1; i++)
		insert(arr, i);
}

int delete(int arr[], int n)
{
	int ret = arr[1];
	arr[1] = arr[n];

	int i = 1, j = 2*i;
	while(j < n)
	{
		if(arr[j+1] > arr[j])
			j++;
		if(arr[i] < arr[j])
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			i = j;
			j = 2*i;
		}
		else break;
	}
	arr[n] = ret;
	return ret;
}

void heapify(int arr[], int n)
{
	int i = n, j, k;

	while(i > 0)
	{
		k = i;
		j = k*2;
		while(j < n)
		{
			if(arr[j+1] > arr[j]) j++;
			if(arr[k] < arr[j])
			{
				int temp = arr[k];
				arr[k] = arr[j];
				arr[j] = temp;

				k = j;
				j = k*2;
			}
		}
		i--;
	}
}

int main()
{
	int heap[11] = {0, 5, 10, 30, 20, 35, 40, 15};
	// int heap[11] = {0, 10, 20, 30, 25, 5, 40, 35};
				//  0   1   2   3   4  5   6   7
	int lastIndex = 7;

	// heap[++lastIndex] = 40;
	// insert(heap, lastIndex);

	// heap[++lastIndex] = 35;
	// insert(heap, lastIndex);

	// createHeap(heap, 7);

	heapify(heap, 7);

	for (int i = 1; i < lastIndex+1; i++)
		printf("%d ", heap[i]);
	printf("\n");


	printf("%d\n", delete(heap, lastIndex--));
	printf("%d\n", delete(heap, lastIndex--));
	printf("%d\n", delete(heap, lastIndex--));
	printf("%d\n", delete(heap, lastIndex--));
	printf("%d\n", delete(heap, lastIndex--));
	printf("%d\n", delete(heap, lastIndex--));
	printf("%d\n", delete(heap, lastIndex--));

	for (int i = 1; i < lastIndex+1; i++)
		printf("%d ", heap[i]);
	printf("\n");

	for (int i = 1; i < 8; i++)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}