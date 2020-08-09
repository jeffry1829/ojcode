#include <bits/stdc++.h>
using namespace std;
const int _n = 1e7 + 10;
int a[110], sum, n;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (1) {
    sum = 0, n = -1;
    for (int i = 0; i < 110; i++) {
      cin >> a[i];
      n++;
      sum += a[i];
      if (!a[i]) break;
    }
    if (!a[0]) exit(0);
    for (int i = 0; i < n; i++) {
      int l = __builtin_clz(a[i]);
      sum -= (a[i] ^ (1 << (31 - l)));
    }
    cout << sum << '\n';
  }
  return 0;
}