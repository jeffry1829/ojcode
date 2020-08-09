#include <bits/stdc++.h>
using namespace std;
struct P {
  int len, st;
  bool operator<(const P& rhs) const {
    if (len != rhs.len) return len < rhs.len;
    return st > rhs.st;
  }
};
const int _n = 2e5 + 10;
int t, n, ans[_n];
priority_queue<P> pq;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    while (!pq.empty()) pq.pop();
    pq.push({n, 1});
    for (int i = 1; i <= n; i++) {
      P now = pq.top();
      pq.pop();
      int l = now.st, r = l + now.len - 1, mid = (l + r) >> 1;
      ans[mid] = i;
      pq.push({mid - l, l}), pq.push({r - mid, mid + 1});
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}