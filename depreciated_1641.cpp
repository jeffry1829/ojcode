#include <bits/stdc++.h>
using namespace std;
struct WE {
  int v, w;
};
struct sci {
  int real, e;
  sci operator*(const sci& r) const {
    int _real = (real * r.real), _e = e + r.e;
    while (_real >= 1000) _real = ((_real - _real % 10) / 10);
    return {_real, _e};
  }
  void print() {
    char tmp[4];
    sprintf(tmp, "%03d", e);
    cout << ((double)real / 100.0) << "e" << tmp << '\n';
  }
};
sci conv2sci(int x) {
  int e = 0;
  while (x >= 10) {
  }
  x = ((x - x % 10) / 10);
}
class cmp {
 public:
  bool operator()(pair<sci, int> l, pair<sci, int> r) {
    sci sci1 = l.first, sci2 = r.first;
    if (sci1.e == sci2.e)
      return sci1.real < sci2.real;
    else
      return sci1.e < sci2.e;
  }
};
const int _N = 10010, _M = 200010;
int N, M, S, T;
vector<WE> G[_N];
sci dis[_N] = {{1, 1000000}};
priority_queue<pair<sci, int>, vector<pair<sci, int> >, cmp> pq;
bool in_tree[_N] = {0};
inline void init_G() {
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    G[A].push_back({B, C});
  }
}
inline void dijkstra(int start) {
  pq.push({dis[start] = {0, 0}, start});
  for (int l = 0; l < N; l++) {
    int now = -1;
    while (!pq.empty() && in_tree[now = pq.top().second]) pq.pop();
    in_tree[now] = true;
    for (int i = 0; i < G[now].size(); i++) {
      if (dis[now] * G[now][i].w < dis[G[now][i].v]) {
        pq.push({dis[G[now][i].v] = dis[now] * G[now][i].w,
                 G[now][i].v});
      }
    }
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M >> S >> T;
  init_G();
  dijkstra(S);
  dis[T].print();
  return 0;
}