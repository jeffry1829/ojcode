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
const int _n = 5e3 + 10;
ll t, n, m, par[_n];
VI child[_n];
ll a[_n];
struct dpnode {
  ll cost;
  vector<ll> remain;
};
dpnode dp[_n];
void dfs(int v) {
  // dp[v].cost = 0;
  // dp[v].remain.clear();
  if (SZ(child[v]) == 0) {
    dp[v].cost = 0;
    dp[v].remain.pb(1e15 * 1ll);
    return;
  }
  rep(i, 0, SZ(child[v])) {
    int c = child[v][i];
    dfs(c);
    dp[v].cost += dp[c].cost;
  }
  vector<ll> new_remain;
  ll cur_sum = 0;
  new_remain.push_back(0ll);  // place holder
  rep(i, 0, SZ(dp[child[v][0]].remain)) { new_remain.pb(dp[child[v][0]].remain[i]); }
  // new_remain.emplace_back(dp[child[v][0]].remain);
  cur_sum += a[child[v][0]];
  rep(i, 1, SZ(child[v])) {
    cur_sum += a[child[v][i]];
    rep(j, 0, SZ(dp[child[v][i]].remain)) {
      if (SZ(new_remain) < j + 2) new_remain.push_back(0ll);
      new_remain[j + 1] += (dp[child[v][i]].remain[j]);
    }
  }
  new_remain[0] = max(0ll, cur_sum - a[v]);
  dp[v].remain = new_remain;
  ll to_add = max(0ll, a[v] - cur_sum);
  dp[v].cost += to_add;
  rep(i, 1, SZ(dp[v].remain)) {
    ll cur_remain = dp[v].remain[i];
    ll cur_to_add = max(0ll, to_add - cur_remain);
    dp[v].cost += cur_to_add;
    dp[v].remain[i] = max(0ll, dp[v].remain[i] - cur_to_add);
    to_add -= min(to_add, cur_remain);
    if (to_add == 0) break;
  }
}
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    rep(i, 0, n + 1) child[i].clear();
    rep(i, 0, n + 1) dp[i].cost = 0;
    rep(i, 0, n + 1) dp[i].remain.clear();
    rep(i, 1, n + 1) cin >> a[i];  // 1-indexed
    rep(i, 2, n + 1) {
      cin >> par[i];
      child[par[i]].pb(i);
    }
    dfs(1);
    cout << dp[1].cost << '\n';
  }
  return 0;
}
