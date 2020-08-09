#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int t, n, x, a[_n], dp[2][2];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] % x == 0)
      dp[0][0] = dp[0][1] = -0x7f7f7f7f;
    else
      dp[0][0] = dp[0][1] = a[0];
    for (int i = 1; i < n; i++) {
      dp[i & 1][0] = max(dp[!(i & 1)][0],
                         ((dp[!(i & 1)][1] + a[i]) % x == 0 ? -0x7f7f7f7f : dp[!(i & 1)][1] + a[i]));
      if (dp[!(i & 1)][1] + a[i] >= 0 and (dp[!(i & 1)][1] + a[i]) % x != 0)
        dp[i&1][1]=dp
    }
  }
  return 0;
}