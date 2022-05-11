#include <stdio.h>
#include <algorithm>

int compare(const int& a, const int& b)
{
	return a < b;
}
int lower_bound(int* arr, int target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}
int upper_bound(int* arr, int target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (arr[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}
int arr_n[500000];
int arr_m[500000];
int main()
{
	int N, M;
	int lower, upper;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr_n[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr_m[i]);
	}
	std::sort(arr_n, arr_n + N, compare);
	for (int i = 0; i < M; i++)
	{
		lower = lower_bound(arr_n, arr_m[i], N);
		upper = upper_bound(arr_n, arr_m[i], N);
		if (arr_n[N - 1] == arr_m[i]) upper++;
		printf("%d\n", upper - lower);
	}
	return 0;
}
