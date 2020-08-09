#include <bits/stdc++.h>
using namespace std;
int n, x = 0;
char s[10];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[0] == '+' or s[2] == '+') x++;
    if (s[0] == '-' or s[2] == '-') x--;
  }
  cout << x << '\n';
  return 0;
}