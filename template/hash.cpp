#include <bits/stdc++.h>
using namespace std;
const int _N = 10010;  // str len
const int _p1 = 29, _M = 1000000009;
int pnM[_N] = {0};  // p^n mod M
int hp[_N] = {0};   // hash prefix
char T[_N];
int lenT;

inline void genpnM() {
  int res = 1;  //p^0%M
  pnM[0] = 1;
  for (int i = 1; i < _N; i++) pnM[i] = res = (res * 1ll * _p1) % _M;
}
inline void genhp() {  //hp[n]=hash prefix[0,n)
  int res = 0;
  hp[0] = 0;  //[0,0) is empty string
  for (int i = 1; i <= lenT; i++) hp[i] = res = (res * 1ll * _p1 + T[i - 1] * 1ll) % _M;
}
inline int dhash(char s[]) {  //direct hash
  int len = strlen(s);
  int res = 0;
  for (int i = 1; i <= len; i++) res = (res * 1ll * _p1 + s[i - 1] * 1ll) % _M;
  return res;
}
inline int hashlr(int l, int r) {  //[l,r)
  int tmp = hp[r] * 1ll - pnM[r - l] * 1ll * hp[l] % _M;
  if (tmp < 0) tmp += _M;
  return tmp;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  return 0;
}