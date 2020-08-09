#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 1e5 + 10;
int n, s[_n];
ll a = 0, b = 0, c = 0, t;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    a += t;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> t;
    b += t;
  }
  for (int i = 0; i < n - 2; i++) {
    cin >> t;
    c += t;
  }
  cout << a - b << '\n'
       << b - c << '\n';
  return 0;
}