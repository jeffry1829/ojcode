#include <bits/stdc++.h>
using namespace std;
string s;
int dis = 0;
bool vis[26];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (vis[s[i] - 'a']) continue;
    vis[s[i] - 'a'] = 1, dis++;
  }
  if (dis & 1)
    cout << "IGNORE HIM!\n";
  else
    cout << "CHAT WITH HER!\n";
  return 0;
}