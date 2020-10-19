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
int t,n,m,s,l,u,v,w,dis[_n],fa[_n];
vector<PII> G[_n];
bool vis[_n];
struct WE{
  int f,t,d;
  bool operator<(const WE& rhs)const{return d>rhs.d;}
} e[_n];
priority_queue<WE> pq;
ll ans;
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n>>m>>s;rep(i,0,m){cin>>u>>v>>w;G[u].pb({v,w}),G[v].pb({u,w});e[i]={u,v,w};}
  cin>>l;rep(i,1,n+1)dis[i]=1e9;
  dis[s]=0;for(PII uu:G[s])pq.push({s,uu.fi,uu.se});vis[s]=1;
  rep(_,0,n-1){
    WE now=pq.top();pq.pop();
    if(vis[now.t]){_--;continue;}
    dis[now.t]=now.d;vis[now.t]=1;fa[now.t]=now.f;
    for(PII uu:G[now.t])if(!vis[uu.fi])pq.push({now.t,uu.fi,now.d+uu.se});
  }rep(i,1,n+1)if(dis[i]==l)ans++;
  rep(i,0,m){
    int a=l-dis[e[i].f],b=l-dis[e[i].t];
    if(fa[e[i].f]!=e[i].t and dis[e[i].f]<l and dis[e[i].f]+e[i].d>l and dis[e[i].f]+a<=dis[e[i].t]+e[i].d-a)ans++;
    if(fa[e[i].t]!=e[i].f and dis[e[i].t]<l and dis[e[i].t]+e[i].d>l and dis[e[i].t]+b<=dis[e[i].f]+e[i].d-b)ans++;
    if(fa[e[i].f]!=e[i].t and dis[e[i].f]<l and dis[e[i].f]+e[i].d>l and
      dis[e[i].t]+b<=dis[e[i].f]+e[i].d-b and dis[e[i].f]+a<=dis[e[i].t]+e[i].d-a 
      and fa[e[i].t]!=e[i].f and dis[e[i].t]<l and dis[e[i].t]+e[i].d>l 
      and l-dis[e[i].f]==e[i].d-l+dis[e[i].t])ans--;
  }cout<<ans<<'\n';
  return 0;
}