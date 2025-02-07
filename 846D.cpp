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
const int _n = 500 + 10;
int n, m, k, q, tv[_n][_n], cnt[_n][_n];
struct Query {
  int x, y, t;
  bool operator<(const auto& rhs) const {
    return t < rhs.t;
  }
};
vector<Query> qs;
bool hasKxK(int qsIdx) {
  int time = qs[qsIdx].t;
  memset(cnt, 0, sizeof(cnt));
  cnt[0][0] = tv[0][0] <= time ? 1 : 0;
  rep(i, 1, n + 1) {
    cnt[i][0] = cnt[i - 1][0] + (tv[i][0] <= time ? 1 : 0);
  }
  rep(j, 1, m + 1) {
    cnt[0][j] = cnt[0][j - 1] + (tv[0][j] <= time ? 1 : 0);
  }
  rep(i, 1, n + 1) {
    rep(j, 1, m + 1) {
      cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + (tv[i][j] <= time ? 1 : 0);
    }
  }
  rep(i, k, n + 1) {
    rep(j, k, m + 1) {
      int cntInKxK = cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k];
      if (cntInKxK == k * k) return true;
    }
  }
  return false;
}
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> q;
  rep(i, 0, n + 1) rep(j, 0, m + 1) {
    tv[i][j] = 0x7f7f7f7f;
  }
  rep(i, 0, q) {
    int x, y, t;
    cin >> x >> y >> t;
    qs.pb(Query{x, y, t});
    tv[x][y] = t;
  }
  sort(all(qs));
  int MAXB = (int)log2(qs.size()) + 2;
  int tmp = -1;
  per(i, 0, MAXB) {
    if ((tmp + (1 << i)) < qs.size() and !hasKxK(tmp + (1 << i))) {
      tmp = tmp + (1 << i);
    }
  }
  if (tmp == qs.size() - 1) {
    cout << -1 << '\n';
  } else {
    cout << qs[tmp + 1].t << '\n';
  }

  return 0;
}