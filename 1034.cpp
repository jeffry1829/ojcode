#include <bits/stdc++.h>
using namespace std;
const int _N = 20;
int N, r[_N * _N], dis[_N * _N][_N * _N], Q, a, b, c, d;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N * N; i++) cin >> r[i];
  for (int j = 0; j < N * N; j++)
    for (int k = 0; k < N * N; k++) {
      dis[j][k] = ((abs(j - k) == 1 && j / N == k / N) || abs(j - k) == N) ? r[k] : 999999;
    }
  for (int j = 0; j < N * N; j++) dis[j][j] = 0;
  for (int l = 0; l < N * N; l++)
    for (int j = 0; j < N * N; j++)
      for (int k = 0; k < N * N; k++)
        if (dis[j][k] > dis[j][l] + dis[l][k]) dis[j][k] = dis[j][l] + dis[l][k];
  cin >> Q;
  while (Q--) {
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    int lmin = 0x7f7f7f7f;
    for (int i = 0; i < N * N; i++) lmin = min(lmin, dis[a * N + b][i] + dis[i][c * N + d] - r[i] + r[a * N + b]);
    cout << lmin << '\n';
  }
  return 0;
}