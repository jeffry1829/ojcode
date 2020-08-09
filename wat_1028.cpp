#include <bits/stdc++.h>
#define INF 100001
using namespace std;
struct WE {
  int v, d;
};
const int _N = 14;
int N, M, K, need, initV;
int dpt[_N][1 << _N], d[_N], ___prev[_N][1 << _N], route_length[1 << _N];
bool in_tree[_N] = {0};
vector<WE> G[_N];
inline void init_G() {
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
}
inline void init_goal() {
  need = 0;
  cin >> K >> initV;
  need |= (1 << initV);
  for (int i = 0; i < K - 1; i++) {
    int a;
    cin >> a;
    need |= (1 << a);
  }
}
inline void init_dpt() {
  for (int i = 0; i < _N; i++)
    for (int j = 0; j < (1 << _N); j++) {
      dpt[i][j] = -100;
      ___prev[i][j] = -1;
    }
  for (int i = 0; i < _N; i++) dpt[i][1 << initV] = 0;
}
inline int digit(int stat) {
  int c = 0;
  for (int i = 0; i < N; i++) {
    if (stat & (1 << i)) c++;
  }
  return c;
}
inline void dijkstra(int start, int stat, pair<int, int> tmp_prev[]) {
  fill(d, d + _N, INF);
  fill(in_tree, in_tree + _N, false);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push({d[start] = 0, start});
  tmp_prev[start] = {start, INF + INF};
  for (int l = 0; l < digit(~(need ^ stat)); l++) {
    int now = -1;
    while (!pq.empty() && in_tree[now = pq.top().second]) pq.pop();
    if (now == -1) return;
    in_tree[now] = true;
    for (int i = 0; i < G[now].size(); i++) {
      if (!((need ^ stat) & (1 << G[now][i].v)) && !in_tree[G[now][i].v] &&
          d[G[now][i].v] > d[now] + G[now][i].d) {
        pq.push({d[G[now][i].v] = d[now] + G[now][i].d, G[now][i].v});
        if ((pair<int, int>){tmp_prev[G[now][i].v].second, tmp_prev[G[now][i].v].first} >
            (pair<int, int>){d[G[now][i].v], G[now][i].v})
          tmp_prev[G[now][i].v] = {now, d[G[now][i].v]};
      }
    }
  }
}
int dp(int now, int stat) {
  if (now == initV && stat != (1 << initV)) return 3 * INF;
  if (!(stat & (1 << initV)) && digit(stat) != 1) return 3 * INF;
  if (dpt[now][stat] != -100) return dpt[now][stat];
  int minn = INF;
  for (int i = 0; i < N; i++) {
    if ((stat ^ (1 << now)) & (1 << i)) {
      pair<int, int> tmp_prev[_N];
      for (int j = 0; j < _N; j++) tmp_prev[j] = {-1, INF + INF};
      dijkstra(i, stat, tmp_prev);
      int tmpd = d[now];
      if (dp(i, stat ^ (1 << now)) + tmpd < minn) {
        minn = dp(i, stat ^ (1 << now)) + tmpd;
        if (route_length[stat] > minn) {
          for (int j = 0; j < _N; j++) ___prev[j][stat] = tmp_prev[j].first;
          route_length[stat] = minn;
        }
      }
    }
  }
  return dpt[now][stat] = minn;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  fill(route_length, route_length + (1 << _N), INF);
  init_G();
  init_goal();
  init_dpt();
  int minn = INF, minni;
  for (int i = 0; i < N; i++)
    if (need & (1 << i)) {
      if (minn > dp(i, need)) {
        minn = dp(i, need);
        minni = i;
      }
    }
  cout << "Minimum travel distance: " << minn << '\n';
  cout << "Travel route: ";
  int lastminni = minni;
  vector<int> seq;
  seq.push_back(minni);
  while (need != (1 << initV)) {
    minni = ___prev[minni][need];
    if (minni < 0) {
      cout << "FUCK" << endl;
      exit(0);
    }
    seq.push_back(minni);
    if (minni == ___prev[minni][need]) {
      need ^= (1 << lastminni);
      lastminni = minni;
    }
  }
  for (int i = seq.size() - 1; i >= 0; i--) cout << seq[i] << " ";
  cout << '\n';
  return 0;
}