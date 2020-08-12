#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
	printf("%d\n-\n", v.size());
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d\n", v[i]);
	}
}

int search_ind_longest(vector<vector<int>> &v)
{
	int ind = 0, sofar = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].size() >= sofar)
		{
			ind = i;
		}
		if (sofar < v[i].size())
		{
			sofar = v[i].size();
		}
	}
	return ind;
}

main(void)
{
	vector<int> v;
	vector<vector<int>> res;
	v.reserve(500000);
	res.reserve(500000);
	int n;
	while (scanf("%d", &n) == 1)
	{
		v.push_back(n);
		vector<int> tmp;
		tmp.push_back(n);
		res.push_back(tmp);
	}
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] < v[j])
			{
				vector<int> tmp = res[i];
				tmp.push_back(v[j]);
				if (res[i].size() + 1 >= res[j].size())
				{
					res[j] = tmp;
				}
			}
		}
	}
	printVec(res[search_ind_longest(res)]);
}