#include <bits/stdc++.h>
using namespace std;
int t, n, p[1010], minf[1010], minb[1010], pp[1010];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      pp[p[i]] = i;
    }
    minf[1] = p[1], minb[n] = p[n];
    for (int i = 2; i <= n; i++) minf[i] = min(minf[i - 1], p[i]);
    for (int i = n - 1; i >= 1; i--) minb[i] = min(minb[i + 1], p[i]);
    bool yes = 0;
    for (int i = 2; i <= n - 1; i++) {
      if (p[i] > minf[i - 1] and p[i] > minb[i + 1]) {
        cout << "YES\n";
        cout << pp[minf[i - 1]] << " " << i << " " << pp[minb[i + 1]] << '\n';
        yes = 1;
        break;
      }
    }
    if (!yes) cout << "NO\n";
  }
  return 0;
}