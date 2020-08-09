#include <bits/stdc++.h>
using namespace std;
int k, l, m, n, d;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> k >> l >> m >> n >> d;
  int res = 0;
  for (int i = 1; i <= d; i++) {
    if (!(i % k) or !(i % l) or !(i % m) or !(i % n)) res++;
  }
  cout << res << '\n';
  return 0;
}