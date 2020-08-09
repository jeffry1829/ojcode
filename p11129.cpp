#include <bits/stdc++.h>
using namespace std;
vector<int> vB;
inline void _f(vector<int> &a) {
  if (a.size() <= 2u) return;
  vector<int> v1, v2;
  for (int i = 0; i < (int)a.size(); i += 2) {
    v1.push_back(a[i]);
    if (i + 1 < (int)a.size()) v2.push_back(a[i + 1]);
  }
  _f(v1), _f(v2), v1.insert(v1.end(), v2.begin(), v2.end()), a.assign(v1.begin(), v1.end());
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  while (true) {
    cin >> n;
    if (n == 0) return 0;
    vB.clear();
    for (int i = 0; i < n; i++) vB.push_back(i);
    _f(vB);
    cout << n << ":";
    for (int i = 0; i < (int)vB.size(); i++) cout << " " << vB[i];
    cout << '\n';
  }
  return 0;
}