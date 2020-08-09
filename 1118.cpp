/*#include <bits/stdc++.h>
using namespace std;
string A, B;
int dp[20][20], _prev[20][20];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> A >> B) {
    int lA = A.length(), lB = B.length();
    memset(dp, 0, sizeof(dp[0][0]) * 20 * 20);
    memset(_prev, 0, sizeof(_prev[0][0]) * 20 * 20);
    for (int i = 1; i <= lA; i++) {
      for (int j = 1; j <= lB; j++) {
        if (A[i - 1] == B[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          _prev[i][j] = 1;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
          dp[i][j] = dp[i][j - 1], _prev[i][j] = 2;
        } else {
          dp[i][j] = dp[i - 1][j], _prev[i][j] = 3;
        }
      }
    }
    double sum = 0;
    int l = dp[lA][lB], i = lA, j = lB, I, J, prevA = lA + 1, prevB = lB + 1;
    while (l) {
      if (_prev[i][j] == 1) {
        I = prevA - i - 1, J = prevB - j - 1;
        sum += 10.0, sum -= (3.0 * abs(J - I)), sum -= (5.0 * min(J, I));
        prevA = i, prevB = j;
        l--, i--, j--;
      } else if (_prev[i][j] == 2)
        j--;
      else if (_prev[i][j] == 3)
        i--;
    }
    I = prevA - 0 - 1, J = prevB - 0 - 1;
    sum -= (3.0 * abs(J - I)), sum -= (5.0 * min(J, I));
    //cout << I << " " << J << '\n';
    //cout << sum << '\n';
    cout << fixed << setprecision(2) << (sum / (double)lA) * 10.0 << "%\n";
  }
  return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
string A, B;
int dp[20][20];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> A >> B) {
    int lA = A.length(), lB = B.length();
    memset(dp, 0, sizeof(dp[0][0]) * 20 * 20);
    for (int i = 0; i <= lA; i++) dp[i][0] = -3.0 * (double)i;
    for (int i = 0; i <= lB; i++) dp[0][i] = -3.0 * (double)i;
    for (int i = 1; i <= lA; i++) {
      for (int j = 1; j <= lB; j++) {
        if (A[i - 1] == B[j - 1]) {
          dp[i][j] = max(dp[i - 1][j - 1] + 10.0, max(dp[i - 1][j] - 3.0, dp[i][j - 1] - 3.0));
        } else {
          dp[i][j] = max(dp[i - 1][j - 1] - 5.0, max(dp[i - 1][j] - 3.0, dp[i][j - 1] - 3.0));
        }
      }
    }
    cout << fixed << setprecision(2) << (dp[lA][lB] / (double)lA) * 10.0 << "%\n";
  }
  return 0;
}