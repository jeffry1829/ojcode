#include <bits/stdc++.h>
using namespace std;
const int _n = 3e4 + 10;
int n, t, x;
vector<int> a[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> t;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x;
    a[i].push_back(i + x);
  }
  int i = 1;
  while (1) {
    i = a[i][0];
    if (i == t) {
      cout << "YES\n";
      return 0;
    }
    if (i == n) {
      cout << "NO\n";
      return 0;
    }
  }

  return 0;
}