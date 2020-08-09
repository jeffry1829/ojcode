#include <bits/stdc++.h>
using namespace std;
int m, s;
vector<int> res;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> m >> s;
  if (!s or s / m > 9) {
    cout << "-1 -1\n";
    return 0;
  }
  if (s < m) {
    cout << 1;
    for (int i = 0; i < m - s; i++) cout << 0;
    for (int i = 0; i < s - 1; i++) cout << 1;
    cout << " ";
    for (int i = 0; i < s; i++) cout << 1;
    for (int i = 0; i < m - s; i++) cout << 0;
    cout << '\n';
    return 0;
  }
  while (m) {
    if (s - 9 < m - 1) {
      s -= (m - 1), m = 0;
      res.push_back(s);
      for (int i = 0; i < m - 1; i++) res.push_back(1);
    } else {
      res.push_back(9), m--, s -= 9;
    }
  }
  for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
  cout << " ";
  for (int i = 0; i < res.size(); i++) cout << res[i];
  cout << '\n';
  return 0;
}