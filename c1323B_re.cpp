#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int _n = 4e4 + 10;
int n, m, k;
bool x[_n], y[_n];
ll cnt = 0, cntx[_n], cnty[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) cin >> y[i];
  int sum = y[0], _prev = y[0];
  for (int i = 1; i < m + 1; i++) {
    if (y[i] != _prev and sum > 0 and y[i] == 0) {
      for (int j = 1; j <= sum; j++) cnty[j] += sum - j + 1;
      _prev = y[i], sum = 0;
    } else {
      _prev = y[i], sum += y[i];
    }
  }
  sum = x[0], _prev = x[0];
  for (int i = 1; i < n + 1; i++) {
    if (x[i] != _prev and sum > 0 and x[i] == 0) {
      for (int j = 1; j <= sum; j++) cntx[j] += sum - j + 1;
      _prev = x[i], sum = 0;
    } else {
      _prev = x[i], sum += x[i];
    }
  }
  int len = min(k, m);
  for (int i = 1; i <= len; i++) {
    if (k % i == 0 and k / i <= n) {
      cnt += cnty[i] * cntx[k / i];
    }
  }
  cout << cnt << '\n';
  return 0;
}