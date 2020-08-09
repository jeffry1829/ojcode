#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <cstdio>
inline bool gin(unsigned int &x) {
  register char c;
  while (c = getchar(), c < '0' || c > '9')
    return 0;
  x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
  return 1;
}
main() {
  register unsigned int n;
  while (gin(n)) {
    n = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
    printf("%d\n", ((n + (n >> 3)) & 030707070707) % 63);
  }
  return 0;
}