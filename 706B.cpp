#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int n, x[_n], q, m[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> m[i];
  sort(x, x + n);
  for (int i = 0; i < q; i++) cout << upper_bound(x, x + n, m[i]) - x << '\n';
  return 0;
}