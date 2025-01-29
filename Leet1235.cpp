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
struct Seg {
  int s, e, p;
  bool operator<(const Seg& rhs) const { return e < rhs.e; }
};
void binsearch(int idx, vector<Seg>& segs, int MAXB, vector<int>& dp) {
  int ans = dp[idx - 1];
  int a = idx;
  per(i, 0, MAXB) {
    ll j = 1 << i;
    if (a - j >= 0 and segs[a - j].e > segs[idx].s) {
      a = a - j;
    }
  }
  a--;
  if (a >= 0 and segs[a].e <= segs[idx].s and segs[idx].p + dp[a] > ans) {
    ans = segs[idx].p + dp[a];
  }
  dp[idx] = ans;
}
class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Seg> segs;
    int n = SZ(startTime) + 1;
    segs.pb({0, 0, 0});
    vector<int> dp(n, 0);
    rep(i, 0, SZ(startTime)) {
      Seg tmp = {startTime[i], endTime[i], profit[i]};
      segs.pb(tmp);
    }
    sort(all(segs));
    dp[0] = segs[0].p;
    int MAXB = ceil(log2(n));
    rep(i, 1, n) {
      binsearch(i, segs, MAXB, dp);
    }
    return dp[n - 1];
  }
};