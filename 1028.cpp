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
const int _n=13;
int t,n,m,a,b,w,k;
PII prev[1<<_n][_n],dis[1<<_n][_n];
struct WE{int x,y,d;};
vector<WE> e;
VI ks;
bool ok(int x){
  rep(i,0,SZ(ks))if(!(x&(1<<ks[i])))return 0;
  return 1;
}
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;rep(i,0,m){cin>>a>>b>>w;e.pb({a,b,w}),e.pb({b,a,w});};
  cin>>k;rep(i,0,k){cin>>a;ks.pb(a);} rep(i,0,1<<_n)rep(j,0,n)dis[i][j].fi=1e5; dis[1<<ks[0]][ks[0]]={0,1}; prev[1<<ks[0]][ks[0]]={-1,-1};
  rep(_,0,n-1){
    rep(__,0,SZ(e)){
      int u=e[__].x,v=e[__].y,d=e[__].d;
      rep(i,0,1<<n)if((i&(1<<u)) and (i&(1<<v))){
        if(dis[i][v].fi>dis[i][u].fi+d)dis[i][v].fi=dis[i][u].fi+d,dis[i][v].se=dis[i][u].se+1,prev[i][v]={i,u};
        if(dis[i][v].fi>dis[i^(1<<v)][u].fi+d)dis[i][v].fi=dis[i^(1<<v)][u].fi+d,dis[i][v].se=dis[i^(1<<v)][u].se+1,prev[i][v]={i^(1<<v),u};
        if(dis[i][v].fi==dis[i][u].fi+d)if(dis[i][v].se>=dis[i][u].se and (dis[i][v].se>dis[i][u].se or u<prev[i][v].se))prev[i][v]={i,u};
        if(dis[i][v].fi==dis[i^(1<<v)][u].fi+d)if(dis[i][v].se>=dis[i^(1<<v)][u].se and (dis[i][v].se>dis[i^(1<<v)][u].se or u<prev[i][v].se))prev[i][v]={i^(1<<v),u};
      }
    }
  }PII ans={1e9,1e9},ans2={0,0};rep(i,0,1<<n)if(ok(i))rep(j,0,n)if(dis[i][j].fi<ans.fi or (dis[i][j].fi==ans.fi and dis[i][j].se<ans.se))ans={dis[i][j].fi,dis[i][j].se},ans2={i,j};
  cout<<"Minimum travel distance: "<<ans.fi<<"\nTravel route: ";
  ans={ans2.fi,ans2.se};
  VI AC;while(~ans.fi){
    AC.pb(ans.se);
    ans=prev[ans.fi][ans.se];
  }per(i,0,SZ(AC))cout<<AC[i]<<' '; cout<<'\n';
  return 0;
}