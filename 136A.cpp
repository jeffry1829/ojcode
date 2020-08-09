#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> v[110];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    v[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) cout << v[i][0] << " ";
  cout << '\n';
  return 0;
}