#include <bits/stdc++.h>
using namespace std;
int f(int n, int m) {
  if (n == m) return 0;
  if (n > m) return n - m;
  if (m & 1) return f(n, m + 1) + 1;
  if (!(m & 1)) return f(n, m >> 1) + 1;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  cout << f(n, m) << '\n';
  return 0;
}