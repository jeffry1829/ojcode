#include <bits/stdc++.h>
using namespace std;
const int _N = 5e5 + 10, p = 29, M = 1e9 + 7;
char s[_N], t[_N];
int s_c[2], t_c[2], slen = 0, tlen = 0, pnM[_N], A[_N], B[_N];
inline void genpnM(int len) {
  pnM[0] = 1;
  int tmp = pnM[0];
  for (int i = 1; i <= len; i++) tmp = pnM[i] = (tmp * 1ll * p) % M;
}
inline void _hash(char s[], int hs[], int len) {
  hs[0] = 0;
  hs[1] = s[0] % M;
  for (int i = 2; i <= len; i++) hs[i] = (hs[i - 1] * 1ll * p + s[i - 1] * 1ll) % M;
}
inline int hashlr(int hs[], int l, int r) {
  int res = hs[r] - pnM[r - l] * 1ll * hs[l] % M;
  if (res < 0) res += M;
  return res;
}
main(void) {
  register char c;
  register int i = 0;
  while (c = getchar(), c == '0' || c == '1') {
    s_c[c - '0']++;
    s[i] = c;
    i++;
    slen++;
  }
  s[i] = '\0';
  i = 0;
  while (c = getchar(), c == '0' || c == '1') {
    t_c[c - '0']++;
    t[i] = c;
    i++;
    tlen++;
  }
  t[i] = '\0';

  if (slen < tlen) {
    printf("%s\n", s);
  } else if (slen == tlen) {
    if (s_c[0] == t_c[0])
      printf("%s\n", t);
    else
      printf("%s\n", s);
  } else {
    genpnM(tlen);
    _hash(t, B, tlen);
    int k = 1;
    for (; k < tlen; k++) {
      if (hashlr(B, 0, tlen - k) == hashlr(B, k, tlen)) break;
    }
    int zero = 0;
    int one = 0;
    for (int i = tlen - k; i < tlen; i++) {
      if (t[i] == '0')
        zero++;
      else if (t[i] == '1')
        one++;
      else
        printf("FUCK\n");
    }
    int __z, __o;
    t_c[0] == 0 ? __z = 0x7FFFFFFF : __z = s_c[0] / t_c[0];
    t_c[1] == 0 ? __o = 0x7FFFFFFF : __o = s_c[1] / t_c[1];
    if (min(__z, __o) > 0) {
      int _z, _o;
      zero == 0 ? _z = 0x7FFFFFFF : _z = (s_c[0] - t_c[0]) / zero;
      one == 0 ? _o = 0x7FFFFFFF : _o = (s_c[1] - t_c[1]) / one;
      printf("%s", t);
      int i = 0;
      for (; i < min(_z, _o); i++) {
        printf("%s", &t[tlen - k]);
      }
      for (int j = 0; j < s_c[0] - t_c[0] - i * zero; j++) printf("0");
      for (int j = 0; j < s_c[1] - t_c[1] - i * one; j++) printf("1");
      printf("\n");
    } else {
      printf("%s\n", s);
    }
  }
  return 0;
}