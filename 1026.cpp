#include <bits/stdc++.h>
using namespace std;
unsigned int _d;
int d, k;
string res = "";
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> _d;
  k = 1 << (32 - __builtin_clz(_d));
  d = (int)_d;
  while (d) {
    k /= 2;
    if (d > 0) {
      res = '+' + res;
      d -= k;
    } else {
      res = '-' + res;
      d += k;
    }
  }
  cout << res.length() << '\n';
  cout << res;
  cout << '\n';
  return 0;
}