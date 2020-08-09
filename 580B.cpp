#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 1e5 + 10;
int n, d, s, m;
ll maxx = -1, pre[_n];
pair<int, int> a[_n];
bool cmp(int val, pair<int, int> a) { return a.first > val; }
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> s >> m;
    a[i] = {s, m};
  }
  sort(a + 1, a + n + 1), pre[1] = a[1].second, pre[0] = 0;
  for (int i = 2; i <= n; i++) pre[i] = pre[i - 1] + a[i].second;
  for (int i = n; i >= 1; i--) {
    int l = upper_bound(a + 1, a + 1 + i, a[i].first - d, cmp) - a;
    maxx = max(maxx, pre[i] - pre[l - 1]);
  }
  cout << maxx << '\n';
  return 0;
}