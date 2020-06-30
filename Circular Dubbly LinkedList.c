#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	struct Node *prev, *next;
	int data;
} *first = NULL;

void create(int arr[], int n)
{
	struct Node *t, *l;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = arr[0];
	t->next = t;
	t->prev = t;
	first = l = t;

	for (int i = 1; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = arr[i];
		l->next->prev = t;
		t->next = l->next;
		t->prev = l;
		l->next = t;
		l = t;
	}
}

void display(struct Node *p)
{
	if(!p) 
		printf("List is Empty!...");
	else
	{
		do
		{
			printf("%d ", p->data);
			p = p->next;
		} while(p != first);
	}
	printf("\n");
}

void insert(int index, int item)
{
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	p->data = item;
	if(index == 0)
	{
		if(first == NULL)
		{
			p->prev = p;
			p->next = p;
		}
		else
		{
			p->next = first;
			p->prev = first->prev;
			first->prev->next = p;
			first->prev = p;
		}
		first = p;
	}
	else
	{
		struct Node *i = first;
		for (int j = 1; j < index; j++)
			i = i->next;
		p->next = i->next;
		p->prev = i;
		i->next->prev = p;
		i->next = p;
	}
}

int delete(int index)
{
	int item = -1;
	struct Node *p = first;
	if(index == 1)
	{
		item = first->data;
		first = first->next;
		if(first == p)
		{
			free(p);
			first = NULL;
		}
		else
		{
			first->prev = p->prev;
			p->prev->next = first;
			free(p);
		}
	}
	else
	{
		for (int i = 1; i < index; i++)
			p = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		item = p->data;
		free(p);
	}
	return item;
}

int main()
{
	// int arr[] = {1, 2, 5, 6, 3};
	// create(arr, sizeof(arr)/sizeof(int));
	// display(first);

	// printf("Deleted element = %d\n", delete(1));
	// display(first);

	// printf("Deleted element = %d\n", delete(4));
	// display(first);

	insert(0, 10);
	insert(0, 20);
	insert(0, 30);
	insert(0, 40);
	insert(0, 50);
	display(first);


	return 0;
}