#include <bits/stdc++.h>
#define add askdfjosdgns
#define sub akmfosdgbmmm
using namespace std;
char s[20];
int n, ar[4], b[4] = {2, 3, 5, 7};
void add(int x) {
  switch (x) {
    case 2:
      ar[0]++;
      break;
    case 3:
      ar[0]++, ar[1]++;
      break;
    case 4:
      ar[0] += 3, ar[1]++;
      break;
    case 5:
      ar[0] += 3, ar[1]++, ar[2]++;
      break;
    case 6:
      ar[0]++, ar[1]++, add(5);
      break;
    case 7:
      ar[3]++, add(6);
      break;
    case 8:
      ar[0] += 3, add(7);
      break;
    case 9:
      ar[1] += 2, add(8);
      break;
    default:
      break;
  }
}
void sub(int x, int t) {
  while (t--) {
    switch (x) {
      case 3:
        ar[0]--;
        break;
      case 5:
        ar[0] -= 3, ar[1]--;
        break;
      case 7:
        ar[0] -= 4, ar[1] -= 2, ar[2]--;
        break;
      default:
        break;
    }
  }
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) add(s[i] - '0');
  for (int i = 3; i >= 1; i--) sub(b[i], ar[i]);
  for (int i = 3; i >= 0; i--) {
    while (ar[i]--) cout << b[i];
  }
  cout << '\n';
  return 0;
}