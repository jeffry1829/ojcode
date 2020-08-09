#include <bits/stdc++.h>
using namespace std;
const int _N = 3010;
double EPS = 1e-8;
int N;
struct P {
  double x, y;
} pts[_N];
inline double dis(P a, P b) { return hypot(a.x - b.x, a.y - b.y); }
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> N && N) {
    for (int i = 0; i < N; i++) {
      double x, y;
      cin >> x >> y;
      pts[i] = {x, y};
    }
    double resD = -1e20;
    pair<double, double> res;
    for (int i = N - 2; i >= 0; i--) {
      for (int j = N - 1; j > i; j--) {
        double D = dis(pts[i], pts[j]);
        if (D >= resD) {
          resD = D, res = {i, j};
        }
      }
    }
    cout << res.first << " " << res.second << '\n';
  }
  return 0;
}