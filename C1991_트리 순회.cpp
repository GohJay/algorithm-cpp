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

struct NODE
{
	char data;
	char left;
	char right;
};
NODE tree[127];

void preOrder(NODE* node)
{
	if (node->data == '.')
		return;

	printf("%c", node->data);
	preOrder(&tree[node->left]);
	preOrder(&tree[node->right]);
}

void inOrder(NODE* node)
{
	if (node->data == '.')
		return;

	inOrder(&tree[node->left]);
	printf("%c", node->data);
	inOrder(&tree[node->right]);
}

void postOrder(NODE* node)
{
	if (node->data == '.')
		return;

	postOrder(&tree[node->left]);
	postOrder(&tree[node->right]);
	printf("%c", node->data);
}

int main()
{
	int N;
	scanf("%d", &N);

	char data, left, right;
	for (int i = 0; i < N; i++)
	{
		scanf("\n%c \n%c \n%c", &data, &left, &right);
		tree[data].data = data;
		tree[data].left = left;
		tree[data].right = right;
	}

	tree['.'].data = '.';

	preOrder(&tree['A']);
	printf("\n");
	inOrder(&tree['A']);
	printf("\n");
	postOrder(&tree['A']);

	return 0;
}
