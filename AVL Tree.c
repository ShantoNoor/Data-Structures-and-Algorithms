#include <stdio.h>
#include <stdlib.h>

#define balanceFactor BF

struct Node 
{
	struct Node *l, *r;
	int data, h;
}*root = NULL;

int nodeHeight(struct Node *p)
{
	int hl = p && p->l ? p->l->h : 0;
	int hr = p && p->r ? p->r->h : 0;
	return hl > hr ? hl+1 : hr+1;
}

int balanceFactor(struct Node *p)
{
	int hl = p && p->l ? p->l->h : 0;
	int hr = p && p->r ? p->r->h : 0;
	return hl-hr;
}

struct Node* rrRotation(struct Node* t)
{
	struct Node *tl, *tlr;
	tl = t->l;
	tlr = tl->r;

	tl->r = t;
	t->l = tlr;

	t->h = nodeHeight(t);
	tl->h = nodeHeight(tl);

	if(t == root)
		root = tl;

	return tl;
}

struct Node* llRotation(struct Node* t)
{
	struct Node *tr, *trl;
	tr = t->r;
	trl = tr->l;

	tr->l = t;
	t->r = trl;

	t->h = nodeHeight(t);
	tr->h = nodeHeight(tr);

	if(t == root)
		root  = tr;
	return tr;
}

// struct Node* lrRotation(struct Node* t)
// {
// 	struct Node *tl, *tlr;
// 	tl = t->l;
// 	tlr = tl->r;

// 	tl->r = tlr->l;
// 	t->l = tlr->r;
// 	tlr->l = tl;
// 	tlr->r = t;

// 	t->h = nodeHeight(t);
// 	tl->h =  nodeHeight(tl);
// 	tlr->h = nodeHeight(tlr);

// 	if(t == root)
// 		root = tlr;
// 	return tlr;
// }

// struct Node* rlRotation(struct Node* t)
// {
// 	struct Node *tr, *trl;
// 	tr = t->r;
// 	trl = tr->l;

// 	tr->l = trl->l;
// 	t->r = trl->r;
// 	trl->l = t;
// 	trl->r = tr;

// 	t->h = nodeHeight(t);
// 	tr->h = nodeHeight(tr);
// 	trl->h = nodeHeight(trl);

// 	if(t == root)
// 		root = trl;
// 	return trl;
// }

struct Node* lrRotation(struct Node* t)
{
	t->l = llRotation(t->l);
	return rrRotation(t);
}

struct Node* rlRotation(struct Node* t)
{
	t->r = rrRotation(t->r);
	return llRotation(t);
}

struct Node* Rinsert(struct Node *t, int item)
{
	if(t == NULL)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = item;
		t->h = 1;
		t->l = t->r = NULL;
		return t;
	}
	if(t->data < item)
		t->r  = Rinsert(t->r, item);
	else if(t->data > item)
		t->l = Rinsert(t->l, item);
	else return t;

	t->h = nodeHeight(t);

	if(BF(t) == 2 && BF(t->l) == 1)
		return rrRotation(t);
	else if(BF(t) == 2 && BF(t->l) == -1)
		return lrRotation(t);
	else if(BF(t) == -2 && BF(t->r) == -1)
		return llRotation(t);
	else if(BF(t) == -2 && BF(t->r) == 1)
		return rlRotation(t);

	return t;
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

struct Node* insuc(struct Node *t)
{
	t = t->r;
	while(t && t->l) t = t->l;
	return t;
}

struct Node* inpre(struct Node *t)
{
	t = t->l;
	while(t && t->r) t = t->r;
	return t;
}

struct Node* delete(struct Node *t, int item)
{
	if(!t) return NULL;
	if(!t->l && !t->r)
	{
		if(t == root)
			root = NULL;
		free(t);
		return NULL;
	}

	if(item == t->data)
	{
		struct Node *q = insuc(t);
		if(q)
		{
			t->data = q->data;
			t->r = delete(t->r, q->data);
		}
		else
		{
			q = inpre(t);
			t->data = q->data;
			t->l = delete(t->l, q->data);
		}
	}
	else if(item < t->data)
		t->l = delete(t->l, item);
	else t->r = delete(t->r, item);

	t->h = nodeHeight(t);

	// Rotations ----
	if(BF(t) == 2 && (BF(t->l) == 1 || BF(t->l) == 0))
		return rrRotation(t);
	else if(BF(t) == -2 && (BF(t->r) == -1 || BF(t->r) == 0))
		return llRotation(t);
	else if(BF(t) == 2 && BF(t->l) == -1)
		return lrRotation(t);
	else if(BF(t) == -2 && BF(t->r) == 1)
		return rlRotation(t);

	return t;
}

int main()
{
	// root = Rinsert(root, 25);
	// Rinsert(root, 10);
	// Rinsert(root, 28);
	// Rinsert(root, 5);
	// Rinsert(root, 30);
	// Rinsert(root, 27);
	// Rinsert(root, 20);
	// inorder(root); printf("\n");	
	// preorder(root); printf("\n");	
	// printf("%d\n", root->h);

	// root = Rinsert(root, 50);
	// Rinsert(root, 40);
	// Rinsert(root, 60);
	// Rinsert(root, 30);
	// Rinsert(root, 55);
	// Rinsert(root, 45);
	// Rinsert(root, 10);

	// preorder(root); printf("\n");	
	// printf("%d\n", root->h); 
 //    /*preorder 50 40 30 10 45 60 55 || height = 4*/
	// delete(root, 55);
	// /*preorder 40 30 10 50 45 60 || height = 3*/	
	// preorder(root); printf("\n");	
	// printf("%d\n", root->h);

	// root = NULL;

	root = Rinsert(root, 9);  
    Rinsert(root, 5);  
    Rinsert(root, 10);  
    Rinsert(root, 0);  
    Rinsert(root, 6);  
    Rinsert(root, 11);  
    Rinsert(root, -1);  
    Rinsert(root, 1);  
    Rinsert(root, 2); 

    preorder(root); printf("\n");	
	printf("%d\n", root->h); 
    /*preorder 9 1 0 -1 5 2 6 10 11 || height = 4*/
	delete(root, 10);
	/*preorder 1 0 -1 9 5 2 6 11 || height = 4*/	
	preorder(root); printf("\n");	
	printf("%d\n", root->h);
	

	return 0;
}