#include <bits/stdc++.h>
using namespace std;
int n, res = 1;
char s[5], _prev[5], *t;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> _prev;
  strncpy(s, _prev, 2);
  s[3] = '\0';
  for (int i = 1; i < n; i++) {
    cin >> s;
    if (strcmp(s, _prev) != 0) res++;
    swap(s, _prev);
  }
  cout << res << '\n';
  return 0;
}