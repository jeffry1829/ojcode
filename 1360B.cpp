#include <bits/stdc++.h>
using namespace std;
int t, n, s[60];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    int minn = 0x7f7f7f7f;
    for (int i = 1; i < n; i++) minn = min(minn, s[i] - s[i - 1]);
    cout << minn << '\n';
  }
  return 0;
}