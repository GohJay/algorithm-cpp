#include <stdio.h>

int main()
{
	int N, M;
	int input[100];
	int sum, max = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = input[i] + input[j] + input[k];
				if (sum <= M && sum > max)
					max = sum;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
