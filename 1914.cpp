#include <bits/stdc++.h>
using namespace std;
const int _N = 210, _M = 210;
int T, N, M, S[_N], dpT[_N][_N];

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> S][i];
    for (int i = 0; i < N; i++) dpT[i][i] = 1;
    for (int len = 2; len <= N; len++) {
      for (int st = 0; st <= N - len; st++) {
        dpT[st][st + len - 1] = 1 << 25;
        for (int i = st; i <= st + len - 2; i++)
          dpT[st][st + len - 1] = min(dpT[st][st + len - 1], dpT[st][i] + dpT[i + 1][st + len - 1]);
        if (S[st] == S[st + len - 1]) dpT[st][st + len - 1]--;
      }
    }
    cout << dpT[0][N - 1] << '\n';
  }
  return 0;
}