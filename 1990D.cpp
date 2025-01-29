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
int t, n, m, a[_n], dp[_n];
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    rep(i, 0, n + 1) { dp[i] = 0; }
    rep(i, 1, n + 1) {
      cin >> a[i];
    }
    int prev2 = -1, prev4 = -1;
    dp[0] = 0;
    if (a[1] > 0) {
      dp[1] = 1;
    } else {
      dp[1] = 0;
    }
    if (a[1] <= 2) prev2 = 1;
    if (a[1] <= 4 and a[1] > 2) prev4 = 1;
    if (a[2] > 0) {
      dp[2] = dp[1] + 1;
    } else {
      dp[2] = dp[1];
    }
    if (a[2] <= 2) prev2 = 2;
    if (a[2] <= 4 and a[2] > 2) prev2 = 4;
    if (a[1] <= 2 and a[2] <= 2) {
      dp[2] = min(dp[2], 1);
    }
    rep(i, 3, n + 1) {
      if (a[i] > 4) {
        if (prev2 == -1) {
          dp[i] = dp[i - 1] + 1;
          prev2 = -2;
          prev4 = -2;
        } else if (prev2 != -1 and prev4 <= prev2) {
          dp[i] = dp[i - 1] + 1;
          prev2 = -2;
          prev4 = -2;
        } else if ((prev2 != -1 and prev4 > prev2) or i == n) {
          dp[i] = dp[i - 1] + i + 1 - prev2;
          prev2 = -2;
          prev4 = -2;
        } else {
          cout << "error\n";
        }
        // dp[i] = dp[i - 1] + 1;
        // prev2 = -2;
        // prev4 = -2;
      } else if (a[i] <= 4 and a[i] > 2) {
        if (prev2 == -1) {
          dp[i] = dp[i - 1] + 1;
        } else if (prev2 != -1 and prev4 < prev2) {
          dp[i] = dp[i - 1];
        } else if ((prev2 != -1 and prev4 > prev2) or i == n) {
          dp[i] = dp[i - 1];
        } else {
          cout << "error\n";
        }
      } else if (a[i] <= 2 and a[i] > 0) {
        if (prev2 == -1) {
          dp[i] = dp[i - 1] + 1;
        } else if (prev2 != -1 and prev4 < prev2) {
          dp[i] = dp[i - 1];
          prev2 = -2;
          prev4 = -2;
        } else if ((prev2 != -1 and prev4 > prev2) or i == n) {
          dp[i] = dp[i - 1] + i - prev2 + 1 - (i - prev2 > 2);
          prev2 = -2;
          prev4 = -2;
        } else {
          cout << "error\n";
        }
      } else if (a[i] == 0) {
        if (prev2 == -1) {
          dp[i] = dp[i - 1];
          prev2 = -2;
          prev4 = -2;
        } else if (prev2 != -1 and prev4 < prev2) {
          dp[i] = dp[i - 1];
          prev2 = -2;
          prev4 = -2;
        } else if ((prev2 != -1 and prev4 > prev2) or i == n) {
          dp[i] = dp[i - 1] + i - prev2;
          prev2 = -2;
          prev4 = -2;
        } else {
          cout << "error\n";
        }
      }
      if (prev2 != -2 and a[i] <= 2) prev2 = i;
      if (prev4 != -2 and a[i] <= 4 and a[i] > 2) prev4 = i;
      if (prev2 == -2) prev2 = -1;
      if (prev4 == -2) prev4 = -1;
      // int poss1 = dp[i - 1] + (a[i] > 0);
      // int poss2 = poss1;
      // int poss3 = poss1;
      // if (i - 3 > 0 and a[i - 3] <= 2 and a[i - 2] <= 4 and a[i - 1] <= 4 and a[i] <= 2) {
      //   poss2 = dp[i - 4] + 3;
      // }
      // if (a[i - 1] <= 2 and a[i] <= 2) {
      //   poss3 = dp[i - 2] + 1;
      // }
      // dp[i] = min(poss1, min(poss2, poss3));
    }
    cout << dp[n] << '\n';
  }
  return 0;
}