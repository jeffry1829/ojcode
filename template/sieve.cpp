#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _N = 1e5 + 10;
bool prime[_N];
inline void sieve(int n) {
  for (int i = 2; i <= n; i++) prime[i] = 1;
  for (int i = 2; i <= n; i++)
    if (prime[i])
      for (ll j = 1ll * i * i; j < n; j += i) prime[j] = 0;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  return 0;
}