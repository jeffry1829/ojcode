#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int M, D, S;
  while (cin >> M) {
    cin >> D;
    int S = (M * 2 + D) % 3;
    switch (S) {
      case 0:
        cout << "普通\n";
        break;
      case 1:
        cout << "吉\n";
        break;
      case 2:
        cout << "大吉\n";
        break;
    }
  }

  return 0;
}