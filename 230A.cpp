#include <bits/stdc++.h>
using namespace std;
const int _n = 1e4 + 10;
struct P {
  int st, bo;
  bool operator<(const P& rhs) const { return st < rhs.st; }
} x[_n];
int s, n, a, b;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    x[i] = {a, b};
  }
  sort(x, x + n);
  for (int i = 0; i < n; i++) {
    if (x[i].st >= s) {
      cout << "NO\n";
      return 0;
    }
    s += x[i].bo;
  }
  cout << "YES\n";
  return 0;
}