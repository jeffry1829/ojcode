//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
//#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define abs(x) (((x)<0)?(-(x)):(x))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x){return mrand()%x;}
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
#define rank oiajgpowsdjg
const int N = 100;
int parent[N], rank[N];
inline void dsinit(int n) {for (int i = 0; i < n; i++)parent[i] = i;memset(rank, 0, sizeof rank);}
inline int dsfind(int e) {return parent[e] == e ? e : parent[e] = dsfind(parent[e]);}
inline void dsunion(int s1, int s2) {if (rank[s1] < rank[s2])swap(s1, s2);parent[s2] = s1;if (rank[s1] == rank[s2]) rank[s1]++;}
#define y1 ojsapogjahg
#define prev ojaposjdas
//#define end aononcncnccc
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
//head
const int _n=2010,MAXB=13;
int t,n,dep[_n],fa[_n][MAXB];
ll d[_n][_n],dis[_n];
vector<PII> G[_n];
bool vis[_n];
struct node{
  int f,t,w;
  bool operator<(const node& rhs) const {return w>rhs.w;}
};
class Cmp{
  public:
  bool operator()(const PII& a,const PII& b) const {return d[a.fi][a.se]>d[b.fi][b.se];}
};
priority_queue<node> pq;
void dfs(int v,int faa,ll len){
  dep[v]=dep[faa]+1;dis[v]=dis[faa]+len;fa[v][0]=faa;
  rep(i,0,SZ(G[v]))if(faa!=G[v][i].fi)dfs(G[v][i].fi,v,G[v][i].se);
}
void bfa(){
  rep(j,1,MAXB)rep(i,1,n+1)if(~fa[i][j-1])
    fa[i][j]=fa[fa[i][j-1]][j-1];
}
int lca(int a,int b){
  if(dep[a]<dep[b])swap(a,b);
  per(j,0,MAXB)if(~fa[a][j] and dep[fa[a][j]]>=dep[b])a=fa[a][j];
  if(a==b)return a;
  per(j,0,MAXB)if(~fa[a][j] and fa[a][j]!=fa[b][j])a=fa[a][j],b=fa[b][j];
  return fa[a][0];
}
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n;rep(i,1,n+1)rep(j,1,n+1)cin>>d[i][j];
  rep(i,1,n+1)rep(j,i,n+1)if((i==j and d[i][i]) or d[i][j]!=d[j][i] or (i!=j and d[i][j]==0)){cout<<"NO\n";return 0;}
  pq.push({0,1});
  while(!pq.empty()){
    /*PII now;while(!pq.empty() and vis[(now=pq.top()).se])pq.pop();
    if(pq.empty())break;*/
    node now=pq.top(); pq.pop();
    if(vis[now.t])continue;
    vis[now.t]=1;
    G[now.f].pb({now.t,d[now.f][now.t]});
    //if(now.fi!=0)G[now.se].pb({now.fi,d[now.se][now.fi]});
    rep(i,1,n+1)if(!vis[i])pq.push({now.t,i,d[now.t][i]});
  }
  dep[0]=-1;dfs(1,0,0);rep(i,1,n+1)rep(j,1,MAXB)fa[i][j]=-1; bfa();
  rep(i,1,n+1)rep(j,i,n+1){
    int l=lca(i,j);
    if(d[i][j]!=dis[i]+dis[j]-dis[l]*2){cout<<"NO\n";return 0;}
  }cout<<"YES\n";
  return 0;
}