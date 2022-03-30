#include <stdio.h>

int main()
{
	int zero[41] = { 1, 0 };
	int one[41] = { 0, 1 };
	int n, v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v);
		for (int j = 2; j <= v; j++)
		{
			zero[j] = zero[j - 1] + zero[j - 2];
			one[j] = one[j - 1] + one[j - 2];
		}
		printf("%d %d\n", zero[v], one[v]);
	}
}