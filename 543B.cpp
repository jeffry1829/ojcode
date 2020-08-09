#include <bits/stdc++.h>
using namespace std;
const int _N = 3010, _M = 4500000;
vector<int> G[_N];
int dis[_N][_N] = {{0}}, s1, t1, l1, s2, t2, l2, N, M;
bool visited[_N];
inline void init_vals() {
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  s1--;
  t1--;
  s2--;
  t2--;
}
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
        //cout << "dis[" << start << "][" << G[now][i] << "]=" << dis[start][now] + 1 << endl;
      }
    }
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  init_vals();
  for (int i = 0; i < N; i++) bfs(i);
  int minn = dis[s1][t1] + dis[s2][t2];
  if (dis[s1][t1] > l1 || dis[s2][t2] > l2) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      int first1 = dis[s1][i] + dis[i][j] + dis[j][t1];
      int second1 = dis[s2][i] + dis[i][j] + dis[j][t2];
      int first2 = dis[s1][j] + dis[i][j] + dis[i][t1];
      int second2 = dis[s2][j] + dis[i][j] + dis[i][t2];
      if (first1 <= l1 && second1 <= l2) {
        minn = min(minn, dis[s1][i] + dis[i][j] + dis[j][t1] +
                             dis[s2][i] + dis[j][t2]);
      }
      if (first1 <= l1 && second2 <= l2) {
        minn = min(minn, dis[s1][i] + dis[i][j] + dis[j][t1] +
                             dis[s2][j] + dis[i][t2]);
      }
      if (first2 <= l1 && second2 <= l2) {
        minn = min(minn, dis[s1][j] + dis[i][j] + dis[i][t1] +
                             dis[s2][j] + dis[i][t2]);
      }
      if (first2 <= l1 && second1 <= l2) {
        minn = min(minn, dis[s1][j] + dis[i][j] + dis[i][t1] +
                             dis[s2][i] + dis[j][t2]);
      }
    }
  }
  cout << M - minn << '\n';
  return 0;
}