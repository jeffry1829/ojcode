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
#define int long long
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
struct slice_ {
  int l, r, num;
};
const int _n = 2e5 + 10;
int t, n, m, a[_n], la, ra, b[_n], lb, rb, c[_n], lc, rc, tot, frac;
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    tot = 0;
    frac = 0;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) tot += a[i];
    frac = std::ceil(1.0 * tot / 3.0);
    int sum = 0;
    la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0;
    rep(i, 0, n) {
      sum += a[i];
      if (sum >= frac) {
        la = i;
        break;
      }
    }
    sum = 0;
    rep(i, 0, n) {
      sum += b[i];
      if (sum >= frac) {
        lb = i;
        break;
      }
    }
    sum = 0;
    rep(i, 0, n) {
      sum += c[i];
      if (sum >= frac) {
        lc = i;
        break;
      }
    }
    sum = 0;
    per(i, 0, n) {
      sum += a[i];
      if (sum >= frac) {
        ra = i;
        break;
      }
    }
    sum = 0;
    per(i, 0, n) {
      sum += b[i];
      if (sum >= frac) {
        rb = i;
        break;
      }
    }
    sum = 0;
    per(i, 0, n) {
      sum += c[i];
      if (sum >= frac) {
        rc = i;
        break;
      }
    }
    slice_ s[3] = {{la, ra, 0}, {lb, rb, 1}, {lc, rc, 2}};
    // sort(s, s + 3, [](slice_ a, slice_ b) { return a.l < b.l; });
    int ans[3] = {0, 0, 0};
    // ans[0] = s[0].num;
    // sort(s, s + 3, [](slice_ a, slice_ b) { return a.r < b.r; });
    // ans[2] = s[2].num;
    // ans[1] = 3 - ans[0] - ans[2];
    // sort(s, s + 3, [](slice_ a, slice_ b) { return a.num < b.num; });
    bool ok = false;
    int qq[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    rep(ii, 0, 6) {
      ans[0] = qq[ii][0];
      ans[1] = qq[ii][1];
      ans[2] = qq[ii][2];
      int midsum = 0;
      rep(i, s[ans[0]].l + 1, s[ans[2]].r) {
        if (s[ans[1]].num == 0) {
          midsum += a[i];
        } else if (s[ans[1]].num == 1) {
          midsum += b[i];
        } else {
          midsum += c[i];
        }
      }
      if (midsum >= frac) {
        ok = true;
        break;
      }
    }
    // int midsum = 0;
    // rep(i, s[ans[0]].l + 1, s[ans[2]].r) {
    //   if (s[ans[1]].num == 0) {
    //     midsum += a[i];
    //   } else if (s[ans[1]].num == 1) {
    //     midsum += b[i];
    //   } else {
    //     midsum += c[i];
    //   }
    // }
    // if (midsum < frac) {
    //   // cout << frac << '\n';
    //   cout << "-1\n";
    // } else {
    if (!ok) {
      cout << "-1\n";
    } else {
      PII p[3] = {{1, s[ans[0]].l + 1},
                  {s[ans[0]].l + 1 + 1, s[ans[2]].r - 1 + 1},
                  {s[ans[2]].r + 1, n}};
      int cnt = 0;
      rep(i, 0, 3) {
        int e = ans[i];
        if (e == cnt) {
          cnt++;
          cout << p[i].fi << " " << p[i].se << " ";
          break;
        }
      }
      rep(i, 0, 3) {
        int e = ans[i];
        if (e == cnt) {
          cnt++;
          cout << p[i].fi << " " << p[i].se << " ";
          break;
        }
      }
      rep(i, 0, 3) {
        int e = ans[i];
        if (e == cnt) {
          cnt++;
          cout << p[i].fi << " " << p[i].se << " ";
          break;
        }
      }
      cout << '\n';
      // cout << 1 << " " << s[ans[0]].l + 1 << " " << s[ans[0]].l + 1 + 1 << " " << s[ans[2]].r - 1 + 1 << " " << s[ans[2]].r + 1 << " " << n << '\n';
    }
  }
  return 0;
}