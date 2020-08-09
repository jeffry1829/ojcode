#include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
class BIT {
 private:
  vector<int> arr;
  int n;
  inline int lowbit(int x) { return x & (-x); }

 public:
  void init(int n_) {
    n = n_;
    arr.resize(n);
    fill(ALL(arr), INF);
  }
  int query(int x) {
    int ret = INF;
    while (x) {
      ret = min(ret, arr[x]);
      x -= lowbit(x);
    }
    return ret;
  }
  void modify(int p, int v) {
    while (p < n) {
      arr[p] = min(arr[p], v);
      p += lowbit(p);
    }
  }
} bit;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  return 0;
}