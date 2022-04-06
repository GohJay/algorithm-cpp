#include <stdio.h>
#include <algorithm>

int arr[1000001];
void Solution(int n, int key)
{
	int start = 0;
	int end = n - 1;
	int mid;
	while (end >= start)
	{
		mid = (start + end) / 2;
		if (arr[mid] == key)
		{
			printf("1\n");
			return;
		}
		else if (arr[mid] > key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	printf("0\n");
}
int main()
{
	int t, n, m, tmp;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		std::sort(arr, arr + n);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			Solution(n, tmp);
		}
	}	
	return 0;
}