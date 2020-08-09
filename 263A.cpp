#include <bits/stdc++.h>
using namespace std;
int x, y, t;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> t;
      if (t) x = i, y = j;
    }
  }
  cout << abs(3 - x) + abs(3 - y) << '\n';
  return 0;
}