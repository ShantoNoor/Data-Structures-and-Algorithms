#include <stdio.h>
#include <stdlib.h>

#define deb(x) printf("%s = %d\n",#x, x);

/*--------Chaining--------*/
// struct Node
// {
// 	int data;
// 	struct Node *next;
// };

// struct Node* createNode(int x)
// {
// 	struct Node *t = (struct Node*)malloc(sizeof(struct Node));
// 	t->data = x;
// 	t->next = NULL;
// 	return t;
// }

// void sortInsert(struct Node **t, int item)
// {
// 	struct Node *p = *t, *q = NULL, *temp = NULL;
// 	temp = createNode(item);
// 	while(p && p->data < item)
// 	{
// 		q = p;
// 		p = p->next;
// 	}
// 	if(q == NULL)
// 	{
// 		temp->next = *t;
// 		*t = temp;
// 	}
// 	else
// 	{
// 		temp->next = q->next;
// 		q->next = temp;
// 	}
// }

// struct Node* search(struct Node *p, int key)
// {
// 	while(p)
// 	{
// 		if(p->data == key)
// 			return p;
// 		p = p->next;
// 	}
// 	return NULL;
// }

// void display(struct Node *p)
// {
// 	if(p == NULL) printf("List is Empty!");
// 	while(p)
// 	{
// 		printf("%d ", p->data);
// 		p = p->next;
// 	}
// 	printf("\n");
// }

// int hash(int x){ return x%10; }

// void hashInsert(struct Node *h[], int key)
// {
// 	sortInsert(&h[hash(key)], key);
// }

// void chaining()
// {
// 	struct Node *H[10] = {NULL};
// 	hashInsert(H, 1);
// 	hashInsert(H, 2);
// 	hashInsert(H, 4);
// 	hashInsert(H, 44);

// 	struct Node *t = search(H[hash(4)], 44);
// 	deb(t->data)
// }

/*------Linear Probing------*/
// #define size 10

// int hash(int key) { return key%size; }

// int probe(int H[], int key)
// {
// 	int index = hash(key);
// 	int i = 0;
// 	while(H[(index+i*i)%size] != 0) i++;
// 	return (index+i*i)%size;
// }
// int Search(int H[], int key)
// {
// 	int index = hash(key);
// 	int i = 0;
// 	while(H[(index+i*i)%size] != key && H[(index+i*i)%size] != 0) i++;
// 	if(H[(index+i*i)%size] == 0) return -1;
// 	return (index+i*i)%size;
// }

// void Insert(int H[], int key)
// {
// 	int index = probe(H, key);
// 	H[index] = key;
// }

// void LinearProbing()
// {
// 	int HT[size] = {0};
// 	Insert(HT, 12);
// 	Insert(HT, 25);
// 	Insert(HT, 35);
// 	Insert(HT, 26);
// 	Insert(HT, 2);

// 	printf("\nKey Found at %d\n", Search(HT, 25));
// 	printf("Key Found at %d\n", Search(HT, 35));
// 	printf("Key Found at %d\n", Search(HT, 26));
// 	printf("Key Found at %d\n", Search(HT, 2));
// }

/*------Quadretic Probing------*/
// #define size 10

// int hash(int key) { return key%size; }

// int probe(int H[], int key)
// {
// 	int index = hash(key);
// 	int i = 0;
// 	while(H[(index+i*i)%size] != 0) i++;
// 	return (index+i*i)%size;
// }
// int Search(int H[], int key)
// {
// 	int index = hash(key);
// 	int i = 0;
// 	while(H[(index+i*i)%size] != key && H[(index+i*i)%size] != 0) i++;
// 	if(H[(index+i*i)%size] == 0) return -1;
// 	return (index+i*i)%size;
// }

// void Insert(int H[], int key)
// {
// 	int index = probe(H, key);
// 	H[index] = key;
// }

// void QuadreticProbing()
// {
// 	int HT[size] = {0};
// 	Insert(HT, 12);
// 	Insert(HT, 25);
// 	Insert(HT, 35);
// 	Insert(HT, 5);
// 	Insert(HT, 26);
// 	Insert(HT, 2);
// 	Insert(HT, 22);

// 	printf("Key Found at %d\n", Search(HT, 25));
// 	printf("Key Found at %d\n", Search(HT, 35));
// 	printf("Key Found at %d\n", Search(HT, 5));
// 	printf("Key Found at %d\n", Search(HT, 26));
// 	printf("Key Found at %d\n", Search(HT, 2));
// 	printf("Key Found at %d\n", Search(HT, 22));
// }

/*------Double Hashing------*/
#define size 10
#define prime 7

int hash1(int key) { return key%size; }
int hash2(int key) { return prime-(key%prime); }

int hash(int H[], int x)
{
	int i = 0;
	int index = hash1(x);
	while(H[index] != 0)
		index = (hash1(x)+(++i)*hash2(x))%size;
	return index;
}
int Search(int H[], int x)
{
	int i = 0;
	int index = hash1(x);
	while(H[index] != 0 && H[index] != x)
		index = (hash1(x)+(++i)*hash2(x))%size;
	if(H[index] == 0) return -1;
	return index;
}

void Insert(int H[], int key)
{
	int index = hash(H, key);
	H[index] = key;
}

void QuadreticProbing()
{
	int HT[size] = {0};
	Insert(HT, 12);
	Insert(HT, 25);
	Insert(HT, 35);
	Insert(HT, 5);
	Insert(HT, 26);
	Insert(HT, 2);
	Insert(HT, 22);

	printf("Key Found at %d\n", Search(HT, 25));
	printf("Key Found at %d\n", Search(HT, 35));
	printf("Key Found at %d\n", Search(HT, 5));
	printf("Key Found at %d\n", Search(HT, 26));
	printf("Key Found at %d\n", Search(HT, 2));
	printf("Key Found at %d\n", Search(HT, 22));
}

void DoubleHashing()
{
	int HT[size] = {0};
	Insert(HT, 5);
	Insert(HT, 25);
	Insert(HT, 15);
	Insert(HT, 35);
	Insert(HT, 95);

	deb(Search(HT, 5))
	deb(Search(HT, 1))
	deb(Search(HT, 25))
	deb(Search(HT, 15))
	deb(Search(HT, 35))
	deb(Search(HT, 95))
}

int main()
{
	// chaining();
	// LinearProbing();
	// QuadreticProbing();
	DoubleHashing();
	
	return 0;
}