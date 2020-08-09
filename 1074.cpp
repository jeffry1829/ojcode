#include <bits/stdc++.h>
using namespace std;
const int _N = 22;
int N;
map<int, bool> mp;
int s[_N];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
next:
  while (cin >> N && N) {
    int K = 0;
    mp.clear();
    for (int i = 0; i < N; i++) {
      cin >> s[i];
      K += s[i];
    }
    if (K == N) {
      cout << "NO\n";
      goto next;
    }
    for (int i = 1; i <= N; i++) {
      for (int k = 0; k <= N - i; k++) {
        int sum = 0;
        for (int j = k; j < k + i; j++) sum += s[j];
        mp[sum] = 1;
      }
    }
    for (int i = 1; i <= K; i++) {
      if (!mp.count(i)) {
        cout << "NO\n";
        goto next;
      }
    }
    cout << "YES\n";
  }
  return 0;
}