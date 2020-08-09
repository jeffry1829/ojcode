#include <bits/stdc++.h>
using namespace std;
bool vis[200];
char c;
int cnt = 0;
main(void) {
  while (1) {
    while (c = getchar(), c < 'a' or c > 'z')
      if (c == -1) goto A;
    if (!vis[c]) cnt++, vis[c] = 1;
  }
A:
  printf("%d\n", cnt);
  return 0;
}