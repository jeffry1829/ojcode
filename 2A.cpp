#include <bits/stdc++.h>
using namespace std;
const int _n = 1010;
int n, sc[_n];
string s[_n];
unordered_map<string, int> mp;
vector<string> candidate;
unordered_map<string, bool> is_candidate;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> sc[i];
    if (!mp.count(s[i])) mp[s[i]] = 0;
    mp[s[i]] += sc[i];
  }
  int maxx = -1;
  for (auto it = mp.begin(); it != mp.end(); it++) maxx = max(maxx, it->second);
  for (int i = 0; i < n; i++)
    if (mp[s[i]] == maxx) candidate.push_back(s[i]), is_candidate[s[i]] = 1;
  string ans = candidate[0];
  if (candidate.size() > 1) {
    mp.clear();
    for (int i = 0; i < n; i++) {
      if (!mp.count(s[i])) mp[s[i]] = 0;
      mp[s[i]] += sc[i];
      if (mp[s[i]] >= maxx and is_candidate.count(s[i]) == 1 and is_candidate[s[i]]) {
        ans = s[i];
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}