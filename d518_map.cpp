#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int N, counter = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> N) {
    mp.clear();
    counter = 0;
    while (N--) {
      string s;
      cin >> s;
      if (mp.count(s) == 0) {
        mp[s] = ++counter;
        cout << "New! " << mp[s] << '\n';
      } else {
        cout << "Old! " << mp[s] << '\n';
      }
    }
  }
  return 0;
}