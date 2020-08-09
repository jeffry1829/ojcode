#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int w;
  cin >> w;
  string res = "NO";
  if (!(w & 1)) res = "YES";
  if (w <= 2) res = "NO";
  cout << res;
  return 0;
}