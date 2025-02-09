#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    vector<int> cnttarget(1001, 0), cntarr(1001, 0);
    for (int i = 0; i < target.size(); i++) {
      cnttarget[target[i]]++;
    }
    for (int i = 0; i < arr.size(); i++) {
      cntarr[arr[i]]++;
    }
    bool ok = true;
    for (int i = 1; i <= 1000; i++) {
      if (cnttarget[i] != cntarr[i]) {
        ok = false;
        break;
      }
    }
    return ok;
  }
};