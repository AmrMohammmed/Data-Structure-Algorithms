#include<iostream>
using namespace std;

struct treeNode
{
	int value;
	treeNode *left;
	treeNode *right;
};

treeNode* create_Node(int val)
{
	treeNode *newNode = new treeNode;

	newNode->value = val;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

bool insertNum(treeNode *&root,int val)
{
	

	if(root==NULL)
	{
		root = create_Node(val);
	}
	if (val == root->value)
	{
		return false;//do nothing it's aldready there

	}
	else if(val < root->value)
	{
		return insertNum(root->left,val);
	}
	else
	{
		return insertNum(root->right, val);
	}
}
bool findNum(treeNode * root, int val)
{
	if (root == NULL)
	{
		return false;
	}
	if (val == root->value)
	{
		return true;

	}
	else if (val < root->value)
	{
		return findNum(root->left, val);
	}
	else
	{
		return findNum(root->right, val);
	}
}


void printTabs(int n)
{
	for (int i = 0; i < n; i++)
		cout << "\t";
}

void printTree(treeNode *head,int level=0)
{
	if(head == NULL)
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

	printTree(head->left,level+1);

	printTabs(level);
	cout << "right" << endl;
	
	printTree(head->right, level + 1);

	printTabs(level-1);
	cout << "Done:"<< head->value << endl;
}
int main()
{
	treeNode *root = NULL;

	insertNum(root, 15);
	insertNum(root, 11);
	insertNum(root, 19);
	insertNum(root, 5);
	insertNum(root, 16);
	insertNum(root, 24);
	
	printTree(root);

	return 0;
}


/*treeNode *n1, *n2, *n3, *n4, *n5;
	n1 = create_Node(10);
	n2 = create_Node(11);
	n3 = create_Node(12);
	n4 = create_Node(13);
	n5 = create_Node(14);

	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;
	printTree(n1);*/