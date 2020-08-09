#include <bits/stdc++.h>
using namespace std;
const int _MN = 210;
int M, N, ans = -1, mp[_MN][_MN], com[_MN];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> M >> N;
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) {
      cin >> mp[j][i];
      if (!mp[j][i]) mp[j][i] = -9999;
    }
  for (int i = 0; i < N; i++) {
    memset(com, 0, sizeof(com));
    for (int j = i; j < N; j++) {
      int tmp = 0;
      for (int k = 0; k < M; k++) {
        com[k] += mp[j][k];
        if (tmp >= 0)
          tmp += com[k];
        else
          tmp = com[k];
        ans = max(ans, tmp);
      }
    }
  }
  cout << max(ans, 0) << '\n';
  return 0;
}