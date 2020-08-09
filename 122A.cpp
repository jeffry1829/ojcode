#include <bits/stdc++.h>
using namespace std;
int n, chkls[14] = {444, 447, 474, 477, 744, 747, 774, 777, 44, 47, 74, 77, 4, 7};
string res = "NO\n";
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < 14; i++) {
    if (!(n % chkls[i])) res = "YES\n";
  }
  cout << res;
  return 0;
}