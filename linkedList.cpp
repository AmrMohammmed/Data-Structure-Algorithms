
#include<iostream>
using namespace std;

struct linkedList
{
	struct Node
	{
		int value;
		Node *next;
	};

	Node *head = NULL;
	Node *tail = NULL;
	int length = 0;

	void insertFront(int val)
	{
		Node *newNode = new Node;
		newNode->value = val;
		if (length == 0)
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		length++;

	}

	void insertLast(int val)
	{
		Node *newNode = new Node;
		newNode->value = val;
		if (length == 0)
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else
		{
			tail->next = newNode;
			newNode->next = NULL;
			tail = newNode;
		}
		length++;

	}

	void insertAtPosition(int pos,int val)
	{
		if(pos < 0 || pos > length)
		{
			cout << "Invalid Position! Can't Insert!" << endl;
		}
		else if(pos == 0)
		{
			insertFront(val);
		}
		else if(pos == length)
		{
			insertLast(val);
		}
		else
		{
			Node *newNode = new Node;
			newNode->value = val;
			Node *current=head;

			for(int i=1;i< pos;i++)
			{
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
			length++;
		}
	
	}
	void deleteFirst()
	{
		if(length==0)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		else if(length == 1)
		{
			delete head;
			head = tail = NULL;
			length--;
		}
		else
		{
			Node *current = head;
			head = head->next;
			delete current;
			length--;
		}
		
	}
	void deleteLast()
	{
		if (length == 0)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		else if (length == 1)
		{
			delete head;
			head = tail = NULL;
			length--;
		}
		else
		{
			Node *current = head;
			while(current->next != tail)
			{
				current = current->next;
			}
			delete tail;
			tail = current;
			tail->next = NULL;
			length--;
		}
	}

	void deleteValue(int val)
	{
		if (length == 0)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		else if(head->value == val)
		{
			deleteFirst();
		}
		else
		{
			Node *current = head;
			while (current != NULL)
			{
				if (current->next != NULL && current->next->value == val)
						break;
				current = current->next;
			}
			if(current == NULL)
			{
				cout << "Value not found!" << endl;
				return;
			}
			Node *prev = current;

			current = current->next;

			prev->next = current->next;

			delete current;

			length--;
		}
	}
	void deleteAtPosition(int pos)
	{
	
		if (pos < 0 || pos >= length)
		{
			cout << "Invalid Position! Can't delete!" << endl;
		}
		else if (pos == 0)
		{
			deleteFirst();
		}
		else if (pos == length-1)
		{
			deleteLast();
		}
		else
		{
			Node *current = head;

			for (int i = 1; i < pos; i++)
			{
				current = current->next;
			}
			Node *temp = current->next;
			current->next = temp->next;
			delete temp;
			length--;
		}
	
	}

	int search(int val)
	{
		if(head == NULL)
		{
			cout << "list is Empty!" << endl;
			return -1;
		}
		else
		{
			Node *current = head;
			int pos = 0;
			while (current != NULL)
			{
				if (current->value == val)
					return pos;
				current = current->next;
				pos++;
			}

		}
	
		cout << "Value not found!" << endl;
		return -1;
	}
	Node* find(int val)
	{
		if (head == NULL)
		{
			cout << "list is Empty!" << endl;
			return NULL;
		}
		else
		{
			Node *current = head;
			while (current != NULL)
			{
				if (current->value == val)
					return current;
				current = current->next;
			}

		}

		cout << "Value not found!" << endl;
		return NULL;
	
	}

	void printList()
	{
		if(head == NULL)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		Node *current = head;

		while (current != NULL)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
	

	void destoryList()
	{
		while (length >0)
		{
			deleteFirst();
		}
	}
	~linkedList()
	{
		destoryList();
	}
};

int main()
{
	linkedList l1;

	// Test: Insertions
	l1.insertFront(10); // List: 10
	l1.insertFront(20); // List: 20 -> 10
	l1.insertLast(30);  // List: 20 -> 10 -> 30
	l1.insertAtPosition(1, 15); // List: 20 -> 15 -> 10 -> 30

	cout << "After Insertions: ";
	l1.printList(); // Output: 20 15 10 30

	// Test: Deletions
	l1.deleteFirst(); // List: 15 -> 10 -> 30
	cout << "After deleteFirst: ";
	l1.printList(); // Output: 15 10 30

	l1.deleteLast(); // List: 15 -> 10
	cout << "After deleteLast: ";
	l1.printList(); // Output: 15 10

	l1.deleteValue(15); // List: 10
	cout << "After deleteValue(15): ";
	l1.printList(); // Output: 10

	l1.insertLast(40); // List: 10 -> 40
	l1.insertLast(50); // List: 10 -> 40 -> 50
	l1.deleteAtPosition(1); // List: 10 -> 50
	cout << "After deleteAtPosition(1): ";
	l1.printList(); // Output: 10 50

	// Test: Search
	int pos = l1.search(50);
	cout << "Position of 50: " << pos << endl; // Output: 1

	pos = l1.search(100);
	cout << "Position of 100: " << pos << endl; // Output: -1 (Value not found)

	// Test: Find
	linkedList::Node *node = l1.find(50);
	if (node)
		cout << "Node found with value: " << node->value << endl; // Output: Node found with value: 50
	else
		cout << "Node not found!" << endl;

	// Test: Edge Cases
	l1.deleteAtPosition(5); // Invalid position
	l1.printList();

	l1.deleteFirst();       // List: 50
	l1.printList();

	l1.deleteLast();        // List is now empty
	l1.printList();

	l1.deleteLast();        // Attempt to delete from empty list
	l1.printList();

	cout << "After all deletions: ";
	l1.printList(); // Output: List is Empty!

	// Test: Insert after clear
	l1.insertLast(60); // List: 60
	l1.insertFront(70); // List: 70 -> 60
	cout << "After reinserting: ";
	l1.printList(); // Output: 70 60
	return 0;
}