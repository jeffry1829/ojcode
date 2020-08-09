#include <bits/stdc++.h>
using namespace std;
int n, p, q, res = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p >> q;
    if (q - p >= 2) res++;
  }
  cout << res << '\n';
  return 0;
}