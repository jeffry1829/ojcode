#include <bits/stdc++.h>
using namespace std;
int n, res = 1, t = 1, _prev, x;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> _prev;
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (_prev <= x)
      t++;
    else
      t = 1;
    res = max(res, t);
    _prev = x;
  }
  cout << res << '\n';
  return 0;
}