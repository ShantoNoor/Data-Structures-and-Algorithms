#include <iostream>

using namespace std;


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
			arr[head] = -1;
		head = (head+1) % (size+1);
		}
		return ret;
	}
	bool isEmpty() { return head == tail; }
	bool isFull() { return head == (tail+1)%(size+1); }
};

int main()
{
	queue<int, 10> q;

	q.enque(10);
	q.enque(40);
	q.enque(30);
	q.enque(20);
	q.enque(10);
	q.enque(40);
	q.enque(30);
	q.enque(30);
	q.enque(30);
	q.enque(20);

	// cout << q.deque() << endl;
	// cout << q.deque() << endl;
	// cout << q.deque() << endl;
	cout << q.isFull() << endl;

	return 0;
}