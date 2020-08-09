#include <bits/stdc++.h>
#define CT pair<pair<int, int>, int>  //CoordinaTe
#define MCT(X, Y, Z) make_pair(make_pair(X, Y), Z)
#define PB push_back
using namespace std;
const int r = 500, lb = (r * r / 4) + 1, rb = r * r;  //left-bound
int x, y, z;
vector<CT> qs;  //quater sphere

bool ib(int x) { return x <= rb && x >= lb; }  //in-bound
int sq(int x) { return x * x; }                //square
void nct(int x, int y) {                       //new CT
  int sum, maxz;
  if (ib(sum = sq(x) + sq(y))) maxz = sqrt(rb - sum);
  if (maxz > 0)
    for (int i = 0; i < maxz; i++) qs.PB(MCT(x, y, i));
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> x >> y >> z;

  return 0;
}