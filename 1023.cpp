#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _M = 5e4 + 10;
int m, r[_M], b[_M];
ll gmax;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> m) {
    gmax = 0;
    for (int i = 0; i < m; i++) cin >> r[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(r, r + m);
    sort(b, b + m);
    for (int i = 0; i < m; i++) gmax += r[i] * b[i];
    cout << gmax << '\n';
  }
  return 0;
}