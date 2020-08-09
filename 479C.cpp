#include <bits/stdc++.h>
using namespace std;
const int _n = 5010;
int n, a, b;
pair<int, int> s[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    s[i] = {a, b};
  }
  sort(s, s + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i].second >= ans)
      ans = s[i].second;
    else
      ans = s[i].first;
  }
  cout << ans << '\n';
  return 0;
}