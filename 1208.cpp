#include <bits/stdc++.h>
using namespace std;
const int _N = 2e4 + 10;
int A[_N], S[_N], s[_N], n, k, tmp[_N];
inline int _std_(int l, int r, int q) {
  int cnt = 0;
  for (int i = l; i < r - 1; i++)
    for (int j = i + 1; j < r; j++)
      if (s[j] - s[i] > q) cnt++;
  for (int i = l; i < r; i++)
    if (s[i] - S[l - 1] > q) cnt++;
  sort(s + l, s + r);
  return cnt;
}
inline int _ms(int l, int r, int q) {
  /*if (r - l == 0) return 0;
  if (r - l == 1) return (int)(A[l - 1] > q);*/
  if (r - l < 75) return _std_(l, r, q);
  int cnt = 0;
  cnt += _ms(l, (l + r) / 2, q);
  cnt += _ms((l + r) / 2, r, q);

  int _tmp = S[l - 1];
  int _j = (l + r) / 2;
  while (_j < r && s[_j] - _tmp <= q) _j++;
  cnt += r - _j;

  _tmp = S[(l + r) / 2 - 1];
  _j = (l + r) / 2;
  while (_j < r && s[_j] - _tmp <= q) _j++;
  cnt -= r - _j;

  _j = (l + r) / 2;
  for (int i = l; i < (l + r) / 2; i++) {
    while (_j < r && s[_j] - s[i] <= q) _j++;
    cnt += r - _j;
  }
  /*
    int _tmp = S[l - 1];
    int _j = upper_bound(s + (l + r) / 2, s + r, _tmp + q) - s;
    cnt += r - _j;

    _tmp = S[(l + r) / 2 - 1];
    _j = upper_bound(s + (l + r) / 2, s + r, _tmp + q) - s;
    cnt -= r - _j;

    for (int i = l; i < (l + r) / 2; i++) {
      int j = upper_bound(s + (l + r) / 2, s + r, s[i] + q) - s;
      cnt += r - j;
    }
  */
  int i = l, j = (l + r) / 2, k = 0;
  while (i < (l + r) / 2 && j < r) {
    if (s[i] < s[j])
      tmp[k++] = s[i++];
    else
      tmp[k++] = s[j++];
  }
  while (i < (l + r) / 2) tmp[k++] = s[i++];
  while (j < r) tmp[k++] = s[j++];
  memcpy(s + l, tmp, sizeof(int) * (r - l));
  return cnt;
}
inline bool C(int q) {
  memcpy(s, S, sizeof(S));
  return _ms(1, n + 1, q) > k - 1;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> n >> k && n && k) {
    for (int i = 0; i < n; i++) cin >> A[i];
    int tmp = 0;
    S[0] = tmp;
    for (int i = 0; i < n; i++) {
      tmp += A[i];
      S[i + 1] = tmp;
    }
    int idx = n * (-10000) - 1;
    for (int d = 29; d >= 0; d--) {
      if (idx + (1 << d) <= n * 10000 && C(idx + (1 << d)) == 1)
        idx += (1 << d);
    }
    cout << idx + 1 << '\n';
  }
  return 0;
}