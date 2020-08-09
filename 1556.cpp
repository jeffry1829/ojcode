#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll N, ans = 0, u;
  cin >> N;
  u = sqrt(N);
  for (int i = 1; i <= u; i++) ans += (N / i);
  ans <<= 1, ans -= u * u, ans -= N;
  cout << ans << '\n';
  return 0;
}