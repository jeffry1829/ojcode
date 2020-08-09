#include <bits/stdc++.h>
using namespace std;
const int _K = 6, _N = 52;
int sc[_N][3][2 * _K + 1], K, N, S;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> K >> N;
  for (int i = 0; i < N; i++) {
    cin >> S;
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 2 * K + 1; k++) cin >> sc[S - 1][j][k];
  }
  for (int i = N - 1; i >= 1; i--) {
    for (int j = i - 1; j >= 0; j--) {
      for (int k = 0; k < K + 1; k++) {
        if (sc[i][0][k] <= sc[j][0][K + k]) goto A;
      }
    }
    cout << i + 1 << ' ';
    break;
  A:
    if (i == 1) cout << "1 ";
  }
  for (int i = N - 1; i >= 1; i--) {
    for (int j = i - 1; j >= 0; j--) {
      for (int k = 0; k < K + 1; k++) {
        if (sc[i][1][k] <= sc[j][2][K + k]) goto B;
      }
    }
    cout << i + 1 << '\n';
    break;
  B:
    if (i == 1) cout << "1\n";
  }
  return 0;
}