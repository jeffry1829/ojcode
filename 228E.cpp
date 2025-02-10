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
// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
// __gnu_pbds::gp_hash_table<string, int> mp;
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
const int _n = 100 + 10;
int t, n, m, T = 0;
VI G[_n * 2];
int id[_n * 2], low[_n * 2], scc[_n * 2];
stack<int> st;
void dfs(int v, int fa) {
  id[v] = low[v] = ++T;
  st.push(v);
  for (int u : G[v]) {
    if (!id[u]) dfs(u, v);
    if (u != fa and !scc[u]) low[v] = min(low[v], low[u]);
  }
  if (low[v] == id[v]) {
    int temp;
    do {
      scc[temp = st.top()] = v;
      st.pop();
    } while (temp != v);
  }
}
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    // G[a].pb(b);
    if (c) {
      G[a * 2 + 1].pb(b * 2 + 1);  // x*2 false, x*2+1 true
      G[b * 2 + 1].pb(a * 2 + 1);
      G[a * 2].pb(b * 2);
      G[b * 2].pb(a * 2);
    } else {
      G[a * 2 + 1].pb(b * 2);
      G[b * 2].pb(a * 2 + 1);
      G[a * 2].pb(b * 2 + 1);
      G[b * 2].pb(a * 2 + 1);
    }
  }
  rep(i, 0, n) {
    if (!id[i * 2]) dfs(i * 2, i * 2);
    if (!id[i * 2 + 1]) dfs(i * 2 + 1, i * 2 + 1);
  }
  // tarjan 算出來的scc 實際上是反過來的topo order
  // 而這剛好是我們找2-SAT最後的解要的：反過來的topo order

  // 檢查同個scc裡面有沒有 p and ~p
  rep(i, 0, n) {
    if (scc[i * 2] == scc[i * 2 + 1]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  VI ans;
  rep(i, 0, n) {
    // scc比較小的 出現在拓樸排序的比較後面
    if (scc[i * 2 + 1] < scc[i * 2]) {
      ans.pb(i / 2);
    }
  }
  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}