#pragma GCC("Ofast")
#include <bits/stdc++.h>
#include "lib1631.h"
#define ll long long
using namespace std;
struct pt {
  int x, y, c, n;
  pt operator-(pt b) const { return {x - b.x, y - b.y, c, n}; }
  bool operator==(pt b) const { return x == b.x && y == b.y && c == b.c && n == b.n; }
};

int g, r;
vector<pt> pts[2];
inline ll _area(const pt &v1, const pt &v2) { return 1ll * v1.x * 1ll * v2.y * 1ll - 1ll * v1.y * 1ll * v2.x * 1ll; }
inline void _in(pt &a, pt &b, pt &c, vector<pt> v[2], vector<pt> r[2]) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < (int)v[i].size(); j++) {
      pt _t = v[i][j];
      if (abs(_area(a - _t, b - _t)) + abs(_area(b - _t, c - _t)) + abs(_area(c - _t, a - _t)) == abs(_area(b - a, c - a)))
        r[i].push_back(_t);
    }
}
inline void _f(pt &a, pt &b, pt &c, vector<pt> v[2]) {
  if (v[a.c].size() == 1) {
    for (int i = 0; i < (int)v[b.c].size(); i++) {
      if (v[b.c][i].n != c.n && v[b.c][i].n != b.n) Report(b.c, v[b.c][i].n, b.n);
    }
    return;
  }
  if (v[b.c].size() == 2) {
    for (int i = 0; i < (int)v[a.c].size(); i++) {
      if (v[a.c][i].n != a.n) Report(a.c, v[a.c][i].n, a.n);
    }
    return;
  }
  vector<pt> r1[2], r2[2], r3[2];
  _in(v[a.c][0] == a ? v[a.c][1] : v[a.c][0], b, c, v, r1);
  _in(b, v[a.c][0] == a ? v[a.c][1] : v[a.c][0], a, v, r2);
  _in(c, v[a.c][0] == a ? v[a.c][1] : v[a.c][0], a, v, r3);
  Report(a.c, v[a.c][0] == a ? v[a.c][1].n : v[a.c][0].n, a.n);
  _f(v[a.c][0] == a ? v[a.c][1] : v[a.c][0], b, c, r1);
  _f(b, v[a.c][0] == a ? v[a.c][1] : v[a.c][0], a, r2);
  _f(c, v[a.c][0] == a ? v[a.c][1] : v[a.c][0], a, r3);
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  Init(g, r);
  for (int i = 0; i < g; i++) {
    pt t = {0, 0, 0, i + 1};
    Get(0, t.x, t.y);
    pts[0].push_back(t);
  }
  for (int i = 0; i < r; i++) {
    pt t = {0, 0, 1, i + 1};
    Get(1, t.x, t.y);
    pts[1].push_back(t);
  }
  vector<pt> r1[2], r2[2];
  _in(pts[0][0], pts[1][0], pts[1][1], pts, r1);
  _in(pts[1][1], pts[0][0], pts[0][1], pts, r2);
  Report(0, 1, 2), Report(1, 1, 2);
  _f(pts[0][0], pts[1][0], pts[1][1], r1);
  _f(pts[1][1], pts[0][0], pts[0][1], r2);
  Finish();
  return 0;
}