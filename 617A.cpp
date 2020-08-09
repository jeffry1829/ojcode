#include <bits/stdc++.h>
using namespace std;
int x;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> x;
  cout << x / 5 + (x % 5 ? 1 : 0) << '\n';
  return 0;
}