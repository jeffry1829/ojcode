#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a;
  cin >> n >> m >> a;
  int x, y;
  x = ceil((double)n / (double)a), y = ceil((double)m / (double)a);
  cout << 1ll * x * y << '\n';
  return 0;
}