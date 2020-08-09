#include <bits/stdc++.h>
using namespace std;
const int _NM = 210;
int N, M, T;
struct P {
  int ok, no;
} dp[_NM];
int mp[_NM][_NM];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> mp[i][j];
    int ans = -1;
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        memset(dp, 0, sizeof(dp[0][0]) * _NM);
      }
    }
  }
  return 0;
}