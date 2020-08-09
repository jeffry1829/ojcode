#include <bits/stdc++.h>
using namespace std;

struct TN {
  TN* dic[26];
  vector<int> pts;
  TN() {
    for (int i = 0; i < 26; i++) dic[i] = nullptr;
  }
};
const int _N = 2e5 + 10;
const int _Q = 5e6 + 10;
TN root;
TN* no2TN[_N];
TN* father[_N][20];
int depth[_N];
int n, q;

void dfs(TN* v, int next_d, TN* fa) {
  for (int i = 0; i < v->pts.size(); i++) {
    depth[v->pts[i]] = next_d;
  }
  father[v->pts[0]][0] = fa;
  for (int i = 0; i < 26; i++) {
    if (v->dic[i] != nullptr) {
      dfs(v->dic[i], next_d + 1, v);
    }
  }
}
void find_fa() {
  for (int step = 0; step < 19; step++) {
    for (int i = 0; i < n + 1; i++) {
      if (father[i][step] != nullptr) {
        father[i][step + 1] = father[father[i][step]->pts[0]][step];
      }
    }
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  u = no2TN[u]->pts[0];
  v = no2TN[v]->pts[0];
  for (int i = 19; i >= 0; i--) {
    if (father[u][i] != nullptr) {
      if (depth[father[u][i]->pts[0]] >= depth[v]) {
        u = father[u][i]->pts[0];
      }
    }
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (father[u][i] != father[v][i] && father[u][i] != nullptr) {
      u = father[u][i]->pts[0];
      v = father[v][i]->pts[0];
    }
  }
  return father[u][0]->pts[0];
}
inline void init() {
  memset(depth, -1, sizeof(int) * _N);
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < 20; j++) {
      father[i][j] = nullptr;
    }
  }
  root.pts.push_back(0);
  no2TN[0] = &root;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  int k;
  char c;
  init();
  for (int i = 0; i < n; i++) {
    cin >> k;
    cin >> c;
    if (no2TN[k]->dic[c - 'a'] == nullptr) {
      no2TN[k]->dic[c - 'a'] = new TN();
    }
    no2TN[k]->dic[c - 'a']->pts.push_back(i + 1);
    no2TN[i + 1] = no2TN[k]->dic[c - 'a'];
  }
  dfs(&root, 0, nullptr);  //init depth=0
  find_fa();
  cin >> q;
  int a, b;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    cout << depth[lca(a, b)] << '\n';
  }
  return 0;
}