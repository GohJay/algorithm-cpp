#include <stdio.h>
#include <algorithm>

int main()
{
	int N;
	int P[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &P[i]);
	}

	std::sort(P, P + N);
	for (int i = 1; i < N; i++)
	{
		P[i] = P[i - 1] + P[i];
	}

	int total = 0;
	for (int i = 0; i < N; i++)
	{
		total += P[i];
	}

	printf("%d\n", total);
	return 0;
}
