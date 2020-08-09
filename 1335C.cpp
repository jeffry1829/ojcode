#include <bits/stdc++.h>
using namespace std;
const int _n = 2e5 + 10;
int t, n, s[_n], dis = 0, same = 0, tmp;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    memset(s, 0, sizeof(s));
    dis = 0, same = 0;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      if (!s[tmp]) dis++;
      s[tmp]++;
    }
    for (int i = 0; i < _n; i++) same = max(same, s[i]);
    cout << max(min(same - 1, dis), min(same, dis - 1)) << '\n';
  }
  return 0;
}