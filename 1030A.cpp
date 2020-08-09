#include <bits/stdc++.h>
using namespace std;
bool ez = 1;
int n, x;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x) {
      ez = 0;
      break;
    }
  }
  if (ez) {
    cout << "EASY\n";
  } else {
    cout << "HARD\n";
  }
  return 0;
}