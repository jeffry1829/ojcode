#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int t, n, pre, suf;
char s[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    pre = suf = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') break;
      pre++;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') break;
      suf++;
    }
    for (int i = 0; i < pre; i++) cout << '0';
    if (pre + suf != n) cout << '0';
    for (int i = 0; i < suf; i++) cout << '1';
    cout << '\n';
  }
  return 0;
}