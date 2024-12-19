#include <iostream>

using namespace std;

struct  node
{
	int value;
	node* next;
};

node * top=NULL;

void push(int val)
{
	node* temp = new node;
	temp->value = val;
	temp->next = top;
	top = temp;
}

void pop()
{
	node*temp = top;
	top = top->next;
	delete temp;
}

void print_stack()
{
	node*temp = top;
	while(temp!=NULL)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}

}
int main()
{
	push(2);
	push(5);
	push(3);
	pop();
	push(7);
	print_stack();
	return 0;
}