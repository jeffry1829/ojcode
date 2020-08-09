#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
a:;
  while (T--) {
    int W, B, N, M;
    cin >> W >> B >> N;
    int weight[1001] = {0}, cost[1001] = {0};
    for (int i = 0; i < N; i++) {
      cin >> weight[i] >> cost[i];
    }
    cin >> M;
    for (int i = 0; i < N; i++) weight[i] += M;
    int c[10001] = {0};  //c[w]
    int maxx_allWeight = -1;
    for (int w = 1; w <= W - 1; w++) {
      int maxx = 0;
      for (int i = 0; i < N; i++) {
        int ww = w - weight[i];
        if (ww >= 0)
          if (maxx < c[ww] + cost[i]) maxx = c[ww] + cost[i];
      }
      c[w] = maxx;
      if (maxx > maxx_allWeight) maxx_allWeight = maxx;
      if (maxx_allWeight >= B) {
        cout << "Yes\n";
        goto a;
      }
    }
    if (maxx_allWeight < B) {
      cout << "No\n";
      goto a;
    }
  }
  return 0;
}