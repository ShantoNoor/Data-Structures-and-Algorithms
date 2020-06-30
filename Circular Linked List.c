#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

struct Node *first;

struct Node* create(int arr[], int n)
{
	struct Node *f, *t, *l;
	f = (struct Node*)malloc(sizeof(struct Node));
	l = f;
	l->data = arr[0];
	l->next = l; 

	for (int i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = arr[i];
		t->next = l->next;
		l->next = t;
		l = t;
	}

	return f;
}

void printList(struct Node *p)
{
	if(p == NULL) {
		printf("Error-->List is EMPTY\n");
		return;
	}
	struct Node *q = p;
	do
	{
		printf("%d ", q->data);
		q = q->next;
	} while(p != q);
	printf("\n");
}

void RprintList(struct Node *p, struct Node *q)
{
	static int flag = 0;

	if(p != q || flag == 0)
	{
		flag = 1;
		printf("%d ", q->data);
		RprintList(p, q->next);
	}

	if(flag == 1)
		printf("\n");
	flag = 0;
}

struct Node* insert(struct Node *p, int index, int item)
{
	struct Node *t = (struct Node*)malloc(sizeof(struct Node));
	t->data = item;
	t->next = t;

	if(index = 1 && p == NULL)
		p = t;
	else
	{
		for (int i = 1; i < index && p; i++)
			p = p->next;
		
		t->next = p->next;
		p->next = t;
	}
	return p;
}

int delete(int index)
{
	struct Node *p = first, *q = NULL;
	int x;
	if(index == 1)
	{
		while(p->next != NULL && p->next != first)
			p = p->next;
		x = first->data;
		
		if(p == first)
		{
			free(first);
			first = NULL;
		}
		else
		{
			p->next = first->next;
			free(first);
			first = p->next;
		}
	}
	else
	{
		for (int i = 2; i < index; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);
	}
	return x;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	first = create(arr, sizeof(arr)/sizeof(int));

	printList(first); 
	printf("%d\n", delete(7));
	printList(first);

	return 0;
}