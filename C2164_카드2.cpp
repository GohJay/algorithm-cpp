#include <stdio.h>
#include <queue>

int main()
{
	int N;
	std::queue<int> card;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		card.push(i + 1);
	bool temp = true;
	while (card.size() > 1)
	{
		if (temp)
		{
			card.pop();
		}
		else
		{
			int head = card.front();
			card.pop();
			card.push(head);
		}
		temp = !temp;
	}
	printf("%d\n", card.front());
	return 0;
}
