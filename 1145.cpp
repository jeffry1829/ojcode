#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
vector<char> opts;
struct P {
  int M, m;
} dp[60][60];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string str;
  cin >> str;
  nums.push_back(0);
  for (int i = 0; i < str.length(); i++) {
    if ('0' <= str[i] && str[i] <= '9') {
      nums.back() = nums.back() * 10 + str[i] - '0';
    } else {
      opts.push_back(str[i]);
      nums.push_back(0);
    }
  }
  int cnt = nums.size();
  fill(dp[0], dp[cnt - 1] + cnt, (P){-0x7f7f7f7f, 0x7f7f7f7f});
  for (int i = 0; i < cnt; i++) dp[i][i] = {nums[i], nums[i]};
  for (int j = 1; j < cnt; j++) {
    for (int i = j - 1; i >= 0; i--) {
      for (int k = i; k < j; k++) {
        if (opts[k] == '+') {
          dp[i][j].M = max(dp[i][j].M, dp[i][k].M + dp[k + 1][j].M);
          dp[i][j].m = min(dp[i][j].m, dp[i][k].m + dp[k + 1][j].m);
        } else if (opts[k] == '-') {
          dp[i][j].M = max(dp[i][j].M, dp[i][k].M - dp[k + 1][j].m);
          dp[i][j].m = min(dp[i][j].m, dp[i][k].m - dp[k + 1][j].M);
        } else if (opts[k] == '*') {
          dp[i][j].M = max(dp[i][j].M, dp[i][k].M * dp[k + 1][j].M);
          dp[i][j].M = max(dp[i][j].M, dp[i][k].M * dp[k + 1][j].m);
          dp[i][j].M = max(dp[i][j].M, dp[i][k].m * dp[k + 1][j].M);
          dp[i][j].M = max(dp[i][j].M, dp[i][k].m * dp[k + 1][j].m);

          dp[i][j].m = min(dp[i][j].m, dp[i][k].M * dp[k + 1][j].M);
          dp[i][j].m = min(dp[i][j].m, dp[i][k].M * dp[k + 1][j].m);
          dp[i][j].m = min(dp[i][j].m, dp[i][k].m * dp[k + 1][j].M);
          dp[i][j].m = min(dp[i][j].m, dp[i][k].m * dp[k + 1][j].m);
        }
      }
    }
  }
  cout << dp[0][cnt - 1].M << '\n';
  return 0;
}