#include <bits/stdc++.h>
using namespace std;
int n, x, cnt = 0, po = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > 0) po += x;
    if (x < 0) {
      if (po == 0)
        cnt++;
      else
        po += x;
    }
  }
  cout << cnt << '\n';
  return 0;
}