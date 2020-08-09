#include <bits/stdc++.h>
#define int unsigned int
using namespace std;

vector<vector<int> > tsp;
int matrix[35][35] = {{0}};
int N;
int dp(int status, int cityIndex) {
  if ((1 & status) == 0)
    return __INT_MAX__;
  if (tsp[status][cityIndex] != __INT_MAX__) {
    return tsp[status][cityIndex];
  } else {
    int minn = __INT_MAX__;
    for (int i = 0; i < N; i++)
      if (((1 << i) & status) != 0)
        if (matrix[i][cityIndex] != 0)
          minn = min(minn, dp(status - (1 << cityIndex), i) + matrix[i][cityIndex]);
    tsp[status][cityIndex] = minn;
    return minn;
  }
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> matrix[i][j];
  tsp = vector<vector<int> >((1 << N) + 1, vector<int>(N, __INT_MAX__));
  tsp[0][0] = 0;  // should never be used
  tsp[1][0] = 0;
  for (int i = 1; i < N; i++)
    if (matrix[0][i] != 0)
      tsp[1 << i + 1][i] = matrix[0][i];
  int minn = __INT_MAX__;
  for (int i = 1; i < N; i++)
    if (matrix[i][0] != 0)
      minn = min(minn, dp((1 << N) - 1, i) + matrix[i][0]);
  cout << minn << '\n';
  return 0;
}