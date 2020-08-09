#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char str[1000];
  while (cin.getline(str, 1000)) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
      str[i] = str[i] - 7;
    }
    cout << str << '\n';
  }
  return 0;
}