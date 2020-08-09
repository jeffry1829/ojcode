#include <bits/stdc++.h>
using namespace std;
int n, k;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  while (k--) {
    if (n % 10)
      n--;
    else {
      n /= 10;
    }
  }
  cout << n << '\n';
  return 0;
}