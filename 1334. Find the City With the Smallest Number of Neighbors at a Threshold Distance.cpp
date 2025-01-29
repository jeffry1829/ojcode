typedef long long ll;
class Solution {
 public:
  const inline static int _n = 110;
  ll dp[_n][_n];
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = 1e18;
      }
    }
    for (auto& e : edges) {
      dp[e[0]][e[1]] = dp[e[1]][e[0]] = e[2];
    }
    for (int k = 0; k < n; k++) {      // mid
      for (int i = 0; i < n; i++) {    // from
        for (int j = 0; j < n; j++) {  // to
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    int minncity = 0;
    int minn = 1e9;
    for (int i = 0; i < n; i++) {
      int ncity = 0;
      for (int j = 0; j < n; j++) {
        if (j != i and distanceThreshold >= dp[i][j]) {
          ncity++;
        }
      }
      if (ncity <= minn) {
        minn = ncity;
        minncity = i;
      }
    }
    return minncity;
  }
};