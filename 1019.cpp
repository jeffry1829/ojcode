#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _N = 1010;
int T, N, d[_N];
ll t, o;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> d[i];
    t = 0, o = abs(d[1] * 1ll - d[0] * 1ll);
    for (int i = 2; i < N; i++) {
      ll tmp = o;
      o = min(t + abs(d[i] * 1ll - d[i - 2] * 1ll), o + abs(d[i] * 1ll - d[i - 1] * 1ll));
      t = tmp;
    }
    cout << o << '\n';
  }
  return 0;
}