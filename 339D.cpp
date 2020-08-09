#include <bits/stdc++.h>
using namespace std;
const int _n = ((1 << 17) + 10);
int n, m, p, b, a[_n];
struct node {
  int v, lvl;
  node *l, *r;
  node(int v, int lvl) : v(v), lvl(lvl) {}
  node(node *l, node *r) : l(l), r(r) { pull(); }
  void pull() {
    lvl = l->lvl + 1;
    if (lvl & 1)
      v = l->v | r->v;
    else
      v = l->v ^ r->v;
  }
};
node *build(int l, int r) {
  if (l + 1 == r) return new node(a[l], 0);
  int mid = (l + r) / 2;
  return new node(build(l, mid), build(mid, r));
}
void modify(node *cur, int pos, int l, int r, int v) {
  if (l + 1 == r) {
    cur->v = v;
    return;
  }
  int mid = (l + r) / 2;
  if (pos < mid)
    modify(cur->l, pos, l, mid, v);
  else
    modify(cur->r, pos, mid, r, v);
  cur->pull();
}
node *rt;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  int nn = 1 << n;
  for (int i = 0; i < nn; i++) cin >> a[i];
  rt = build(0, nn);
  while (m--) {
    cin >> p >> b;
    p--;
    modify(rt, p, 0, nn, b);
    cout << rt->v << '\n';
  }
  return 0;
}