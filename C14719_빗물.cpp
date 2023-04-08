#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	
	int arr[501];
	for (int i = 0; i < W; i++)
		cin >> arr[i];

	int answer = 0;
	for (int i = 1; i < W - 1; i++)
	{
		int left = 0;
		int right = 0;

		// 왼쪽 최대 값
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);

		// 오른쪽 최대 값
		for (int j = W - 1; j > i; j--)
			right = max(right, arr[j]);

		// 빗물 계산
		answer += max(0, min(left, right) - arr[i]);
	}

	cout << answer;

	return 0;
}
