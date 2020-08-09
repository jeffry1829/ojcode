#include <bits/stdc++.h>
using namespace std;
int T, C, my[5], boss[5], sum = 0, used = 0, val[5] = {1, 5, 10, 20, 50};
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> C >> my[0] >> my[1] >> my[2] >> my[3] >> my[4] >> boss[0] >> boss[1] >> boss[2] >> boss[3] >> boss[4];
    for (int i = 0; i < 5; i++) sum += my[i];
  test:
    while (C > 0) {
      for (int i = 0; i < 5; i++) {
        if (my[i] > 0) {
          C -=
        }
      }
    }
  }
  return 0;
}