#include<stdio.h>
#define _N 11
#define _M 257
//typedef struct rc{int r,c;}rc;
int N, M;
int x[_N][_M*_M],y[_N][_M*_M];
//rc G[_N][_M*_M];
char names[_N][70];
int column[_N][_M]={0}, row[_N][_M]={0}, dia[_N][2]={0},t;
inline int gin(int *x) {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == -1) return 0;
  *x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') *x = *x * 10 + c - '0';
  return 1;
}
inline void init_G() {
  for (int i = 0; i < N; i++) {
    scanf("%s",names[i]);
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < M; k++) {
        gin(&t);
        x[i][t]=j;
        y[i][t]=k;
        //G[i][t].r = j;
        //G[i][t].c = k;
      }
    }
  }
}
int main(void) {
  gin(&N);
  gin(&M);
  init_G();
  int coutNum = 0;
  int end=0;
  while(gin(&t)) {
    if(end) break;
    for (int l = 0; l < N; l++) {
      int r=x[l][t],c=y[l][t];
      //int r = G[l][t].r;
      //int c = G[l][t].c;
      row[l][r]--;
      column[l][c]--;
      if (r == c) dia[l][0]--;
      if (r + c == M - 1) dia[l][1]--;
      if (row[l][r] == -M || column[l][c] == -M ||
          dia[l][0] == -M || dia[l][1] == -M) {
        end=1;
        if (!coutNum) {
          printf("%d",t);
          coutNum = 1;
        }
        printf(" %s",names[l]);
      }
    }
  }
  printf("\n");
  return 0;
}