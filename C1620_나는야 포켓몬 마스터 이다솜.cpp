#include <stdio.h>
#include <map>
#include <string>

bool isInteger(const char* str)
{
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return false;
		str++;
	}
	return true;
}
int main()
{
	int N, M;
	char name[20];
	char question[20];
	std::map<int, std::string> mapIndex;
	std::map<std::string, int> mapName;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", name);
		mapIndex.insert(std::pair<int, std::string>(i, name));
		mapName.insert(std::pair<std::string, int>(name, i));
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", &question);
		if (isInteger(question))
		{
			auto iter = mapIndex.find(atoi(question));
			printf("%s\n", iter->second.c_str());
		}
		else
		{
			auto iter = mapName.find(question);
			printf("%d\n", iter->second);
		}
	}
	return 0;
}