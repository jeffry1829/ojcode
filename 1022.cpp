#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y, d;
};
const int _MN = 110;
int K, m, n;
int G[_MN][_MN];
bool vis[_MN][_MN];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> K;
  while (K--) {
    for (int i = 0; i < _MN; i++)
      for (int j = 0; j < _MN; j++) {
        G[i][j] = 0x7f7f7f7f;
        vis[i][j] = 0;
      }
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        cin >> G[i][j];
    queue<pt> q;
    q.push({1, 1, 0});
    vis[1][1] = 1;
    while (!q.empty()) {
      pt p0 = q.front();
      q.pop();
      if (p0.x == m && p0.y == n) {
        cout << p0.d << '\n';
        break;
      }
      //u,r,d,l
      if (!vis[p0.x - 1][p0.y] && abs(G[p0.x - 1][p0.y] - G[p0.x][p0.y]) <= 5) {
        q.push({p0.x - 1, p0.y, p0.d + 1});
        vis[p0.x - 1][p0.y] = 1;
      }
      if (!vis[p0.x][p0.y + 1] && abs(G[p0.x][p0.y + 1] - G[p0.x][p0.y]) <= 5) {
        q.push({p0.x, p0.y + 1, p0.d + 1});
        vis[p0.x][p0.y + 1] = 1;
      }
      if (!vis[p0.x + 1][p0.y] && abs(G[p0.x + 1][p0.y] - G[p0.x][p0.y]) <= 5) {
        q.push({p0.x + 1, p0.y, p0.d + 1});
        vis[p0.x + 1][p0.y] = 1;
      }
      if (!vis[p0.x][p0.y - 1] && abs(G[p0.x][p0.y - 1] - G[p0.x][p0.y]) <= 5) {
        q.push({p0.x, p0.y - 1, p0.d + 1});
        vis[p0.x][p0.y - 1] = 1;
      }
    }
  }
  return 0;
}