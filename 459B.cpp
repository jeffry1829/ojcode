#include <bits/stdc++.h>
using namespace std;
const int _n = 2e5 + 10;
int n, b[_n], low = 0, high = 0, minn, maxx;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(b, b + n);
  minn = b[0], maxx = b[n - 1];
  for (int i = 0; i < n; i++) {
    if (b[i] != minn) break;
    low++;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (b[i] != maxx) break;
    high++;
  }
  cout << maxx - minn << " " << (minn == maxx ? (1ll * n * (n - 1)) >> 1ll : 1ll * low * high) << '\n';
  return 0;
}