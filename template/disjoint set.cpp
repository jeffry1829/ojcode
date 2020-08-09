#include <bits/stdc++.h>
#define rank oiajgpowsdjg
using namespace std;

const int N = 100;
int parent[N], rank[N];
inline void dsinit(int n) {
  for (int i = 0; i < n; i++)
    parent[i] = i;
  memset(rank, 0, sizeof rank);
}
inline int dsfind(int e) { return parent[e] == e ? e : parent[e] = dsfind(parent[e]); }
inline void dsunion(int s1, int s2) {
  if (rank[s1] < rank[s2]) swap(s1, s2);
  parent[s2] = s1;
  if (rank[s1] == rank[s2]) rank[s1]++;
}