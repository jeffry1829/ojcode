#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define abs(x) (((x) > 0) ? (x) : (-(x)))
using namespace std;
const int _rc = 300;
int r, c, ans[_rc], rc2;
int p[_rc][8];
bool over = 0, pl[_rc];
inline void f(int x) {
  if (!ans[x]) {
    f(x + 1);
    return;
  }
  for (int i = c + 4; i < rc2 - (c + 3); i++) {
    if (pl[i]) continue;
    for (int j = 0; j < 4; j++) {
      // cout << (char)p[i][j] << (char)p[x - 1][ans[x - 1] % 1000] << " "
      //     << (char)p[i][(j + 1) % 4]
      //     << (char)p[x - (c + 2)][(ans[x - (c + 2)] % 1000 + 1) % 4] << '\n';
      if ((abs(p[i][j] - p[x - 1][ans[x - 1] % 1000]) == 32 ||
           (p[i][j] == p[x - 1][ans[x - 1] % 1000] && p[i][j] == '-')) &&
          (abs(p[i][(j + 1) % 4] -
               p[x - (c + 2)][(ans[x - (c + 2)] % 1000 + 1) % 4]) == 32 ||
           (p[i][(j + 1) % 4] ==
                p[x - (c + 2)][(ans[x - (c + 2)] % 1000 + 1) % 4] &&
            p[i][(j + 1) % 4] == '-'))) {
        // cout << " in!\n";
        ans[x] = 1000 * i + ((j + 2) % 4), pl[i] = 1;
        if (x == rc2 - (c + 4)) {
          over = 1;
          for (int l = 1; l <= r; l++) {
            for (int h = 1; h <= c; h++) {
              if (!ans[l * (c + 2) + h]) continue;
              cout << p[(ans[l * (c + 2) + h]) / 1000]
                       [4 + (((ans[l * (c + 2) + h] % 1000) - 2 + 4) % 4)];
            }
            cout << '\n';
          }
        }
        if (over) return;
        f(x + 1);
        if (over) return;
        pl[i] = 0, ans[x] = -1;
      }
    }
  }
}
int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> r >> c && r && c) {
    memset(ans, 0, sizeof(ans));
    over = 0;
    rc2 = (r + 2) * (c + 2);
    for (int i = 0; i <= r + 1; i++)
      for (int j = 0; j <= c + 1; j++)
        for (int k = 0; k < 8; k++)
          p[i * (c + 2) + j][k] = '-', pl[i * (c + 2) + j] = 1;
    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++) {
        for (int k = 0; k < 8; k++) p[i * (c + 2) + j][k] = (int)getchar();
        ans[i * (c + 2) + j] = -1, getchar(), pl[i * (c + 2) + j] = 0;
      }
    ans[c + 3] = (c + 3) * 1000 + 2, pl[c + 3] = 1, f(c + 4);
    cout << '\n';
  }
  return 0;
}