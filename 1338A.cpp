#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int t, n, a[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxx = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        maxx = max(maxx, 32 - __builtin_clz(a[i] - a[i + 1]));
        a[i + 1] = a[i];
      }
    }
    cout << maxx << '\n';
  }
  return 0;
}