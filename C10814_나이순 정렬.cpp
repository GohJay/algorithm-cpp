#include <stdio.h>
#include <algorithm>

struct Member
{
	int age;
	char name[200];
};
Member member[100000];

bool compare(const Member& a, const Member& b)
{
	return a.age < b.age;
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &member[i].age, &member[i].name);
	}
	std::stable_sort(member, member + N, compare);
	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", member[i].age, member[i].name);
	}
	return 0;
}
