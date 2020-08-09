#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int r, c;
  while (cin >> r >> c) {
    int table[100][100];
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cin >> table[i][j];
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < r; j++)
        cout << table[j][i] << " ";
      cout << "\n";
    }
  }
  return 0;
}