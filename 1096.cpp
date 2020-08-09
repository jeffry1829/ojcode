#include <bits/stdc++.h>
#define INF 9999999
using namespace std;
struct WE {
  int v, w;
};
const int _N = 110;
int N;
vector<WE> G[_N];
int dpt[_N][_N] = {INF};
inline void init_G_dpt() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int w;
      cin >> w;
      if (w == 0) continue;
      G[i].push_back({j, w});
      dpt[i][j] = w;
    }
}
inline void dp() {
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        dpt[i][j] = min(dpt[i][k] + dpt[k][j], dpt[i][j]);
      }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> N && N) {
    for (int i = 0; i < N; i++) G[i].clear();
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        dpt[i][j] = INF;
    init_G_dpt();
    dp();
    int res = INF;
    for (int i = 0; i < N; i++) res = min(res, dpt[i][i]);
    if (res == INF)
      cout << "-1\n";
    else
      cout << res << '\n';
  }
  return 0;
}