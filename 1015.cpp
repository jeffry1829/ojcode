#include <bits/stdc++.h>
#define int long long
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int M, N;
  while (cin >> M >> N) {
    if (M == 0 && N == 0) return 0;
    int sum = 0;
    int big = max(M, N);
    int low = min(M, N);
    cout << low * (low + 1) * (big + 1) -
                (low + big + 2) * (low * low + low) / 2 +
                low * (low + 1) * (2 * low + 1) / 6
         << '\n';
  }
  return 0;
}