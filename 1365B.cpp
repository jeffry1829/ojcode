#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int t, n;
pair<int, int> s[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i].first;
    for (int i = 0; i < n; i++) cin >> s[i].second;
    int sgn = s[0].second, both = 0;
    for (int i = 1; i < n; i++) {
      if (s[i].second != sgn) {
        both = 1;
        break;
      }
    }
    if (both) {
      cout << "Yes\n";
    } else {
      int is = 1, tmp = s[0].first;
      for (int i = 1; i < n; i++) {
        if (s[i].first < tmp) {
          is = 0;
          break;
        }
        tmp = s[i].first;
      }
      cout << (is ? "Yes\n" : "No\n");
    }
  }
  return 0;
}