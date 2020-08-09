#include <bits/stdc++.h>
using namespace std;
string s1, s2;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s1 >> s2;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == s2[i])
      cout << "0";
    else
      cout << "1";
  }
  cout << '\n';
  return 0;
}