#include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
class LiSan {
 private:
  vector<int> vv;

 public:
  inline void init() { vv.clear(); }
  inline void insert(int x) { vv.push_back(x); }
  inline void done() {
    sort(ALL(vv));
    vv.resize(distance(vv.begin(), unique(ALL(vv))));
  }
  inline int size() { return vv.size(); }
  inline int get(int x) {
    return distance(vv.begin(), lower_bound(ALL(vv), x));
  }
  inline int inv_get(int x) { return vv[x]; }
} lisan;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  return 0;
}