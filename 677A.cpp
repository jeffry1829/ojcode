#include <bits/stdc++.h>
using namespace std;
int n, h, x, res = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > h) res++;
    res++;
  }
  cout << res << '\n';
  return 0;
}