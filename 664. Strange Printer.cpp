class Solution {
 public:
  int dp[110][36];
  int strangePrinter(string s) {
    for (int i = 0; i < 26; i++) {
      dp[0][i] = 2;
    }
    dp[0][s[0] - 'a'] = 1;

    for (int i = 1; i < s.length(); i++) {
      int lowest = 1e9;
      for (int c = 0; c < 26; c++) {
        lowest = min(lowest, dp[i - 1][c]);
      }
      for (int c = 0; c < 26; c++) {
        if (s[i] - 'a' == c) {
          dp[i][c] = min(dp[i - 1][c], lowest + 1);
        } else {
          dp[i][c] = min(dp[i - 1][c] + 1, lowest + 2);
        }
      }
    }
    return dp[s.length() - 1][s[s.length() - 1] - 'a'];
  }
};