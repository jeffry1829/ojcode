#include <bits/stdc++.h>
using namespace std;

int n, k, t, a[80], b[80];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    int sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (int i = k; i < n; i++) sum += a[i];
    for (int i = k; i < 2 * k; i++) a[i] = b[n - k - k + i];
    sort(a, a + 2 * k, greater<int>());
    for (int i = 0; i < k; i++) sum += a[i];
    cout << sum << '\n';
  }
  return 0;
}