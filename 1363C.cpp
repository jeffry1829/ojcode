#include <bits/stdc++.h>
using namespace std;
int t, n, x, u, v;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> x;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      if (u == x or v == x) cnt++;
    }
    if (cnt < 2)
      cout << "Ayush\n";
    else {
      n -= 3;
      cout << ((n & 1) ? "Ayush\n" : "Ashish\n");
    }
  }
  return 0;
}