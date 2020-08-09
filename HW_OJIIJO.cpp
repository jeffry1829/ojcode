#include <bits/stdc++.h>
using namespace std;
const int _n = 2e5 + 10;
int n, cnt[3], b[400];
char s[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  b['O'] = 0, b['J'] = 1, b['I'] = 2;
  for (int i = 0; i < n; i++) cnt[b[s[i]]]++;
  int l = 0, r = n - 1;
  while (!(cnt[0] == cnt[1] and cnt[1] == cnt[2])) {
    int maxx = max(cnt[0], max(cnt[1], cnt[2]));
    if (cnt[b[s[l]]] == maxx) {
      cnt[b[s[l]]]--, l++;
    } else if (cnt[b[s[r]]] == maxx) {
      cnt[b[s[r]]]--, r--;
    } else if (cnt[b[s[l]]] < cnt[b[s[r]]]) {
      cnt[b[s[r]]]--, r--;
    } else {
      cnt[b[s[l]]]--, l++;
    }
  }
  cout << cnt[0] + cnt[1] + cnt[2] << '\n';
  return 0;
}