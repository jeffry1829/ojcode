#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> a >> b;
  if (m * a < b) {
    cout << n * a << '\n';
    return 0;
  }
  cout << b * (n / m) + min(b, a * (n % m)) << '\n';
  return 0;
}