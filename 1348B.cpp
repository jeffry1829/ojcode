#include <bits/stdc++.h>
using namespace std;
int t, n, k, a, cnt;
bool vis[110];
vector<int> lst;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(vis, 0, sizeof vis);
    lst.clear();
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (!vis[a]) lst.push_back(a);
      vis[a] = 1;
    }
    if (lst.size() > k)
      cout << -1 << '\n';
    else {
      while (lst.size() < k) lst.push_back(1);
      cout << 1ll * n * k << '\n';
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < lst.size(); j++) cout << lst[j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}