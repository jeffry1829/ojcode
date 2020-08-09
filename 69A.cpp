#include <bits/stdc++.h>
using namespace std;
int x, y, z, n, X = 0, Y = 0, Z = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    X += x, Y += y, Z += z;
  }
  if (!X and !Y and !Z)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}