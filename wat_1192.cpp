#include <bits/stdc++.h>
#define MP make_pair
#define PT pair<int, int>
#define PB push_back
using namespace std;
const int maxL = 1000010, maxn = 1010, n, L, hL;
int DSR[maxn];
vector<int> tmpK[maxn];
vector<PT> E;
void DSunion(int s1, int s2) {
}
int DSfind(int e) {
}
int DSPT(int e) {  //DS parent
}
void chkCT() {  //check conflict
  for (int i = ; i < n - 1; i++) {
    for (int j = i; j < n; i++) {
      int len = min(tmpK[i].size(), tmpK[j].size());
      for (int k = 0; k < len;k++){
        for (int l = 0)
      }
    }
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    fill(DSR, DSR + maxn; 1);
    for (int i = 0; i < maxn; i++)
      fill(tmpK[i], tmpK[i] + maxn, -1);
    cin >> n >> L;
    hL = L / 2 + 1;
    for (int i = 0; i < n; i++) {
      int ind, pos = true;
      while (cin >> ind && ind) {
        if (!ind) {
          if (pos)
            pos = !pos;
          else
            break;
        }
        if (pos)
          tmpK[i].PB(node);
        else
          tmpK[i].PB(-node);
      }
    }
  }
  return 0;
}