#include <bits/stdc++.h>
using namespace std;
string s, res;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  if (s.length() % 2) s = '0' + s;
  for (int i = 0; i < 52; i++) s = s + '0';
  int leov = 0, le = 0;
  for (int i = 0; i < s.length() / 2; i++) {
    int t = leov * 100 + stoi(s.substr(i * 2, i * 2 + 2));
    cout << t << '\n';
    for (int k = 1; k <= 10; k++) {
      if ((le * 20 + k) * k > t) {
        res = res + (char)((int)'0' + (k - 1));
        leov = t - (le * 20 + k - 1) * (k - 1);
        le = le * 10 + k - 1;
        break;
      }
    }
  }
  cout << res << '\n';
  return 0;
}