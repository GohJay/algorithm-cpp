#include <stdio.h>
#include <string.h>

int M, N;
int g_graph[50][50];
int g_visited[50][50];
int g_dx[4] = { 0, 1, 0, -1 };
int g_dy[4] = { 1, 0, -1, 0 };
bool DFS(int x, int y)
{
	if (g_visited[x][y]) return false;
	g_visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + g_dx[i];
		int ny = y + g_dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && g_graph[nx][ny])
			DFS(nx, ny);
	}
	return true;
}
int main()
{
	int T;
	int K;
	int x, y;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		memset(g_graph, 0, sizeof(g_graph));
		memset(g_visited, 0, sizeof(g_visited));
		scanf("%d %d %d", &M, &N, &K);
		while (K > 0)
		{
			scanf("%d %d", &x, &y);
			g_graph[x][y] = 1;
			K--;
		}
		int cnt = 0;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (g_graph[j][k])
				{
					if (DFS(j, k))
						cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}
