#include <stdio.h>
#include <queue>
#define MAX_SIZE 100001
int visited[MAX_SIZE] = { 0, };
int N, K;
void BFS(int v)
{
	std::queue<int> queue;
	visited[v] = 1;
	queue.push(v);
	while (queue.size() > 0)
	{
		int x = queue.front();
		queue.pop();
		if (x == K) return;
		for (int i = 0; i < 3; i++)
		{
			int nx;
			if (i == 0) nx = x + 1;
			else if (i == 1) nx = x - 1;
			else if (i == 2) nx = x * 2;
			if (0 <= nx && nx < MAX_SIZE && !visited[nx])
			{
				visited[nx] = visited[x] + 1;
				queue.push(nx);
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &K);
	BFS(N);
	printf("%d\n", visited[K] - 1);
	return 0;
}
