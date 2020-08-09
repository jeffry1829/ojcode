#include <bits/stdc++.h>
using namespace std;
struct E {
  int f, t, c;
  bool operator<(const E& b) const { return c < b.c; }
};
const int _n = 1e4 + 10, _m = 1e6 + 10;
int n, m, R[_n], s_c[_n];
E edges[_m];
inline int dsf(int e) {
  if (R[e] == e) return R[e];
  return R[e] = dsf(R[e]);
}
inline void dsu(int e1, int e2) {
  if (s_c[e1] < s_c[e2]) swap(e1, e2);
  R[dsf(e2)] = dsf(e1);
  s_c[dsf(e1)] += s_c[dsf(e2)];
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> n >> m && n && m) {
    for (int i = 0; i < n; i++) {
      R[i] = i;
      s_c[i] = 1;
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      edges[i] = {a - 1, b - 1, c};
    }
    sort(edges, edges + m);
    int res = 0, u_c = 0;
    for (int i = 0; i < m; i++) {
      if (dsf(edges[i].t) != dsf(edges[i].f)) {
        dsu(edges[i].t, edges[i].f);
        u_c++;
        res += edges[i].c;
      }
      if (u_c == n - 1) break;
    }
    if (u_c < n - 1) res = -1;
    cout << res << '\n';
  }
  return 0;
}