#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  char A[1000000], B[1000000];
  int T;
  cin >> A >> B >> T;
  int strA = strlen(A), strB = strlen(B);
  int lcm_str = lcm(strA, strB);
  int sum = 0;
  int lcm_sum = 0;
  if (T / lcm_str == 0) goto a;
  for (int i = 0; i < lcm_str; i++) {
    int iA = (i % strA);
    int iB = (i % strB);
    lcm_sum += (26 - abs((int)A[iA] - (int)B[iB]));
  }
a:;
  sum = lcm_sum * (T / lcm_str);
  int len_left = T % lcm_str;
  for (int i = 0; i < len_left; i++) {
    int iA = (i % strA);
    int iB = (i % strB);
    sum += (26 - abs((int)A[iA] - (int)B[iB]));
  }
  cout << sum;
  return 0;
}