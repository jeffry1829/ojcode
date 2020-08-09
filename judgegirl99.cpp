#include <bits/stdc++.h>
using namespace std;
struct rc {
  int r, c;
};
const int _N = 11, _M = 257;
int N, M;
rc G[_N][_M * _M];
char names[_N][70];
int column[_N][_M], row[_N][_M], dia[_N][2];
inline void init_G() {
  for (int i = 0; i < N; i++) {
    cin.getline(names[i], 70);
    cin.getline(names[i], 70);
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < M; k++) {
        int t;
        cin >> t;
        G[i][t].r = j;
        G[i][t].c = k;
      }
    }
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  init_G();
  bool end = false, coutNum = false;
  for (int i = 0; i < M * M; i++) {
    int t;
    cin >> t;
    if (end) break;
    for (int l = 0; l < N; l++) {
      int r = G[l][t].r;
      int c = G[l][t].c;
      row[l][r]--;
      column[l][c]--;
      if (r == c) dia[l][0]--;
      if (r + c == M - 1) dia[l][1]--;
      if (row[l][r] == -M || column[l][c] == -M ||
          dia[l][0] == -M || dia[l][1] == -M) {
        end = true;
        if (!coutNum) {
          cout << t;
          coutNum = true;
        }
        cout << " " << names[l];
      }
    }
  }
  cout << '\n';
  return 0;
}