#include <bits/stdc++.h>
#define int unsigned int
using namespace std;
const int N = 100010, M = 2000010;
int n, m;
vector<int> G[N];
int dsc[N], djs[N];
unordered_map<int, vector<int>> sfirst;

inline int dsfind(int x) {
  if (djs[x] != x) djs[x] = dsfind(djs[x]);
  return djs[x];
}
/*inline void dsunion(int s1, int s2) {
  //if (dsc[s1] < dsc[s2]) swap(s1, s2);
  djs[s2] = djs[s1];
  //dsc[s1] += dsc[s2];
  if (sfirst.count(s2) == 0)
    sfirst[s1].push_back(s2);
  else {
    sfirst[s1].insert(sfirst[s1].end(), sfirst[s2].begin(), sfirst[s2].end());
    //for (int i = 0; i < sfirst[s2].size(); i++) sfirst[s1].push_back(sfirst[s2][i]);
    sfirst.erase(s2);
  }
}*/
inline void dsunion(int s1, int s2) {
  if (dsc[s1] < dsc[s2]) swap(s1, s2);
  djs[s2] = s1;
  if (dsc[s1] == dsc[s2]) dsc[s1]++;
  if (sfirst.count(s2) == 0)
    sfirst[s1].push_back(s2);
  else {
    sfirst[s1].insert(sfirst[s1].end(), sfirst[s2].begin(), sfirst[s2].end());
    sfirst.erase(s2);
  }
}
inline bool _comp(vector<int>& Gv, vector<int>& s) {  //sorted
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    bool found = false;
    for (; Gv[j] <= s[i]; j++) {
      if (Gv[j] == s[i]) {
        found = true;
        break;
      }
    }
    if (!found) return false;
  }
  return true;
}
inline void getIn(int v) {
  sort(G[v].begin(), G[v].end());
  vector<int> mergewith;
  for (auto it = sfirst.begin(); it != sfirst.end(); it++) {
    vector<int> s = it->second;
    int sf = it->first;
    if (G[v].size() < s.size()) {
      mergewith.push_back(sf);
      continue;
    } else {
      sort(s.begin(), s.end());
      if (!_comp(G[v], s))
        mergewith.push_back(sf);
    }
  }
  if (mergewith.size() == 0) {
    sfirst[v] = (vector<int>){v};
    return;
  }
  int s1;
  for (int i = 0; i < mergewith.size(); i++) {
    s1 = dsfind(v); /*if ((s1 = dsfind(v)) != s2))*/
    dsunion(mergewith[i], s1);
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  //memset(dsc, 1, sizeof(int) * (n + 10));
  for (int i = 0; i <= n; i++) djs[i] = i;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;  //from 1 to n
    G[l].push_back(r);
    G[r].push_back(l);
  }
  //vector<int> tmp;
  //for (int i = 1; i <= n; i++) tmp.push_back(i);
  //sort(tmp.begin(), tmp.end(), [&G](int a, int b) -> bool { return G[a].size() < G[b].size(); });
  //sfirst[1] = (vector<int>){1};
  //for (int i = 0; i < n; i++) getIn(tmp[i]);
  for (int i = 1; i <= n; i++) getIn(i);
  cout << sfirst.size() << '\n';
  return 0;
}