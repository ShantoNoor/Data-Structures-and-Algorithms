#include <stdio.h>
#include <stdlib.h>

struct Term
{
	int coff;
	int exp;
};

struct Poly
{
	int n;
	struct Term* t;
};


void setPoly(struct Poly* p)
{
	int i;
	printf("Enter number of non-zero element:");
	scanf("%d", &p->n);
	p->t = (struct Term*)malloc(p->n*sizeof(struct Term));
	printf("Enter all the terms:\n");
	for(i = 0; i < p->n; i++)
	{
		scanf("%d%d", &p->t[i].coff, &p->t[i].exp);
	}
}

void displayPoly(struct Poly p)
{
	int i;
	printf("-------Start-------\n");
	for (i = 0; i < p.n; i++)
	{
		printf("%dx^%d + ", p.t[i].coff, p.t[i].exp);
	}
	printf("\n--------end--------\n\n");
}

struct Poly* add(struct Poly s1, struct Poly s2)
{
	int i, j, k;
	struct Poly *s3;
	s3 = (struct Poly*)malloc(sizeof(struct Poly));
	s3->t = (struct Term*)malloc((s1.n+s2.n)*sizeof(struct Term));
	i = j = k = 0;

	while(i < s1.n && j < s2.n)
	{
		if(s1.t[i].exp > s2.t[j].exp)
			s3->t[k++] = s1.t[i++];
		else if(s1.t[i].exp < s2.t[j].exp)
			s3->t[k++] = s2.t[j++];
		else
		{
			s3->t[k] = s1.t[i++];
			s3->t[k++].coff += s2.t[j++].coff; 
		}
	}

	for( ; i < s1.n; i++)
		s3->t[k++] = s1.t[i++];

	for( ; j < s2.n; j++)
		s3->t[k++] = s2.t[j++];

	s3->n = k;

	return s3;
}

int main()
{
	struct Poly x, y, *z;

	setPoly(&x);
	setPoly(&y);

	z = add(x, y);

	displayPoly(x);
	getchar();
	displayPoly(y);
	getchar();
	displayPoly(*z);



	return 0;
}