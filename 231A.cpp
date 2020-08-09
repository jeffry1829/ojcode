#include <bits/stdc++.h>
using namespace std;
int r[1010], n, x, y, z;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    if (x) r[i]++;
    if (y) r[i]++;
    if (z) r[i]++;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (r[i] >= 2) cnt++;
  }
  cout << cnt << '\n';
  return 0;
}