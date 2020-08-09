#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, arr[2010];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = (upper_bound(arr, arr + n, 5 - k) - arr) / 3;
  cout << ans << '\n';
  return 0;
}