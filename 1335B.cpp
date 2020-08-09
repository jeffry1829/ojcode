#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;
char s[2010];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    for (int i = 0; i < b; i++) s[i] = 'a' + i;
    for (int i = 0; i < a - b; i++) s[b + i] = 'a' + b - 1;
    for (int i = a; i < n; i++) {
      if (s[i - a] == s[i - a + 1])
        s[i] = s[i - 1];
      else
        s[i] = 'a' + ((s[i - 1] - 'a' + 1) % 26);
    }
    s[n] = '\0';
    cout << s << '\n';
  }
  return 0;
}