#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0, a[200], b[200];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n), sort(b, b + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (abs(a[i] - b[j]) <= 1) {
        sum++, b[j] = 1000;
        break;
      }
    }
  }
  cout << sum << '\n';
  return 0;
}