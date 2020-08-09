#include <bits/stdc++.h>
#define prev asojsjkdgoiosjswighsodefg
using namespace std;
const int _n = 1e5 + 10;
int t, n;
char a[_n], b[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> (a + 1) >> (b + 1);
    vector<int> ans;
    a[n + 1] = '0';
    int prev = a[1];
    for (int i = 2; i <= n + 1; i++) {
      if (a[i] != prev) {
        ans.push_back(i - 1);
        prev = a[i];
      }
    }
    b[0] = '0';
    for (int i = n; i >= 0; i--) {
      if (b[i] == '1') {
        int ed = i;
        while (b[i] == '1') i--;
        ans.push_back(ed);
        if (i != 0) ans.push_back(i);
      }
    }
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}