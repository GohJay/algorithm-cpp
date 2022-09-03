#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <functional>

using namespace std;

int N;
int K;
int T;

bool Solution(vector<int>& nadoriBaguni)
{
	int start = 0;
	int end = N - 1;
	for (int i = 0; i < N; i++)
	{
		if (nadoriBaguni[i] > 0)
			break;
		start++;
	}

	while (T > 0 && start < end)
	{
		int max = K - nadoriBaguni[end];
		int cnt = max > nadoriBaguni[start] ? nadoriBaguni[start] : max;

		nadoriBaguni[start] -= cnt;
		nadoriBaguni[end] += cnt;

		if (nadoriBaguni[start] == 0)
			start++;

		if (K - nadoriBaguni[end] == 0)
			end--;

		T -= cnt;
	}

	if (T >= 0 && nadoriBaguni[end] == 0)
		return true;

	return false;
}

int main()
{
	cin >> N >> K >> T;

	vector<int> nadoriBaguni(N);
	for (int i = 0; i < N; i++)
		cin >> nadoriBaguni[i];

	sort(nadoriBaguni.begin(), nadoriBaguni.end());
	bool answer = Solution(nadoriBaguni);
	cout << (answer ? "YES" : "NO") << endl;

	return 0;
}
