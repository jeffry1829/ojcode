#include <bits/stdc++.h>
using namespace std;
const int p = 2609;
bool vis[p];
int x, cnt = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 4; i++) {
    cin >> x;
    if (!vis[x % p]) cnt++, vis[x % p] = 1;
  }
  cout << 4 - cnt << '\n';
  return 0;
}