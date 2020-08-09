#include <bits/stdc++.h>
using namespace std;
int n, p = 0, x;
main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    p += x;
  }
  printf("%lf\n", 1.0 * p / (1.0 * n));

  return 0;
}