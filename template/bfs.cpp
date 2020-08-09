#include <bits/stdc++.h>
using namespace std;
vector<int> G[_N];
int dis[_N][_N] = {{0}};
bool visited[_N];
inline void bfs(int start) {
  memset(visited, 0, sizeof(visited));
  int now;
  dis[start][start] = 0;
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    now = q.front();
    q.pop();
    visited[now] = true;
    for (int i = 0; i < G[now].size(); i++) {
      if (!visited[G[now][i]]) {
        q.push(G[now][i]);
        visited[G[now][i]] = true;
        dis[start][G[now][i]] = dis[start][now] + 1;
      }
    }
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  return 0;
}