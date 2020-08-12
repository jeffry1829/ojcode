#include <bits/stdc++.h>
using namespace std;
deque<int> A, station, fix;
int indexof(deque<int> d, int item)
{
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i] == item)
		{
			return i;
		}
	}
	return -1;
}
int main(void)
{
	int N, M, want[10];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &want[i]);
	for (int i = 1; i <= N; i++)
		A.push_back(i);
	for (int i = 1; i <= N; i++)
	{ //i_th car
		int cur = want[i - 1];
		int index;
		if ((index = indexof(A, cur)) != -1)
		{
			for (int j = 0; j <= index - 1; j++)
			{
				station.push_front(A.front());
				A.pop_front();
			}
			A.pop_front();
		}
		else if ((index = indexof(station, cur)) != -1)
		{
			for (int j = 0; j <= index - 1; j++)
			{
				fix.push_front(station.front());
				station.pop_front();
			}
			if (fix.size() > M)
			{
				puts("no");
				return 0;
			}
			station.pop_front();
			for (int j = 0; j < fix.size(); j++)
			{
				station.push_front(fix.front());
				fix.pop_front();
			}
		}
	}
	puts("yes");
	return 0;
}
