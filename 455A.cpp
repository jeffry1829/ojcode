#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 1e5 + 10;
ll n, b[_n], x, dp[_n], l = 0x7f7f7f7f, r = -0x7f7f7f7f;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    b[x]++;
    l = min(l, x), r = max(r, x);
  }
  dp[1] = b[1];
  if (l == 1) l = 2;
  for (int i = l; i <= r; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + i * b[i]);
  }
  cout << dp[r] << '\n';
  return 0;
}