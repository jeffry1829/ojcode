// https://codeforces.com/blog/entry/60445
using ull = unsigned long long;
static const int _N = 3e4 + 10;  // str len
static const int base = 1e9 + 7, _M = 1e9 + 123;
static const int MAXB = 16;
int pn1[_N] = {0};  // p^n mod M
ull pn2[_N] = {0};  // p^n mod 2^64
int hp1[_N] = {0};  // hash prefix
ull hp2[_N] = {0};  // hash prefix mod 2^64
string T;
int lenT;

inline void genpnM() {
  pn1[0] = 1;
  pn2[0] = 1;
  for (int i = 1; i < _N; i++) {
    pn1[i] = (1ll * pn1[i - 1] * base) % _M;
    pn2[i] = pn2[i - 1] * base;
  }
}
inline void genhp() {  // hp[n]=hash prefix[0,n)
  hp1[0] = 0;          //[0,0) is empty string
  hp2[0] = 0;          //[0,0) is empty string
  for (int i = 1; i <= lenT; i++) {
    hp1[i] = (1ll * hp1[i - 1] * base + 1ll * T[i - 1]) % _M;
    hp2[i] = hp2[i - 1] * base + 1ll * T[i - 1];
  }
}
inline int dhash(string s) {  // direct hash // not usable after 2^64 version
  int len = lenT;
  int res = 0;
  for (int i = 1; i <= len; i++)
    res = (res * 1ll * base + s[i - 1] * 1ll) % _M;
  return res;
}
inline pair<int, ull> hashlr(int l, int r) {  //[l,r)
  int tmp1 = hp1[r] * 1ll - pn1[r - l] * 1ll * hp1[l] % _M;
  ull tmp2 = hp2[r] - pn2[r - l] * hp2[l];
  if (tmp1 < 0) tmp1 += _M;
  return {tmp1, tmp2};
}

// 下面是只有一個的版本
#include <bits/stdc++.h>
using namespace std;
const int _N = 10010;  // str len
const int _p1 = 97, _M = 1000000009;
int pnM[_N] = {0};  // p^n mod M
int hp[_N] = {0};   // hash prefix
char T[_N];
int lenT;

inline void genpnM() {
  int res = 1;  // p^0%M
  pnM[0] = 1;
  for (int i = 1; i < _N; i++) pnM[i] = res = (res * 1ll * _p1) % _M;
}
inline void genhp() {  // hp[n]=hash prefix[0,n)
  int res = 0;
  hp[0] = 0;  //[0,0) is empty string
  for (int i = 1; i <= lenT; i++) hp[i] = res = (res * 1ll * _p1 + T[i - 1] * 1ll) % _M;
}
inline int dhash(char s[]) {  // direct hash
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