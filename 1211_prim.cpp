#include <bits/stdc++.h>
using namespace std;
struct E {
  int to;
  int c;
  bool operator<(const E& b) const { return c > b.c; }
};
const int _n = 1e4 + 10, _m = 1e6 + 10;
int n, m, in_c = 0, res = 0, dis[_n];
bitset<_n> in;
vector<E> G[_n];
priority_queue<E> pq;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> n >> m && n && m) {
    in_c = 0, res = 0;
    while (!pq.empty()) pq.pop();
    in.reset();
    memset(dis, 0x7f, sizeof(dis));
    for (int i = 0; i < n; i++) G[i].clear();
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      G[a - 1].push_back({b - 1, c});
      G[b - 1].push_back({a - 1, c});
    }
    for (int i = 0; i < G[0].size(); i++) {
      pq.push(G[0][i]);
      dis[G[0][i].to] = G[0][i].c;
    }
    in[0] = 1;
    in_c++;
    dis[0] = 0;
    while (in_c != n) {
      E e;
      while (!pq.empty() && in[(e = pq.top()).to]) pq.pop();
      if (pq.empty()) {
        res = -1;
        break;
      }
      res += e.c;
      in[e.to] = 1;
      in_c++;
      for (int j = 0; j < G[e.to].size(); j++) {
        if (!in[G[e.to][j].to] && dis[G[e.to][j].to] > G[e.to][j].c) {
          pq.push(G[e.to][j]);
          dis[G[e.to][j].to] = G[e.to][j].c;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}