#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a, n, y;
inline int qpow(int a, int n, int y) {
  if (a == n && a == 0) return 1e9 + 7;
  int r = 1;
  while (n) {
    if (n & 1) r = (1ll * r * a) % y;
    n >>= 1;
    a = (1ll * a * a) % y;
  }
  return r % y;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> a >> n >> y && a + n + y) {
    int res = 0;
    for (int i = 0; i < y; i++) {
      if (qpow(i, n, y) == a) res++;
    }
    cout << res << '\n';
  }
  return 0;
}