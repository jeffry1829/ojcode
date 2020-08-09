#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 3e5 + 10;
int t, n;
ll a, b;
pair<ll, ll> s[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    int minn = 0;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      s[i] = {a, b};
    }
    for (int i = 1; i < n; i++) {
      int prev1 = (i - 1 == -1 ? n - 1 : i - 1);
      int prev2 = (minn - 1 == -1 ? n - 1 : minn - 1);
      if (s[i].first - max(0ll, s[i].first - s[prev1].second) <
          s[minn].first - max(0ll, s[minn].first - s[prev2].second))
        minn = i;
    }
    ll sum = 0;
    for (int i = minn; i < n + minn; i++) {
      sum += s[i % n].first, s[(i + 1) % n].first -= s[i % n].second;
      if (s[(i + 1) % n].first < 0) s[(i + 1) % n].first = 0;
    }
    cout << sum << '\n';
  }
  return 0;
}