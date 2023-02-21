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

int tree[64][64];

void QuadTree(int x, int y, int size)
{
	int data = tree[y][x];
	bool combine = true;

	for (int i = y; i < y + size && combine; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (tree[i][j] != data)
			{
				combine = false;
				break;
			}
		}
	}

	if (combine)
	{
		printf("%c", data);
		return;
	}
	
	size /= 2;

	printf("(");
	QuadTree(x, y, size);
	QuadTree(x + size, y, size);
	QuadTree(x, y + size, size);
	QuadTree(x + size, y + size, size);
	printf(")");
}

int main()
{
	int n;
	scanf("%d\n", &n);

	char str[65];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		for (int j = 0; j < n; j++)
			tree[i][j] = str[j];
	}

	QuadTree(0, 0, n);
	return 0;
}
