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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	long long result = 0;

	cin >> N;
	int arr[6];
	int six = 0;
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
		result += arr[i];
		six = max(six, arr[i]);
	}
	
	int sum1;
	int sum2;
	int sum3;
	if (N == 1)
	{
		cout << result - six;
	}
	else
	{
		result = 0;
		arr[0] = min(arr[0], arr[5]);
		arr[1] = min(arr[1], arr[4]);
		arr[2] = min(arr[2], arr[3]);

		sort(arr, arr + 3);
		sum1 = arr[0];
		sum2 = sum1 + arr[1];
		sum3 = sum2 + arr[2];


		result += sum3 * 4;
		result += sum2 * (((N - 1) * 4) + ((N - 2) * 4));
		result += sum1 * (((N - 1) * (N - 2)) * 4 + ((N - 2) * (N - 2)));

		cout << result;
	}

	return 0;
}