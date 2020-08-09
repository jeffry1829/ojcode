#include <cstdio>
//#define getchar_unlocked getchar
#define ll long long

inline void gin(int &x) {
  register char c;
  while (c = getchar_unlocked(), c < '0' || c > '9')
    ;
  x = c - '0';
  while (c = getchar_unlocked(), c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
}
main(void) {
  register const int _N = 2e7 + 10, _size = 262144;
  register int N, tor_c = 1, s_c = 1;
  register ll sum = 0, tor = 0;
  register short s[_N];
  register char b[_size];
  gin(N);
  char _c;
  while (_c = getchar_unlocked(), _c < '0' || _c > '9')
    ;
  register int c, t = _c - '0';
  while ((c = fread_unlocked(b, 1, _size, stdin)) > 0) {
    for (register int j = 0; j < c; j++) {
      if (b[j] >= '0' && b[j] <= '9') {
        t = (t << 3) + (t << 1) + b[j] - '0';
      } else {
        s[s_c] = t;
        tor += tor_c * 1ll * s[s_c];
        tor_c++;
        sum += s[s_c];
        s_c++;

        t = 0;
      }
    }
  }
  s[0] = s[N + 1] = 0;
  register int hN = N >> 1, x;
  for (x = 0; x <= hN; x++) {
    tor += ((N + 1 - (x << 1)) * 1ll * (s[x] - s[N + 1 - x]));
    if (!(tor % sum)) goto A;
  }
A:
  printf("%d %lld\n", x, (tor / sum) - 1);
  return 0;
}