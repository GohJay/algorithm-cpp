#include <stdio.h>

int graph[101][101] = { 0, };
int visited[101];
int node, cnt;
void BFS(int start)
{
	visited[start] = 1;
	int queue[101] = { 0, };
	int front = 0;
	int rear = 0;
	queue[rear++] = start;
	do
	{
		int val = queue[front++];
		for (int i = 1; i <= node; i++)
		{
			if (!visited[i] && graph[val][i])
			{
				queue[rear++] = i;
				visited[i] = 1;
				cnt++;
			}
		}
	} while (front < rear);
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
	BFS(1);
	printf("%d", cnt);
	return 0;
}