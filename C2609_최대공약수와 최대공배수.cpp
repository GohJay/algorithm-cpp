#include <stdio.h>

int gdc(int a, int b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int c = a % b;
	while (c > 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
int lcm(int a, int b)
{
	int div = gdc(a, b);
	return (a * b) / div;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gdc(a, b));
	printf("%d\n", lcm(a, b));
	return 0;
}
