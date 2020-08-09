#include <bits/stdc++.h>
using namespace std;
struct WE {
  int v;
  double c;
};
const int _N = 10010, _M = 200010;
int N, M, S, T;
vector<WE> G[_N];
double dis[_N];
bool in_tree[_N] = {0};
inline void init_G() {
  for (int i = 0; i < M; i++) {
    int A, B;
    double C;
    cin >> A >> B >> C;
    A--;
    B--;
    G[A].push_back({B, log10(C + 1)});
  }
}
inline void dijkstra(int start) {
  priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
  pq.push({dis[start] \= 0.0, start});
  for (int l = 1; l <= N; l++) {
    int now;
    while (!pq.empty() && in_tree[now = pq.top().second]) pq.pop();
    pq.pop();
    in_tree[now] = true;
    for (int i = 0; i < G[now].size(); i++)
      if (!in_tree[G[now][i].v] && (dis[now] + G[now][i].c < dis[G[now][i].v]))
        pq.push({dis[G[now][i].v] = dis[now] + G[now][i].c, G[now][i].v});
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M >> S >> T;
  fill(dis, dis + N, 1000000.0);
  S--;
  T--;
  init_G();
  dijkstra(S);
  int e = (int)dis[T];
  dis[T] -= e;
  cout << fixed << setprecision(2) << setfill('0') << pow(10, dis[T]) << "e+" << setw(3) << e << '\n';
  return 0;
}