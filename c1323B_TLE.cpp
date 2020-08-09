#include <bits/stdc++.h>
using namespace std;
const int _n = 4e4 + 10;
int n, m, k, dp[_n];
int x[_n], y[_n], cnt = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) cin >> y[i];
  for (int i = 0; i < m; i++) {
    memset(dp, 0, sizeof(int) * n);
    for (int j = i; j < m; j++) {
      int sum = 0, line = 0;
      for (int l = 0; l < n; l++) {
        if (y[j] * x[l] > 0 and dp[l] >= 0) {
          dp[l]++;
          sum += dp[l];
          line++;
        } else {
          if (sum >= k and (k % (j - i + 1)) == 0) {
            cnt += line - (k / (j - i + 1)) + 1;
          }
          sum = 0, line = 0;
          dp[l] = -0x7f7f7f7f;
          continue;
        }
      }
      if (sum >= k and (k % (j - i + 1)) == 0) {
        cnt += line - (k / (j - i + 1)) + 1;
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}