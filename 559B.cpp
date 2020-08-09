#include <bits/stdc++.h>
using namespace std;

string A, B, R;
inline void _f(string &a) {
  if (a.size() % 2) return;
  string t1 = a.substr(0, a.size() / 2), t2 = a.substr(a.size() / 2, a.size());
  _f(t1), _f(t2);
  if (t1 > t2)
    a = t2 + t1;
  else
    a = t1 + t2;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> A >> B;
  _f(A), _f(B);
  if (A == B)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}