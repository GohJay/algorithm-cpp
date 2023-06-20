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

using namespace std;

int G;
int graph[101][101];
int answer[101][101];
int visited[101];

void BFS(int start)
{
	std::queue<int> nodeQ;
	nodeQ.push(start);

	int n;
	while (nodeQ.size() > 0)
	{
		n = nodeQ.front();
		nodeQ.pop();

		for (int i = 1; i <= G; i++)
		{
			if (!visited[i] && graph[n][i])
			{
				nodeQ.push(i);
				visited[i] = 1;
				answer[start][i] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d", &G);

	for (int i = 1; i <= G; i++)
	{
		for (int j = 1; j <= G; j++)
		{
			int n;
			scanf("%d", &n);
			graph[i][j] = n;
		}
	}

	for (int i = 1; i <= G; i++)
	{
		memset(visited, 0, sizeof(visited));
		BFS(i);
	}

	for (int i = 1; i <= G; i++)
	{
		for (int j = 1; j <= G; j++)
		{
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}

	return 0;
}
