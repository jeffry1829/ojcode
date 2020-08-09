#include <bits/stdc++.h>
using namespace std;
struct P {
  int from, to, v;
  bool operator<(const P& rhs) const { return v > rhs.v; }
};
const int _n = 1e5 + 10;
int n, m, dis[_n], fa[_n], a, b, w;
P now;
vector<pair<int, int>> G[_n];
priority_queue<P> pq;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) dis[i] = 0x7f7f7f7f;
  while (m--) {
    cin >> a >> b >> w;
    G[a].push_back({w, b}), G[b].push_back({w, a});
  }
  pq.push({1, 1, 1}), fa[1] = 1;
  for (int loop = 1; loop <= n; loop++) {
    while (!pq.empty() and dis[pq.top().to] != 0x7f7f7f7f) pq.pop();
    if (pq.empty()) break;
    now = pq.top();
    dis[now.to] = now.v, fa[now.to] = now.from;
    for (int i = 0; i < G[now.to].size(); i++) {
      if (dis[G[now.to][i].second] == 0x7f7f7f7f)
        pq.push({now.to, G[now.to][i].second, dis[now.to] + G[now.to][i].first});
    }
  }
  if (dis[n] == 0x7f7f7f7f)
    cout << -1 << '\n';
  else {
    vector<int> ans;
    ans.push_back(n);
    while (1) {
      if (n == 1) break;
      ans.push_back(fa[n]);
      n = fa[n];
    }
    for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}