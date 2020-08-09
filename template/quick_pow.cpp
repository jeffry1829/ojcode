#include <bits/stdc++.h>
using namespace std;
int qPow(int a, int b, int m) {
  int r = 1;
  while (b) {
    if (b & 1) r = (r * a) % m;
    b >>= 1;
    a = (a * a) % m;
  }
  return r % m;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  return 0;
}