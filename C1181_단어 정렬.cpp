#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

bool compare(std::string a, std::string b)
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main()
{
	int N;
	scanf("%d", &N);
	char temp[50];
	std::vector<std::string> wordList;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &temp);
		wordList.push_back(temp);
	}
	sort(wordList.begin(), wordList.end(), compare);
	printf("%s\n", wordList[0].c_str());
	for (int i = 1; i < N; i++)
	{
		if (wordList[i] == wordList[i - 1])
			continue;
		printf("%s\n", wordList[i].c_str());
	}
	return 0;
}
