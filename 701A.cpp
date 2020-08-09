#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int cards[101];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> cards[i];
    sum += cards[i];
  }
  int each = sum / (n / 2);
  int cardi;
a:;
  for (int i = 0; i < n; i++) {
    if (cards[i] != 0) {
      cout << i + 1 << " ";
      cardi = cards[i];
      cards[i] = 0;
    } else
      continue;
    for (int j = 0; j < n; j++) {
      if (cards[j] != 0 && cardi + cards[j] == each) {
        cout << j + 1 << '\n';
        cards[j] = 0;
        goto a;
      } else
        continue;
    }
  }
  return 0;
}