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
#include <unordered_map>

using namespace std;

int main()
{
	int site, find;
	cin >> site >> find;

	unordered_map<string, string> siteMap;
	string url;
	string password;
	for (int i = 0; i < site; i++)
	{
		cin >> url >> password;
		siteMap.insert(make_pair(url, password));
	}

	string question;
	string answer;
	for (int i = 0; i < find; i++)
	{
		cin >> question;
		cout << siteMap[question] << "\n";
	}

	return 0;
}
