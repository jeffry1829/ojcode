#include <bits/stdc++.h>
#include "lib1341.h"
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, X0, Y0;
  Init(&N, &X0, &Y0);

  int X_offset = 0, M = 1, step = 1;
  while (X0 + step <= N && Examine(X0 + step, Y0)) {
    step *= 2;
  }
  step /= 2;
  X_offset += step;
  M += step;
  for (int i = X0 + step + 1; i <= N; i++) {
    if (!Examine(i, Y0)) break;
    X_offset++;
    M++;
  }

  step = 1;
  while (X0 - step >= 1 && Examine(X0 - step, Y0)) {
    step *= 2;
  }
  step /= 2;
  X_offset -= step;
  M += step;
  for (int i = X0 - step - 1; i >= 1; i--) {
    if (!Examine(i, Y0)) break;
    X_offset--;
    M++;
  }

  int Y_offset = 0;
  step = 1;
  while (Y0 + step <= N && Examine(X0, Y0 + step)) {
    step *= 2;
  }
  step /= 2;
  Y_offset += step;
  for (int i = Y0 + step + 1; i <= N; i++) {
    if (!Examine(X0, i)) break;
    Y_offset++;
  }
  Y_offset -= (M - Y_offset - 1);

  pair<int, int> local_cen = make_pair(X0 + X_offset / 2, Y0 + Y_offset / 2);
  X_offset = 0;
  for (int i = local_cen.first - 2 * M; i >= 1; i -= 2 * M) {
    if (!Examine(i, Y0)) break;
    X_offset -= 2 * M;
  }
  for (int i = local_cen.first + 2 * M; i <= N; i += 2 * M) {
    if (!Examine(i, Y0)) break;
    X_offset += 2 * M;
  }
  Y_offset = 0;
  for (int i = local_cen.second - 2 * M; i >= 1; i -= 2 * M) {
    if (!Examine(X0, i)) break;
    Y_offset -= 2 * M;
  }
  for (int i = local_cen.second + 2 * M; i <= N; i += 2 * M) {
    if (!Examine(X0, i)) break;
    Y_offset += 2 * M;
  }
  Solution(local_cen.first + X_offset / 2, local_cen.second + Y_offset / 2);
  return 0;
}