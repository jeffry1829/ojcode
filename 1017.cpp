#include <bits/stdc++.h>
using namespace std;
const int _N = 1000010;
int S[_N];
bool front[_N], back[_N];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T, N;
  cin >> T;
  while (T--) {
    memset(S, 0, sizeof(int) * _N);
    memset(front, 0, sizeof(bool) * _N);
    memset(back, 0, sizeof(bool) * _N);
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> S[i];
    }
    int maxx = S[0];
    int minn = S[N - 1];
    for (int i = 1; i < N - 1; i++) {
      if (S[i] > maxx) {
        maxx = S[i];
        front[i] = 1;
      }
    }
    for (int i = N - 2; i > 0; i--) {
      if (S[i] < minn) {
        back[i] = 1;
        minn = S[i];
      }
    }
    int _count = 0;
    for (int i = 1; i < N - 1; i++) {
      if (front[i] && back[i]) _count++;
    }
    cout << _count << '\n';
  }
  return 0;
}