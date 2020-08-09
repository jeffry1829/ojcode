#include <bits/stdc++.h>
using namespace std;
int a, b, dirt = 0, cnt = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b;
  cnt += a, dirt = a;
  while (dirt / b) {
    cnt += dirt / b, dirt = dirt % b + dirt / b;
  }
  cout << cnt << '\n';
  return 0;
}