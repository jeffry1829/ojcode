#include <bits/stdc++.h>
using namespace std;
int order[256];
struct node {
  node *l, *r;
  char c;
  node() { l = NULL, r = NULL; }
  node(char c) : c(c) { l = NULL, r = NULL; }
};
void insert(node *&rr, node *t) {
  if (rr == NULL) {
    rr = t;
  } else {
    if (order[t->c] <= order[rr->c])
      insert(rr->l, t);
    else
      insert(rr->r, t);
  }
}
void remove(node *rr) {
  if (rr->l) remove(rr->l);
  if (rr->r) remove(rr->r);
  delete rr;
}
void post_dfs(node *rr) {
  if (rr->l) post_dfs(rr->l);
  if (rr->r) post_dfs(rr->r);
  cout << rr->c;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string pre, in;
  while (cin >> pre >> in) {
    for (int i = 0; i < in.length(); i++) order[in[i]] = i;
    node *root = new node(pre[0]);
    for (int i = 1; i < pre.length(); i++) insert(root, new node(pre[i]));
    post_dfs(root), remove(root);
    cout << '\n';
  }
  return 0;
}