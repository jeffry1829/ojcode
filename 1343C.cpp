#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 2e5 + 10;
int t, n, a[_n];
ll sum = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxx = a[0], i = 1;
    sum = 0;
    while (i <= n) {
      while (i < n and (a[i - 1] > 0) == (a[i] > 0)) {
        maxx = max(maxx, a[i]);
        i++;
      }
      sum += maxx;
      maxx = a[i];
      i++;
    }
    cout << sum << '\n';
  }
  return 0;
}