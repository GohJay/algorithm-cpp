#include <stdio.h>
#include <queue>

int main()
{
	int N, K;
	std::queue<int> queue;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		queue.push(i);
	printf("<");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K - 1; j++)
		{
			queue.push(queue.front());
			queue.pop();
		}
		printf("%d", queue.front());
		if (i < N - 1) printf(", ");
		queue.pop();
	}
	printf(">");
}
