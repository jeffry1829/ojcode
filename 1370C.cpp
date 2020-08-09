#include <bits/stdc++.h>
using namespace std;
int t, n, k, m;
inline void f() {
  int nn = n;
  k = 0;
  while (((nn >> 1) << 1) == nn) k++, nn >>= 1;
  m = n / (1 << k);
}
inline bool p() {
  int hf = sqrt(m);
  for (int i = 2; i <= hf; i++) {
    if (m % i == 0) return false;
  }
  return true;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    f();
    if (n != 1 and (n == 2 or (n & 1) or (k >= 2 and m != 1) or (k == 1 and m != 1 and !p())))
      cout << "Ashishgup\n";
    else
      cout << "FastestFinger\n";
  }
  return 0;
}