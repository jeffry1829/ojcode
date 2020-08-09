#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int n, fell[_n], cnt = 1;
pair<int, int> a[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  fell[0] = -1, a[n] = {INT_MAX, 1};
  for (int i = 1; i < n; i++) {
    if (1ll * a[i].first - 1ll * a[i].second >
        max(1ll * a[i - 1].first, 1ll * a[i - 1].first + 1ll * fell[i - 1] * a[i - 1].second)) {
      fell[i] = -1, cnt++;
    } else {
      if (a[i].first + a[i].second < a[i + 1].first)
        fell[i] = 1, cnt++;
      else
        fell[i] = 0;
    }
  }
  cout << cnt << '\n';
  return 0;
}