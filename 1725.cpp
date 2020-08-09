#include <bits/stdc++.h>
using namespace std;
const int _N = 1000010;
char s1[_N], s1s2[_N * 3], revs1s2[_N * 3];  //s1s2 from s1
int Z1[_N * 3], lens1, lens1s2, N, Z2[_N * 3];
vector<int> answer;
int maxl = 0, lZl = 0;  //l+Z(l)
inline void gens1s2(char s[], char toccat[]) {
  strcat(s, "_");
  strcat(s, toccat);
  strcat(s, toccat);
}
inline int dcZ(int start, int from, char s[]) {  //directly calculate Z, S[start], S[from]
  int res = 0;
  for (int i = 0; i < lens1; i++) {
    if (s[i + from] == s[start + i])
      res++;
    else
      break;
  }
  return res;
}
inline void genZ(char s[], int Z[]) {
  Z[0] = 0;
  for (int i = 1; i < lens1s2; i++) {  //dont care Z[0]
    int ii = i - maxl;                 // i for i'
    if (lZl <= i) {
      Z[i] = dcZ(i, 0, s);
      maxl = i;
      lZl = maxl + Z[i];
    } else if (lZl > i && lZl > i + Z[ii]) {
      Z[i] = Z[ii];
    } else if (lZl > i && lZl == i + Z[ii]) {
      Z[i] = dcZ(lZl, Z[ii], s) + Z[ii];
      maxl = i;
      lZl = maxl + Z[i];
    } else if (lZl > i && lZl < i + Z[ii]) {
      Z[i] = Z[maxl] - ii;
      maxl = i;
    }
  }
}
inline int check(int from) {  //lens1+1+from
  //0:TAK -1:completely same 1:completely different
  int first = Z1[lens1 + 1 + from];
  if (first == lens1) return -1;
  if (first + Z2[2 * lens1 - from + 1] == lens1 - 1) return 0;
  return 1;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> s1 >> s1s2;
  lens1 = strlen(s1s2);
  strcpy(revs1s2, s1s2);
  gens1s2(s1s2, s1);
  reverse(revs1s2, revs1s2 + lens1);
  reverse(s1, s1 + lens1);  //////////
  gens1s2(revs1s2, s1);
  lens1s2 = strlen(s1s2);
  genZ(s1s2, Z1);
  maxl = 0;
  lZl = 0;
  genZ(revs1s2, Z2);
  for (int i = 0; i < lens1; i++) {
    int res = check(i);
    if (res == 0) {
      answer.push_back(i);
    } else if (res == -1) {
      cout << "NIE" << endl;
      exit(0);
    }
  }
  if (answer.size() == 0) {
    cout << "NIE\n";
  } else {
    cout << "TAK\n";
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i];
      if (i != answer.size() - 1) cout << " ";
    }
    cout << '\n';
  }
  return 0;
}