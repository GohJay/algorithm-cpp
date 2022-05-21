#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int N, M;
	char name[20];
	std::unordered_set<std::string> setHuman;
	std::vector<std::string> vectHuman;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &name);
		setHuman.insert(name);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", &name);
		auto iter = setHuman.find(name);
		if (iter != setHuman.end())
			vectHuman.push_back(name);
	}
	std::sort(vectHuman.begin(), vectHuman.end());
	printf("%d\n", vectHuman.size());
	for (int i = 0; i < vectHuman.size(); i++)
	{
		printf("%s\n", vectHuman[i].c_str());
	}
	return 0;
}