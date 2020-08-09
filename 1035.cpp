#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
using namespace std;
string a, b;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b;
  int gmax = 0;
  for (int i = 0; i < a.length() - gmax; i++) {
    int sum = 0, l = MIN(a.length() - i, b.length());
    for (int j = 0; j < l; j++)
      if (a[i + j] == b[j]) sum++;
    gmax = MAX(gmax, sum);
  }
  for (int i = 0; i < b.length() - gmax; i++) {
    int sum = 0, l = MIN(a.length() - i, b.length());
    for (int j = 0; j < l; j++)
      if (b[i + j] == a[j]) sum++;
    gmax = MAX(gmax, sum);
  }
  cout << gmax << '\n';
  return 0;
}