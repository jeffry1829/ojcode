#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int _N = 1e5 + 10;
int wa[_N], wb[_N], wv[_N], _ws_[_N], sa[_N], n, m;
char s[_N];
inline bool cmp(int *r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}
void da() {
  int i, j, p, *x = wa, *y = wb, *t;
  for (i = 0; i < m; i++) _ws_[i] = 0;
  for (i = 0; i < n; i++) _ws_[x[i] = s[i]]++;
  for (i = 1; i < m; i++) _ws_[i] += _ws_[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--_ws_[x[i]]] = i;
  for (j = 1, p = 1; p < n; j *= 2, m = p) {
    for (i = n - j, p = 0; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) _ws_[i] = 0;
    for (i = 0; i < n; i++) _ws_[wv[i]]++;
    for (i = 1; i < m; i++) _ws_[i] += _ws_[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--_ws_[wv[i]]] = y[i];
    for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
}
main(void) {
  // cin.tie(0);
  // ios_base::sync_with_stdio(0);
  // cin >> s;
  gets(s);
  n = strlen(s);
  s[n] = 0;
  n++;
  m = 129;
  da();
  for (int i = 1; i < n; i++) cout << sa[i] << '\n';
}