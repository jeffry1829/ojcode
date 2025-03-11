/*
 * 注意!這個Template並不保證在任何情況下都work
 */
// #pragma GCC optimize(1)
// #pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
// #define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(x) (((x) < 0) ? (-(x)) : (x))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline int pmod(int x, int d) {
  int m = x % d;
  return m + ((m >> 31) & d);
}
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
// #define end aononcncnccc
// head
const int _n = 1e5 + 10;
const ll inf = 1e18;
int t, n, m, k, u, v, x, s, y, ans, train[_n];
ll dis[_n];
struct WE {
  int to, w;
};
struct W {
  ll f, t, w;
  bool operator<(const W& rhs) const { return w > rhs.w; }
};
vector<WE> G[_n];
priority_queue<W> pq;
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  rep(i, 0, m) {
    cin >> u >> v >> x;
    G[u].pb({v, x}), G[v].pb({u, x});
  }
  rep(i, 0, k) {
    cin >> s >> y;
    if (!train[s])
      train[s] = y;
    else if (train[s])
      ans++, train[s] = min(train[s], y);
  }

  // START
  // THIS TEMPLATE IS FOR REFERENCE PURPOSE
  rep(i, 1, n + 1) dis[i] = inf;
  rep(i, 2, n + 1) if (train[i]) pq.push({0, i, train[i]});
  pq.push({0, 1, 0});
  while (!pq.empty()) {
    W now = pq.top();
    pq.pop();
    if (now.w >= dis[now.t]) continue;
    dis[now.t] = now.w;
    for (WE& u : G[now.t]) {
      if (dis[now.t] + u.w < dis[u.to]) pq.push({now.t, u.to, dis[now.t] + u.w});
      if (train[u.to] and dis[now.t] + u.w <= train[u.to]) ans++, train[u.to] = 0;
    }
  }

  cout << ans << '\n';
  return 0;
}

/////////////////////////////////////
struct E {
  int x1, y1, x2, y2, w;
  bool operator<(auto& rhs) const {
    return w > rhs.w;
  }
};
class Solution {
 public:
  int dis[110][110], n, m;
  bool vis[110][110];
  int minCost(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dis[i][j] = 0x7f7f7f7f;
      }
    }
    dis[0][0] = 0;
    priority_queue<E> pq;
    pq.push({0, 0, 0, 0, 0});
    while (!pq.empty()) {
      E curE = pq.top();
      pq.pop();
      if (vis[curE.x2][curE.y2]) continue;  // 其實只要判斷有沒有已經在最短路徑樹上就好
      dis[curE.x2][curE.y2] = curE.w;
      int x = curE.x2, y = curE.y2;
      // 判斷dis是不是比較小其實不需要 感覺只是常數優化
      if (y + 1 < m and !vis[x][y + 1] and dis[x][y + 1] > dis[x][y] + (grid[x][y] == 1 ? 0 : 1)) pq.push({x, y, x, y + 1, dis[x][y] + (grid[x][y] == 1 ? 0 : 1)});
      if (y - 1 >= 0 and !vis[x][y - 1] and dis[x][y - 1] > dis[x][y] + (grid[x][y] == 2 ? 0 : 1)) pq.push({x, y, x, y - 1, dis[x][y] + (grid[x][y] == 2 ? 0 : 1)});
      if (x + 1 < n and !vis[x + 1][y] and dis[x + 1][y] > dis[x][y] + (grid[x][y] == 3 ? 0 : 1)) pq.push({x, y, x + 1, y, dis[x][y] + (grid[x][y] == 3 ? 0 : 1)});
      if (x - 1 >= 0 and !vis[x - 1][y] and dis[x - 1][y] > dis[x][y] + (grid[x][y] == 4 ? 0 : 1)) pq.push({x, y, x - 1, y, dis[x][y] + (grid[x][y] == 4 ? 0 : 1)});

      vis[x][y] = 1;
    }
    return dis[n - 1][m - 1];
  }
};