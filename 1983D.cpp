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
const int _n = 2e5 + 10;
int t, n, m, aparity, bparity;
int cur[_n], inv_cur[_n], a[_n], b[_n];
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    rep(i, 0, n) { cin >> a[i]; }
    rep(i, 0, n) { cin >> b[i]; }
    auto do_cycle = [&](int i, int j, int k) {
      int tmp = cur[k];
      cur[k] = cur[j];
      cur[j] = cur[i];
      cur[i] = tmp;

      inv_cur[cur[i]] = i;
      inv_cur[cur[j]] = j;
      inv_cur[cur[k]] = k;
    };
    std::copy(a, a + n, cur);
    std::sort(cur, cur + n);
    rep(i, 0, n) inv_cur[cur[i]] = i;
    aparity = bparity = 0;
    rep(i, 0, n - 2) {
      if (cur[i] != a[i] and inv_cur[a[i]] != n - 1) {
        do_cycle(n - 1, inv_cur[a[i]], i);
      } else if (cur[i] != a[i] and inv_cur[a[i]] == n - 1) {
        do_cycle(n - 2, inv_cur[a[i]], i);
      }
    }
    if (cur[n - 1] != a[n - 1])
      aparity = 1;  // odd
    else
      aparity = 0;  // even
    std::copy(b, b + n, cur);
    std::sort(cur, cur + n);
    rep(i, 0, n) inv_cur[cur[i]] = i;
    rep(i, 0, n - 2) {
      if (cur[i] != b[i] and inv_cur[b[i]] != n - 1) {
        do_cycle(n - 1, inv_cur[b[i]], i);
      } else if (cur[i] != b[i] and inv_cur[b[i]] == n - 1) {
        do_cycle(n - 2, inv_cur[b[i]], i);
      }
    }
    if (cur[n - 1] != b[n - 1])
      bparity = 1;  // odd
    else
      bparity = 0;  // even
    sort(a, a + n);
    sort(b, b + n);
    bool sameelems = true;
    rep(i, 0, n) {
      if (a[i] != b[i]) {
        sameelems = false;
        break;
      }
    }
    if (aparity == bparity and sameelems)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}