#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _nn = 1e6 + 100;
ll n, x;
bool prime[_nn];
inline void sieve(int n) {
  for (int i = 2; i <= n; i++) prime[i] = 1;
  for (int i = 2; i <= n; i++)
    if (prime[i])
      for (ll j = 1ll * i * i; j <= n; j += i) prime[j] = 0;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  sieve(_nn - 10);
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1) {
      cout << "NO\n";
      continue;
    }
    ll t = sqrt(x);
    if (t * t == x) {
      if (prime[t]) {
        cout << "YES\n";
        continue;
      } else {
        cout << "NO\n";
        continue;
      }
    } else {
      cout << "NO\n";
      continue;
    }
  }
  return 0;
}