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

int graph[1001][1001];
int visited[1001];
int node;

void BFS(int val)
{
	std::queue<int> nodeQ;
	nodeQ.push(val);
	visited[val] = 1;

	int n;
	while (nodeQ.size() > 0)
	{
		n = nodeQ.front();
		nodeQ.pop();
		printf("%d ", n);

		for (int i = 1; i <= node; i++)
		{
			if (!visited[i] && graph[n][i])
			{
				nodeQ.push(i);
				visited[i] = 1;
			}
		}
	}
}

void DFS(int val)
{
	std::stack<int> nodeStack;
	nodeStack.push(val);
	visited[val] = 1;

	int n;
	while (nodeStack.size() > 0)
	{
		n = nodeStack.top();
		nodeStack.pop();
		printf("%d ", n);

		for (int i = node; i >= 1; i--)
		{
			if (!visited[i] && graph[n][i])
			{
				nodeStack.push(i);
				visited[i] = 1;
			}
		}
	}
}

void DFS_r(int val)
{
	visited[val] = 1;
	printf("%d ", val);
	for (int i = 1; i <= node; i++)
	{
		if (!visited[i] && graph[val][i])
		{
			DFS_r(i);
		}
	}
}

int main()
{
	int m, v;
	scanf("%d %d %d", &node, &m, &v);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	memset(visited, 0, sizeof(visited));
	DFS_r(v);
	//DFS(v);

	printf("\n");

	memset(visited, 0, sizeof(visited));
	BFS(v);
	return 0;
}
