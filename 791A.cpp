#include <bits/stdc++.h>
using namespace std;
int a, b;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b;
  int t = 0;
  while (a <= b) {
    t++;
    a *= 3, b *= 2;
  }
  cout << t << '\n';
  return 0;
}