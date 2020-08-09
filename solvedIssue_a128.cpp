#include <bits/stdc++.h>
#define int unsigned int
using namespace std;

vector<vector<int> > Tdp;
int n;
int sizes[30];
unordered_map<int, int> Tsum_s;
int cases;
int sum_s(int s) {
  if (Tsum_s.count(s) > 0) return Tsum_s[s];
  int sum = 0;
  for (int i = 0; i < n; i++)
    if (((1 << i) & s) != 0)
      sum += sizes[i];
  return Tsum_s[s] = sum;
}
bool dp(int stat, int s_side) {
  if (Tdp[stat][s_side] != __INT_MAX__) return Tdp[stat][s_side];
  int sum = sum_s(stat);
  int x = s_side, y = sum / s_side;
  if (sum % x) return Tdp[stat][s_side] = 0;
  for (int s = (stat - 1) & stat; s != 0; s = (s - 1) & stat)
    if (sum_s(s) % y == 0 && dp(s, sum_s(s) / y) && dp(stat ^ s, sum_s(stat ^ s) / y))
      return Tdp[stat][s_side] = 1;
  for (int s = (stat - 1) & stat; s != 0; s = (s - 1) & stat)
    if (sum_s(s) % x == 0 && dp(s, min(x, sum_s(s) / x)) && dp(stat ^ s, min(x, sum_s(stat ^ s) / x)))
      return Tdp[stat][s_side] = 1;
  return Tdp[stat][s_side] = 0;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cases = 1;
  while (cin >> n && n != 0) {
    Tsum_s.clear();
    Tdp.clear();
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < n; i++)
      cin >> sizes[i];
    Tdp = vector<vector<int> >((1 << n) + 1, vector<int>(max(x, y) + 1, __INT_MAX__));
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= max(x, y); j++)
        if (j != 0 && sizes[i] % j == 0 && (sizes[i] / j) >= j)
          Tdp[1 << i][j] = 1;
        else if (j == 0 && sizes[i] == 0)
          Tdp[1 << i][j] = 1;
    Tdp[0][0] = 1;
    if (sum_s((1 << n) - 1) != x * y) {
      cout << "Case " << cases << ": No\n";
      cases++;
      continue;
    }
    if (dp((1 << n) - 1, min(x, y)))
      cout << "Case " << cases << ": Yes\n";
    else
      cout << "Case " << cases << ": No\n";
    cases++;
  }
  return 0;
}