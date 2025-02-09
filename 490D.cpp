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
ll t, a1, b1, a2, b2, fac2One = 0, fac3One = 0, fac2Two = 0, fac3Two = 0, remainOne = 1, remainTwo = 1;
ll fac2a1 = 0, fac2b1 = 0, fac2a2 = 0, fac2b2 = 0, fac3a1 = 0, fac3b1 = 0, fac3a2 = 0, fac3b2 = 0;
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a1 >> b1 >> a2 >> b2;
  while (a1 % 2 == 0) {
    a1 /= 2;
    fac2One++;
    fac2a1++;
  }
  while (b1 % 2 == 0) {
    b1 /= 2;
    fac2One++;
    fac2b1++;
  }
  while (a1 % 3 == 0) {
    a1 /= 3;
    fac3One++;
    fac3a1++;
  }
  while (b1 % 3 == 0) {
    b1 /= 3;
    fac3One++;
    fac3b1++;
  }
  remainOne = a1 * b1;

  while (a2 % 2 == 0) {
    a2 /= 2;
    fac2Two++;
    fac2a2++;
  }
  while (b2 % 2 == 0) {
    b2 /= 2;
    fac2Two++;
    fac2b2++;
  }
  while (a2 % 3 == 0) {
    a2 /= 3;
    fac3Two++;
    fac3a2++;
  }
  while (b2 % 3 == 0) {
    b2 /= 3;
    fac3Two++;
    fac3b2++;
  }
  remainTwo = a2 * b2;
  if (remainOne != remainTwo) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = fac2One + fac3One + fac2Two + fac3Two;
  // cout << "ans:" << ans << '\n';
  // cout << "fac2One:" << fac2One << '\n';
  // cout << "fac3One:" << fac3One << '\n';
  // cout << "fac2Two:" << fac2Two << '\n';
  // cout << "fac3Two:" << fac3Two << '\n';
  int twoNeed = min(fac2One, fac2Two),
      threeNeed = min(fac3One, fac3Two);
  int twoNeed2 = min(fac2One, fac2Two), threeNeed2 = min(fac3One, fac3Two);
  // cout << "twoNeed:" << twoNeed << "\n";
  // cout << "threeNeed:" << threeNeed << "\n";
  ans -= twoNeed * 2 + threeNeed * 2;
  while (fac2a1 and twoNeed) {
    twoNeed--;
    if (fac2a1) {
      a1 *= 2;
      fac2a1--;
    }
  }
  while (fac2b1 and twoNeed) {
    twoNeed--;
    if (fac2b1) {
      b1 *= 2;
      fac2b1--;
    }
  }

  while (fac3a1 and threeNeed) {
    threeNeed--;
    if (fac3a1) {
      a1 *= 3;
      fac3a1--;
    }
  }
  while (fac3b1 and threeNeed) {
    threeNeed--;
    if (fac3b1) {
      b1 *= 3;
      fac3b1--;
    }
  }

  while (fac2a2 and twoNeed2) {
    twoNeed2--;
    if (fac2a2) {
      a2 *= 2;
      fac2a2--;
    }
  }
  while (fac2b2 and twoNeed2) {
    twoNeed2--;
    if (fac2b2) {
      b2 *= 2;
      fac2b2--;
    }
  }

  while (fac3a2 and threeNeed2) {
    threeNeed2--;
    if (fac3a2) {
      a2 *= 3;
      fac3a2--;
    }
  }
  while (fac3b2 and threeNeed2) {
    threeNeed2--;
    if (fac3b2) {
      b2 *= 3;
      fac3b2--;
    }
  }
  cout << ans << '\n';
  cout << a1 << ' ' << b1 << '\n';
  cout << a2 << ' ' << b2 << '\n';
  return 0;
}