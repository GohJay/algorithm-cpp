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

int N, M;
int sequence[10000];
int answer[10000];

void Solution(int point, int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";

		cout << "\n";
		return;
	}

	for (int i = point; i < N; i++)
	{
		answer[count] = sequence[i];
		Solution(i, count + 1);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> sequence[i];

	sort(sequence, sequence + N);

	Solution(0, 0);
	return 0;
}
