#include <stdio.h>
#include <math.h>

int N, r, c;
int result = 0;
void DP(int x, int y, int size)
{
	if (c == x && r == y)
	{
		// 찾으려는 열과 행이 일치하면 
		printf("%d\n", result);
		return;
	}
	else if (c < x + size && r < y + size && c >= x && r >= y)
	{
		//찾으려는 열과 행이 4분면안에 있을 경우
		DP(x, y, size / 2);
		DP(x + size / 2, y, size / 2);
		DP(x, y + size / 2, size / 2);
		DP(x + size / 2, y + size / 2, size / 2);
	}
	else
	{
		// 없다면 숫자 카운트 -> 정사각형 넓이
		result += size * size;
	}
}
int main() {
	scanf("%d %d %d", &N, &r, &c);
	DP(0, 0, pow(2, N));
	return 0;
}
