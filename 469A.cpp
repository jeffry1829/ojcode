#include <bits/stdc++.h>
using namespace std;
int n, p, x, y = 2;
bool vis[110];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  while (y--) {
    cin >> p;
    for (int i = 0; i < p; i++) {
      cin >> x;
      vis[x] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << "Oh, my keyboard!\n";
      return 0;
    }
  }
  cout << "I become the guy.\n";
  return 0;
}