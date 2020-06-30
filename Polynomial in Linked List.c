#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
	int coff, exp;
	struct Node *next;
};
struct Poly
{
	int n;
	struct Node *e;
};

struct Poly create()
{
	struct Poly p;
	scanf("%d", &p.n);
	
	struct Node *t, *l;
	int f = 1;
	for (int i = 0; i < p.n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		scanf("%d %d", &t->coff, &t->exp);
		t->next = NULL;

		if(f == 1)
		{
			p.e = l = t;
			f++;
		}
		else
			l->next = t;
		l = t;
	}

	return p;
}

void display(struct Poly p)
{
	struct Node *q = p.e;
	for (int i = 0; i < p.n; i++)
	{
		printf("%dx%d + ", q->coff, q->exp);
		q = q->next;
	}
	printf("\n");
}

double eval(struct Poly p, double x)
{
	struct Node *q = p.e;
	double res = 0;
	for (int i = 0; i < p.n; i++)
	{
		res += q->coff * pow(x, q->exp);
		q = q->next;
	}

	return res;
}

struct Poly add(struct Poly p1, struct Poly p2)
{
	struct Poly p;
	struct Node *i, *j, *t, *l;
	i = p1.e;
	j = p2.e;
	int co, ex, k = 0, f = 1;
	while(i && j)
	{
		if(i->exp > j->exp)
		{
			co = i->coff;
			ex = i->exp;
			i = i->next;
		}
		else if(i->exp < j->exp)
		{
			co = j->coff;
			ex = j->exp;
			j = j->next;
		}
		else
		{
			co = i->coff + j->coff;
			ex = i->exp;
			i = i->next;
			j = j->next;
		}
		t = (struct Node*)malloc(sizeof(struct Node));
		t->coff = co;
		t->exp = ex;
		t->next = NULL;
		if(f == 1)
		{
			p.e = l = t;
			f++;
		}
		else
			l->next = t;
		l = t;
		k++;
	}
	/* for remaining node(create new Node and copy value)
	while(i)
	{
		co = i->coff;
		ex = i->exp;
		i = i->next;
		t = (struct Node*)malloc(sizeof(struct Node));
		t->coff = co;
		t->exp = ex;
		t->next = NULL;
		if(f == 1)
		{
			p.e = l = t;
			f++;
		}
		else
			l->next = t;
		l = t;
		k++;
	}
	while(j)
	{
		co = j->coff;
		ex = j->exp;
		j = j->next;
		t = (struct Node*)malloc(sizeof(struct Node));
		t->coff = co;
		t->exp = ex;
		t->next = NULL;
		if(f == 1)
		{
			p.e = l = t;
			f++;
		}
		else
			l->next = t;
		l = t;
		k++;
	}
	*/
	
	//joining the remainig node
	if(i)
	{
		l->next = i;
		while(i)
		{
			k++;
			i = i->next;
		}
	}
	if(j)
	{
		l->next = j;
		while(j)
		{
			k++;
			j = j->next;
		}
	}
 	p.n = k;
	return p;
}

int main()
{
	struct Poly p = create();
	display(p);

	struct Poly q = create();
	display(q);

	struct Poly r = add(p, q);
	display(r);

	printf("%lf\n", eval(r, 1));

	return 0;
}