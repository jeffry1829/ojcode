#include <bits/stdc++.h>
using namespace std;
const int _NM = 1e3 + 10;
int N, M;
char _map[_NM][_NM];
bool vis[_NM][_NM];
struct bi {
  int a, b;
};
queue<bi> q;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> M >> N && M + N) {
    int sum = 0;
    memset(vis, 0, sizeof(bool) * _NM * _NM);
    memset(_map, 0, sizeof(char) * _NM * _NM);
    for (int i = 1; i <= M; i++)
      for (int j = 1; j <= N; j++) {
        cin >> _map[i][j];
        _map[i][j] -= '0';
      }
    for (int i = 1; i <= M; i++)
      for (int j = 1; j <= N; j++) {
        if (!vis[i][j] && _map[i][j]) {
          bi now;
          q.push({i, j}), vis[i][j] = 1;
          while (!q.empty()) {
            now = q.front(), q.pop();
            if (!vis[now.a - 1][now.b] && _map[now.a - 1][now.b]) q.push({now.a - 1, now.b}), vis[now.a - 1][now.b] = 1;
            if (!vis[now.a + 1][now.b] && _map[now.a + 1][now.b]) q.push({now.a + 1, now.b}), vis[now.a + 1][now.b] = 1;
            if (!vis[now.a - 1][now.b - 1] && _map[now.a - 1][now.b - 1]) q.push({now.a - 1, now.b - 1}), vis[now.a - 1][now.b - 1] = 1;
            if (!vis[now.a + 1][now.b + 1] && _map[now.a + 1][now.b + 1]) q.push({now.a + 1, now.b + 1}), vis[now.a + 1][now.b + 1] = 1;
            if (!vis[now.a + 1][now.b - 1] && _map[now.a + 1][now.b - 1]) q.push({now.a + 1, now.b - 1}), vis[now.a + 1][now.b - 1] = 1;
            if (!vis[now.a - 1][now.b + 1] && _map[now.a - 1][now.b + 1]) q.push({now.a - 1, now.b + 1}), vis[now.a - 1][now.b + 1] = 1;
            if (!vis[now.a][now.b - 1] && _map[now.a][now.b - 1]) q.push({now.a, now.b - 1}), vis[now.a][now.b - 1] = 1;
            if (!vis[now.a][now.b + 1] && _map[now.a][now.b + 1]) q.push({now.a, now.b + 1}), vis[now.a][now.b + 1] = 1;
          }
          sum++;
        }
      }
    cout << sum << '\n';
  }
  return 0;
}