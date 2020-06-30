#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*first, *last, *secound;

void create(int arr[], int n)
{
	struct Node *temp,  *last;
	int i = 0;

	first = (struct Node*)malloc(sizeof(struct Node));

	first->data = arr[i];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = arr[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void RlistPrint(struct Node* p)
{
	if(p)
	{
		printf("%d ", p->data);
		RlistPrint(p->next);
	}
	if(p == 0)
		printf("\n");
}

void reverseRlistPrint(struct Node* p)
{
	if(p)
	{
		reverseRlistPrint(p->next);
		printf("%d ", p->data);
	}
	if(p == first)
		printf("\n");
}

void listPrint(struct Node* p)
{
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int countNode(struct Node *p)
{
	int count = 0;
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;
}

int RcountNode(struct Node *p)
{
	if(p == NULL)
		return 0;
	return RcountNode(p->next)+1;
}

int sumNode(struct Node *p)
{
	int count = 0;
	while(p)
	{
		count += p->data;
		p = p->next;
	}
	return count;
}

int RsumNode(struct Node *p)
{
	if(p == NULL)
		return 0;
	return RsumNode(p->next)+p->data;
}

int listMax(struct Node *p)
{
	int max = INT_MIN;
	while(p)
	{
		if(p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}

int RlistMax(struct Node *p)
{
	if (p == 0)
		return INT_MIN;
	int x = RlistMax(p->next);
	if(x > p->data)
		return x;
	else
		return p->data;
}

int listMin(struct Node *p)
{
	int min = INT_MAX;
	while(p)
	{
		if(p->data < min)
			min = p->data;
		p = p->next;
	}
	return min;
}

int RlistMin(struct Node *p)
{
	if(p == 0)
		return INT_MAX;
	int x = RlistMin(p->next);
	if (x < p->data)
		return x;
	else
		return p->data;
}

struct Node* listSearch(struct Node *p, int x)
{
	// struct Node *q = NULL;
	while(p)
	{	
		if(p->data == x) 
		{
			/*
			// Move to first
			if(q != NULL)
			{
				q->next = p->next;
				p->next = first;
				first = p;
			}
			*/
			return p;
		}
		// q = p;
		p = p->next;
	}
	return NULL;
}

struct Node* RlistSearch(struct Node *p, int x)
{
	if(p->data == x) 
		return p;
	else if(p->next == 0)
		return NULL;
	RlistSearch(p->next, x);
}

struct Node* moveToFrontRlistSearch(struct Node *p, struct Node *q, int x)
{
	if(p->data == x) 
	{
		// Move to first
		if(q != NULL)
		{
			q->next = p->next;
			p->next = first;
			first = p;
		}
		return p;
	}
	else if(p->next == 0)
		return NULL;
	moveToFrontRlistSearch(p->next, p, x);
}

void insert(int pos, int item)
{
	if (pos < 0)
		return;

	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = item;
	if(pos == 0)
	{
		temp->next = first;
		first = temp;
	}
	else
	{
		struct Node *prev = first;
		for (int i = 1; i < pos && prev; i++)
			prev = prev->next;
			
		if(prev)
		{
			temp->next = prev->next;
			prev->next = temp;
		}
	}
}

void append(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->next = NULL;
	if(first == NULL)
		first=last=temp;
	else
	{
		last->next = temp;
		last = temp;
	}
}

void sortInsert(int item)
{
	struct Node *p = first, *q = NULL, *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	while(p && p->data < item)
	{
		q = p;
		p = p->next;
	}
	if(q == NULL)
	{
		temp->next = first;
		first = temp;
	}
	else
	{
		temp->next = q->next;
		q->next = temp;
	}
}

int deleteNode(int index)
{
	int ele = -1;
	struct Node *p = first, *q = NULL;
	if(index == 1)
	{
		p = first;
		first = first->next;
		ele = p->data; 
		free(p);
	}
	else
	{
		for (int i = 1; i < index && p; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		ele = p->data;
		free(p);
	}
	return ele;
}

int isSorted(struct Node *p)
{
	int x =  INT_MIN;
	while(p)
	{
		if(x > p->data)
			return 0;
		x = p->data;
		p = p->next;
	}
	return 1;
}

void romoveDuplicateNode(struct Node *p)
{
	struct Node *q = p->next;
	while(q)
	{
		if(p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

void reverseLinkList(struct Node *p)
{
	struct Node *q = NULL, *r = NULL;
	while(p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

void RreverseLinkList(struct Node *p, struct Node *q)
{
	if(p == NULL)
	{
		first = q;
		return;
	}
	RreverseLinkList(p->next, p);
	p->next = q;
}

void concatanate(struct Node *p, struct Node *q)
{
	while(p->next)
		p = p->next;
	p->next = q;
}

struct Node* marge(struct Node *p, struct Node *q)
{
	struct Node *third, *last;

	if(p->data < q->data)
	{
		third = last = p;
		p = p->next;
		last->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		last->next = NULL;
	}

	while(p && q)
	{
		if(p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if(p) last->next = p;
	if(q) last->next = q;

	return third;
}

int isLoop(struct Node *f)
{
	struct Node *p, *q;
	p = q = f;

	do
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : q;
	} while(p && q && p != q);

	if(p==q)
		return 1;
	else
		return 0;
}

struct Node* moveToMiddel(struct Node *p)
{
	struct Node *q = p;
	while(p)
	{
		p = p->next;
		if(p) p = p->next;
		if(p) q = q->next;
	}
	return q;
}

struct Node* intersectingPoint(struct Node *p, struct Node *q)
{
	struct Node *ps[10], *qs[10];
	int i, j;
	for (i = 0; p; i++)
	{
		ps[i] = p;
		p = p->next;
	}
	for (j = 0; q; j++)
	{
		qs[j] = q;
		q = q->next;
	}
	i--; j--;
	for ( ; ps[i] == qs[j]; i--, j--)
	{
		p = ps[i];
	}
	return p;
}

int main()
{
	int list2[] = {10, 20};
	create(list2, sizeof(list2)/sizeof(int));

	secound = first;

	int list1[] = {1, 2, 3, 30, 40, 50};
	create(list1, sizeof(list1)/sizeof(int));

	secound->next->next = first->next->next->next;

	listPrint(first);
	listPrint(secound);

	struct Node *in = intersectingPoint(first, secound);
	printf("%d\n", in->data);

	return 0;
}