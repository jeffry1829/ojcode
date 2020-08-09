#include <stdio.h>
int main(void) {
  int n, m, num, temp;
  int i, j, k;
  int winner = 0, whowin[10], winnum;
  scanf("%d %d", &n, &m);
  int x[n][m * m], y[n][m * m], line[n][m * m + 2];
  char s[n][64];
  for (i = 0; i < n; i++)
    for (j = 0; j < m * 2 + 2; j++)
      line[i][j] = 0;
  for (i = 0; i < n; i++) {
    scanf("%s", &(s[i]));
    for (j = 0; j < m; j++) {
      for (k = 0; k < m; k++) {
        scanf("%d", &temp);
        x[i][temp - 1] = j;
        y[i][temp - 1] = k;
      }
    }
  }

  while (scanf("%d", &num) == 1) {
    if (winner == 0) {
      for (i = 0; i < n; i++) {
        line[i][x[i][num - 1] + m]++;
        line[i][y[i][num - 1]]++;
        if (x[i][num - 1] == y[i][num - 1])
          line[i][2 * m]++;
        if (x[i][num - 1] + y[i][num - 1] == m - 1)
          line[i][2 * m + 1]++;
        if (line[i][x[i][num - 1] + m] == m ||
            line[i][y[i][num - 1]] == m ||
            line[i][2 * m] == m ||
            line[i][2 * m + 1] == m) {
          winner++;
          winnum = num;
          whowin[winner - 1] = i;
        }
      }
    }
  }
  printf("%d", winnum);
  for (i = 0; i < winner; i++) {
    printf(" %s", s[whowin[i]]);
  }
  return 0;
}
2
7
0 0
0 3
1 0
1 2
2 1
2 2
2 3
2
3 4
3 10