// 我抄一遍的
using it = vector<pair<int, int>>::iterator;
class Solution {
 public:
  vector<pair<int, int>> ele;
  vector<int> cnt;
  void mergesort(it l, it r) {
    if (r - l <= 1) return;
    it m = l + (r - l) / 2;
    mergesort(l, m);
    mergesort(m, r);
    for (it i = l, j = m; i < m; i++) {
      while (j < r and (*j).first < (*i).first) j++;
      cnt[(*i).second] += j - m;
    }
    inplace_merge(l, m, r);
  }
  vector<int> countSmaller(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      ele.push_back({nums[i], i});
    }
    cnt = vector<int>(nums.size(), 0);
    mergesort(ele.begin(), ele.end());
    return cnt;
  }
};

// 別人的模板
// [l, r) is the interval to be sorted
int sort_count(iterator l, iterator r) {
  if (r - l <= 1) return;
  // step 1. find the middle
  iterator m = l + (r - l) / 2;
  // step 2. sort left and right subarray
  int count = sort_count(l, m) + sort_count(m, r);
  /* step 3. write your code here for counting the pairs (i, j).*/

  // step 4. call inplace_merge to merge
  inplace_merge(l, m, r);
  return count;
}

// 315. Count of Smaller Numbers After Self
#define iterator vector<vector<int>>::iterator
void sort_count(iterator l, iterator r, vector<int>& count) {
  if (r - l <= 1) return;
  iterator m = l + (r - l) / 2;
  sort_count(l, m, count);
  sort_count(m, r, count);
  for (iterator i = l, j = m; i < m; i++) {
    while (j < r && (*i)[0] > (*j)[0]) j++;
    count[(*i)[1]] += j - m;  // add the number of valid "j"s to the indices of *i
  }
  inplace_merge(l, m, r);
}
vector<int> countSmaller(vector<int>& nums) {
  vector<vector<int>> hold;
  int n = nums.size();
  for (int i = 0; i < n; ++i) hold.push_back(vector<int>({nums[i], i}));  // "zip" the nums with their indices
  vector<int> count(n, 0);
  sort_count(hold.begin(), hold.end(), count);
  return count;
}