#include <iostream>
using namespace std;

struct Node 
{
	struct Node *l, *r;
	int data;
} *root;

template <typename T, int stack_size>
class Stack
{
    int top = 0;
    T ara[stack_size];
public:
    void push(T a)
    {
        if(top >= stack_size)
        {
            cout << "Error: Stack is FULL!" << endl;
            exit(1);
        }
        else
        {
            ara[top] = a;
            top++;
        }
        
    }
    T pop()
    {
        if(top == 0)
        {
            cout << "Error: Stack is EMPTY!" << endl;
            exit(1);
        }
        else
        {
            top--;
            return ara[top];
        }
    }
    T stackTop()
    {
        if(top == 0)
        {
            cout << "Error: Stack is EMPTY!" << endl;
            exit(1);
        }
        else
        {
            return ara[top-1];
        }
    }
    int getTop()
    {
        return top;
    }
    bool isEmpty() { return top == 0; }
    bool isFull() { return top >= stack_size; }
    T peek(int i)
    {
        if(top - i > -1)
            return ara[top-i];
        else
        {
            cout << "Invalid Index : ";
            return -1;
            cout << endl;
        }
    }
};

template <typename T, int size>
class queue
{
	int head = 0;
	int tail = 0;
	T arr[size+1];
public:
	void enque(T x)
	{
		if(head == (tail+1)%(size+1))
			printf("Queue is full!...\n");
		else
		{
			arr[tail] = x;
			tail = (tail+1)%(size+1);
		}
	}
	T deque()
	{
		T ret = 0;
		if(head == tail)
			printf("Queue is Empty!...\n");
		else
		{
			ret = arr[head];
			arr[head] = 0;
			head = (head+1) % (size+1);
		}
		return ret;
	}
	bool isEmpty() { return head == tail; }
	bool isFull() { return head == (tail+1)%(size+1); }
};

void createTree()
{
	queue<Node*, 10> q;
	root = new Node;
	// printf("Enter root value : ");
	scanf("%d", &root->data);
	root->l = root->r = NULL;
	q.enque(root);
	Node *t = NULL, *l = NULL;
	int x;
	while(!q.isEmpty())
	{
		l = q.deque();

		// printf("Enter left child of %d: ", l->data);
		scanf("%d", &x);
		if(x != -1)
		{
			t = new Node;
			t->data = x;
			t->l = t->r = NULL;
			l->l = t;
			q.enque(t);
		}
		// printf("Enter right child of %d: ", l->data);
		scanf("%d", &x);
		if(x != -1)
		{
			t = new Node;
			t->data = x;
			t->l = t->r = NULL;
			l->r = t;
			q.enque(t);
		}
	}
}

void preorder(Node *p)
{
	if(p)
	{
		printf("%d ", p->data);
		preorder(p->l);
		preorder(p->r);
	}
}

void inorder(Node *p)
{
	if(p)
	{
		inorder(p->l);
		printf("%d ", p->data);
		inorder(p->r);
	}
}

void postorder(Node *p)
{
	if(p)
	{
		postorder(p->l);
		postorder(p->r);
		printf("%d ", p->data);
	}
}

void Ipreorder(Node *p)
{
	Stack<Node*, 10> s;
	
	while(p || !s.isEmpty())
	{
		if(p)
		{
			printf("%d ", p->data);
			s.push(p);
			p = p->l;
		}
		else
		{
			p = s.pop();
			p = p->r;
		}
	}
	printf("\n");
}

void Iinorder(Node *p)
{
	Stack<Node*, 10> s;
	
	while(p || !s.isEmpty())
	{
		if(p)
		{
			s.push(p);
			p = p->l;
		}
		else
		{
			p = s.pop();
			printf("%d ", p->data);
			p = p->r;
		}
	}
	printf("\n");
}

void Ipostorder(Node *p)
{
	Stack<Node*, 10> s;
	
	while(p || !s.isEmpty())
	{
		if(p)
		{
			s.push(p);
			p = p->l;
		}
		else
		{
			long long a = (long long)(s.pop());
			if(a > 0)
			{
				s.push((Node*)(a*(-1)));
				p = ((Node*)a)->r;
			}
			else
			{
				printf("%d ", ((Node*)(a*(-1)))->data);
				p = NULL;
			}
		}
	}
	printf("\n");
}

void levelorder(Node *p)
{
	queue<Node*, 10> q;
	q.enque(p);

	while(!q.isEmpty())
	{
		p = q.deque();
		printf("%d ", p->data);
		if(p->l != NULL)
			q.enque(p->l);
		if(p->r != NULL)
			q.enque(p->r);
	}
	printf("\n");
}

int countNumberOfAllNodes(Node *p)
{
	if(p)
	{
		int x = countNumberOfAllNodes(p->l);
		int y = countNumberOfAllNodes(p->r);
		return x+y+1;
	}
	return 0;
}

int countSumOfAllNodes(Node *p)
{
	if(p)
	{
		int x = countSumOfAllNodes(p->l);
		int y = countSumOfAllNodes(p->r);
		return x+y+p->data;
	}
	return 0;
}

int countNumberOfNodesWithDegree0(Node *p)
{
	if(p)
	{
		int x = countNumberOfNodesWithDegree0(p->l);
		int y = countNumberOfNodesWithDegree0(p->r);

		if(!p->l && !p->r)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int countSumOfNodesWithDegree0(Node *p)
{
	if(p)
	{
		int x = countSumOfNodesWithDegree0(p->l);
		int y = countSumOfNodesWithDegree0(p->r);

		if(!p->l && !p->r)
			return x+y+p->data;
		else
			return x+y;
	}
	return 0;
}

int countNumberOfNodesWithDegree1(Node *p)
{
	if(p)
	{
		int x = countNumberOfNodesWithDegree1(p->l);
		int y = countNumberOfNodesWithDegree1(p->r);

		if((p->l && p->r == NULL) || (p->l == NULL && p->r))
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int countSumOfNodesWithDegree1(Node *p)
{
	if(p)
	{
		int x = countSumOfNodesWithDegree1(p->l);
		int y = countSumOfNodesWithDegree1(p->r);

		if((p->l && p->r == NULL) || (p->l == NULL && p->r))
			return x+y+p->data;
		else
			return x+y;
	}
	return 0;
}

int countNumberOfNodesWithDegree2(Node *p)
{
	if(p)
	{
		int x = countNumberOfNodesWithDegree2(p->l);
		int y = countNumberOfNodesWithDegree2(p->r);

		if(p->l && p->r)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int countSumOfNodesWithDegree2(Node *p)
{
	if(p)
	{
		int x = countSumOfNodesWithDegree2(p->l);
		int y = countSumOfNodesWithDegree2(p->r);

		if(p->l && p->r)
			return x+y+p->data;
		else
			return x+y;
	}
	return 0;
}

int countHeight(Node *p)
{
	if(p)
	{
		int x = countHeight(p->l);
		int y = countHeight(p->r);

		if(x > y)
			return x+1;
		else
			return y+1;
	}
	return 0;
}

Node* createTreeWithPreorderAndInoreder(int preo[], int ino[], int i, int j)
{
	static int p = 0;

	if(i > j) return NULL;

	Node* t = new Node;
	t->data = preo[p++];
	t->l = NULL;
	t->r = NULL;

	if(i == j) return t;

	int index;
	for (index = i; index <= j; index++)
		if(t->data == ino[index])
			break;

	t->l = createTreeWithPreorderAndInoreder(preo, ino, i, index-1);
	t->r = createTreeWithPreorderAndInoreder(preo, ino, index+1, j);

	return t;
}

int main()
{
	// createTree();

	// preorder(root); printf("\n");
	// Ipreorder(root);
	// inorder(root); printf("\n");
	// Iinorder(root);
	// postorder(root); printf("\n");
	// Ipostorder(root);
	// levelorder(root);

	// printf("N0 = %d\n", countNumberOfNodesWithDegree0(root));
	// printf("S0 = %d\n", countSumOfNodesWithDegree0(root));
	// printf("N1 = %d\n", countNumberOfNodesWithDegree1(root));
	// printf("S1 = %d\n", countSumOfNodesWithDegree1(root));
	// printf("N2 = %d\n", countNumberOfNodesWithDegree2(root));
	// printf("S2 = %d\n", countSumOfNodesWithDegree2(root));
	// printf("NA = %d\n", countNumberOfAllNodes(root));
	// printf("SA = %d\n", countSumOfAllNodes(root));
	// printf("TH = %d\n", countHeight(root));

	int preo[] = {1, 2, 4, 5, 3, 6, 7};
	int ino[] = {4, 2, 5, 1, 6, 3, 7};
	int posto[] = {4, 5, 2, 6, 7, 3, 1};
	root = createTreeWithPreorderAndInoreder(preo, ino, 0, sizeof(ino)/sizeof(ino[0])-1);

	preorder(root); printf("\n");
	Ipreorder(root);
	inorder(root); printf("\n");
	Iinorder(root);
	postorder(root); printf("\n");
	Ipostorder(root);
	levelorder(root);

	printf("N0 = %d\n", countNumberOfNodesWithDegree0(root));
	printf("S0 = %d\n", countSumOfNodesWithDegree0(root));
	printf("N1 = %d\n", countNumberOfNodesWithDegree1(root));
	printf("S1 = %d\n", countSumOfNodesWithDegree1(root));
	printf("N2 = %d\n", countNumberOfNodesWithDegree2(root));
	printf("S2 = %d\n", countSumOfNodesWithDegree2(root));
	printf("NA = %d\n", countNumberOfAllNodes(root));
	printf("SA = %d\n", countSumOfAllNodes(root));
	printf("TH = %d\n", countHeight(root));

	return 0;
}