#include <bits/stdc++.h>
using namespace std;
int n, x, sum = 0, a[110], t = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n, greater<int>());
  int i;
  for (i = 0; i < n; i++) {
    t += a[i];
    if (t > sum / 2) break;
  }
  cout << i + 1 << '\n';
  return 0;
}