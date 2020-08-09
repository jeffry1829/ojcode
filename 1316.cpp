#include <bits/stdc++.h>
using namespace std;
const int _n = 4010;
int num[2 * _n], l[_n], r[_n], s[2 * _n];
bool cleared[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  memset(l, -1, sizeof(l));
  for (int i = 0; i < 2 * n; i++) {
    cin >> s[i];
    if (l[s[i]] == -1)
      l[s[i]] = i;
    else
      r[s[i]] = i;
  }
  int now = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (l[s[i]] == i) now++;
    num[i] = now;
    if (r[s[i]] == i) now--;
  }
  int res = n;
  for (int i = 0; i < 2 * n; i++) {
    while (num[i] > 2) {
      int M = -1, J;
      for (int j = 0; j <= i; j++) {
        if (!cleared[s[j]] && j == l[s[j]] && r[s[j]] > M) {
          M = r[s[j]], J = j;
        }
      }
      for (int k = J; k <= r[s[J]]; k++) num[k]--;
      res--, cleared[s[J]] = 1;
    }
  }
  cout << res << '\n';
  return 0;
}