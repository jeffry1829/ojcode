#include <bits/stdc++.h>
using namespace std;
const int _m = 1e9 + 7, _n = 1e5 + 10;
int t, k, a, b, dp[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t >> k;
  for (int i = 0; i <= k - 1; i++) dp[i] = 1;
  for (int i = k; i <= 100000; i++) dp[i] = (1ll * dp[i - 1] + 1ll * dp[i - k]) % _m;
  for (int i = 1; i <= 100000; i++) dp[i] = (1ll * dp[i - 1] + 1ll * dp[i]) % _m;
  while (t--) {
    cin >> a >> b;
    cout << ((1ll * dp[b] - 1ll * dp[a - 1]) % _m >= 0 ? (1ll * dp[b] - 1ll * dp[a - 1]) % _m : (1ll * dp[b] - 1ll * dp[a - 1]) % _m + _m) << '\n';
  }
  return 0;
}