#include <bits/stdc++.h>
using namespace std;
int k, n, cnt = 0, x, pt = -1;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i == k - 1) pt = x;
    if (x > 0 and x >= pt) cnt++;
    if (x < pt) break;
  }
  cout << cnt << '\n';
  return 0;
}