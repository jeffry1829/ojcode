#include <bits/stdc++.h>
using namespace std;
int M, N;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> M >> N;
  int sum = M * N;
  if (sum & 1) sum--;
  cout << sum / 2 << '\n';
  return 0;
}