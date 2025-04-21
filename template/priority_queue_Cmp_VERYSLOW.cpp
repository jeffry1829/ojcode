// pbds
// #include <ext/pb_ds/priority_queue.hpp>
#include <bits/extc++.h>  // include這個就好了
using namespace __gnu_pbds;
__gnu_pbds::priority_queue<long long, decltype([](long long& a, long long& b) {
                             return a > b;
                           })>
    pq;
__gnu_pbds::priority_queue<int> q;  // 因为名字和std重复，故需要带上命名空间
__gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>, binary_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>, binomial_heap_tag> pq;  // 好像是最快的
__gnu_pbds::priority_queue<int, greater<int>, rc_binomial_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>, thin_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>> pq;

// 這應該蠻不錯的 沒有測速度
// 測起來比pbds的還快 (?)
priority_queue<long long, vector<long long>, decltype([](long long& a, long long& b) { return a > b; })> pq;
priority_queue<long long, vector<long long>, greater<long long>> pq;

// 神奇的reserve方法
std::vector<unsigned char> container;
container.reserve(1024);
std::priority_queue<unsigned char, std::vector<unsigned char>, std::less<unsigned char>> pq(std::less<unsigned char>(), std::move(container));

class Cmp {
 public:
  bool operator()(const PII& a, const PII& b) const { return d[a.fi][a.se] > d[b.fi][b.se]; }
};
priority_queue<PII, vector<PII>, Cmp> pq;

/*
搞了三個小時，不知道為什麼會TLE
有人知道為什麼
struct node{
  int f,t,w;
  bool operator<(const node& rhs) const {return w>rhs.w;}
};
priority_queue<node> pq;
遠好於
class Cmp{
  public:
  bool operator()(const PII& a,const PII& b) const {return d[a.fi][a.se]>d[b.fi][b.se];}
};
priority_queue<PII,vector<PII>,Cmp> pq;
嗎?
*/