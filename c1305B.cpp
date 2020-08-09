#include <bits/stdc++.h>
using namespace std;
string s;
bool vis[1010];
int k = 0;
vector<int> res[510];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  while (1) {
    int x = 0, y = s.length() - 1;
    while (x < y) {
      if (vis[x] or s[x] != '(') {
        x++;
        continue;
      }
      if (vis[y] or s[y] != ')') {
        y--;
        continue;
      }
      if (s[x] == '(' and s[y] == ')') {
        res[k].push_back(x + 1), res[k].push_back(y + 1);
        vis[x] = 1, vis[y] = 1, x++, y--;
        continue;
      }
    }
    if (!res[k].size()) break;
    k++, sort(res[k - 1].begin(), res[k - 1].end());
  }
  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    cout << res[i].size() << '\n';
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}