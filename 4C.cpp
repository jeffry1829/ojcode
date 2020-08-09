#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string, int> vis;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (!vis.count(s)) {
      cout << "OK\n";
      vis[s] = 1;
    } else {
      cout << s << vis[s] << '\n';
      vis[s]++;
    }
  }
  return 0;
}