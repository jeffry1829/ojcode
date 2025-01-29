#include <bits/stdc++.h>
using namespace std;
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
#define rank oiajgpowsdjg
#define y1 ojsapogjahg
#define prev ojaposjdas
// #define end aononcncnccc
inline int pmod(int x, int d) {
  int m = x % d;
  return m + ((m >> 31) & d);
}
// head
const int _n = 1e5 + 10;
main(void) {
  rep(i, 0, 20) rep(j, 0, 11) {
    cout << i << ' ' << j << '\n';
    if (i == 0 & j == 0) {
      cout << "A:" << i << ' ' << j << '\n';
    }
  }
}