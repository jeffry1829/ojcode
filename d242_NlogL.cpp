#include <bits/stdc++.h>
using namespace std;

main(void)
{
    vector<int> s;
    int n;
    while (scanf("%d", &n) == 1)
    {
        s.push_back(n);
    }

    vector<int> v;
    vector<int> pos;
    v.push_back(s[0]);
    pos.push_back(0);
    for (int i = 1; i < s.size(); i++)
    {
        int n = s[i];
        if (v.back() < n)
        {
            v.push_back(n);
            pos.push_back(v.size() - 1);
        }
        else
        {
            *lower_bound(v.begin(), v.end(), n) = n;
            pos.push_back(lower_bound(v.begin(), v.end(), n) - v.begin()); //
        }
    }
    printf("%d\n-\n", v.size());
    deque<int> res;
    int pos_now = v.size() - 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (pos[i] == pos_now)
        {
            pos_now--;
            res.push_front(s[i]);
        }
        if (pos_now == -1)
            break;
    }
    while (!res.empty())
    {
        printf("%d\n", res.front());
        res.pop_front();
    }
}