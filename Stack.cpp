#include <iostream>

using namespace std;

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
    int getTop() { return top; }
    bool isEmpty() { return top == 0; }
    bool isFull() { return top >= stack_size; }
    void beEmpty() { top = 0; }
};

int main()
{
	Stack<int, 20> s;

	s.push(2);
	s.push(1);
	s.push(6);

    std::cout << s.peek(5) << std::endl;
    std::cout << s.getTop() << std::endl;


	return 0;
}