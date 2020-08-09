#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7, _N = 1e6 + 10, _K = 1e9 + 10, p = 29;
int N, K;
char S[_N];
int fT[_N], pnM[_N];
inline int expmod(int x, int toexp) {
  int tmp = x, res = 1;
  for (; toexp > 0; toexp >>= 1) {
    if (toexp & 1) {
      res = (res * 1ll * tmp) % M;
    }
    tmp = (tmp * 1ll * tmp) % M;
  }
  return res;
}
inline int expmodsum(int x, int toexp) {
  int res = 1;
  int sum = res;
  for (int i = 1; i <= toexp; i++) {
    res = (res * 1ll * x) % M;
    sum += res;
    sum %= M;
  }
  return sum;
}
inline void genpnM() {
  int res = 1;
  pnM[0] = 1;
  for (int i = 1; i < N + 1; i++) {
    res = pnM[i] = (res * 1ll * p) % M;
  }
}
inline void prehash(char s[], int table[]) {
  int tmp = s[0];
  table[0] = tmp;
  for (int i = 1; i < N; i++) {
    tmp = table[i] = (tmp * 1ll * p * 1ll + s[i] * 1ll) % M;
  }
}
inline int lrhash(int table[], int l, int r) {
  if (l == 0) return table[r - 1];
  int tmp = table[r - 1] * 1ll - (pnM[r - l] * 1ll * table[l - 1] * 1ll) % M;
  if (tmp < 0) tmp += M;
  return tmp;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> K >> S;
  prehash(S, fT);
  genpnM();
  int _count = 0;
  if (K < 2 * N) {
    for (int i = 0; i < K - N + 1; i++) {
      if (lrhash(fT, i, N) == lrhash(fT, 0, N - i)) {
        _count++;
      }
    }
    cout << _count % M << '\n';
  } else {
    for (int i = 0; i < N; i++) {
      if (lrhash(fT, i, N) == lrhash(fT, 0, N - i)) {
        _count++;
      }
    }
    //if (K < 1e7)
    //  cout << (_count % M + expmodsum(26, K - 2 * N)) % M << '\n';
    //else
    cout << ((_count % M) * 1ll + expmod(25, M - 2) * 1ll * ((expmod(26, K - 2 * N + 1) * 1ll - 1ll) % M)) % M << '\n';
  }
  return 0;
}