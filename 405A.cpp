#include <bits/stdc++.h>
using namespace std;
int n, a[110];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << '\n';
  return 0;
}