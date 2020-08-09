#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int n, m, l, r, pre[_n];
char s[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  n = strlen(s);
  pre[0] = (s[0] == s[1] ? 1 : 0);
  for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + (s[i] == s[i + 1] ? 1 : 0);
  cin >> m;
  while (m--) {
    cin >> l >> r;
    l--, r--;
    int ans = pre[r - 1] - (l == 0 ? 0 : pre[l - 1]);
    cout << ans << '\n';
  }
  return 0;
}