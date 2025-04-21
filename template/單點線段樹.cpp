// https://leetcode.com/problems/find-x-value-of-array-ii
class Solution {
 public:
  using ll = long long;
  const static inline int _n = 1e5 + 10;
  static inline ll n, k;

  struct Node {
    ll prod;
    int cnt[5];
  };
  class Seg {
   public:
    vector<Node> nodes;
    Seg(int nn) {
      // 很重要 一開始開 4 * _n 的話，很容易TLE
      nodes = vector<Node>{(size_t)(4 * nn)};
    }
    void build(int v, int l, int r, vector<int>& nums) {
      if (l + 1 == r) {
        nodes[v].prod = nums[l] % k;
        nodes[v].cnt[nums[l] % k] = 1;
      } else {
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid, nums);
        build(2 * v + 2, mid, r, nums);
        nodes[v].prod = nodes[2 * v + 1].prod * nodes[2 * v + 2].prod % k;
        for (int i = 0; i < k; i++) {
          nodes[v].cnt[i] += nodes[2 * v + 1].cnt[i];
          nodes[v].cnt[nodes[2 * v + 1].prod * i % k] += nodes[2 * v + 2].cnt[i];
        }
      }
    }
    void update(int v, int l, int r, int idx, int val, vector<int>& nums) {
      if (r <= idx or l > idx) return;
      if (l + 1 == r) {
        if (l == idx) {
          nodes[v].prod = val % k;
          for (int i = 0; i < k; i++) {
            nodes[v].cnt[i] = 0;
          }
          nodes[v].cnt[val % k] = 1;
        }
      } else {
        int mid = (l + r) / 2;
        update(2 * v + 1, l, mid, idx, val, nums);
        update(2 * v + 2, mid, r, idx, val, nums);
        nodes[v].prod = nodes[2 * v + 1].prod * nodes[2 * v + 2].prod % k;
        for (int i = 0; i < k; i++) {
          nodes[v].cnt[i] = 0;
        }
        for (int i = 0; i < k; i++) {
          nodes[v].cnt[i] += nodes[2 * v + 1].cnt[i];
          nodes[v].cnt[nodes[2 * v + 1].prod * i % k] += nodes[2 * v + 2].cnt[i];
        }
      }
    }
    Node query(int v, int l, int r, int ql, int qr) {
      if (r <= ql or l >= qr) return Node{1, {0, 0, 0, 0, 0}};
      if (l >= ql and r <= qr) return nodes[v];
      int mid = (l + r) / 2;
      auto Lres = query(2 * v + 1, l, mid, ql, qr);
      auto Rres = query(2 * v + 2, mid, r, ql, qr);
      Node res = {Lres.prod * Rres.prod % k, {0, 0, 0, 0, 0}};
      for (int i = 0; i < k; i++) {
        res.cnt[i] = Lres.cnt[i];
      }
      for (int i = 0; i < k; i++) {
        res.cnt[Lres.prod * i % k] += Rres.cnt[i];
      }
      return res;
    }
  };
  vector<int> resultArray(vector<int>& nums, int kk, vector<vector<int>>& queries) {
    n = nums.size();
    k = kk;
    Seg seg(n);
    seg.build(0, 0, n, nums);
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
      int idx = queries[i][0];
      int val = queries[i][1];
      int st = queries[i][2];
      int x = queries[i][3];
      seg.update(0, 0, n, idx, val, nums);
      nums[idx] = val;
      auto res = seg.query(0, 0, n, st, n);
      ans.push_back(res.cnt[x]);
    }
    return ans;
  }
};