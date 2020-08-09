#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 5e5 + 10;
ll n, a[_n], aa[_n], cnt[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    aa[i] = (i == 0 ? 0 : aa[i - 1]) + a[i];
  }
  ll h = sum / 3;
  if (h * 3 != sum) {
    cout << "0\n";
    return 0;
  }
  cnt[n] = 0;
  for (int i = n - 1; i >= 1; i--) {
    cnt[i] = cnt[i + 1] + (aa[n - 1] - aa[i - 1] == h ? 1 : 0);
  }
  ll ans = 0;
  for (int i = 0; i < n - 2; i++) {
    if (aa[i] == h) {
      ans += cnt[i + 2];
    }
  }
  cout << ans << '\n';
  return 0;
}