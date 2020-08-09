#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 1e5 + 10;
int n, d[_n];
ll sum;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> n && n) {
    sum = 2;
    for (int i = 0; i < n; i++) {
      cin >> d[i];
      sum += (2 * d[i] - 1);
      d[i]--;
    }
    sort(d, d + n);
    for (int i = 0; i < n - 1; i++) sum -= d[i];
    cout << sum << '\n';
  }
  return 0;
}