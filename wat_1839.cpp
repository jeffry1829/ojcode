#include <bits/stdc++.h>
#include <lib1839.h>
using namespace std;

int n, S[5005], D[5005], right_bound;
inline int c(int x) {
  if (x == 1) return 0;
  if (x == 0) return 1;
  cout << "FUCK";
}
void _search(int left, int right, int doorIndex, bool begin_door_open) {  //[left,right]
  for (int i = left; i <= right; i++)
    if (D[i] == -1) S[i] = c(S[i]);
  int tmp = tryCombination(S);  // dont consider -1
  if (left == right) {
    if ((tmp == doorIndex && !begin_door_open) ||
        (tmp != doorIndex && begin_door_open)) {
      D[left + 1] = doorIndex;
      if (!begin_door_open) S[left + 1] = c(S[left + 1]);
    } else {
      D[left] = doorIndex;
      if (begin_door_open) S[left] = c(S[left]);
    }
    right_bound = n - 1;
    return;
  }
  if ((tmp == doorIndex && !begin_door_open) ||
      (tmp != doorIndex && begin_door_open)) {
    _search(right + 1, right_bound, doorIndex, tmp != doorIndex);
  } else {
    right_bound = right;
    _search(left, left + (right - left) / 2, doorIndex, tmp != doorIndex);
  }
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (1) {
    n = Initialize();
    fill(S, S + 5005, 0);
    fill(D, D + 5005, -1);
    right_bound = n - 1;
    for (int i = 0; i < n; i++) {
      int tmp = tryCombination(S);
      _search(0, (n - 1) / 2, i, tmp != i);
    }
    answer(S, D);
  }
  return 0;
}