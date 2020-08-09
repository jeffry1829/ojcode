#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
struct IV {
  int c = 0;
  vector<int> v;
};
const int _N = 32;
int n;
IV f(int st, vector<int>& now) {
  IV r;
  if (st < n) {
    int k = 0;
    while (st % (now[k] + now[k + 1]) != 0 && k + 1 < (int)now.size()) k++;
    if (k == (int)now.size() - 1) return r;

    vector<int> now1;
    now1.assign(now.begin(), now.end());
    now1.insert(now1.begin() + k + 1, st);
    IV r1 = f(st + 1, now1);
    r.c += r1.c;
    r.v = r1.v;
    for (int i = k + 1; i < (int)now.size() - 1; i++) {
      if (st % (now[i] + now[i + 1]) != 0) continue;

      vector<int> now2;
      now2.assign(now.begin(), now.end());
      now2.insert(now2.begin() + i + 1, st);
      IV r2 = f(st + 1, now2);
      r.c += r2.c;
      if (r2.v > r.v) r.v = r2.v;
    }
  } else {
    int k = 0;
    while (st % (now[k] + now[k + 1]) != 0 && k + 1 < (int)now.size()) k++;
    if (k == (int)now.size() - 1) return r;
    vector<int> now1;
    now1.assign(now.begin(), now.end());
    now1.insert(now1.begin() + k + 1, st);
    r.c++;
    r.v = now1;
    for (int i = k + 1; i < (int)now.size() - 1; i++) {
      if (st % (now[i] + now[i + 1]) == 0) {
        r.c++;
      }
    }
  }
  return r;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n == 1) {
    cout << "1\n0 1\n";
    return 0;
  }
  vector<int> tmp = {0, 1};
  IV res = f(2, tmp);
  if (res.c == 0) {
    cout << 0;
    return 0;
  }
  cout << res.c << '\n';
  cout << res.v[0];
  for (int i = 1; i < (int)res.v.size(); i++) cout << " " << res.v[i];
  return 0;
}