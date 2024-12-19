#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node *left;
	Node * right;
};
void insertNode(Node *&root, int val)
{
	Node *newNode = new Node;
	newNode->value = val;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		Node *cur, *pre;
		cur = pre = root;
		while (cur != NULL)
		{
			pre = cur;
			if (val > cur->value)
				cur = cur->right;
			else
				cur = cur->left;
		}
		if (val > pre->value)
			pre->right = newNode;
		else
			pre->left = newNode;
	}
}
void inorder(Node * root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->value << " ";
		inorder(root->right);
	}
}

void preOrder(Node * root)
{

	if (root != NULL)
	{
		cout << root->value << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void posOrder(Node * root)
{

	if (root != NULL)
	{

		posOrder(root->left);
		posOrder(root->right);
		cout << root->value << " ";
	}
}
void printTabs(int n)
{
	for (int i = 0; i < n; i++)
		cout << "\t";
}
void printTree(Node *head, int level = 0)
{
	if (head == NULL)
	{
		printTabs(level);
		cout << "<empty>" << endl;
		return;
	}

	printTabs(level);
	cout << "value = " << head->value << endl;

	level++;
	printTabs(level);
	cout << "left" << endl;

	printTree(head->left, level + 1);

	printTabs(level);
	cout << "right" << endl;

	printTree(head->right, level + 1);

	printTabs(level - 1);
	cout << "Done:" << head->value << endl;
}


int main()
{
	Node *root=NULL;
	insertNode(root, 15);
	insertNode(root, 11);
	insertNode(root, 19);
	insertNode(root, 5);
	insertNode(root, 16);
	insertNode(root, 24);

	printTree(root);

	cout <<"\nPre-order : ";
	preOrder(root);

	cout << "\nIn-order : ";
	inorder(root);

	cout << "\nPost-order : ";
	posOrder(root);

	cout << endl;

	return 0;
}