#include <bits/stdc++.h>
using namespace std;
int r[200], n;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    r[s[i]]++;
  }
  if (r['A'] > r['D']) cout << "Anton\n";
  if (r['A'] == r['D']) cout << "Friendship\n";
  if (r['A'] < r['D']) cout << "Danik\n";
  return 0;
}