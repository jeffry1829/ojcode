#include <bits/stdc++.h>
using namespace std;
int n, x, maxx = -0x7f7f7f7f, minn = 0x7f7f7f7f, Imax, Imin;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > maxx) maxx = x, Imax = i;
    if (x <= minn) minn = x, Imin = i;
  }
  cout << Imax + n - 1 - Imin + (Imax > Imin ? -1 : 0) << '\n';
  return 0;
}