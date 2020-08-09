#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int n, s[5], x, t;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s[x]++;
  }
  t = min(s[1], s[3]);
  s[1] -= t, s[3] -= t, s[4] += t;
  t = s[1] / 2;
  s[2] += t, s[1] -= (t << 1);
  t = s[2] / 2;
  s[4] += t, s[2] -= (t << 1);
  if (s[1] > 0 and s[2] > 0) s[1] = 0;
  cout << s[4] + s[3] + s[2] + s[1] << '\n';
  return 0;
}