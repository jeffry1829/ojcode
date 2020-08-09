#include <bits/stdc++.h>
using namespace std;
int n;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n < 0) {
    n = -n;
    n = min(n, min(n / 10, (n - n % 100) / 10 + n % 10));
    n = -n;
  } else {
    n = max(n, max(n / 10, (n - n % 100) / 10 + n % 10));
  }
  cout << n << '\n';
  return 0;
}