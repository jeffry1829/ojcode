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
//#define int long long
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
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
//#define end aononcncnccc
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
//head
const int _n=1e5+10;
int t,n,m,p[_n],x,y,dp[_n],dep[_n];
VI G[_n];
PII e[_n];
ll ecnt[_n];
void dfs(int v,int fa,int d){
  dep[v]=d;
  if(SZ(G[v])==1 and G[v][0]==fa){dp[v]=1;return;}
  int res=1;
  rep(i,0,SZ(G[v]))if(fa!=G[v][i])dfs(G[v][i],v,d+1),res+=dp[G[v][i]];
  dp[v]=res;
}
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>t;while(t--){
    cin>>n;rep(i,0,n)G[i].clear();
    rep(i,0,n-1){cin>>x>>y;x--,y--;G[x].pb(y),G[y].pb(x);e[i]={x,y};}
    cin>>m;rep(i,0,m)cin>>p[i]; sort(p,p+m);
    dfs(0,-1,0); ll ans=0;rep(i,0,n-1){
      int u=e[i].fi,v=e[i].se;
      if(dep[u]>dep[v])swap(u,v);
      ecnt[i]=1ll*dp[v]*(n-dp[v]);
    } sort(ecnt,ecnt+n-1);
    if(n-1>m){
      int len=max(0,n-1-m);
      rep(i,0,len)ans+=ecnt[i],ans%=mod;
      rep(i,len,len+m)ans+=1ll*p[i-len]*ecnt[i],ans%=mod;
    }
    if(m>=n-1){
      rep(i,0,n-2)ans+=1ll*p[i]*ecnt[i],ans%=mod;
      ll tmp=1;rep(i,n-2,m)tmp*=1ll*p[i],tmp%=mod;
      ans+=1ll*tmp*(ecnt[n-2]%mod); ans%=mod;
    }
    cout<<ans<<'\n';
  }
  return 0;
}