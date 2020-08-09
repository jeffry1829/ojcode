#include <bits/stdc++.h>
using namespace std;

int item[51] = {0};
int Tdp[51][51] = {{0}};
int dp(int l, int r) {
  if (Tdp[l][r] != -1) return Tdp[l][r];
  int minn = __INT_MAX__;
  for (int i = 1; i <= r - l; i++)
    minn = min(minn, dp(l, r - i) + dp(r - i + 1, r) + item[l] * item[r - i + 1] * item[r + 1]);
  return Tdp[l][r] = minn;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> item[i];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      Tdp[i][j] = -1;
  for (int l = 0; l < N - 2; l++) {
    Tdp[l][l] = 0;
    Tdp[l][l + 1] = item[l] * item[l + 1] * item[l + 2];
  }
  Tdp[N - 2][N - 2] = 0;

  cout << dp(0, N - 2) << '\n';
  return 0;
}