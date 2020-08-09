#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
struct WE {
  int v, d;
};
struct EDGE {
  int x, y, d;
  bool operator<(const EDGE& rhs) { return d < rhs.d; }
};
const int _V = 30010, _E = 50010, maxB = 17;  //maxB->2^15>30000
EDGE E1[_E] = {0};
vector<WE> G2[_V];
int djs[_V], dsc[_V], depth[_V] = {0}, V, E, Q, in_t[_V] = {0}, out_t[_V] = {0}, now = 0;
pair<int, int> father[_V][maxB];
bool visited[_V] = {0};
inline void dsunion(int s1, int s2) {
  if (dsc[s1] < dsc[s2]) swap(s1, s2);
  djs[s2] = s1;
  if (dsc[s1] == dsc[s2]) dsc[s1]++;
}
inline int dsfind(int x) {
  if (djs[x] != x) djs[x] = dsfind(djs[x]);
  return djs[x];
}
void dfs(int v, int d, int fa, int weight) {
  in_t[v] = now++;
  visited[v] = true;
  depth[v] = d;
  father[v][0] = make_pair(fa, weight);
  for (int i = 0; i < G2[v].size(); i++)
    if (!visited[G2[v][i].v]) dfs(G2[v][i].v, d + 1, v, G2[v][i].d);
  out_t[v] = now++;
}
bool anc(int u, int v) {  // is v u's ancessor? and  includes u==v
  return in_t[v] <= in_t[u] && out_t[v] >= out_t[u];
}
inline void findfather() {
  for (int j = 1; j < maxB; j++)
    for (int i = 1; i <= V; i++)
      father[i][j] = {father[father[i][j - 1].F][j - 1].F,
                      max(father[i][j - 1].S, father[father[i][j - 1].F][j - 1].S)};
}
inline int lca(int u, int v) {  // be used when everything is ready
  if (depth[u] < depth[v]) swap(u, v);
  if (anc(u, v)) return v;
  for (int j = maxB - 1; j >= 0; j--)
    if (!anc(v, father[u][j].F)) u = father[u][j].F;
  return father[u][0].F;
}
inline void getE1() {
  int X, Y, d;
  for (int i = 0; i < E; i++) {
    cin >> X >> Y >> d;
    E1[i] = (EDGE){X, Y, d};
  }
}
inline void kruskal() {
  sort(E1, E1 + E);
  for (int i = 0; i < E; i++) {
    EDGE e = E1[i];
    int s1, s2;
    if ((s1 = dsfind(e.x)) != (s2 = dsfind(e.y))) {
      dsunion(s1, s2);
      G2[e.x].push_back((WE){e.y, e.d});
      G2[e.y].push_back((WE){e.x, e.d});
    }
  }
}
inline void genG2() {
  kruskal();
}
inline int walk(int u, int v) {  //return max
  int maxedge = 0;
  for (int j = maxB - 1; j >= 0; j--)
    if (depth[father[u][j].F] >= depth[v]) {
      maxedge = max(maxedge, father[u][j].S);
      u = father[u][j].F;
    }
  return maxedge;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> V >> E;
  memset(dsc, 0, sizeof(int) * V);
  for (int i = 1; i <= V; i++)
    for (int j = 0; j < maxB; j++)
      father[i][j] = {i, 0};
  for (int i = 1; i <= V; i++) djs[i] = i;
  getE1();
  genG2();
  for (int i = 1; i <= V; i++)
    if (!visited[i]) dfs(i, 0, i, 0);
  findfather();
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int ST, ED;
    cin >> ST >> ED;
    if (ST == ED) {
      cout << "0\n";
    } else if (dsfind(ST) != dsfind(ED)) {
      cout << "-1\n";
    } else {
      int LCA = lca(ST, ED);
      cout << max(walk(ST, LCA), walk(ED, LCA)) << '\n';
    }
  }
  return 0;
}