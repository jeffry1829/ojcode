#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int _N = 10010;
const ULL _p1 = 29, _M = 1000000009;
ULL pnM[_N] = {0};  // p^n mod M
ULL hp[_N] = {0};   // hash prefix
char T[_N];
int N, lenT;

inline void genpnM() {
  ULL res = 1;  //p^0%M
  pnM[0] = 1;
  for (int i = 1; i < _N; i++) pnM[i] = res = (res * _p1) % _M;
}
inline void genhp() {  //hp[n]=hash prefix[0,n)
  ULL res = 0;
  hp[0] = 0;  //[0,0) is empty string
  for (int i = 1; i <= lenT; i++) hp[i] = res = (res * _p1 + T[i - 1]) % _M;
}
inline ULL dhash(char s[]) {  //direct hash
  int len = strlen(s);
  ULL res = 0;
  for (int i = 1; i <= len; i++) res = (res * _p1 + s[i - 1]) % _M;
  return res;
}
inline ULL hashlr(int l, int r) {  //[l,r)
  long long tmp = hp[r] - pnM[r - l] * hp[l] % _M;
  if (tmp < 0) tmp += _M;
  return tmp;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  genpnM();
  int K;
  cin >> K;
  while (K--) {
    cin >> T;
    lenT = strlen(T);
    genhp();
    int Q;
    cin >> Q;
    while (Q--) {
      char Qi[_N];
      cin >> Qi;
      ULL hashQi = dhash(Qi);
      int lenQi = strlen(Qi);
      int start = 0;
      int count = 0;
      while (start + lenQi <= lenT) {
        if (hashQi == hashlr(start, start + lenQi)) count++;
        start++;
      }
      cout << count << '\n';
    }
  }

  return 0;
}