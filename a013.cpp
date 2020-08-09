#include <bits/stdc++.h>
using namespace std;
int ch2lev(char c) {
  switch (c) {
    case 'M':
      return 6;
    case 'D':
      return 5;
    case 'C':
      return 4;
    case 'L':
      return 3;
    case 'X':
      return 2;
    case 'V':
      return 1;
    case 'I':
      return 0;
  }
}
char lev2ch(int lev) {
  switch (lev) {
    case 6:
      return 'M';
    case 5:
      return 'D';
    case 4:
      return 'C';
    case 3:
      return 'L';
    case 2:
      return 'X';
    case 1:
      return 'V';
    case 0:
      return 'I';
  }
}
void ipt2ro(int ro1[], int ro2[]) {
  int* ro = ro1;
  char ipt[100];
  cin.getline(ipt, 100);
  if (ipt[0] == '#') exit(0);
  int prev_lev = 6;
  for (int i = 0; ipt[i] != '\0'; i++) {
    if (ipt[i] == ' ') {
      ro = ro2;
      prev_lev = 6;
      continue;
    }
    if (prev_lev < ch2lev(ipt[i])) {
      if (ch2lev(ipt[i]) - prev_lev == 1)
        ro[prev_lev] = 4;
      else {
        ro[prev_lev] = 4;
        ro[prev_lev + 1] = 1;
      }
      continue;
    }
    prev_lev = min(prev_lev, ch2lev(ipt[i]));
    ro[ch2lev(ipt[i])]++;
  }
}
int ro2num(int ro[]) {
  int sum = 0;
  for (int i = 0; i < 7; i++) sum += (i + 1) * ro[i];
  return sum;
}
int gi5ou2(int x) {
  if (x % 2 == 0)
    return 2;
  else
    return 5;
}
void sub(int ro1[], int ro2[], int ro3[]) {
  if (ro2num(ro1) < ro2num(ro2)) {
    sub(ro2, ro1, ro3);
    return;
  }
  for (int i = 0; i < 7; i++) ro3[i] = ro1[i] - ro2[i];
  for (int i = 0; i < 7; i++)
    if (ro3[i] < 0) {
      ro3[i + 1]--;
      ro3[i] += gi5ou2(i + 1);
    }
}
void printro(int ro[]) {
  bool isZERO = true;
  for (int i = 6; i >= 0; i--) {
    if (ro[i] != 0) isZERO = false;
    if (i == 5 && ro[5] == 1 && ro[4] == 4) {
      cout << "CM";
      i--;
      continue;
    }
    if (i == 3 && ro[3] == 1 && ro[2] == 4) {
      cout << "XC";
      i--;
      continue;
    }
    if (i == 1 && ro[1] == 1 && ro[0] == 4) {
      cout << "IX";
      i--;
      continue;
    }
    if (ro[i] == 4) {
      cout << lev2ch(i) << lev2ch(i + 1);
      continue;
    }
    for (int j = 0; j < ro[i]; j++) cout << lev2ch(i);
  }
  if (isZERO) cout << "ZERO";
  cout << "\n";
}
main(void) {
  while (true) {
    int ro1[7] = {0}, ro2[7] = {0}, ro3[7] = {0};
    ipt2ro(ro1, ro2);
    sub(ro1, ro2, ro3);
    printro(ro3);
  }
  return 0;
}