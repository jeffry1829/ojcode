#include <bits/stdc++.h>
using namespace std;
int n, last[2], cnt[2], x;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    cnt[x & 1]++, last[x & 1] = i;
  }
  if (cnt[0] > cnt[1])
    cout << last[1] << '\n';
  else
    cout << last[0] << '\n';
  return 0;
}