#include <bits/stdc++.h>
#define rank dkngpsngs
using namespace std;
const int _n = 2e5 + 10;
int n, a[_n], cnt = 0, ans[_n];
vector<int> Rings, Roots;

int parent[_n], rank[_n];
inline void dsinit(int n) {
  for (int i = 0; i < n; i++)
    parent[i] = i;
  memset(rank, 0, sizeof rank);
}
inline int dsfind(int e) { return parent[e] == e ? e : parent[e] = dsfind(parent[e]); }
inline void dsunion(int s1, int s2) {
  if (rank[s1] < rank[s2]) swap(s1, s2);
  parent[s2] = s1;
  if (rank[s1] == rank[s2]) rank[s1]++;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  dsinit(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == i)
      Roots.push_back(i);
    else {
      if (dsfind(a[i]) != dsfind(i))
        dsunion(dsfind(a[i]), dsfind(i));
      else
        Rings.push_back(i);
    }
  }
  for (int i = 0; i < (int)Rings.size(); i++) {
    ans[Rings[i]] = Rings[i];
    Roots.push_back(Rings[i]);
  }
  for (int i = 1; i < (int)Roots.size(); i++) ans[Roots[i]] = Roots[i - 1];
  for (int i = 1; i <= n; i++)
    if (ans[i] != a[i]) cnt++;
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}