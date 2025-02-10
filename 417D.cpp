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
#define mp make_pair
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
const int _n = 100 + 10, _m = 20 + 3;
ll n, m, b;
struct Friend {
  ll x, k, mMask;
  bool operator<(auto& rhs) const {
    return k < rhs.k;
  }
};
vector<Friend> Fs;
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> b;
  ll fullmask = (1 << m) - 1;
  rep(i, 0, n) {
    ll x, k, numm;
    cin >> x >> k >> numm;
    ll mask = 0;
    rep(j, 0, numm) {
      ll mi;
      cin >> mi;
      mask |= (1 << (mi - 1));
    }
    Fs.pb({x, k, mask});
  }
  sort(all(Fs));
  ll ans = 0x7f7f7f7f7f7f7f7f;
  vector<ll> mask2cost((1 << m), 0x7f7f7f7f7f7f7f7f);
  mask2cost[0] = 0;
  rep(i, 0, n) {
    ll curK = Fs[i].k;
    rep(oldmask, 0, (1 << m)) {
      ll newmask = oldmask | Fs[i].mMask;
      mask2cost[newmask] = min(mask2cost[newmask], mask2cost[oldmask] + Fs[i].x);
    }
    if (mask2cost[fullmask] != 0x7f7f7f7f7f7f7f7f) ans = min(ans, mask2cost[fullmask] + curK * b);
  }

  if (ans != 0x7f7f7f7f7f7f7f7f) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}