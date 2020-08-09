#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int C(int a, int b) {
  if (a < b) {
    return 0;
  }
  int up = 1, down = 1;
  int G;
  for (int i = 0; i < b; i++) {
    up *= (a - i);
    down *= (b - i);
    if ((G = gcd(up, down)) != 1) {
      up /= G;
      down /= G;
    }
  }
  return up / down;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  while (cin >> n >> m && n != 0) {
    cout << C(n + m - 1, m) << '\n';
  }
  return 0;
}