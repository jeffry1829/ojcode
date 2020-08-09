#include <bits/stdc++.h>
#define ll long long
using namespace std;
int k, w;
ll n;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> k >> n >> w;
  for (int i = 1; i <= w; i++) n -= i * k;
  if (n < 0)
    cout << -n << '\n';
  else
    cout << 0 << '\n';
  return 0;
}