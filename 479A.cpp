#include <bits/stdc++.h>
using namespace std;
int a, b, c, t, g;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c;
  t = max(a * b, a + b);
  t = max(t * c, t + c);
  g = max(b * c, b + c);
  g = max(a * g, a + g);
  t = max(t, g);
  cout << t << '\n';
  return 0;
}