#include <stdio.h>
#include <algorithm>

int main()
{
	int N;
	int *input;
	scanf("%d", &N);
	input = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
	}
	std::sort(input, input + N);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", input[i]);
	}
	free(input);
	return 0;
}
