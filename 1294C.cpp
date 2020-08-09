#include <bits/stdc++.h>
using namespace std;
int t, n, a, b, c, hf;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    hf = sqrt(n);
    a = b = c = -1;
    for (int i = 2; i <= hf; i++) {
      if (n % i == 0) {
        a = i;
        break;
      }
    }
    if (a == -1) {
      cout << "NO\n";
      continue;
    }
    hf = sqrt(n / a);
    for (int i = 2; i <= hf; i++) {
      if ((n / a) % i == 0 and i != a) {
        b = i;
        break;
      }
    }
    if (b == -1) {
      cout << "NO\n";
      continue;
    }
    if (a * b != n and n / a / b != a and n / a / b != b) {
      cout << "YES\n"
           << a << " " << b << " " << n / a / b << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}