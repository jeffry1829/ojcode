#include <bits/stdc++.h>
using namespace std;
int t, n, cnt, a[100010];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << "First\n";
      continue;
    }
    cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 1) cnt++;
      if (a[i] != 1) break;
    }
    if (cnt & 1)
      cout << "Second\n";
    else
      cout << "First\n";
  }
  return 0;
}