#include <stdio.h>

int main()
{
	int a, b, c;
	int temp;
	for (;;)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a + b + c == 0) break;
		if (c < b)
		{
			temp = c;
			c = b;
			b = temp;
		}
		if (c < a)
		{
			temp = c;
			c = a;
			a = temp;
		}
		/*
		직각 삼각형 공식 : 작은변 제곱 * 작은변 제곱 == 큰변 제곱
		*/
		if ((a * a) + (b * b) == (c * c))
			printf("%s\n", "right");
		else
			printf("%s\n", "wrong");
	}
	return 0;
}
