#include <bits/stdc++.h>
using namespace std;
int t;
char a;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  cin.get();
  while (t--) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cin.get(a);
        if (a == '2')
          cout << '1';
        else
          cout << a;
      }
      cin.get();
      cout << '\n';
    }
  }
  return 0;
}