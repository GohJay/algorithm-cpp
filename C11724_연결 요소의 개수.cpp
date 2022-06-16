#include <stdio.h>

int graph[1001][1001];
int visited[1001];
int node;
void DFS(int start)
{
	visited[start] = 1;
	for (int i = 1; i <= node; i++)
	{
		if (!visited[i] && graph[start][i])
		{
			DFS(i);
		}
	}
}
int main()
{
	int m;
	scanf("%d%d", &node, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= node; i++)
	{
		if (visited[i])
			continue;
		DFS(i);
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
