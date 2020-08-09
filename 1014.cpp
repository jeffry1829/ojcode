#include <bits/stdc++.h>
using namespace std;
const unsigned int _N = 1 << 16 + 10;
pair<bitset<16>, int> status;
int interval[16];
int dpT[_N][16] = {-1};
int n;
int f(bitset<16> stat, int now, int t) {
  if (dpT[stat][now] != -1) return dpT[stat][now];
  int minimal = 0;
  for (int i = 0; i < n; i++) {
    if (stat[i] == 0) {
      bitset<16> cp_stat(stat);
      cp_stat[i] = 1;
      if (abs(now - i) > interval[i] - (t % interval[i])) {
        if ((abs(now - i) + (t % interval[i]) - interval[i]) % interval[i] == 0) {
          minimal = min(minimal, f(cp_stat, i, t + abs(now - i)) + abs(now - i));
        } else {
          minimal = min(minimal, f(cp_stat, i, t + abs(now - i)) + abs(now - i));
        }
        minimal = min(minimal, f(cp_stat, i, (t % interval[i]) + interval[i]) + (t % interval[i]) + interval[i]);
      }
    }
  }
  dpT[stat][now] = minimal;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;

  return 0;
}