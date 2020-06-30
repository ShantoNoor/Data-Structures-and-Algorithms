#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first = NULL;

void create(int arr[], int n)
{
	struct Node *t, *l;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = arr[0];
	t->prev = t->next = NULL;
	first = l = t;

	for (int i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = arr[i];
		t->next = l->next;
		t->prev = l;
		l->next = t;
		l = t;
	}
}

void print(struct Node *p)
{
	if(p)
	{
		while(p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
	else printf("List is empty!");
	printf("\n");
}

void insert(int index, int item)
{
	struct Node *t = (struct Node*)malloc(sizeof(struct Node));
	t->data = item;
	t->prev = t->next = NULL;

	if(index == 0)
	{
		if(first == NULL)
			first = t;
		else
		{
			t->next = first;
			first->prev = t;
			first = t;
		}
	}
	else
	{
		struct Node *p = first;
		for (int i = 1; i < index; i++)
			p = p->next;

		t->next = p->next;
		t->prev = p;
		if(p->next)
			p->next->prev = t;
		p->next = t;
	}	
}

int delete(int index)
{
	struct Node *p = NULL;
	int x = -1;

	if(index == 1)
	{
		p = first;
		x = p->data;
		first = first->next;
		if(first)
			first->prev	= NULL;
		free(p);
	}
	else
	{
		p = first;
		for (int i = 1; i < index; i++)
			p = p->next;

		p->prev->next = p->next;
		if(p->next)
			p->next->prev = p->prev;

		x = p->data;
		free(p);
	}
	
	return x;
}

void reverse()
{
	struct Node *p = first, *temp = NULL;

	while(p)
	{
		temp = p->prev;
		p->prev = p->next;
		p->next = temp;
		p = p->prev;

		if(p && p->next == NULL) //<-- p is importent -->
			first = p;
	}

}

int main()
{
	int arr[] = {2, 3, 5, 6, 7};
	create(arr, sizeof(arr)/sizeof(int));

	print(first);
	delete(1);
	print(first);

	return 0;
}