#include <bits/stdc++.h>
using namespace std;
int a[3];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  sort(a, a + 3);
  cout << a[2] - a[0] << '\n';
  return 0;
}