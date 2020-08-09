#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int n, a[_n], aa[_n], m, q;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  a[n] = 0x7f7f7f7f;
  aa[0] = a[0];
  for (int i = 1; i < n; i++) aa[i] = aa[i - 1] + a[i];
  aa[n] = aa[n - 1] + a[n];
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> q;
    int ans = upper_bound(aa, aa + n, q) - aa;
    //cout << "ans:" << ans << '\n';
    cout << (aa[ans] - a[ans] < q ? ans + 1 : ans) << '\n';
  }
  return 0;
}