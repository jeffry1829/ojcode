#include <bits/stdc++.h>
using namespace std;
int n, k, t = 0, cnt = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    if (t + i * 5 <= 240 - k)
      t += i * 5, cnt++;
    else
      break;
  }
  cout << cnt << '\n';
  return 0;
}