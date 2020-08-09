#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  if (k <= n / 2 + n % 2) {
    cout << 2 * k - 1 << '\n';
  } else
    cout << 2 * (k - (n / 2 + n % 2));
  return 0;
}