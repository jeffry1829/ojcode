#include <bits/stdc++.h>
using namespace std;
const int _n = 1e6 + 10;
int a, b, ab, t, A[_n], B[_n], W[_n], S[_n], cnt = 0, pT = 0, pA, pB;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> t;
  ab = max(a, b);
  for (int i = 0; i < a; i++) cin >> A[i];
  for (int i = 0; i < b; i++) cin >> B[i];
  if (a < b)
    for (int i = a; i < b; i++) A[i] = -1;
  if (b < a)
    for (int i = b; i < a; i++) A[i] = -1;
  for (int i = 0; i < t; i++) cin >> W[i] >> S[i];
  sort(A, A + a), sort(B, B + b), sort(W, W + t), sort(S, S + t);
  if (B[b - 1] < S[t - 1] and A[a - 1] < W[t - 1]) {
    cout << -1 << '\n';
    return 0;
  }
  while (pT < t) {
    pA = pB = 0;
    while (pA < a and pB < b) {
      if (A[pA] > W[pT] and B[pB] > W[pT]) {
        if (upper_bound(W + pT, W + t, A[pA]) - (W + pT) > upper_bound(S + pT, S + t, B[pB]) - (S + pT)) {
          pT++, pB++;
        } else {
          pT++, pA++;
        }
      } else if (A[pA] > W[pT] and B[pB] <= W[pT]) {
        pT++, pA++;
      } else if (A[pA] <= W[pT] and B[pB] > W[pT]) {
        pT++, pB++;
      } else {
        pA++, pB++;
      }
    }
    cnt++;
  }
  cout << cnt << '\n';
  return 0;
}