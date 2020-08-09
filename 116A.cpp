#include <bits/stdc++.h>
using namespace std;
int n, in = 0, res = 0, x, y;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    in -= x, in += y;
    res = max(in, res);
  }
  cout << res << '\n';
  return 0;
}