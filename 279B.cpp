#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 1e5 + 10, MAXB = 17;
int n, t, a[_n];
ll pre[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> a[i];
  pre[n - 1] = a[n - 1], pre[n] = 0;
  for (int i = n - 2; i >= 0; i--) pre[i] = pre[i + 1] + a[i];
  int maxx = 0;
  for (int l = 0; l < n; l++) {
    int r = l;
    for (int i = MAXB; i >= 0; i--) {
      if (r + (1 << i) < n and pre[l] - pre[r + (1 << i) + 1] <= t) r = r + (1 << i);
    }
    if (r == l and pre[l] - pre[r + 1] > t) r--;
    maxx = max(maxx, r - l + 1);
  }
  cout << maxx << '\n';
  return 0;
}