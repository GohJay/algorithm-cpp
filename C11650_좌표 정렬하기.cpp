#include <stdio.h>
#include <algorithm>

struct Point
{
	int x;
	int y;
};
bool comapre(const Point& a, const Point& b)
{
	if (a.x < b.x)
		return true;
	else if (a.x > b.x)
		return false;
	else
		return a.y < b.y;
}
int main()
{
	int N;
	Point point[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &point[i].x, &point[i].y);
	}
	std::sort(point, point + N, comapre);
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", point[i].x, point[i].y);
	}
}
