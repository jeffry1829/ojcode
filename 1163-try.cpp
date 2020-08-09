#include <bits/stdc++.h>
#define _V 30010
#define _E 50010
#define maxB 15  //2^15>30000
using namespace std;
struct WE {
  int v, d;
};
struct EDGE {
  int x, y, d;
};
EDGE E1[_E];
vector<WE> G2[_V];
int djs[_V], dsc[_V], depth[_V], father[_V][maxB], fatherwei[_V], V, E, Q;
bool visited[_V];
inline void dsunion(int s1, int s2) {
  if (dsc[s1] < dsc[s2]) swap(s1, s2);
  djs[s2] = djs[s1];
  dsc[s1] += dsc[s2];
}
inline int dsfind(int x) {
  if (djs[x] != x) djs[x] = dsfind(djs[x]);
  return djs[x];
}
void dfs(int v, int d, int fa, int weight) {
  visited[v] = true;
  depth[v] = d;
  father[v][0] = fa;
  fatherwei[v] = weight;
  for (int i = 0; i < G2[v].size(); i++) {
    if (!visited[G2[v][i].v]) {
      dfs(G2[v][i].v, d + 1, v, G2[v][i].d);
    }
  }
}
inline void findfather() {
  for (int j = 1; j < maxB; j++)
    for (int i = 0; i < V; i++)
      if (~father[i][j - 1])
        father[i][j] = father[father[i][j - 1]][j - 1];
}
inline int lca(int u, int v) {  // be used when everything is ready
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = maxB - 1; i >= 0; i--)
    if (~father[u][i] && depth[father[u][i]] >= depth[v])
      u = father[u][i];
  if (u == v) return v;
  for (int i = maxB - 1; i >= 0; i--)
    if (~father[u][i] && ~father[v][i] && father[u][i] != father[v][i]) {
      u = father[u][i];
      v = father[v][i];
    }
  return father[u][0];
}
inline void getE1() {
  int X, Y, d;
  for (int i = 0; i < E; i++) {
    cin >> X >> Y >> d;
    X--;
    Y--;  // because input vertices are 1~V
    E1[i] = (EDGE){X, Y, d};
  }
}
inline void kruskal() {
  sort(E1, E1 + E, [](EDGE l, EDGE r) -> bool { return l.d < r.d; });
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
  int maxedge = -1;
  if (depth[u] < depth[v]) swap(u, v);
  while (u != v) {
    maxedge = max(maxedge, fatherwei[u]);
    u = father[u][0];
  }
  return maxedge;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> V >> E;
  memset(dsc, 1, sizeof(int) * _V);
  memset(depth, 0, sizeof(int) * _V);
  memset(fatherwei, 0, sizeof(int) * _V);
  for (int i = 0; i < V; i++)
    for (int j = 0; j < maxB; j++)
      father[i][j] = -1;
  memset(visited, 0, sizeof(bool) * _V);
  memset(E1, 0, sizeof(EDGE) * _E);
  for (int i = 0; i < V; i++)
    djs[i] = i;
  getE1();
  genG2();
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(i, 0, -1, -1);
    }
  }
  findfather();
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int ST, ED;
    cin >> ST >> ED;
    ST--;
    ED--;
    if (dsfind(ST) != dsfind(ED)) {
      cout << "-1\n";
      continue;
    }
    if (ST == ED) {
      cout << "0\n";
      continue;
    }
    int LCA = lca(ST, ED);
    cout << max(walk(ST, LCA), walk(ED, LCA)) << '\n';
  }
  return 0;
}