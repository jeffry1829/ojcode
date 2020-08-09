#include <bits/stdc++.h>
using namespace std;
int n, m;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i & 1)
        cout << "#";
      else {
        if (j == 1 and i % 4 == 0)
          cout << "#";
        else if (j == m and i % 4)
          cout << "#";
        else
          cout << ".";
      }
    }
    cout << '\n';
  }
  return 0;
}