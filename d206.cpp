#include <bits/stdc++.h>
using namespace std;

int biggest;
int s[101][101];
int column_arr[101][101];  //直行的上面(含)的加總

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  while (cin >> n) {
    memset(s, 0, sizeof(s) / sizeof(int));
    memset(column_arr, 0, sizeof(column_arr) / sizeof(int));
    biggest = INT_MIN;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> s[i][j];
        // if (s[i][j] > biggest) biggest = s[i][j];
      }
    }
    for (int i = 0; i <= n; i++) {
      column_arr[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
      column_arr[0][j] = 0;
    }
    column_arr[1][1] = s[1][1];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        column_arr[i][j] = column_arr[i - 1][j] + s[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        int sum = 0;
        for (int k = 1; k <= n; k++) {
          sum += column_arr[j][k] - column_arr[i - 1][k];
          biggest = max(biggest, sum);
          if (sum < 0) sum = 0;
        }
      }
    }
    cout << biggest << '\n';
  }
  return 0;
}