// https://www.cnblogs.com/week-end/articles/17652672.html
// https://www.luogu.com/article/rqkexmuc
struct custom_hash  // 手写的 hash 函数
{
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<long long, int, custom_hash> safe_map;
gp_hash_table<long long, int, custom_hash> safe_hash_table;

// To use rapidly
#include <ext/pb_ds/assoc_container.hpp>
__gnu_pbds::gp_hash_table<string, int> mp;
__gnu_pbds::gp_hash_table<int, int> mp;