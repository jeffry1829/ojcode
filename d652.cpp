#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int Tdp[500][500] = {{0}};
int element[500];
int dp(int l, int r) {
  if (Tdp[l][r] != 0) return Tdp[l][r];
  return Tdp[l][r] = min(dp(l + 1, r) + element[l] * element[l + 1] * element[r],
                         dp(l, r - 1) + element[l] * element[r - 1] * element[r]);
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> element[i];
  for (int l = 0; l < N - 2; l++)
    Tdp[l][l + 2] = element[l] * element[l + 1] * element[l + 2];
  cout << dp(0, N - 1) << '\n';
  return 0;
}