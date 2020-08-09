#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  while (n) {
    n--, cnt++;
    if (cnt % m == 0) n++;
  }
  cout << cnt << '\n';
  return 0;
}