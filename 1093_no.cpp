#include <bits/stdc++.h>
using namespace std;

const int _N = 1e3 + 10, _M = _N * _N;
const double eps = 1e-8;
int N, M;
struct P {
  double x, y;
  P() {}
  P(double x, double y) : x(x), y(y) {}
} pts[_M], O;
inline double dis(P a, P b) { return hypot(a.x - b.x, a.y - b.y); }
inline P cen(P A, P B, P C) {
  P A2 = P(0.0, 0.0), B2 = P(B.x - A.x, B.y - A.y), C2 = P(C.x - A.x, C.y - A.y);
  double Ox, Oy, d = B2.y * C2.x - B2.x * C2.y, AB = dis(A, B), AC = dis(A, C);
  if (abs(d) > eps) {
    Oy = (0.5 * (AB * AB * C2.x + AC * AC * B2.x)) / d;
    Ox = (0.5 * AB * AB - Oy * B2.y) / B2.x;
    return P(A.x + Ox, A.y + Oy);
  }
  return P(1e20, 1e20);
}
main(void) {
  while (scanf("%d%d", &N, &M) == 2 && N + M) {
    for (int i = 0; i < M; i++) scanf("%lf%lf", &pts[i].x, &pts[i].y);
    random_shuffle(pts, pts + M);
    double r = 0;
    O.x = pts[0].x, O.y = pts[0].y;
    for (int i = 1; i < M; i++) {
      if (dis(O, pts[i]) - r > eps) {
        O = pts[i];
        for (int j = 0; j < i; j++) {
          if (dis(O, pts[j]) - r > eps) {
            O.x = (pts[i].x + pts[j].x) / 2.0, O.y = (pts[i].y + pts[j].y) / 2.0;
            r = dis(O, pts[i]);
            for (int k = 0; k < j; k++) {
              if (dis(O, pts[k]) - r > eps) {
                O = cen(pts[i], pts[k], pts[j]);
                r = dis(O, pts[i]);
              }
            }
          }
        }
      }
    }
    printf("%.3lf\n", r);
  }
  return 0;
}