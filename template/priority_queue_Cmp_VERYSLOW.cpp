class Cmp{
  public:
  bool operator()(const PII& a,const PII& b) const {return d[a.fi][a.se]>d[b.fi][b.se];}
};
priority_queue<PII,vector<PII>,Cmp> pq;