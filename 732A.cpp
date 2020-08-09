#include <bits/stdc++.h>
using namespace std;
int k, r;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> k >> r;
  for (int i = 1; i <= 10; i++) {
    if ((i * k - r) % 10 == 0 or (i * k) % 10 == 0) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}