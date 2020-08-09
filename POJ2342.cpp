//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int _N = 6e3 + 10;
vector<int> G[_N];
int cv[_N];
bool not_root[_N];
inline void _f(int e, int &r1, int &r2) {  // e=no,r1=root include,r2=without root (of subtree)
  if (G[e].size() == 0) {
    r1 = cv[e], r2 = 0;
    return;
  }
  int v1 = cv[e], v2 = 0;
  for (int i = 0; i < (int)G[e].size(); i++) {
    int _r1, _r2;
    _f(G[e][i], _r1, _r2);
    v1 += max(0, _r2), v2 += max(0, max(_r1, _r2));
  }
  r1 = v1, r2 = v2;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> cv[i];
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[b].push_back(a);
    not_root[a] = 1;
  }
  int root;
  for (int i = 1; i <= n; i++)
    if (!not_root[i]) root = i;
  int r1, r2;
  _f(root, r1, r2);
  cout << max(r1, r2) << '\n';
  return 0;
}