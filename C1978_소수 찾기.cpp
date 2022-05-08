#include <stdio.h>

int main()
{
	int N;
	int input;
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		if (input <= 1) continue;
		int find = 1;
		for (int j = 2; j < input; j++)
		{
			if (input % j == 0)
			{
				find = 0;
				break;
			}
		}
		if (find) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
