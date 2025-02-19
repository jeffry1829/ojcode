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
const int _n = 100 + 10;
ll n, k, a[_n];
struct Mat {
 public:
  int rlen, clen;
  vector<vector<int>> _a;
  Mat(int rlen, int clen) : rlen(rlen), clen(clen) {
    _a = vector<vector<int>>(rlen, vector<int>(clen, 0));
  }
  Mat operator*(const Mat& rhs) const {
    Mat res(this->rlen, rhs.clen);
    rep(i, 0, res.rlen) rep(j, 0, res.clen) {
      res._a[i][j] = 0;
      rep(k, 0, this->clen) res._a[i][j] = (1ll * res._a[i][j] + 1ll * (_a[i][k] % mod) * (rhs._a[k][j] % mod)) % mod;
    }
    return res;
  }
  Mat operator^(ll b) {
    Mat res(rlen, clen), tmp = *this;
    assert(rlen == clen);
    rep(i, 0, rlen) {
      res._a[i][i] = 1;
    }
    while (b) {
      if (b & 1ll) res = res * tmp;
      b >>= 1ll;
      tmp = tmp * tmp;
    }
    return res;
  }
};
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  Mat G(n, n);
  Mat z(n, 1);
  rep(i, 0, n) {
    cin >> a[i];
    z._a[i][0] = 1;
  }

  rep(i, 0, n) {
    rep(j, 0, n) {
      if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) {
        G._a[i][j] = 1;
      }
    }
  }
  z = (G ^ (k - 1)) * z;
  ll ans = 0;
  rep(i, 0, n) {
    ans = (1ll * ans + 1ll * z._a[i][0]) % mod;
  }
  cout << ans << '\n';
  return 0;
}