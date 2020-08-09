#include <bits/stdc++.h>
using namespace std;
int y;
bool vis[10];
inline bool chk(int t) {
  memset(vis, 0, sizeof(vis));
  int m = 10, x;
  while ((x = ((t % m) - t % (m / 10)) / (m / 10)), t % m != t) {
    if (vis[x]) return 0;
    vis[x] = 1;
    m *= 10;
  }
  x = ((t % m) - t % (m / 10)) / (m / 10);
  if (vis[x]) return 0;
  return 1;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> y;
  y++;
  while (!chk(y)) y++;
  cout << y << '\n';
  return 0;
}