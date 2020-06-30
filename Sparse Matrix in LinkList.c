#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int col, data;
	struct Node *next;
};

struct SparseMatrix
{
	int i, j, n;
	struct Node **e;
};

struct SparseMatrix create()
{
	struct SparseMatrix sp;
	scanf("%d %d %d", &sp.i, &sp.j, &sp.n);
	sp.e = (struct Node **)malloc(sp.i*sizeof(struct Node));

	for (int i = 0; i < sp.i; i++)
	{
		struct Node *t, *l;
		int x;
		int f = 1;
		for (int j = 0; j < sp.j; j++)
		{
			scanf("%d", &x);
			if(x != 0)
			{
				t = (struct Node *)malloc(sizeof(struct Node));
				t->col = j;
				t->data = x;
				t->next = NULL;
				
				if(f == 1)
				{
					sp.e[i] = l = t;
					f++;
				}
				else
					l->next = t;
				l = t;
			}
		}
	}
	return sp;
}

void display(struct SparseMatrix sp)
{
	for (int i = 0; i < sp.i; i++)
	{
		struct Node *p = sp.e[i];
		
		for (int j = 0; j < sp.j; j++)
		{
			if(p && p->col == j)
			{
				printf("%d ", p->data);
				p = p->next;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}

struct SparseMatrix add(struct SparseMatrix sp1, struct SparseMatrix sp2)
{
	struct SparseMatrix sp;
	if(sp1.i != sp2.i && sp1.j != sp2.j)
	{
		sp.i = sp.j = sp.n = -1;
		sp.e = NULL;
		printf("Matrix can not be add!...\n");
		return sp;
	}
	sp.i = sp1.i;
	sp.j = sp1.j;
	sp.e = (struct Node **)malloc(sp.i*sizeof(struct Node));

	struct Node *p, *q, *t, *l;
	int k = 0;
	for (int i = 0; i < sp.i; i++)
	{
		p = sp1.e[i];
		q = sp2.e[i];
		int f = 1;
		int data, col;
		while(p && q)
		{
			if(p->col < q->col)
			{
				data = p->data;
				col = p->col;
				p = p->next;
			}
			else if(p->col > q->col)
			{
				data = q->data;
				col = q->col;
				q = q->next;
			}
			else
			{
				col = p->col;
				data = p->data + q->data;
				p = p->next;
				q = q->next;
			}
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = data;
			t->col = col;
			t->next = NULL;
			if(f == 1)
			{
				sp.e[i] = l = t;
				f++;
			}
			else
				l->next = t;
			l = t;
			k++;
		}
		while(p)
		{
			data = p->data;
			col = p->col;
			p = p->next;
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = data;
			t->col = col;
			t->next = NULL;
			if(f == 1)
			{
				sp.e[i] = l = t;
				f++;
			}
			else
				l->next = t;
			l = t;
			k++;
		}
		while(q)
		{
			data = q->data;
			col = q->col;
			q = q->next;
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = data;
			t->col = col;
			t->next = NULL;
			if(f == 1)
			{
				sp.e[i] = l = t;
				f++;
			}
			else
				l->next = t;
			l = t;
			k++;
		}
	}
	sp.n = k;
	return sp;
}

int main()
{
	
	struct SparseMatrix sp = create();
	display(sp);

	struct SparseMatrix sp1 = create();
	display(sp1);

	struct SparseMatrix sp3 = add(sp, sp1);
	display(sp3);

	return 0;
}