class Cmp{
  public:
  bool operator()(const PII& a,const PII& b) const {return d[a.fi][a.se]>d[b.fi][b.se];}
};
priority_queue<PII,vector<PII>,Cmp> pq;

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