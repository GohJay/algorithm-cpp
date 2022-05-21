#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    int begin, end;
    std::vector<std::pair<int, int>> schedule;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &begin, &end);
        schedule.push_back(std::make_pair(end, begin));
    }
    std::sort(schedule.begin(), schedule.end());
    int time = schedule[0].first;
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        if (time <= schedule[i].second)
        {
            time = schedule[i].first;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}