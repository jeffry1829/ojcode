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
#define y1 ojsapogjahg
#define prev ojaposjdas
//#define end aononcncnccc
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
//head
const int _n=1e5+10;
int t,n,m,s,l,u,v,w,dis[_n];
vector<PII> G[_n],G2[_n];
bool vis[_n];
struct WE{
  int f,t,w,we;
  bool operator<(const WE& rhs)const{return w>rhs.w;}
};
priority_queue<WE> pq;
ll ans;
void dfs(int v,int fa){
  if(dis[v]>=l){ans++;return;}
  for(PII uu:G2[v])if(uu.fi!=fa)dfs(uu.fi,v);
  for(PII uu:G[v])if(uu.fi!=fa and dis[v]+uu.se>l)ans++;
}
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n>>m>>s;while(m--){cin>>u>>v>>w;G[u].pb({v,w}),G[v].pb({u,w});}cin>>l;
  rep(i,1,n+1)dis[i]=1e9;
  dis[s]=0;for(PII uu:G[s])pq.push({s,uu.fi,uu.se,uu.se});vis[s]=1;
  rep(o,0,n-1){
    WE now=pq.top();pq.pop();
    if(vis[now.t])continue;
    dis[now.t]=now.w;vis[now.t]=1;
    G2[now.f].pb({now.t,now.we}),G2[now.t].pb({now.f,now.we});
    for(PII uu:G[now.t])if(!vis[uu.fi])pq.push({now.t,uu.fi,now.w+uu.se,uu.se});
  }
  dfs(s,0);
  rep(i,1,n+1)cout<<dis[i]<<' '; cout<<'\n';
  cout<<ans<<'\n';
  return 0;
}