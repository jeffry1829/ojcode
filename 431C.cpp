#include <bits/stdc++.h>
using namespace std;
const int _m = 1e9 + 7;
int n, k, d, dp[110][2], tmp;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> d;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    tmp = min(d - 1, i);
    for (int j = 1; j <= tmp; j++) dp[i][0] += dp[i - j][0], dp[i][0] %= _m;
    tmp = min(i, k);
    for (int j = 1; j <= tmp; j++) dp[i][1] += dp[i - j][1], dp[i][1] %= _m;
    for (int j = d; j <= tmp; j++) dp[i][1] += dp[i - j][0], dp[i][1] %= _m;
  }
  cout << dp[n][1] << '\n';
  return 0;
}