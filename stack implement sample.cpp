#include<iostream>
#include <string>
#include<stack>
using namespace std;

const int stackSize = 10;

template <class stackType>
struct Stack
{

private:

	stackType arr[stackSize];
	int top = -1;

public:
	void push(stackType value)
	{
		if (top == stackSize - 1)
		{
			cout << "Stack Overflow!" << endl;
			return;
		}
		top++;
		arr[top] = value;

	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		return false;
	}

	void pop()
	{
		if (isEmpty() == true)
		{
			cout << "Stack Underflow!" << endl;
			return;
		}

		top--;
	}

	void pop(stackType &x)
	{
		if (isEmpty() == true)
		{
			cout << "Stack Underflow!" << endl;
			return;
		}

		x = arr[top];
		top--;
	}
	stackType getTop()
	{
		if (isEmpty() == true)
		{
			cout << "Stack Underflow! nothing to get" << endl;

			return stackType();//provide a default value suitable for the type
							   // (0 for numbers, empty string for std::string, etc.).
		}
		return arr[top];
	}
	void display()
	{
		cout << "Stack Contents:\n";
		for (int i = top; i >= 0; i--)
		{

			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Stack<int> s1;
	s1.push(1);
	s1.push(33);
	s1.pop();
	s1.push(14);
	s1.display();

	Stack<string> s2;

	s2.push("asd1");
	s2.push("asd2");
	s2.push("asd3");
	s2.pop();
	s2.display();

	stack<float> s3;
	s3.push(1.1);
	s3.push(1.2);
	cout <<"\nc++ stack top: "<< s3.top() << endl;

	return 0;
}