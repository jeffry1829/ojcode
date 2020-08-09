#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> Tdp = vector<int>(41, -1);
int dp(int n) {
  if (Tdp[n] != -1) return Tdp[n];
  return Tdp[n] = dp(n - 1) + dp(n - 2) * 4 + dp(n - 3) * 2;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Tdp[0] = 0;
    Tdp[1] = 1;
    Tdp[2] = 5;
    Tdp[3] = 11;
    cout << dp(n) << '\n';
  }
  return 0;
}