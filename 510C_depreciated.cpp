#include <bits/stdc++.h>
#define int unsigned int
using namespace std;
const int _N = 110;
int N;
map<char, vector<char> > G;
map<char, int> indeg;
vector<pair<char, int> > vindeg;
char lines[_N][_N] = {{0}};
inline void cmpstr(char s1[_N], char s2[_N]) {  //s1<s2
  int len = min(strlen(s1), strlen(s2));
  for (int i = 0; i < len; i++) {
    if (s1[i] != s2[i]) {
      G[s1[i]].push_back(s2[i]);  //s1<s2
      indeg[s2[i]]++;
      return;
    }
  }
}
inline void findzero() {
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N; i++)
    cin.getline(lines[i], _N);
  for (int i = 97; i <= 122; i++) {
    G[(char)i] = (vector<char>){};
    indeg[(char)i] = 0;
  }
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N - 1; j++)
      cmpstr(lines[i], lines[j]);
  for (auto it = indeg.begin(); it != indeg.end(); it++)
    vindeg.push_back(*it);
  sort(vindeg.begin(), vindeg.end(), [](auto l, auto r) -> bool { return l.second < r.second; });
  for (int i = 0; i < vindeg.size(); i++)
    cout << vindeg[i].first;
  cout << '\n';
  return 0;
}