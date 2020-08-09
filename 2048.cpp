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
  for (int i = 0; i < N; i++) front[i + 1] = max(max(front[i], A[i]), front[i] + A[i]);
  back[0] = INT_MIN;
  for (int i = N - 1; i >= 0; i--) back[N - i] = max(max(back[N - i - 1], A[i]), back[N - i - 1] + A[i]);
  ll res = LLONG_MIN;
  for (int i = 1; i < N - 1; i++) res = max(res, front[i] + back[N - i - 1]);
  cout << res << '\n';
  return 0;
}