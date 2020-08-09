#include <bits/stdc++.h>
using namespace std;
const int _n = 2e5 + 10;
int t, n, k, a[_n], pre[_n];
bool peak[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(peak, 0, sizeof peak);
    for (int i = 1; i <= n; i++) cin >> a[i];
    peak[1] = 0, peak[n] = 0;
    for (int i = 2; i <= n - 1; i++)
      if (a[i - 1] < a[i] and a[i] > a[i + 1]) peak[i] = 1;
    pre[0] = 0, pre[1] = 0;
    for (int i = 2; i <= n; i++) pre[i] = pre[i - 1] + peak[i];
    int maxx = -1, left = 0;
    for (int i = 1; i <= n - k + 1; i++) {
      if (maxx < pre[i + k - 1] - pre[i - 1] - peak[i] - peak[i + k - 1]) {
        maxx = pre[i + k - 1] - pre[i - 1] - peak[i] - peak[i + k - 1];
        left = i;
      }
    }
    cout << maxx + 1 << " " << left << '\n';
  }
  return 0;
}