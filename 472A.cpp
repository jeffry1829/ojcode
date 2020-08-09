#include <bits/stdc++.h>
using namespace std;
int n;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n & 1)
    cout << "9 " << n - 9 << '\n';
  else
    cout << "4 " << n - 4 << '\n';
  return 0;
}