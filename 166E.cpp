#include <bits/stdc++.h>
using namespace std;
const int _n = 1e7 + 10, _m = 1e9 + 7;
int n, dp[2][2];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  dp[1][0] = 0, dp[1][1] = 3;
  for (int i = 2; i <= n; i++) {
    dp[i & 1][0] = dp[!(i & 1)][1];
    dp[i & 1][1] = 1ll * dp[!(i & 1)][0] * 3 % _m + 1ll * dp[!(i & 1)][1] * 2 % _m, dp[i & 1][1] %= _m;
  }
  cout << dp[n & 1][0];
  return 0;
}