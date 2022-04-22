#include <stdio.h>

int main()
{
	int x, y, w, h;
	int w_min, h_min;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	w_min = x < (w - x) ? x : (w - x);
	h_min = y < (h - y) ? y : (h - y);
	printf("%d\n", w_min < h_min ? w_min : h_min);
}
