#include <bits/stdc++.h>
using namespace std;
const int _n = 2e5 + 10;
int n, k, uu, vv, num[_n], happy[_n];
vector<int> G[_n];
void dfs(int v, int d, int fa) {
  for (int i = 0; i < G[v].size(); i++)
    if (G[v][i] != fa) dfs(G[v][i], d + 1, v);
  num[v] = 1, happy[v] = d;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] != fa) {
      num[v] += num[G[v][i]];
      happy[v] -= num[G[v][i]];
    }
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    cin >> uu >> vv;
    G[uu].push_back(vv), G[vv].push_back(uu);
  }
  dfs(1, 0, 1);
  nth_element(happy + 1, happy + k + 1, happy + n + 1, greater<int>());
  long long sum = 0;
  for (int i = 1; i <= k; i++) sum += happy[i];
  cout << sum << '\n';
  return 0;
}