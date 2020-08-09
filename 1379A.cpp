#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[60];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n - 6; i++) {
      if (s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'a' and s[i + 3] == 'c' and s[i + 4] == 'a' and s[i + 5] == 'b' and s[i + 6] == 'a') cnt++;
    }
    if (cnt >= 2) {
      cout << "No\n";
      continue;
    }
    if (cnt == 1) {
      cout << "Yes\n";
      for (int i = 0; i < n; i++) {
        if (s[i] == '?')
          cout << "z";
        else
          cout << s[i];
      }
      cout << '\n';
      continue;
    }
    cnt = 0;
    int ind = 0;
    int last = 0;
    for (int i = 0; i < n - 6; i++) {
      if ((s[i] == 'a' or s[i] == '?') and (s[i + 1] == 'b' or s[i + 1] == '?') and (s[i + 2] == 'a' or s[i + 2] == '?') and (s[i + 3] == 'c' or s[i + 3] == '?') and (s[i + 4] == 'a' or s[i + 4] == '?') and (s[i + 5] == 'b' or s[i + 5] == '?') and (s[i + 6] == 'a' or s[i + 6] == '?')) {
        if (!cnt) {
          cnt++, ind = i;
        } else {
          if (last + 4 == i and (s[last + 4] == '?' or s[last + 5] == '?' or s[last + 6] == '?') and
              s[i + 3] == 'c' and s[i + 4] == 'a' and s[i + 5] == 'b' and s[i + 6] == 'a') cnt--;
        }
        last = i;
      }
    }
    if (cnt) {
      cout << "Yes\n";
      for (int i = 0; i < n; i++) {
        if (i != ind) {
          if (s[i] == '?')
            cout << "z";
          else
            cout << s[i];
        } else {
          cout << "abacaba";
          i += 6;
        }
      }
      cout << '\n';
    } else {
      cout << "No\n";
    }
  }
  return 0;
}