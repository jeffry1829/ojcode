#include <bits/stdc++.h>
using namespace std;
inline bool gin(int &x) {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == -1) return 0;
  x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  return 1;
}