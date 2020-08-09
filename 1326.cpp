#include <bits/stdc++.h>
using namespace std;
const int _N = 1010;
int N, T;
struct P {
  int x, y, c;
  bool operator<(const P &rhs) const { return c > rhs.c; }
};
priority_queue<P> q;
bool mp[_N][_N], vis[_N][_N];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    int cost = 0;
    cin >> N;
    int X, Y;
    while (!q.empty()) q.pop();
    memset(mp, 0, sizeof(mp[0][0]) * _N * _N);
    memset(vis, 0, sizeof(vis[0][0]) * _N * _N);
    for (int i = 0; i < N; i++) {
      int x, y;
      cin >> x >> y;
      mp[x][y] = 1;
      X = x, Y = y;
    }
    q.push({X, Y, 0});
    while (!q.empty()) {
      while (!q.empty() && vis[q.top().x][q.top().y]) q.pop();
      if (q.empty()) break;
      P now = q.top();
      q.pop();
      vis[now.x][now.y] = 1;
      cost += now.c;
      for (int i = now.x; i <= 1000; i++) {
        if (mp[i][now.y] && !vis[i][now.y]) {
          q.push({i, now.y, i - now.x});
          break;
        }
      }
      for (int i = now.x; i >= 0; i--) {
        if (mp[i][now.y] && !vis[i][now.y]) {
          q.push({i, now.y, now.x - i});
          break;
        }
      }
      for (int i = now.y; i <= 1000; i++) {
        if (mp[now.x][i] && !vis[now.x][i]) {
          q.push({now.x, i, i - now.y});
          break;
        }
      }
      for (int i = now.y; i >= 0; i--) {
        if (mp[now.x][i] && !vis[now.x][i]) {
          q.push({now.x, i, now.y - i});
          break;
        }
      }
    }
    cout << cost << '\n';
  }
  return 0;
}