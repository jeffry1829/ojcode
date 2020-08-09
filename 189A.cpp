#include <bits/stdc++.h>
using namespace std;
const int _n = 4010;
int dpT[_n], n, a[3];
int dp(int l) {
  if (l < 0) return -0x7f7f7f7f;
  if (!l) return 0;
  if (dpT[l]) return dpT[l];
  int maxx = -0x7f7f7f7f;
  for (int i = 0; i < 3; i++) {
    maxx = max(maxx, dp(l - a[i]) + 1);
  }
  return dpT[l] = maxx;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> a[0] >> a[1] >> a[2];
  int t = min(a[0], min(a[1], a[2]));
  for (int i = 1; i < t; i++) {
    dpT[i] = -0x7f7f7f7f;
  }
  dpT[t] = 1;
  cout << dp(n) << '\n';
  return 0;
}