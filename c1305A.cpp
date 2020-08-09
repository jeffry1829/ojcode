#include <bits/stdc++.h>
using namespace std;
int t, n, a[110], b[110];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n), sort(b, b + n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << '\n';
  }
  return 0;
}