#include <bits/stdc++.h>
using namespace std;
const int _N = 26, _M = 110;
int now = 0, n;
vector<int> G[_N];
bool visited[_N] = {0};
int out_t[_N];
char lines[_M][_M];
map<int, int> mp_out_t;
inline void init_G() {
  cin.getline(lines[0], _M);
  for (int i = 0; i < n; i++) cin.getline(lines[i], _M);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int len = min(strlen(lines[i]), strlen(lines[j]));
      for (int k = 0; k < len; k++) {
        if (lines[i][k] != lines[j][k]) {
          int c1 = lines[i][k] - 97;
          int c2 = lines[j][k] - 97;
          G[c1].push_back(c2);
          break;
        } else if (k == len - 1) {
          if (strlen(lines[i]) > strlen(lines[j])) {
            cout << "Impossible" << endl;
            exit(0);
          }
        }
      }
    }
  }
}
void dfs(int v) {
  visited[v] = true;
  for (int i = 0; i < G[v].size(); i++) {
    if (!visited[G[v][i]]) {
      dfs(G[v][i]);
    } else if (out_t[G[v][i]] == -1) {
      cout << "Impossible" << endl;
      exit(0);
    }
  }
  out_t[v] = now++;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  memset(out_t, -1, sizeof(int) * _N);
  cin >> n;
  init_G();
  for (int i = 0; i < _N; i++)
    if (!visited[i]) dfs(i);
  int tmp = -1;
  for (int i = 0; i < _N; i++) {
    if (out_t[i] == -1) out_t[i] = tmp--;
    mp_out_t[out_t[i]] = i;
  }
  sort(out_t, out_t + _N, [](int l, int r) { return l > r; });
  for (int i = 0; i < _N; i++) cout << (char)(mp_out_t[out_t[i]] + 97);
  cout << '\n';
  return 0;
}