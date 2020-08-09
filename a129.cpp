#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define PT pair<pair<int, int>, int>
using namespace std;
int n, m;

int DSR[100001];
int DSfind(int e) {
  return DSR[e] == e ? e : (DSR[e] = DSfind(DSR[e]));
}
void DSunion(int e1, int e2) {
  DSR[DSfind(e1)] = DSfind(e2);
}
PT E[200001];

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> n >> m) {
    int sofar = 0;
    for (int i = 0; i < 100001; i++) DSR[i] = i;

    for (int i = 0; i < m; i++) {
      int k, l, w;
      cin >> k >> l >> w;
      E[i] = MP(MP(k, l), w);
    }
    sort(E, E + n, [](PT l, PT r) -> bool { return l.second < r.second; });
    int i, j;
    for (i = 0, j = 0; i < n - 1 && j < m; i++) {
      while (DSfind(E[j].first.first) == DSfind(E[j].first.second)) {
        j++;
      }
      DSunion(E[j].first.first, E[j].first.second);
      sofar += E[j].second;
      j++;
    }
    if (i == n - 1)
      cout << sofar << '\n';
    else
      cout << "-1" << '\n';
  }
  return 0;
}