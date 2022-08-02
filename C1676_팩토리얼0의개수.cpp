#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int cnt = 0;
	while (N >= 5)
	{
		cnt += N / 5;
		N /= 5;
	}
	printf("%d", cnt);
	return 0;
}