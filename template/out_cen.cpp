#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};
Point center(Point a, Point b, Point c) {
  double Ox, Oy, d, A2, B2, C2;
  d = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2;
  if (abs(d) >= EPS) {
    A2 = a.y * a.y + a.x * a.x;
    B2 = b.y * b.y + b.x * b.x;
    C2 = c.y * c.y + c.x * c.x;
    Ox = (A2 * (b.y - c.y) + B2 * (c.y - a.y) + C2 * (a.y - b.y)) / d;
    Oy = (A2 * (c.x - b.x) + B2 * (a.x - c.x) + C2 * (b.x - a.x)) / d;
  } else {
    Ox = 1e20;
    Oy = 1e20;
  }
  return Point(Ox, Oy);
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  return 0;
}