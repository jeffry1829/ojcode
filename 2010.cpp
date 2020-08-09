#include <cstdio>
#define MAX(x, y) x > y ? x : y
const int _N = 2000 + 10;
int T, N, M, dpT[_N][_N], from[_N][_N], mN;
char A[_N], B[_N];
int main(void) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%s%s", &N, &M, A, B);
    mN = MAX(N, M);
    for (int i = 0; i < mN; i++) dpT[i][0] = dpT[0][i] = 0;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) {
        if (A[i - 1] == B[j - 1]) {
          dpT[i][j] = dpT[i - 1][j - 1] + 1;
          from[i][j] = 1;
        } else {
          if (dpT[i - 1][j] > dpT[i][j - 1]) {
            dpT[i][j] = dpT[i - 1][j];
            from[i][j] = 2;
          } else {  //if(dpT[i-1][j]<=dpT[i][j-1])
            dpT[i][j] = dpT[i][j - 1];
            from[i][j] = 3;
          }
        }
      }
    if (dpT[N][M] == 0) {
      printf("*\n");
      continue;
    }
    int next_ind = 0, i = N, j = M;
    char res[_N];
    while (!(i == 0 || j == 0)) {
      if (from[i][j] == 1) {
        res[next_ind] = A[i - 1];
        next_ind++, i--, j--;
      } else if (from[i][j] == 2)
        i--;
      else if (from[i][j] == 3)
        j--;
    }
    for (int i = next_ind - 1; i >= 0; i--) printf("%c", res[i]);
    printf("\n");
  }
  return 0;
}