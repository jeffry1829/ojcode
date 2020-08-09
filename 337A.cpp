#include <bits/stdc++.h>
using namespace std;
int f[1010], n, m;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> f[i];
  sort(f, f + m);
  int minn = 0x7f7f7f7f;
  for (int j = 0; j < m - n + 1; j++) {
    minn = min(minn, abs(f[j + n - 1] - f[j]));
  }
  cout << minn << '\n';
  return 0;
}