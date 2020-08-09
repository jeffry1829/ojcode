#include <bits/stdc++.h>
using namespace std;
string A, B;
int res_os[(int)3e6 + 10];
inline void eqL(string &a, string &b) {
  int alen = a.size(), blen = b.size();
  if (a.size() > b.size())
    for (int i = 0; i < alen - blen; i++) b = '0' + b;
  if (a.size() < b.size())
    for (int i = 0; i < blen - alen; i++) a = '0' + a;
  if (a.size() % 2 != 0) a = '0' + a, b = '0' + b;
}
inline string _add(string &a, string &b) {
  string sum;
  int next = 0, res;
  eqL(a, b);
  for (int i = a.size() - 1; i >= 0; i--) {
    res = a[i] + b[i] + next - '0' - '0';
    next = res / 10;
    sum = to_string(res % 10) + sum;
  }
  if (next) sum = '1' + sum;
  return sum;
}
inline string _sub(string &a, string &b) {  //a-b
  string sum;
  int next = 0;
  eqL(a, b);
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] - next < b[i]) {
      sum = to_string(a[i] - next - b[i] + 10) + sum;
      next = 1;
    } else {
      sum = to_string(a[i] - next - b[i]) + sum;
      next = 0;
    }
  }
  return sum;
}
inline void _exp(string &a, int e) {  //directly change a
  for (int i = 0; i < e; i++) a = a + '0';
}
inline void trim(string &a) {  //directly change a
  while (a[0] == '0') a.erase(0, 1);
  if (a.size() == 0) a = '0';
}
inline string carry(int len) {
  for (int i = 0; i < 2 * len; i++) {
    if (res_os[i] >= 10) {
      res_os[i + 1] += res_os[i] / 10;
      res_os[i] = res_os[i] % 10;
    }
  }
  string res;
  for (int i = 0; i < 2 * len; i++) res = to_string(res_os[i]) + res;
  trim(res);
  return res;
}
inline string oldschool(string &a, string &b) {
  eqL(a, b);
  memset(res_os, 0, sizeof(res_os));
  for (int i = a.size() - 1; i >= 0; i--)
    for (int j = b.size() - 1; j >= 0; j--)
      res_os[a.size() - 1 - i + b.size() - 1 - j] += (a[i] - '0') * (b[j] - '0');
  return carry(a.size());
}
inline string karatsuba(string &a, string &b) {
  trim(a), trim(b);
  if (a.size() <= 256 && b.size() <= 256) return oldschool(a, b);
  eqL(a, b);
  string f1 = a.substr(0, a.size() / 2), f2 = a.substr(a.size() / 2);
  string g1 = b.substr(0, b.size() / 2), g2 = b.substr(b.size() / 2);
  string f1_f2 = _add(f1, f2), g1_g2 = _add(g1, g2);
  string tmp2 = karatsuba(f1, g1),
         tmp3 = karatsuba(f2, g2);
  string tmp2_tmp3 = _add(tmp2, tmp3);
  _exp(tmp2, a.size());
  string tmp1 = karatsuba(f1_f2, g1_g2);
  tmp1 = _sub(tmp1, tmp2_tmp3);
  _exp(tmp1, a.size() / 2);
  string res = _add(tmp2, tmp3);
  res = _add(res, tmp1);
  trim(res);
  return res;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> A >> B;
  cout << karatsuba(A, B);
  return 0;
}