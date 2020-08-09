#include <bits/stdc++.h>
#define ULL int
using namespace std;
const int _N = 1000010 * 2;  // str len
const ULL _p1 = 29, _M = 1000000009;
ULL pnM[_N] = {0};  // p^n mod M
ULL hp1[_N] = {0};  // hash prefix
ULL hp2[_N] = {0};
char dupT[_N], revdupT[_N], tmp[_N / 2];
char TT[_N];
int lenT, lendupT, half;
vector<int> answer;

inline void gendupT() {
  strcpy(tmp, dupT);
  strcat(dupT, tmp);
}
inline void genrevdupT() {
  for (int i = 0; i < lendupT; i++) revdupT[lendupT - i - 1] = dupT[i];
}
inline void genpnM() {
  ULL res = 1;  //p^0%M
  pnM[0] = 1;
  for (int i = 1; i < _N; i++) pnM[i] = res = (res * 1ll * _p1) % _M;
}
inline void genhp1() {  //hp[n]=hash prefix[0,n]
  ULL res = 0;
  hp1[0] = 0;
  for (int i = 1; i <= lendupT; i++) hp1[i] = res = (res * 1ll * _p1 + dupT[i - 1]) % _M;
}
inline ULL hashlr1(int l, int r) {  //[l,r)
  long long tmp = hp1[r] * 1ll - pnM[r - l] * 1ll * hp1[l] % _M;
  if (tmp < 0) tmp += _M;  //(a - b) mod p = ((a mod p - b mod p) + p) mod p
  return tmp;
}
inline void genhp2() {  //hp[n]=hash prefix[0,n]
  ULL res = 0;
  hp2[0] = 0;
  for (int i = 1; i <= lendupT; i++) hp2[i] = res = (res * 1ll * _p1 + revdupT[i - 1] * 1ll) % _M;
}
inline ULL hashlr2(int l, int r) {  //[l,r)
  int tmp = hp2[r] * 1ll - pnM[r - l] * 1ll * hp2[l] % _M;
  if (tmp < 0) tmp += _M;  //(a - b) mod p = ((a mod p - b mod p) + p) mod p
  return tmp;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> dupT;
  lenT = strlen(dupT);
  gendupT();
  lendupT = strlen(dupT);
  genrevdupT();
  genpnM();
  genhp1();
  genhp2();
  half = lenT % 2 ? (lenT - 1) / 2 : lenT / 2;
  for (int k = 0; k < lenT; k++)
    if (hashlr1(k, k + half) == hashlr2(lenT - k, lenT - k + half))
      answer.push_back(k);
  if (answer.size() != 0) {
    cout << answer.size() << ":";
    for (int i = 0; i < answer.size(); i++) {
      cout << " " << answer[i];
    }
    cout << '\n';
  } else {
    cout << "none\n";
  }
  return 0;
}