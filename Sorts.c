#include <stdio.h>
#include <stdlib.h>

#define deb(x) printf("%s = %d\n",#x, x);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if(i != 0) printf(", "); 
		printf("%d", arr[i]);
	}
	printf("\n");
}

void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < n; j++)
			if(arr[j] < arr[minIndex]) minIndex = j;
		if(i != minIndex)
			swap(&arr[minIndex], &arr[i]);
	}
}

void bubleSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int swapped = 0;
		for (int j = 0; j < n-1-i; j++)
		{
			if(arr[j+1] < arr[j])
			{
				swap(&arr[j+1], &arr[j]);
				swapped++;
			}
		}
		if(swapped == 0) break;
	}
}

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i-1;
		int temp = arr[i];
		while(j > -1 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void shellSort(int arr[], int n)
{
	for (int gap = n/2; gap > 0; gap/=2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i]; //<--Important--<
			int j = i-gap; 
			while(j > -1 && arr[j] > temp)
			{
				arr[j+gap] = arr[j];
				j -= gap;
			}
			arr[j+gap] = temp;
		}
	}
}

/*---------quickSort---------*/
int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = 0, j = h;

	do
	{
		do{i++;}while(arr[i] <= pivot);
		do{j--;}while(arr[j] > pivot);
		if(i<j) swap(&arr[i], &arr[j]);
	}while(i < j);
	swap(&arr[l], &arr[j]);
	return j;
}

void quickSort(int arr[], int l, int h)
{
	if(l < h)
	{
		int j = partition(arr, l, h);
		quickSort(arr, l, j); //<-->| Important not j-1 |<-->//
		quickSort(arr, j+1, h); 
	}
}

/*-----------margeSort-----------*/
void marge(int arr[], int l, int mid, int h)
{
	int i = l, j = mid+1, k = l;
	int ara[h+1];
	while(i <= mid && j <= h)
	{
		if(arr[i] < arr[j])
			ara[k++] = arr[i++];
		else
			ara[k++] = arr[j++];
	}
	while(i <= mid)
		ara[k++] = arr[i++];
	while(j <= h)
		ara[k++] = arr[j++];
	
	while(l <= h)
	{
		arr[l] = ara[l];
		l++;
	}
}

void margeSort(int arr[], int l, int h)
{
	if(l < h)
	{
		int mid = l+(h-l)/2;
		margeSort(arr, l, mid);
		margeSort(arr, mid+1, h);
		marge(arr, l, mid, h);
	}
}

void ImargeSort(int arr[], int n)
{
	int p, i, l, mid, h;
	for (p = 2; p <= n; p*=2)
	{
		for (i = 0; i+p-1 <= n; i=i+p)
		{
			l = i;
			h = i+p-1;
			mid = l+(h-l)/2;
			marge(arr, l, mid, h);
		}
	}
	if(p/2 < n)
		marge(arr, 0, p/2-1, n);
	if((n+1)%2)
		marge(arr, 0, n-1, n);
}

void countSort(int arr[], int n)
{
	int max = arr[0];
	for(int i = 1; i < n; i++) 
		if(max < arr[i])
			max = arr[i];

	int ara[max+1];
	for (int i = 0; i < max+1; i++)
		ara[i] = 0;

	for (int i = 0; i < n; i++)
		ara[arr[i]]++;

	int i = 0, j = 0;
	while(j < max+1)
	{
		if(ara[j] > 0)
		{
			arr[i++] = j;
			ara[j]--;
		}
		else
			j++;
	}
}

/*------binSort and redixSort------*/
struct Node 
{
	int data;
	struct Node *next;
};

struct LL
{
	struct Node *root;
	struct Node *last;
};

struct Node* createNode(int x)
{
	struct Node *t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	return t;
}

void push_back(struct LL* ll, int x)
{
	struct Node *t = createNode(x);
	if(ll->root == NULL) ll->root = t;
	else ll->last->next = t;
	ll->last = t;
}

int pop_front(struct LL* ll)
{
	if(ll->root == NULL) return -1;
	struct Node *p = ll->root;
	int x = p->data;
	if(ll->root->next) ll->root = ll->root->next;
	else ll->root = NULL;
	free(p);
	return x;
}

void show(struct LL ll)
{
	struct Node *p = ll.root;
	if(p == NULL) 
	{
		printf("List is empty!\n");
		return;
	}
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void binSort(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if(max < arr[i])
			max = arr[i];

	struct LL ll[max+1];
	for (int i = 0; i < max+1; i++)
		ll[i].root = NULL;

	for (int i = 0; i < n; i++)
		push_back(&ll[arr[i]], arr[i]);

	int i = 0, j = 0;
	while(i < max+1)
	{
		while(ll[i].last != NULL)
			arr[j++] = pop_front(&ll[i]);
		i++;
	}

}

void redixSort(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if(max < arr[i])
			max = arr[i];

	struct LL ll[10];
	for (int i = 0; i < 10; i++)
		ll[i].root = NULL;

	int m = 1;
	while(max)
	{
		for(int i = 0; i < n; i++)
			push_back(&ll[(arr[i]/m)%10], arr[i]); //<--Important--<

		int i = 0, j = 0;
		while(i < 10)
		{
			while(ll[i].root != NULL)
				arr[j++] = pop_front(&ll[i]);
			i++;
		}
		m *= 10;
		max /= 10;
	}

}

int main()
{
	int arr[] = {9,3,6,2,11,6,3,3,8,9,0,10,1,5,7,4};
	// int arr[] = {1,5,3,7,8,6,4}; 

	int n = sizeof(arr)/sizeof(arr[0]);

	// selectionSort(arr, n);
	// printArr(arr, n);

	// bubleSort(arr, n);
	// printArr(arr, n);

	// insertionSort(arr, n);
	// printArr(arr, n);

	// quickSort(arr, 0, n);
	// printArr(arr, n);

	// margeSort(arr, 0, n-1);
	// printArr(arr, n);

	// ImargeSort(arr, n-1);
	// printArr(arr, n);

	// countSort(arr, n);
	// printArr(arr, n);

	// shellSort(arr, n);
	// printArr(arr, n);

	// binSort(arr, n);
	// printArr(arr, n);

	redixSort(arr, n);
	printArr(arr, n);

	return 0;
}