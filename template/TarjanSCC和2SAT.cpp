// 228E
const int _n = 100 + 10;
int t, n, m, T = 0;
VI G[_n * 2];
int id[_n * 2], low[_n * 2], scc[_n * 2];
stack<int> st;
void dfs(int v) {        // Tarjan SCC
  id[v] = low[v] = ++T;  // 前序
  st.push(v);
  for (int u : G[v]) {
    if (!id[u]) dfs(u);
    if (!scc[u]) low[v] = min(low[v], low[u]);  // 如果是要求BCC 就要判斷u!=father 然後不用判斷!scc[u]
  }
  if (low[v] == id[v]) {
    int temp;
    do {
      scc[temp = st.top()] = v;  // SCC是dfs的後序，剛好是縮點後的DAG的拓樸排序
      st.pop();
    } while (temp != v);
  }
}
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;  // 這跟題目有關 題目的vertex是1-indexed
    if (c) {
      G[a * 2 + 1].pb(b * 2 + 1);  // x*2 false, x*2+1 true
      G[b * 2 + 1].pb(a * 2 + 1);
      G[a * 2].pb(b * 2);
      G[b * 2].pb(a * 2);
    } else {
      G[a * 2 + 1].pb(b * 2);
      G[b * 2 + 1].pb(a * 2);
      G[b * 2].pb(a * 2 + 1);
      G[a * 2].pb(b * 2 + 1);
    }
  }
  rep(i, 0, n) {
    if (!id[i * 2]) dfs(i * 2);
    if (!id[i * 2 + 1]) dfs(i * 2 + 1);
  }
  // tarjan 算出來的scc 實際上是反過來的topo order
  // 而這剛好是我們找2-SAT最後的解要的：反過來的topo order

  // 檢查同個scc裡面有沒有 p and ~p，如果有，有矛盾，不可能
  rep(i, 0, n) {
    if (scc[i * 2] == scc[i * 2 + 1]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  VI ans;
  rep(i, 0, n) {
    // scc比較小的 出現在拓樸排序的比較後面
    if (scc[i * 2 + 1] < scc[i * 2]) {
      ans.pb(i + 1);  // 這跟題目有關 題目的vertex是1-indexed
    }
  }
  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}