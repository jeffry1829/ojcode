#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int Y;
  while (cin >> Y) {
    if (Y % 4 == 0 && Y % 100 != 0) {
      cout << "閏年\n";
    } else if (Y % 400 == 0) {
      cout << "閏年\n";
    } else {
      cout << "平年\n";
    }
  }
  return 0;
}