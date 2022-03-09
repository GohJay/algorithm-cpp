#include <stdio.h>
#include <stdlib.h>
int main() {
	int in;
	scanf("%d", &in);
	long long* result = (long long*)malloc((in + 1) * sizeof(long long));
	for (int i = 0; i < in + 1; i++)
	{
		if (i < 2)
			result[i] = i;
		else
			result[i] = result[i - 1] + result[i - 2];
	}
	printf("%lld", result[in]);
	free(result);
	return 0;
}