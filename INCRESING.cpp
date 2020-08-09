#include <bits/stdc++.h>
using namespace std;
const int _N = 3e6 + 10;
int A[_N], N, S;
inline int binsearch1(int st, int l, int r) {
  while (l != r) {
    int mid = (l + r) >> 1;
    int d = A[st] - A[mid];
    if (d <= S) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
inline int binsearch2(int st, int l, int r) {
  while (l != r) {
    int mid = (l + r) >> 1;
    int d = A[mid] - A[st];
    if (d > S) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  unsigned long long _count = 0;
  for (int b = 1; b < N - 1; b++) {
    int left = binsearch1(b, 0, b - 1);
    if (abs(A[left] - A[b]) > S)
      left++;
    else if (left == 0 && abs(A[left] - A[b]) <= S)
      continue;
    int right = binsearch2(b, b + 1, N - 1);
    if (abs(A[right] - A[b]) <= S)
      continue;
    _count += (left * 1l * (N * 1l - right * 1l));
  }
  cout << _count << '\n';
  return 0;
}