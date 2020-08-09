#include <bits/stdc++.h>
using namespace std;
const int _N = 10010, _E = 100010;
int N, E;
vector<int> G[_N];
int dpt[_N] = {0};  //1->Win,2->Lose,0->undefined
inline void init_G() {
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;  // a,b>=1
    G[a].push_back(b);
  }
}
int dp(int v) {
  if (!dpt[v]) {
    for (int i = 0; i < G[v].size(); i++) {
      int c = G[v][i];
      if (c == N - 1) return dpt[v] = 2;
      if (dp(c) == 1) return dpt[v] = 2;
    }
  } else {
    return dpt[v];
  }
  return dpt[v] = 1;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> N >> E && N + E) {
    if (N == 1) {
      char name[20];
      cin.getline(name, 20);
      cin.getline(name, 20);
      //Mimi: 1 Moumou: 0
      bool who;
      strlen(name) == 4 ? who = 1 : who = 0;
      map<bool, const char*> human;
      human[true] = "Mimi";
      human[false] = "Moumou";
      cout << human[who] << '\n';
      continue;
    }
    for (int i = 0; i < N; i++) G[i].clear();
    memset(dpt, 0, sizeof(int) * _N);
    init_G();
    char name[20];
    cin.getline(name, 20);
    cin.getline(name, 20);
    //Mimi: 1 Moumou: 0
    bool who;
    strlen(name) == 4 ? who = 1 : who = 0;
    map<bool, const char*> human;
    human[true] = "Mimi";
    human[false] = "Moumou";
    int res = dp(0);
    if (res == 1)
      cout << human[who] << '\n';
    else
      cout << human[!who] << '\n';
  }
  return 0;
}