#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXB = 35;
ll t, n, k;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ll i = (-1 + sqrt(1 + 8ll * k)) / 2ll;
    if (i * (i + 1) / 2ll == k) i--;
    if (i) {
      for (int j = 0; j < n; j++) {
        if (j == n - 2 - i or j == n - (k - i * (i + 1) / 2))
          cout << "b";
        else
          cout << "a";
      }
    } else {
      for (int j = 0; j < n - 2; j++) cout << "a";
      cout << "bb";
    }
    cout << '\n';
  }
  return 0;
}