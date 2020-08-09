#include <bits/stdc++.h>
using namespace std;
int t, n, k, sq;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    sq = sqrt(n);
    int minn = 0x7f7f7f7f;
    for (int i = 1; i <= sq; i++) {
      if (n % i == 0 and i <= k) {
        minn = min(minn, n / i);
      }
    }
  }
  return 0;
}