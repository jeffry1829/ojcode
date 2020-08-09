#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (!(n & 1)) {
    cout << n / 2 << '\n';
  } else {
    cout << n / 2 - n << '\n';
  }
  return 0;
}