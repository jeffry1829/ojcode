#include <bits/stdc++.h>
using namespace std;
int n, x, host[110], cnt[110], res = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> host[i] >> x;
    cnt[x]++;
  }
  for (int i = 1; i <= n; i++) {
    res += cnt[host[i]];
  }
  cout << res << '\n';
  return 0;
}