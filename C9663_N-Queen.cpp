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

int N;
int count;
std::vector<int> rows;

bool Check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (rows[i] == rows[row] || abs(rows[row] - rows[i]) == row - i)
			return false;
	}
	return true;
}

void DFS(int row)
{
	if (row == N)
	{
		count++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		rows[row] = i;
		if (Check(row))
		{
			DFS(row + 1);
		}
	}
}

int main()
{
	scanf("%d", &N);
	rows.reserve(N);

	DFS(0);

	printf("%d", count);
	return 0;
}
