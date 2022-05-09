#include <stdio.h>

void swap(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}
int main()
{
	int a, b, c;
	int temp;
	for (;;)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a + b + c == 0) break;
		/*
		직각 삼각형 공식 : 작은변 제곱 * 작은변 제곱 == 큰변 제곱
		*/
		if (b > c) swap(b, c);
		if (a > c) swap(a, c);		
		if ((a * a) + (b * b) == (c * c))
			printf("%s\n", "right");
		else
			printf("%s\n", "wrong");
	}
	return 0;
}
