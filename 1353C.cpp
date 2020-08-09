#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ll hf = (n >> 1);
    cout << 8ll * (hf * (hf + 1ll) * ((hf << 1) + 1)) / 6ll << '\n';
  }
  return 0;
}