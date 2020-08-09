#include <bits/stdc++.h>
using namespace std;
int n, a[110], maxx = -0x7f7f7f7f, sum = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], maxx = max(maxx, a[i]);
  for (int i = 0; i < n; i++) sum += maxx - a[i];
  cout << sum << '\n';
  return 0;
}