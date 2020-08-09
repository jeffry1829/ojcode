#include <bits/stdc++.h>
using namespace std;
const int _M = 1034, _N = 510;
int M;
struct E {
  int x, y;
} edges[_M];
vector<int> v[_N], ans;
bool vis[_M];
bool cmp(int a, int b) {
  if (edges[a].x == edges[b].x) return edges[a].y < edges[b].y;
  if (edges[a].x == edges[b].y) return edges[a].y < edges[b].x;
  if (edges[a].y == edges[b].x) return edges[a].x < edges[b].y;
  if (edges[a].y == edges[b].y) return edges[a].x < edges[b].x;
}
void dfs(int x) {
  for (int i = 0; i < v[x].size(); i++) {
    if (vis[v[x][i]]) continue;
    int to = edges[v[x][i]].x == x ? edges[v[x][i]].y : edges[v[x][i]].x;
    vis[v[x][i]] = 1;
    dfs(to);
  }
  ans.push_back(x);
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> M && M) {
    memset(edges, 0, sizeof(edges[0]) * _M);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < _N; i++) v[i].clear();
    ans.clear();
    for (int i = 1; i <= M; i++) {
      int x, y;
      cin >> x >> y;
      edges[i] = {x, y};
      v[x].push_back(i);
      v[y].push_back(i);
    }
    int odd = 0, st = _N;
    for (int i = 1; i < _N; i++) {
      if (!v[i].empty()) {
        sort(v[i].begin(), v[i].end(), cmp);
        if (!odd && (v[i].size() & 1)) st = i, odd = 1;
        if (!odd) st = min(st, i);
      }
    }
    dfs(st);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
    cout << '\n';
  }
  return 0;
}