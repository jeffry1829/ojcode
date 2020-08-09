#include <bits/stdc++.h>
#define prev akoidhgoisjg
using namespace std;
char n[110];
bool dp[110][8];
int len, prev[110][8];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  len = strlen(n);
  memset(prev, -1, sizeof prev);
  dp[0][(n[0] - '0') % 8] = 1;
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < 8; j++)
      if (dp[i - 1][j])
        dp[i][(j * 10 + n[i] - '0') % 8] = 1, prev[i][(j * 10 + n[i] - '0') % 8] = j;
    for (int j = 0; j < 8; j++)
      if (dp[i - 1][j]) dp[i][j] = 1, prev[i][j] = j;
    dp[i][(n[i] - '0') % 8] = 1, prev[i][(n[i] - '0') % 8] = -2;
  }
  cout << (dp[len - 1][0] ? "YES\n" : "NO\n");
  if (dp[len - 1][0]) {
    vector<char> ans;
    int i = len - 1, j = 0;
    if (prev[i][j] != j) ans.push_back(n[i]);
    j = prev[i][j], i--;
    while (i >= 0 and dp[i][j] and j != -2) {
      if (prev[i][j] != j) ans.push_back(n[i]);
      j = prev[i][j], i--;
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    cout << '\n';
  }

  return 0;
}