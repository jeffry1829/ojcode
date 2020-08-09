#include <bits/stdc++.h>
using namespace std;
int n;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i & 1)
      cout << "I hate";
    else
      cout << "I love";
    if (i != n)
      cout << " that ";
    else
      cout << " it\n";
  }
  return 0;
}