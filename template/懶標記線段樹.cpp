// 這是區間和的懶標記
using ll = long long;
const int _n = 1e5 + 10;
struct Node {
  ll val;
};
class Seg {
 public:
  int seg_n;
  vector<Node> nodes;
  vector<Node> laz;
  void pull(int v) {
    nodes[v].val = nodes[2 * v + 1].val + nodes[2 * v + 2].val;
  }
  void apply(int v, ll val) {
    nodes[v].val = val;
    laz[v].val = val;
  }
  void push(int v) {
    if (laz[v].val != -1) {  // 正常來說要判斷laz != 0，這邊是因為這題需要才用-1
      apply(2 * v + 1, laz[v].val);
      apply(2 * v + 2, laz[v].val);
      laz[v].val = -1;  // 正常來說要laz = 0，這邊是因為這題需要才用-1
    }
  }
  void build(int v, int l, int r) {
    laz[v].val = -1;  // 正常來說要laz = 0，這邊是因為這題需要才用-1
    if (l + 1 == r) {
      nodes[v].val = 1;  // 正常來說要 = 一個外部的資料，這邊是因為這題需要才用1
    } else {
      int m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      pull(v);
    }
  }
  void set(int v, int l, int r, int ql, int qr, ll val) {
    if (r <= ql or qr <= l) {
      return;
    } else if (ql <= l and r <= qr) {
      apply(v, val);
    } else {
      push(v);
      int m = (l + r) / 2;
      set(2 * v + 1, l, m, ql, qr, val);
      set(2 * v + 2, m, r, ql, qr, val);
      pull(v);
    }
  }
  void set(int l, int r, ll val) {
    set(0, 0, seg_n, l, r, val);
  }
  void set(int pos, ll val) {
    set(0, 0, seg_n, pos, pos + 1, val);
  }
  void init(int n_) {
    seg_n = n_;
    nodes = vector<Node>(4 * seg_n);
    laz = vector<Node>(4 * seg_n);
    build(0, 0, seg_n);
  }
  ll query(int v, int l, int r, int ql, int qr) {
    if (r <= ql or l >= qr) {
      return 0;
    }
    if (ql <= l and qr >= r) {
      return nodes[v].val;
    }
    int m = (l + r) / 2;
    ll res = 0;
    push(v);
    res = query(2 * v + 1, l, m, ql, qr) + query(2 * v + 2, m, r, ql, qr);
    pull(v);
    return res;
  }
};

class Solution {
 public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& qs) {
    Seg seg;
    seg.init(n);
    vector<int> ans;
    for (auto& q : qs) {
      int u = q[0];
      int v = q[1];
      seg.set(u + 1, v, 0);
      ans.push_back(seg.query(0, 0, n, 0, n) - 1);
    }
    return ans;
  }
};