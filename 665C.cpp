#include <bits/stdc++.h>
using namespace std;

char chchar(char c, char right) {
  if (c == 'z') return (c - 1) == right ? c - 2 : c - 1;
  // c!='z'
  if (c + 1 == right) return (c + 1) == 'z' ? c - 1 : c + 2;
  //c!='z' and c+1!=right
  return c + 1;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char s[200001];
  cin >> s;
  int lens = strlen(s);
  for (int i = 0; i < lens - 1; i++) {
    if (i + 2 <= lens - 1) {
      if (s[i] == s[i + 1]) s[i + 1] = chchar(s[i + 1], s[i + 2]);
    } else {
      if (s[i] == s[i + 1]) s[i + 1] = chchar(s[i + 1], 'A');
    }
  }
  cout << s << '\n';
  return 0;
}