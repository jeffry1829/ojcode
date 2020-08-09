#include <bits/stdc++.h>
using namespace std;

struct feed {
  int v, w, t;
};
int i, c;
feed feeds[1001] = {0};
vector<int> TC = vector<int>(1001, -1);
int times_eat_for_a_w[1001][1001] = {{0}};  //[w][i]
int C(int w) {
  if (w < 0) return 0;
  if (TC[w] != -1) return TC[w];
  int maxx = 0;
  int maxx_j = -1;
  for (int j = 0; j < i; j++) {
    if (w - feeds[j].w < 0) continue;
    if (times_eat_for_a_w[w - feeds[j].w][j] < feeds[j].t || feeds[j].t == -1) {
      if (maxx < C(w - feeds[j].w) + feeds[j].v) {
        maxx = C(w - feeds[j].w) + feeds[j].v;
        maxx_j = j;
      }
    }
  }
  if (maxx_j != -1) {
    for (int k = 0; k < i; k++)
      times_eat_for_a_w[w][k] = times_eat_for_a_w[w - feeds[maxx_j].w][k];
    times_eat_for_a_w[w][maxx_j]++;
  }
  return TC[w] = maxx;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> i >> c;
  for (int j = 0; j < i; j++)
    cin >> feeds[j].v >> feeds[j].w >> feeds[j].t;
  TC[0] = 0;
  for (int l = 1; l < c; l++) C(l);
  cout << C(c) << '\n';
  return 0;
}