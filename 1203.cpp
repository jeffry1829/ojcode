#pragma GCC optimize("Ofast")
#include <stdio.h>
#define ll long long
ll N, K, M;
inline bool gin(ll &x) {
  register char c;
  while (c = getchar_unlocked(), c < '0' || c > '9')
    if (c == -1) return 0;
  x = c - '0';
  while (c = getchar_unlocked(), c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
  return 1;
}
main(void) {
A:
  while (gin(N), gin(K), gin(M) && N + K + M) {
    if (K == 1) {
      printf("%lld\n", N - M);
      goto A;
    }
    register ll j = N - M - 1;
    for (j = j * K + K - 1; j >= N; j = j - N + (j - N) / (K - 1))
      ;
    printf("%lld\n", j + 1);
  }
  return 0;
}