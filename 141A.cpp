#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
int cnt[200], sum = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s1 >> s2 >> s3;
  for (int i = 0; i < s3.length(); i++) cnt[s3[i]]++, sum++;
  for (int i = 0; i < s1.length(); i++) {
    cnt[s1[i]]--, sum--;
    if (cnt[s1[i]] < 0) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i = 0; i < s2.length(); i++) {
    cnt[s2[i]]--, sum--;
    if (cnt[s2[i]] < 0) {
      cout << "NO\n";
      return 0;
    }
  }
  if (sum != 0)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}