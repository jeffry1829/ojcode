#include <bits/stdc++.h>
using namespace std;
int a, b, res = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b;
  if (a < b) swap(a, b);
  cout << b << " ", a -= b, cout << a / 2 << '\n';
  return 0;
}