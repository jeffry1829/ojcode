#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s.compare("Tetrahedron") == 0) {
      cnt += 4;
      continue;
    }
    if (s.compare("Cube") == 0) {
      cnt += 6;
      continue;
    }
    if (s.compare("Octahedron") == 0) {
      cnt += 8;
      continue;
    }
    if (s.compare("Dodecahedron") == 0) {
      cnt += 12;
      continue;
    }
    if (s.compare("Icosahedron") == 0) {
      cnt += 20;
      continue;
    }
  }
  cout << cnt << '\n';
  return 0;
}