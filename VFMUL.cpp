#include <bits/stdc++.h>
#define ll long long
using namespace std;
string A, B;
vector<ll> vA, vB, vR;
inline void eqL(string &a, string &b) {
  int alen = a.size(), blen = b.size();
  if (a.size() > b.size())
    for (int i = 0; i < alen - blen; i++) b = '0' + b;
  if (a.size() < b.size())
    for (int i = 0; i < blen - alen; i++) a = '0' + a;
  if (a.size() % 2 != 0) a = '0' + a, b = '0' + b;
}
inline void _add(vector<ll> &r, vector<ll> &b) {
  if (r.size() > b.size()) {
    b.resize(r.size() + 1, 0);
    r.resize(r.size() + 1, 0);
  } else {
    r.resize(b.size() + 1, 0);
    b.resize(b.size() + 1, 0);
  }
  for (int i = 0; i < (int)r.size(); i++) r[i] += b[i];
  for (int i = 0; i < (int)r.size(); i++)
    if (r[i] >= (int)1e9) r[i + 1] += r[i] / (int)1e9, r[i] = r[i] % (int)1e9;
}
inline void _sub(vector<ll> &r, vector<ll> &b) {
  if (r.size() > b.size())
    b.resize(r.size(), 0);
  else
    r.resize(b.size(), 0);
  for (int i = 0; i < (int)r.size(); i++) r[i] -= b[i];
  for (int i = 0; i < (int)r.size(); i++)
    if (r[i] < 0) r[i + 1] += (r[i] / (ll)1e9 - 1), r[i] -= ((int)(r[i] / (int)1e9 - 1)) * (int)1e9;
  for (int i = 0; i < (int)r.size(); i++)
    if (r[i] >= (int)1e9) r[i + 1] += r[i] / (int)1e9, r[i] = r[i] % (int)1e9;
}
inline void _mul(vector<ll> &a, vector<ll> &b, vector<ll> &r) {
  if (a.size() > b.size())
    b.resize(a.size(), 0);
  else
    a.resize(b.size(), 0);
  if (a.size() % 2 != 0) a.push_back(0), b.push_back(0);

  if (a.size() <= 256u) {
    r.resize(a.size() * 2, 0);
    for (int i = 0; i < (int)a.size(); i++)
      for (int j = 0; j < (int)b.size(); j++) {
        r[i + j] += a[i] * b[j];
        for (int k = 0; r[i + j + k] >= (ll)1e9; k++)
          r[i + j + k + 1] += r[i + j + k] / (ll)1e9, r[i + j + k] = r[i + j + k] % (ll)1e9;
      }
    while (r.size() > 1u && r.back() == 0) r.pop_back();
    return;
  }
  vector<ll> f1(a.begin(), a.begin() + a.size() / 2), f2(a.begin() + a.size() / 2, a.begin() + a.size()),
      g1(b.begin(), b.begin() + b.size() / 2), g2(b.begin() + b.size() / 2, b.begin() + b.size());
  vector<ll> r1, r2, r3;
  _mul(f1, g1, r1), _mul(f2, g2, r2), _add(f2, f1), _add(g2, g1), _mul(f2, g2, r3), _sub(r3, r1), _sub(r3, r2);
  r.resize(a.size() * 2, 0);
  for (int i = 0; i < (int)r1.size(); i++) r[i] += r1[i];
  for (int i = a.size(); i < (int)a.size() + (int)r2.size(); i++) r[i] += r2[i - a.size()];
  for (int i = a.size() / 2; i < (int)a.size() / 2 + (int)r3.size(); i++) r[i] += r3[i - a.size() / 2];
  for (int i = 0; i < (int)r.size(); i++)
    if (r[i] >= (int)1e9) r[i + 1] += r[i] / (int)1e9, r[i] = r[i] % (int)1e9;
  while (r.size() > 1u && r.back() == 0) r.pop_back();
  return;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    cin >> A >> B;
    vA.clear(), vB.clear(), vR.clear();
    bool flag = 0;  //positive
    if (A[0] == '-') flag = !flag, A.erase(0, 1);
    if (B[0] == '-') flag = !flag, B.erase(0, 1);
    eqL(A, B);
    reverse(A.begin(), A.begin() + A.size());
    reverse(B.begin(), B.begin() + B.size());
    for (int i = 0; i < (int)A.size(); i += 9) {
      vA.push_back(
          (A[i] - '0') * (int)1 +
          (i + 1 < (int)A.size() ? A[i + 1] - '0' : 0) * (int)1e1 +
          (i + 2 < (int)A.size() ? A[i + 2] - '0' : 0) * (int)1e2 +
          (i + 3 < (int)A.size() ? A[i + 3] - '0' : 0) * (int)1e3 +
          (i + 4 < (int)A.size() ? A[i + 4] - '0' : 0) * (int)1e4 +
          (i + 5 < (int)A.size() ? A[i + 5] - '0' : 0) * (int)1e5 +
          (i + 6 < (int)A.size() ? A[i + 6] - '0' : 0) * (int)1e6 +
          (i + 7 < (int)A.size() ? A[i + 7] - '0' : 0) * (int)1e7 +
          (i + 8 < (int)A.size() ? A[i + 8] - '0' : 0) * (int)1e8);
    }
    for (int i = 0; i < (int)B.size(); i += 9) {
      vB.push_back(
          (B[i] - '0') * (int)1 +
          (i + 1 < (int)B.size() ? B[i + 1] - '0' : 0) * (int)1e1 +
          (i + 2 < (int)B.size() ? B[i + 2] - '0' : 0) * (int)1e2 +
          (i + 3 < (int)B.size() ? B[i + 3] - '0' : 0) * (int)1e3 +
          (i + 4 < (int)B.size() ? B[i + 4] - '0' : 0) * (int)1e4 +
          (i + 5 < (int)B.size() ? B[i + 5] - '0' : 0) * (int)1e5 +
          (i + 6 < (int)B.size() ? B[i + 6] - '0' : 0) * (int)1e6 +
          (i + 7 < (int)B.size() ? B[i + 7] - '0' : 0) * (int)1e7 +
          (i + 8 < (int)B.size() ? B[i + 8] - '0' : 0) * (int)1e8);
    }
    if (vA.size() > vB.size())
      vB.resize(vA.size(), 0);
    else
      vA.resize(vB.size(), 0);
    if (vA.size() % 2 != 0) vA.push_back(0);
    if (vB.size() % 2 != 0) vB.push_back(0);

    vR.resize(vA.size() * 2, 0);
    _mul(vA, vB, vR);
    if (flag) cout << '-';
    cout << vR[vR.size() - 1];
    for (int i = (int)vR.size() - 2; i >= 0; i--) cout << setfill('0') << setw(9) << vR[i];
    cout << '\n';
  }
  return 0;
}