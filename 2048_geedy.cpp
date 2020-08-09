#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _N = 1e6 + 10;
int N;
ll A[_N], front[_N], back[_N];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  front[0] = INT_MIN;
  bool allneg = 1;
  for (int i = 0; i < N; i++) {
    if (allneg && A[i] < 0 && A[i] > front[i])
      front[i + 1] = A[i];
    else if (allneg && A[i] < 0 && A[i] <= front[i])
      front[i + 1] = front[i];
    else if (allneg && A[i] >= 0) {
      front[i + 1] = A[i];
      allneg = 0;
    } else if (!allneg)
      front[i + 1] = max(front[i], front[i] + A[i]);
  }
  back[0] = INT_MIN;
  allneg = 1;
  for (int i = N - 1; i >= 0; i--) {
    if (allneg && A[i] < 0 && A[i] > back[N - i - 1])
      back[N - i] = A[i];
    if (allneg && A[i] < 0 && A[i] <= back[N - i - 1])
      back[N - i] = back[N - i - 1];
    else if (allneg && A[i] >= 0) {
      back[N - i] = A[i];
      allneg = 0;
    } else if (!allneg)
      back[N - i] = max(back[N - i - 1], back[N - i - 1] + A[i]);
  }
  ll res = LLONG_MIN;
  for (int i = 1; i < N - 1; i++) res = max(res, front[i] + back[N - i - 1]);
  cout << res << '\n';
  return 0;
}