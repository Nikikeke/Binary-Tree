#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
struct Node
{
	char c;
	Node *leftChild, *rightChild;
	int len;
	int d;
};
Node* BuildTree()
{
	string s;
	int len, top = 1;
	stack<Node*> Stack;
	cin >> s;
	Node *root = new Node;
	root->c = s[0];
	root->leftChild = NULL;
	root->rightChild = NULL;
	root->len = 0;
	root->d = 0;
	Stack.push(root);
	while (cin >> s)
	{
		if (s == "0")
			break;
		len = s.length();
		Node *new_Node = new Node;
		new_Node->c = s[len - 1];
		new_Node->leftChild = NULL;
		new_Node->rightChild = NULL;
		new_Node->len = len - 1;
		new_Node->d = 0;
		Node *r = Stack.top();
		while (new_Node->len - r->len != 1)
		{
			Stack.pop();
			r = Stack.top();
		}
		if (new_Node->c == '*')
		{
			r->d++;
			continue;
		}
		if (r->d == 0)
		{
			r->leftChild = new_Node;
			r->d++;
		}
		else if (r->d == 1)
		{
			r->rightChild = new_Node;
			r->d++;
		}
		if (r->d == 2)
			Stack.pop();
		Stack.push(new_Node);
	}
	return root;
}
void PreOrder(Node *root)
{
	if (root)
	{
		cout << root->c;
		PreOrder(root->leftChild);
		PreOrder(root->rightChild);
	}
}
void InOrder(Node *root)
{
	if (root)
	{
		InOrder(root->leftChild);
		cout << root->c;
		InOrder(root->rightChild);
	}
}
void PostOrder(Node *root)
{
	if (root)
	{
		PostOrder(root->leftChild);
		PostOrder(root->rightChild);
		cout << root->c;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		Node *root = BuildTree();
		PreOrder(root);
		cout << endl;
		PostOrder(root);
		cout << endl;
		InOrder(root);
		cout << endl;
		cout << endl;
	}
	return 0;
}