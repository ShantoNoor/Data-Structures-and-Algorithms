#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	struct Node *l, *r;
	int data;
}*root;

void insert(int item)
{
	struct Node *t = NULL, *f = root;
	
	while(f)
	{
		t = f;
		if(f->data > item)
			f = f->l;
		else if(f->data < item)
			f = f->r;
		else 
			return;
	}

	f = (struct Node*)malloc(sizeof(struct Node));
	f->data = item;
	f->l = f->r = NULL;

	if(t == NULL)
		root = f;
	else
	{
		if(t->data > item)
			t->l = f;
		else
			t->r = f;
	}
}

struct Node* Rinsert(struct Node *t, int item)
{
	if(t == NULL)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = item;
		t->l = t->r = NULL;
		return t;
	}
	if(t->data < item)
		t->r  = Rinsert(t->r, item);
	else if(t->data > item)
		t->l = Rinsert(t->l, item);
	return t;
}

void Rsearch(struct Node *t, int item)
{
	if(t)
	{
		if(t->data < item)
			Rsearch(t->r, item);
		else if(t->data > item)
			Rsearch(t->l, item);
		else
		{
			printf("Found %d\n", item);
			return;
		}
	}
	else printf("NOT Found %d\n", item);
}

struct Node* RNsearch(struct Node *t, int item)
{
	if(t == NULL)
		return NULL;
	if(t->data < item)
		return RNsearch(t->r, item);
	else if(t->data > item)
		return RNsearch(t->l, item);
	else
		return t;
}

void search(int item)
{
	struct Node *t = root;
	while(t)
	{
		if(item < t->data)
			t = t->l;
		else if(item > t->data)
			t = t->r;
		else
		{
			printf("Found %d\n", item);
			return;
		}
	}
	printf("NOT Found %d\n", item);
}

void inorder(struct Node *t)
{
	if(t)
	{
		inorder(t->l);
		printf("%d ", t->data);
		inorder(t->r);
	}
}
void preorder(struct Node *p)
{
	if(p)
	{
		printf("%d ", p->data);
		preorder(p->l);
		preorder(p->r);
	}
}

int height(struct Node *p)
{
	if(p == NULL) return 0;
	int x = height(p->l);
	int y = height(p->r);
	return x > y ? x+1 : y+1;
}

struct Node* inpre(struct Node *p)
{
	while(p && p->r)
		p = p->r;
	return p;
}

struct Node* insuc(struct Node *p)
{
	while(p && p->l)
		p = p->l;
	return p;
}

struct Node* delete(struct Node *p, int item)
{
	if(p == NULL)
		return NULL;

	if(!p->l && !p->r)
	{
		if(p == root)
			root = NULL;
		free(p);
		return NULL;
	}

	if(item < p->data)
		p->l = delete(p->l, item);
	else if(item > p->data)
		p->r = delete(p->r, item);
	else
	{
		struct Node *q;
		if(height(p->l) > height(p->r))
		{
			q = inpre(p->l);
			p->data = q->data;
			p->l = delete(p->l, q->data);
		}
		else
		{
			q = insuc(p->r);
			p->data = q->data;
			p->r = delete(p->r, q->data);
		}
	}
	return p;
}

void createBSTfromPreorder(int preo[], int len)
{
	struct Node *l = NULL, *p = NULL, *s[10] = {NULL};
	int i = 0, si = 0;

	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = preo[i++];
	p->l = p->r = NULL;
	
	root = l = p;

	while(i < len)
	{
		if(preo[i] < l->data)
		{
			p = (struct Node*)malloc(sizeof(struct Node));
			p->data = preo[i++];
			p->l = p->r = NULL;

			l->l = p;
			s[si++] = l; 
			l = p;
		}
		else
		{
			int max = INT_MAX;
			if(si) max = s[si-1]->data; 
			if(preo[i] < max)
			{
				p = (struct Node*)malloc(sizeof(struct Node));
				p->data = preo[i++];
				p->l = p->r = NULL;

				l->r = p; 
				l = p;
			}
			else l = s[--si];
		}	
	}
}

int main()
{
	// insert(50);
	// insert(10);	
	// insert(5);	
	// insert(20);	
	// insert(8);	
	// insert(30);	


	int preo[] = {50, 10, 5, 8, 20, 30};
	int size = sizeof(preo)/sizeof(preo[0]);

	createBSTfromPreorder(preo, size);

	preorder(root); printf("\n");
	inorder(root); printf("\n");
	// delete(root, 50);
	// inorder(root); printf("\n");


	return 0;
}