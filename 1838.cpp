#include <bits/stdc++.h>
#define _N 100010
using namespace std;
struct WE {
  int p, d;
};
struct TRA {
  int p, r;
  double dis;
};
vector<WE> G[_N];
vector<TRA> TreeR;
bool visited[_N];
bool tmp_visited[_N];
bool tmp2_visited[_N];
int N, M, L, R1, R2, R3, D1;
inline bool gin(int &x) {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == -1) return 0;
  x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  return 1;
}
inline void getG() {
  for (int i = 0; i < M; i++) {
    int Ai, Bi, d;
    gin(Ai);
    gin(Bi);
    gin(d);
    G[Ai].push_back((WE){Bi, d});
    G[Bi].push_back((WE){Ai, d});
  }
}
inline void set_visited(int p) {
  visited[p] = true;
  tmp_visited[p] = true;
}
inline void set_visited2(int p) {
  visited[p] = true;
  tmp2_visited[p] = true;
}
inline pair<int, int> dfsR1(int p, int d) {
  int maxRpoint = p, maxR = d;
  set_visited(p);
  for (int i = 0; i < G[p].size(); i++) {
    if (tmp_visited[G[p][i].p]) continue;
    int d2 = d + G[p][i].d;
    pair<int, int> res = dfsR1(G[p][i].p, d2);
    if (maxR < res.second) {
      maxRpoint = res.first;
      maxR = res.second;
    }
  }
  return make_pair(maxRpoint, maxR);
}
inline TRA dfsR(int p, int d) {
  int maxRpoint = p, maxR = d;
  double dis = -__builtin_fabs(maxR / 2.0 - d);
  set_visited2(p);
  for (int i = 0; i < G[p].size(); i++) {
    if (tmp2_visited[G[p][i].p]) continue;
    int d2 = d + G[p][i].d;
    auto res = dfsR(G[p][i].p, d2);
    if (maxR < res.r) {
      maxRpoint = res.p;
      maxR = res.r;
      dis = max(res.dis, -__builtin_fabs(maxR / 2.0 - d));
    }
  }
  return (TRA){maxRpoint, maxR, dis};
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (gin(N), gin(M), gin(L)) {
    for (int i = 0; i < N; i++)
      G[i].clear();
    TreeR.clear();
    memset(visited, 0, sizeof(bool) * N);
    memset(tmp_visited, 0, sizeof(bool) * N);
    memset(tmp2_visited, 0, sizeof(bool) * N);
    getG();
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        auto res = dfsR1(i, 0);
        auto res2 = dfsR(res.first, 0);
        TreeR.push_back((TRA){res2.p, res2.r, res2.dis});
      }
    }
    sort(TreeR.begin(), TreeR.end(), [](TRA tra1, TRA tra2) { return tra1.r / 2.0 - tra1.dis > tra2.r / 2.0 - tra2.dis; });
    R1 = TreeR[0].r / 2.0 - TreeR[0].dis;
    R2 = TreeR[1].r / 2.0 - TreeR[1].dis;
    R3 = TreeR[2].r / 2.0 - TreeR[2].dis;
    D1 = TreeR[0].r;
    if (TreeR.size() >= 3)
      cout << max(D1, max(2 * L + R2 + R3, L + R1 + R2)) << '\n';
    else if (TreeR.size() == 2)
      cout << max(D1, L + R1 + R2) << '\n';
    else
      cout << D1 << '\n';
  }
  return 0;
}