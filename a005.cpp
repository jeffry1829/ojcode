#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    int arr[5];
    int type = 1;  //0=等比,1=
    for (int i = 0; i < 4; i++) {
      cin >> arr[i];
    }
    double res = arr[1] - arr[0];
    for (int i = 2; i < 4; i++) {
      if (arr[i] - arr[i - 1] != res) {
        type = 0;
        res = arr[1] / arr[0];
      }
    }
    switch (type) {
      case 0:
        arr[4] = arr[3] * res;
        break;
      case 1:
        arr[4] = arr[3] + res;
        break;
    }
    for (int i = 0; i < 5; i++) {
      cout << arr[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}