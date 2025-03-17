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
const ll mod = 998244353;
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
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
// #define end aononcncnccc
inline int pmod(int x, int d) {
  int m = x % d;
  return m + ((m >> 31) & d);
}
#define la kaofjpfo
// head
const int _n = 3e5 + 10;
int t, n, k, cnt[_n << 1], num[_n << 1];
PII la[_n];
VI v;
int fac[_n], inv[_n];
void exgcd(int a, int b, int& d, int& x, int& y) {
  if (!b)
    x = 1, y = 0, d = a;
  else
    exgcd(b, a % b, d, y, x), y = (1ll * y - 1ll * x * (a / b) % mod + mod) % mod;
}
int C(int m, int n) {
  if (m < n) return 0;
  if (m < mod and n < mod) return 1ll * fac[m] * inv[n] % mod * inv[m - n] % mod;
  return 1ll * C(m / mod, n / mod) * C(m % mod, n % mod) % mod;
}
void genInv() {
  fac[0] = 1;
  rep(i, 1, n + 1) fac[i] = 1ll * fac[i - 1] * i % mod;
  // int tmp1,tmp2;rep(i,0,n+1)exgcd(fac[i],mod,tmp1,inv[i],tmp2);
  inv[n] = powmod(fac[n], mod - 2);
  per(i, 0, n) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  rep(i, 0, n) {
    cin >> la[i].fi >> la[i].se;
    v.pb(la[i].fi), v.pb(la[i].se);
  }
  sort(all(v));
  int nn = unique(all(v)) - v.begin();
  genInv();
  ll ans = 0;
  rep(i, 0, n) {
    la[i].fi = lower_bound(v.begin(), v.begin() + nn, la[i].fi) - v.begin();
    la[i].se = lower_bound(v.begin(), v.begin() + nn, la[i].se) - v.begin();
  }
  rep(i, 0, n) cnt[la[i].fi]++, cnt[la[i].se + 1]--, num[la[i].fi]++;
  rep(i, 1, nn) cnt[i] = cnt[i - 1] + cnt[i];
  rep(i, 0, nn) ans = (ans + C(cnt[i], k) - C(cnt[i] - num[i], k) + mod) % mod;
  cout << ans << '\n';
  return 0;
}  // #pragma GCC optimize(1)
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
const ll mod = 998244353;
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
#define la kaofjpfo
// head
const int _n = 3e5 + 10;
int t, n;
int fac[_n], inv[_n];
void exgcd(int a, int b, int& d, int& x, int& y) {
  if (!b)
    x = 1, y = 0, d = a;
  else
    exgcd(b, a % b, d, y, x), y = (1ll * y - 1ll * x * (a / b) % mod + mod) % mod;
}
int C(int m, int n) {
  if (m < n) return 0;
  if (m < mod and n < mod) return 1ll * fac[m] * inv[n] % mod * inv[m - n] % mod;
  return 1ll * C(m / mod, n / mod) * C(m % mod, n % mod) % mod;
}
void genInv() {
  fac[0] = 1;
  rep(i, 1, n + 1) fac[i] = 1ll * fac[i - 1] * i % mod;
  // 以下這是用exgcd算
  // int tmp1,tmp2;rep(i,0,n+1)exgcd(fac[i],mod,tmp1,inv[i],tmp2);
  // 以下是用Fermat's Little Thm算
  inv[n] = powmod(fac[n], mod - 2);
  per(i, 0, n) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  genInv();
  return 0;
}

// LC. 3463
// 修正的Lucas，handle n<mod的情況!!!
// 有中國餘數定理
class Solution {
 public:
  using ll = long long;
  static const int _n = 1e5 + 10;
  static const int finalmod = 10;
  static const int m1 = 5;
  static const int m2 = 2;  // 10/5=2
  int invm1 = 1;            // inv 5 mod 2 = 1
  int invm2 = 3;            // inv 2 mod 5 = 3 // we can do this by powmod if this is hard to calculate
  static const int mod1 = 2;
  static const int mod2 = 5;  // 2 * 5 = 10, use CRT
  static const int finmod = 10;
  int n;
  int fac1[_n], inv1[_n];
  int fac2[_n], inv2[_n];
  int C1(int m, int n) {
    if (m < n)
      return 0;
    if (m < mod1 and n < mod1)
      return 1ll * fac1[m] * inv1[n] % mod1 * inv1[m - n] % mod1;
    return 1ll * C1(m / mod1, n / mod1) * C1(m % mod1, n % mod1) % mod1;
  }
  int C2(int m, int n) {
    if (m < n)
      return 0;
    if (m < mod2 and n < mod2)
      return 1ll * fac2[m] * inv2[n] % mod2 * inv2[m - n] % mod2;
    return 1ll * C2(m / mod2, n / mod2) * C2(m % mod2, n % mod2) % mod2;
  }
  ll powmod(ll a, ll b, int mod) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
      if (b & 1)
        res = res * a % mod;
      a = a * a % mod;
    }
    return res;
  }
  void genInv1() {
    fac1[0] = 1;
    int len = min(mod1 - 1, n);
    for (int i = 1; i <= len; i++) {
      fac1[i] = 1ll * fac1[i - 1] * i % mod1;
    }
    // 以下這是用exgcd算
    // int tmp1,tmp2;rep(i,0,n+1)exgcd(fac[i],mod,tmp1,inv[i],tmp2);
    // 以下是用Fermat's Little Thm算
    inv1[len] = powmod(fac1[len], mod1 - 2, mod1);
    for (int i = len - 1; i >= 0; i--) {
      inv1[i] = 1ll * inv1[i + 1] * (i + 1) % mod1;
    }
  }
  void genInv2() {
    fac2[0] = 1;
    int len = min(mod2 - 1, n);
    for (int i = 1; i <= len; i++) {
      fac2[i] = 1ll * fac2[i - 1] * i % mod2;
    }
    // 以下這是用exgcd算
    // int tmp1,tmp2;rep(i,0,n+1)exgcd(fac[i],mod,tmp1,inv[i],tmp2);
    // 以下是用Fermat's Little Thm算
    inv2[len] = powmod(fac2[len], mod2 - 2, mod2);
    for (int i = len - 1; i >= 0; i--) {
      inv2[i] = 1ll * inv2[i + 1] * (i + 1) % mod2;
    }
  }

  bool hasSameDigits(string s) {
    n = s.size();
    genInv1();
    genInv2();
    vector<int> cnt(n - 1);

    invm1 = powmod(m1, mod1 - 2, mod1);
    invm2 = powmod(m2, mod2 - 2, mod2);

    for (int i = 0; i < n - 1; i++) {
      cnt[i] = (C1(n - 2, i) * m1 % finmod * invm1 +
                C2(n - 2, i) * m2 % finmod * invm2) %
               finmod;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n - 1; i++) {
      sum1 = (1ll * sum1 + 1ll * cnt[i] * (s[i] - '0')) % finmod;
    }
    for (int i = 1; i < n; i++) {
      sum2 = (1ll * sum2 + 1ll * cnt[i - 1] * (s[i] - '0')) % finmod;
    }
    return sum1 == sum2;
  }
};