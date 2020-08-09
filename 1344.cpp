#include <bits/stdc++.h>
using namespace std;
const int _N = 1e5 + 10;
int N, dpT[2][4][4][4][4], S[_N];
inline int val(int a, int b, int c) {
  if (a == 0) a = c;
  if (b == 0) b = c;
  int res = 3;
  if (a == b) res--;
  if (a == c)
    res--;
  else if (b == c)
    res--;
  return res;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    char c;
    cin >> c;
    if (c == 'M') S[i] = 1;
    if (c == 'F') S[i] = 2;
    if (c == 'B') S[i] = 3;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        for (int l = 0; l < 4; l++)
          for (int m = 0; m < 4; m++)
            dpT[i][j][k][l][m] = INT_MIN;
  dpT[0][0][S[0]][0][0] = 1;
  dpT[0][0][0][0][S[0]] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 4; j++)
      for (int l = 0; l < 4; l++)
        for (int m = 0; m < 4; m++) {
          int maxx = INT_MIN;
          for (int x = 0; x < 4; x++) maxx = max(maxx, dpT[0][x][j][l][m] + val(x, j, S[i]));
          dpT[1][j][S[i]][l][m] = max(maxx, dpT[1][j][S[i]][l][m]);
        }
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        for (int l = 0; l < 4; l++) {
          int maxx = INT_MIN;
          for (int x = 0; x < 4; x++) maxx = max(maxx, dpT[0][j][k][x][l] + val(x, l, S[i]));
          dpT[1][j][k][l][S[i]] = max(maxx, dpT[1][j][k][l][S[i]]);
        }
    for (int J = 0; J < 4; J++)
      for (int K = 0; K < 4; K++)
        for (int L = 0; L < 4; L++)
          for (int M = 0; M < 4; M++) {
            dpT[0][J][K][L][M] = dpT[1][J][K][L][M];
            dpT[1][J][K][L][M] = INT_MIN;
          }
  }
  int maxx = INT_MIN;
  for (int j = 0; j < 4; j++)
    for (int k = 0; k < 4; k++)
      for (int l = 0; l < 4; l++)
        for (int m = 0; m < 4; m++) {
          maxx = max(maxx, dpT[0][j][k][l][m]);
          //cout << "dpT[" << N - 1 << "][" << j << "][" << k << "][" << l << "][" << m << "]" << dpT[N - 1][j][k][l][m] << endl;
        }
  cout << maxx << '\n';
  return 0;
}