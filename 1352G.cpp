#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> odd, even;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    if (n <= 3) {
      cout << "-1\n";
      continue;
    }
    odd.clear(), even.clear();
    for (int i = 1; i <= n; i += 2) odd.push_back(i);
    for (int i = 2; i <= n; i += 2) even.push_back(i);
    if (!(n & 1))
      swap(odd[odd.size() - 1], odd[odd.size() - 2]);
    else
      swap(even[even.size() - 1], even[even.size() - 2]);
    for (int i = 0; i < odd.size(); i++) cout << odd[i] << " ";
    for (int i = even.size() - 1; i >= 0; i--) cout << even[i] << " ";
    cout << '\n';
  }
  return 0;
}