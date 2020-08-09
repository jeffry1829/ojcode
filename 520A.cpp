#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
string s;
bool vis[200];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] < 'a') s[i] = s[i] - 'A' + 'a';
    if (!vis[s[i]]) cnt++, vis[s[i]] = 1;
  }
  if (cnt == 26)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}