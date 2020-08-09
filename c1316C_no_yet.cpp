#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 1e6 + 10;
int n, m, p, f[_n], g[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < m; i++) cin >> g[i];
  for (int c = 0; c <= n + m - 2; c++) {
    ll t = 0, len = min(c, n);
    for (int j = 0; j <= len; j++) {
      t = (t + (1ll * f[j] * g[c - j]) % p) % p;
    }
    if (t) {
      cout << c << '\n';
      return 0;
    }
  }
  return 0;
}