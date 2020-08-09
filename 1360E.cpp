#include <bits/stdc++.h>
#define in lkdsfpsjg
using namespace std;
int t, n, m[60][60];
char c;
void in(int &x) {
  x = c - '0';
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin.get(c);
        in(m[i][j]);
      }
      cin.get();
    }
    for (int i = 0; i <= n; i++) m[n][i] = 1;
    for (int i = 0; i <= n; i++) m[i][n] = 1;
    bool flag = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (m[i][j] == 1 and !(m[i][j + 1] == 1 or m[i + 1][j] == 1)) flag = 0;
      }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}