#include <bits/stdc++.h>
using namespace std;
const int _m = 1e5 + 10;
int n, m, a[_m], _prev, cnt = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i];
  _prev = a[0];
  for (int i = 1; i < m; i++) {
    if (_prev > a[i]) cnt++;
    _prev = a[i];
  }
  cout << 1ll * n * cnt + _prev - 1 << '\n';
  return 0;
}