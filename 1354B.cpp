#include <bits/stdc++.h>
using namespace std;
const int _n = 2e5 + 10;
int t, len;
char s[_n], tmp;
vector<pair<int, int>> a;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> s;
    a.clear();
    tmp = s[0], len = strlen(s);
    int cnt = 1;
    for (int i = 1; i < len; i++) {
      if (s[i] != tmp)
        a.push_back({tmp - '0', cnt}), tmp = s[i], cnt = 1;
      else
        cnt++;
    }
    a.push_back({tmp - '0', cnt});
    int minn = 0x7f7f7f7f;
    for (int i = 0; i < (int)a.size() - 2; i++) {
      if (a[i].first + a[i + 1].first + a[i + 2].first == 6)
        minn = min(minn, a[i + 1].second + 2);
    }
    cout << (minn == 0x7f7f7f7f ? 0 : minn) << '\n';
  }
  return 0;
}