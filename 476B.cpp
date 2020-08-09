#include <bits/stdc++.h>
using namespace std;
char s1[20], s2[20];
int a = 0, b = 0, len, m = 0, fac[13];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s1 >> s2;
  len = strlen(s1);
  for (int i = 0; i < len; i++) {
    if (s1[i] == '+')
      a++;
    else
      a--;
  }
  for (int i = 0; i < len; i++) {
    if (s2[i] == '+')
      b++;
    else if (s2[i] == '-')
      b--;
    else if (s2[i] == '?')
      m++;
  }
  fac[0] = 1;
  for (int i = 1; i <= 12; i++) fac[i] = fac[i - 1] * i;
  int n = a - b, ans = 0;
  cout.precision(10);
  if ((m - n) & 1)
    ans = 0;
  else if (m < abs(n))
    ans = 0;
  else
    ans = fac[m] / fac[(m + n) / 2] / fac[(m - n) / 2];
  cout << (double)ans / (double)(1 << m) << '\n';
  return 0;
}