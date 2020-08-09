#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char M[1001], B[1001];
  int T;
  cin >> M >> B >> T;
  int lenM = strlen(M);
  int lenB = strlen(B);
  int dp[100][100] = {{0}};
  int biggest = 0;
  for (int i = 1; i <= lenM; i++)
    for (int j = 1; j <= lenB; j++) {
      if (M[i - 1] == B[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (dp[i][j] > biggest) biggest = dp[i][j];
    }
  if (T > biggest)
    cout << "sitini na tisa\n";
  else
    cout << "kwa nini unaendesha\n";
  return 0;
}