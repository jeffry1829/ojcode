#include <ext/pb_ds/assoc_container.hpp>
class Solution {
 public:
  // unordered_map<string, int> mp;
  __gnu_pbds::gp_hash_table<string, int> mp;
  vector<string> solve(int st, const string& s, vector<string>& wordDict) {
    vector<string> res;
    string curstr = "";
    for (int i = st; i < s.size(); i++) {
      curstr += s[i];
      if (mp.find(curstr) != mp.end() and i != s.size() - 1) {
        vector<string> tmp = solve(i + 1, s, wordDict);
        for (string tmpstr : tmp) {
          res.push_back(curstr + " " + tmpstr);
        }
      } else if (mp.count(curstr) and i == s.size() - 1) {
        res.push_back(curstr);
      }
    }
    return res;
  }
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    for (int i = 0; i < wordDict.size(); i++) {
      mp[wordDict[i]] = i;
    }
    vector<string> ans = solve(0, s, wordDict);
    return ans;
  }
};