#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    int coins[1001];
    int sum = 0;
    for (int i = 0; i < m; i++) {
      cin >> coins[i];
      sum += coins[i];
    }
    int halfsum = sum / 2;
    int dp[m + 1][halfsum + 1];
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int i = 0; i <= halfsum; i++) dp[0][i] = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= halfsum; j++) {
        int jj = j - coins[i - 1];
        if (jj < 0)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][jj] + coins[i - 1]);
      }
    cout << sum - 2 * dp[m][halfsum] << '\n';
  }
  return 0;
}