#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  /*
   *三振的 K (Strikeout)，代表保送的 W (Walk)，以及一壘安打 S (Single)，二壘安打
   *D (Double)，三壘安打 T (Three bases?)，全壘打 H (Home Run)以及其他的出局狀況
   *O
   */
  char ipt[10001];
  while (cin >> ipt) {
    int iptlen = strlen(ipt);
    int half = 3;
    int halfs = 18;
    int half_passed = 0;
    int bags[3] = {0};
    int teams[2] = {0};
    int now_team = 0;
    for (int i = 0; i < iptlen; i++) {
      switch (ipt[i]) {
        case 'O':
        case 'K':
          half--;
          if (half == 0) {
            halfs--;
            half = 3;
            half_passed++;
            now_team = half_passed % 2;
            fill(bags, bags + 3, 0);
          }
          if (halfs == 0) {
            cout << teams[0] << " " << teams[1] << '\n';
          }
          break;
        case 'W':
          if (bags[0]) {
            if (bags[1]) {
              if (bags[2]) {
                bags[0] = true;
                bags[1] = true;
                bags[2] = true;
                teams[now_team]++;
              } else {
                bags[0] = true;
                bags[1] = true;
                bags[2] = true;
              }
            } else {
              bags[1] = true;
              bags[0] = true;
            }
          } else {
            bags[0] = true;
          }
          break;
        case 'S':
          if (bags[2]) {
            teams[now_team]++;
            bags[2] = false;
          }
          if (bags[1]) {
            bags[2] = true;
            bags[1] = false;
          }
          if (bags[0]) {
            bags[1] = true;
            bags[0] = false;
          }
          bags[0] = true;
          break;
        case 'D':
          if (bags[2]) {
            teams[now_team]++;
            bags[2] = false;
          }
          if (bags[1]) {
            teams[now_team]++;
            bags[1] = false;
          }
          if (bags[0]) {
            bags[2] = true;
            bags[0] = false;
          }
          bags[1] = true;
          break;
        case 'T':
          if (bags[2]) {
            teams[now_team]++;
            bags[2] = false;
          }
          if (bags[1]) {
            teams[now_team]++;
            bags[1] = false;
          }
          if (bags[0]) {
            teams[now_team]++;
            bags[0] = false;
          }
          bags[2] = true;
          break;
        case 'H':
          if (bags[2]) teams[now_team]++;
          if (bags[1]) teams[now_team]++;
          if (bags[0]) teams[now_team]++;
          teams[now_team]++;
          fill(bags, bags + 3, 0);
          break;
      }
    }
  }
  return 0;
}