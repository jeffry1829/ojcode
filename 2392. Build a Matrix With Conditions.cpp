class Solution {
 public:
  inline static int lefttime[10010] = {0};
  vector<int> E[10010];
  bool vis[10010], visthistime[10010];
  static bool custom_cmp(const int& a, const int& b) {
    return lefttime[a] > lefttime[b];
  }
  int dfs(int v, int in) {
    vis[v] = true;
    int out = in;
    visthistime[v] = true;
    for (auto u : E[v]) {
      if (visthistime[u]) return -1;
      if (!vis[u]) {
        out = dfs(u, in + 1);
      }
      if (out == -1) return -1;
    }
    lefttime[v] = out + 1;
    visthistime[v] = false;
    return true;
  }
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<vector<int>> ans(k, vector<int>(k, 0));
    for (int i = 0; i < rowConditions.size(); i++) {
      E[rowConditions[i][0]].push_back(rowConditions[i][1]);
    }
    int curout = -1;
    for (int v = 1; v <= k; v++) {
      if (!vis[v]) {
        int tmp = dfs(v, curout + 1);
        if (tmp == -1) {
          return {};
        }
        curout = tmp;
      }
    }
    vector<int> rowSort(k + 1, 0);
    iota(rowSort.begin(), rowSort.end(), 0);
    sort(rowSort.begin() + 1, rowSort.end(), custom_cmp);
    for (int i = 0; i < k + 1; i++) {
      vis[i] = false;
      visthistime[i] = false;
      lefttime[i] = 0;
      E[i].clear();
    }
    for (int i = 0; i < colConditions.size(); i++) {
      E[colConditions[i][0]].push_back(colConditions[i][1]);
    }
    curout = -1;
    for (int v = 1; v <= k; v++) {
      if (!vis[v]) {
        int tmp = dfs(v, curout + 1);
        if (tmp == -1) {
          return {};
        }
        curout = tmp;
      }
    }
    vector<int> colSort(k + 1, 0);
    iota(colSort.begin(), colSort.end(), 0);
    sort(colSort.begin() + 1, colSort.end(), custom_cmp);

    vector<vector<int>> toplace(k + 1, vector<int>(2, 0));
    for (int i = 1; i < k + 1; i++) {
      toplace[rowSort[i]][0] = i;
      toplace[colSort[i]][1] = i;
    }
    for (int i = 1; i < k + 1; i++) {
      ans[toplace[i][0] - 1][toplace[i][1] - 1] = i;
    }
    return ans;
  }
};