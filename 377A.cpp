#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char mp[510][510];
bool vis[510][510];
void dfs(int x, int y) {
  vis[x][y] = 1;
  if (!k) return;
  if (!vis[x - 1][y] and mp[x - 1][y] == '.') dfs(x - 1, y);
  if (!k) return;
  if (!vis[x + 1][y] and mp[x + 1][y] == '.') dfs(x + 1, y);
  if (!k) return;
  if (!vis[x][y - 1] and mp[x][y - 1] == '.') dfs(x, y - 1);
  if (!k) return;
  if (!vis[x][y + 1] and mp[x][y + 1] == '.') dfs(x, y + 1);
  if (k) k--, mp[x][y] = 'X';
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int x = 0; x <= m; x++) mp[x][n + 1] = mp[x][0] = '#';
  for (int y = 0; y <= n; y++) mp[m + 1][y] = mp[0][y] = '#';
  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= m; x++) cin >> mp[x][y];
  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= m; x++) {
      if (mp[x][y] == '.') {
        dfs(x, y);
        goto A;
      }
    }
A:
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) {
      cout << mp[x][y];
    }
    cout << '\n';
  }
  return 0;
}