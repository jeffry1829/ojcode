#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _N = 1e5 + 10, _p = 1e9 + 7;
int N, M, K, t, a, b, id;
ll r[_N];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  while (M--) {
    cin >> t;
    switch (t) {
      int val;
      case 0:
        cin >> a >> b;
        val = (a * 1ll * 100000 + b * 1ll) % _p;
        if (a > b) swap(a, b);
        r[a] += val, r[b] -= val;
        break;
      case 1:
        cin >> a >> b;
        val = (a * 1ll * 100000 + b * 1ll) % _p;
        if (a > b) swap(a, b);
        r[a] -= val, r[b] += val;
        break;
      case 2:
        cin >> K;
        ll sum = 0;
        while (K--) {
          cin >> id;
          sum += r[id];
        }
        cout << (!sum) << '\n';
    }
  }
  return 0;
}