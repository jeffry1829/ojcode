#include <bits/stdc++.h>
using namespace std;
int t, n, minn = 1;
char s[5010], mins[5010];
bool cmple(char *s1, char *s2, int from) {
  for (int i = from; i < n; i++) {
    if (s1[i] != s2[i - from]) {
      if (s1[i] < s2[i - from]) return 1;
      return 0;
    }
  }
  for (int i = from - 1, j = 0; i >= 0; i--, j++) {
    if (s1[i] != s2[n - from + j]) {
      if (s1[i] < s2[n - from + j]) return 1;
      return 0;
    }
  }
  return 0;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    minn = 1;
    strncpy(mins, s, n);
    mins[n] = '\0';
    for (int k = 2; k <= n; k++) {
      if (cmple(s, mins, k - 1)) {
        for (int i = k - 1; i < n; i++) mins[i - k + 1] = s[i];
        if (!((n - k) & 1))
          for (int i = k - 2, j = 0; i >= 0; i--, j++) mins[n - k + 1 + j] = s[i];
        if ((n - k) & 1)
          for (int i = 0, j = 0; i < k - 1; i++, j++) mins[n - k + 1 + j] = s[i];
        minn = k;
      }
    }
    cout << mins << '\n';
    cout << minn << '\n';
  }
  return 0;
}