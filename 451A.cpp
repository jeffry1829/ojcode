#include <bits/stdc++.h>
using namespace std;
int n, m, pts, role = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  pts = n * m;
  while (pts) role++, pts -= (n + m - 1), n--, m--;
  if (role & 1)
    cout << "Akshat\n";
  else
    cout << "Malvika\n";
  return 0;
}