#include <bits/stdc++.h>
using namespace std;
int n, len;
char str[110];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  while (n--) {
    cin >> str;
    len = strlen(str);
    if (len > 10) {
      cout << str[0] << len - 2 << str[len - 1] << '\n';
      continue;
    }
    cout << str << '\n';
  }
  return 0;
}