#include<iostream>
#include<queue>
using namespace std;

const int QueueSize = 5;

template<class QueueType>
struct Queue
{
	private:
		QueueType arr[QueueSize];

		int front = -1;
		int rear = -1;
		int counter = 0;
	public:
		bool isEmpty()
		{
			return counter == 0;
		}
		bool isFull()
		{
			return counter == QueueSize;
		}
		void enqueue(QueueType value)
		{
			if (isFull())
			{
				cout << "Queue Overflow!" << endl;
				return;
			}
			if (front == -1)
			{
				front = 0;
			}

			rear = (rear + 1) % QueueSize;
			arr[rear] = value;
			counter++;
		}

		void dequeue()
		{
			if (isEmpty())
			{
				cout << "Queue is Underflow!" << endl;
				return;
			}

			if (front == rear)// Only one element in queue
			{
				front = -1;
				rear = -1;
			}

			else
				front = (front + 1) % QueueSize;

			counter--;

		}

		QueueType getFront()
		{
			if (isEmpty())
			{
				cout << "Queue is Empty!" << endl;
				return QueueType();
			}
			return arr[front];
		}

		QueueType getRear()
		{
			if (isEmpty())
			{
				cout << "Queue is Empty!" << endl;
				return QueueType();
			}
			return arr[rear];
		}

		void displayQueue()
		{
			if (isEmpty())
			{
				cout << "Queue is Empty!" << endl;
				return;
			}
			for (int i = front; i != rear; i = (i + 1) % QueueSize)
			{
				cout << arr[i] << " ";

			}
			cout << arr[rear] <<endl;

		}

		int getSize()
		{
			return counter;
		}
};


int main()
{
	//Userdefined queue

	Queue<int> q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();

	q1.enqueue(7);
	q1.enqueue(8);
	q1.enqueue(9);


	q1.displayQueue();

	cout<<endl;

	//STL queue

	queue<int>q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);

	q2.pop();
	q2.pop();
	q2.pop();

	q2.push(7);
	q2.push(8);
	q2.push(9);

	
	while (!q2.empty()) 
	{
		cout << q2.front() << " ";
		q2.pop();
	}
	
	

	return 0;
}