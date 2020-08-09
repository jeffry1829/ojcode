#include <bits/stdc++.h>
using namespace std;
struct res {
  int l, r;
};  //min:Lamppost,max:Road
const int _N = 1e3 + 10;
vector<int> G[_N];
bool vis[_N];
inline void _f(int v, res &r1, res &r2) {  //light v,dont
  vis[v] = 1;
  if (G[v].size() == 1u && vis[G[v][0]]) {
    r1 = {1, 0}, r2 = {0, 0};
    return;
  }
  r1 = {1, 0}, r2 = {0, 0};
  for (int i = 0; i < (int)G[v].size(); i++) {
    if (vis[G[v][i]]) continue;
    res _r1, _r2;
    _f(G[v][i], _r1, _r2);
    if (_r1.l <= _r2.l) {
      r1.l += _r1.l;
      if (_r1.l == _r2.l) {
        if (_r1.r + 1 <= _r2.r) r1.r += _r2.r;
        if (_r1.r + 1 > _r2.r) r1.r += (1 + _r1.r);
      } else {
        r1.r += (1 + _r1.r);
      }
    } else {
      r1.l += _r2.l, r1.r += _r2.r;
    }
    r2.l += _r1.l, r2.r += _r1.r;
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) G[i].clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    res __res = {0, 0};
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      res _t1, _t2;
      _f(i, _t1, _t2);
      if (_t1.l < _t2.l) __res.l += _t1.l, __res.r += _t1.r;
      if (_t1.l == _t2.l) __res.l += _t1.l, __res.r += max(_t1.r, _t2.r);
      if (_t1.l > _t2.l) __res.l += _t2.l, __res.r += _t2.r;
    }
    cout << __res.l << " " << __res.r << " " << m - __res.r << '\n';
  }
  return 0;
}