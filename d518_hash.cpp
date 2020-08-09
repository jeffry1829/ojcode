#include <bits/stdc++.h>
using namespace std;
const int _PRIME = 3455227, _TABLE_SIZE = 64431893, _I = 97;
int hashmap[64431893] = {0};  //key-number
vector<int> used;
int counter = 0;
int N;

inline unsigned int genhash(char* str) {
  unsigned int seed = 131313;  // 31 131 1313 13131 131313 etc..
  unsigned int hash = 0;
  while (*str) {
    hash = hash * seed + (*str++);
  }
  return (hash & 0x7FFFFFFF) % _TABLE_SIZE;
}
inline int number(char s[]) {
  unsigned int res = genhash(s);
  if (hashmap[res] == 0) {
    hashmap[res] = ++counter;

    used.push_back(res);

    return hashmap[res];
  } else {
    return -hashmap[res];
  }
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> N) {
    for (int i = 0; i < used.size(); i++) {
      hashmap[used[i]] = 0;
    }
    used.clear();
    counter = 0;
    char s[23];
    while (N--) {
      cin >> s;
      int res = number(s);
      if (res > 0)
        cout << "New! " << res << '\n';
      else
        cout << "Old! " << -res << '\n';
    }
  }
  return 0;
}