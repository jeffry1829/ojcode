#include <bits/stdc++.h>
using namespace std;
int t, n, m;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int can = 0, me, x;
    cin >> me;
    for (int i = 1; i < n; i++) {
      cin >> x;
      can += x;
    }
    if (me + can > m)
      cout << m << '\n';
    else
      cout << me + can << '\n';
  }
  return 0;
}