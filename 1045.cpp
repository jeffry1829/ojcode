#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _m = 1e4 + 10;
int n, l, t, r, b;
struct sv {
  int s, v;
};
vector<sv> arr[_m];
ll sum = 0, pn[210];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pn[0] = 1;
  for (int i = 1; i < 60; i++) pn[i] = pn[i - 1] << 1;
  while (cin >> n && n) {
    sum = 0;
    for (int i = 0; i < n; i++) arr[i].clear();
    while (n--) {
      cin >> l >> t >> r >> b;
      for (int i = t; i < b; i++) arr[i].push_back({l, 1}), arr[i].push_back({r - 1, -1});
    }
    for (int i = 0; i < 10000; i++) sort(arr[i].begin(), arr[i].end(), [](const sv &a, const sv &b) { return a.s < b.s; });
    for (int i = 0; i < 10000; i++) {
      int ct = 0, preind = 0;
      for (int j = 0; j < (int)arr[i].size(); j++) {
        int tmp = 0;
        for (int id = arr[i][j].s; arr[i][j].s == id && j < (int)arr[i].size(); j++) tmp += arr[i][j].v;
        if (tmp >= 0) {
          ct += tmp;
          sum += pn[ct];
        } else {
          sum += pn[ct];
          ct += tmp;
        }
      }
    }
    cout << sum << '\n';
  }
}