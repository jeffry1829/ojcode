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
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
//#define end aononcncnccc
//head
const int _n=2e5+10;
int t,n,a,b,dep[_n],fa[_n];
PII dp[_n],dp2[_n];
VI G[_n];
vector<PII> v;
void dfs(int v,int faa){
  dep[v]=dep[faa]+1,fa[v]=faa,dp[v]={0,v};
  for(int u:G[v])if(u!=faa){
    dfs(u,v);
    if(dp[v].fi<dp[u].fi+1)dp[v]={dp[u].fi+1,dp[u].se};
  }
}
void dfs2(int v,int faa){
  vector<PII> vv;vv.pb({dp2[v].fi+1,dp2[v].se});
  for(int u:G[v])if(u!=faa)vv.pb({dp[u].fi+2,dp[u].se});
  sort(all(vv)),reverse(all(vv));
  for(int u:G[v])if(u!=faa){
    if(vv[0]!=make_pair(dp[u].fi+2,dp[u].se))dp2[u]=vv[0];
    else dp2[u]=vv[1];
  }
  for(int u:G[v])if(u!=faa)dfs2(u,v);
}
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;rep(i,0,n-1){cin>>a>>b;G[a].pb(b),G[b].pb(a);}
  dfs(1,0); dp2[1]={0,1}; dfs2(1,0);
  ll sum=0;VI ans;ans.pb(1),ans.pb(2),ans.pb(3);rep(i,1,n+1){
    v.clear();for(int u:G[i])if(u!=fa[i])v.pb({dp[u].fi+1,dp[u].se});
    v.pb(dp2[i]); if(i!=1)v.pb({0,i});
    sort(all(v)),reverse(all(v));
    if(SZ(v)>=3 and sum<v[0].fi+v[1].fi+v[2].fi){
      sum=v[0].fi+v[1].fi+v[2].fi,ans.clear();
      rep(j,0,3)ans.pb(v[j].se);
    }
    //if(SZ(v)==2 and sum<v[0].fi+v[1].fi+v[2].fi)
  }cout<<sum<<'\n';
  rep(i,0,3)cout<<ans[i]<<' '; cout<<'\n';
  return 0;
}