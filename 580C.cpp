#include <bits/stdc++.h>
using namespace std;
const int _n = 1e5 + 10;
int n, m, a[_n], x, y, ans = 0;
vector<int> G[_n];
bool vis[_n];
void dfs(int v, int now, int maxx) {
  if (a[v]) {
    ++now;
    maxx = max(maxx, now);
  }
  if (!a[v]) now = 0;
  vis[v] = 1;
  for (int i = 0; i < (int)G[v].size(); i++) {
    if (!vis[G[v][i]]) dfs(G[v][i], now, maxx);
  }
  if (G[v].size() == 1 and v != 0 and maxx <= m) ans++;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(0, 0, 0);
  cout << ans << '\n';
  return 0;
}