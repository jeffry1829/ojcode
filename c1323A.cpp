#include <bits/stdc++.h>
using namespace std;
int t, n, a[110];
vector<int> res;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    res.clear();
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1 and (a[0] & 1)) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (!(a[i] & 1)) {
        cout << "1\n"
             << i + 1 << '\n';
        break;
      } else {
        if (res.size() == 0)
          res.push_back(i + 1);
        else {
          res.push_back(i + 1);
          cout << "2\n"
               << res[0] << " " << res[1] << '\n';
          break;
        }
      }
    }
  }
  return 0;
}