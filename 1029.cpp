#include <bits/stdc++.h>
using namespace std;
const int _n = 1e3 + 10;
int n, s[_n], dp[_n][_n], sum = 0;
int f(int st, int ed, int lsum) {
  if (dp[st][ed]) return dp[st][ed];
  if (ed - st < 1) return 0x7f7f7f7f;
  if (ed - st == 1) return dp[st][ed] = s[st];
  if (ed - st == 2) return dp[st][ed] = max(s[st], s[st + 1]);
  return dp[st][ed] = max(lsum - f(st, ed - 1, lsum - s[ed - 1]), lsum - f(st + 1, ed, lsum - s[st]));
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  f(0, n, sum);
  cout << f(0, n, sum) << ' ' << sum - f(0, n, sum) << '\n';
  return 0;
}