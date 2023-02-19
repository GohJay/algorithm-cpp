#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <string.h>

struct NODE
{
	NODE(int data, NODE* parent, NODE* left, NODE* right)
		: _data(data), _parent(parent), _left(left), _right(right)
	{
	}
	int _data;
	NODE* _parent;
	NODE* _left;
	NODE* _right;
};
NODE* root;

void Insert(NODE** tree, int data)
{
	NODE* node;
	if (*tree == NULL)
	{
		node = new NODE(data, NULL, NULL, NULL);
		*tree = node;
		return;
	}

	if ((*tree)->_data > data)
	{
		if ((*tree)->_left == NULL)
		{
			node = new NODE(data, *tree, NULL, NULL);
			(*tree)->_left = node;
			return;
		}
		else
			Insert(&(*tree)->_left, data);
	}
	else if ((*tree)->_data < data)
	{
		if ((*tree)->_right == NULL)
		{
			node = new NODE(data, *tree, NULL, NULL);
			(*tree)->_right = node;
			return;
		}
		else
			Insert(&(*tree)->_right, data);
	}
}

void PrintPostOrder(NODE* tree)
{
	if (tree == NULL)
		return;

	PrintPostOrder(tree->_left);
	PrintPostOrder(tree->_right);
	printf("%d\n", tree->_data);
}

int main()
{
	int data;
	while (scanf("%d", &data) != EOF)
		Insert(&root, data);

	PrintPostOrder(root);
	return 0;
}
