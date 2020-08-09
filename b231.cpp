#include <bits/stdc++.h>
using namespace std;

bool cmpgreater(pair<int, int> p1, pair<int, int> p2) {
  return p1.second > p2.second;
}

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  while (cin >> n) {
    vector<pair<int, int> > books;
    books.reserve(1001);
    for (int i = 0; i < n; i++) {
      int pr, bi;
      cin >> pr >> bi;
      books.push_back(make_pair(pr, bi));
    }
    sort(books.begin(), books.end(), cmpgreater);
    int maxTime = 0, nowTime = 0;
    for (int i = 0; i < n; i++) {
      nowTime += books[i].first;
      maxTime = max(maxTime, nowTime + books[i].second);
    }
    cout << maxTime << '\n';
  }
  return 0;
}