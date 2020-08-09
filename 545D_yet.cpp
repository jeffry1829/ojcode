#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int n, t[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i];
  sort(t, t + n);
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] >= sum) cnt++;
    sum += t[i];
  }
  cout << cnt << '\n';
  return 0;
}