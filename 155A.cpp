#include <bits/stdc++.h>
using namespace std;
int n, x, cnt = 0, minn = 0x7f7f7f7f, maxx = -0x7f7f7f7f;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> x;
  maxx = minn = x;
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (x < minn) cnt++, minn = x;
    if (x > maxx) cnt++, maxx = x;
  }
  cout << cnt << '\n';
  return 0;
}