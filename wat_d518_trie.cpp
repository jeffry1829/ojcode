#include <bits/stdc++.h>
using namespace std;
int N, M;
struct node {
  node* sigma[26] = {0};
  int num = 0;
};
node* root;
int counter = 0;
inline int f(char s[]) {
  int len = strlen(s);
  node* curr = root;
  for (int i = 0; i < len; i++) {
    int c = ((int)s[i]) - 97;
    if (curr->sigma[c] != 0) {
      curr = curr->sigma[c];
      if (i == len - 1) {
        if (curr->num != 0)
          return curr->num;
        else {
          curr->num = ++counter;
          return -curr->num;
        }
      }
    } else {
      for (; i < len; i++) {
        int c = ((int)s[i]) - 97;
        curr->sigma[c] = new node;
        curr = curr->sigma[c];
        if (i == len - 1) {
          curr->num = ++counter;
        }
      }
      return -curr->num;
    }
  }
  return 0;
}
void free_all(node*& curs) {
  if (!curs) return;
  for (int i = 0; i < 26; i++)
    free_all(curs->sigma[i]);
  delete curs;
  curs = NULL;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (cin >> N) {
    counter = 0;
    root = new node;
    while (N--) {
      char s[22];
      cin >> s;
      int res = f(s);
      if (res > 0) {
        cout << "Old! " << res << '\n';
      } else if (res == 0) {
        cout << "FUCK" << endl;
        exit(0);
      } else {
        cout << "New! " << -res << '\n';
      }
    }
    free_all(root);
  }
  return 0;
}