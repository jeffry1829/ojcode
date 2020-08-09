#include <bits/stdc++.h>
using namespace std;
int G[9][9], nine[10], times = 0;
inline bool chk(int x, int y, int c) {
  memset(nine, 0, sizeof(nine));
  nine[c] += 1;
  for (int i = 0; i < 9; i++) nine[G[i][y]]++;
  for (int i = 1; i <= 9; i++)
    if (nine[i] > 1) return 0;
  memset(nine, 0, sizeof(nine));
  nine[c] += 1;
  for (int i = 0; i < 9; i++) nine[G[x][i]]++;
  for (int i = 1; i <= 9; i++)
    if (nine[i] > 1) return 0;
  memset(nine, 0, sizeof(nine));
  nine[c] += 1;
  for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
    for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++) nine[G[i][j]]++;
  for (int i = 1; i <= 9; i++)
    if (nine[i] > 1) return 0;
  return 1;
}
void f(int x, int y) {
  if (x == 9 && y == 0) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) cout << G[i][j] << ' ';
      cout << '\n';
    }
    cout << '\n';
    times++;
    return;
  }
  int _x = x, _y = y + 1;
  _x += _y / 9;
  _y = _y % 9;
  if (!G[x][y]) {
    for (int k = 1; k <= 9; k++) {
      if (chk(x, y, k)) {
        G[x][y] = k;
        f(_x, _y);
      } else {
        if (k == 9) {
          G[x][y] = 0;
        } else
          continue;
      }
      G[x][y] = 0;
    }
  } else
    f(_x, _y);
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) cin >> G[i][j];
  f(0, 0);
  cout << "there are a total of " << times << " solution(s).\n";
  return 0;
}