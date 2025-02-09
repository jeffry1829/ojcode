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
const int _n=1e6+10;
int t,n,m,dp[_n][9];
int a[3][_n];
VI nd[9];
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;if(n>=4){cout<<"-1\n";return 0;}
  if(n==1){cout<<"0\n";return 0;}
  cin.get();rep(i,0,n){
    rep(j,0,m){
      char c=cin.get(); a[i][j]=c-'0';
    }
    cin.get();
  }
  rep(i,0,m)rep(j,1,n)a[0][i]+=(1<<j)*a[j][i];
  rep(i,0,1<<n)rep(j,0,1<<n){
    rep(_,0,n-1){
      int cnt=0;
      if((1<<_)&i)cnt++;
      if((1<<(_+1))&i)cnt++;
      if((1<<_)&j)cnt++;
      if((1<<(_+1))&j)cnt++;
      if(!(cnt&1))goto A;
    }
    nd[i].pb(j);
    A:;
  }rep(j,0,1<<n)dp[0][j]=__builtin_popcount(j^a[0][0]);
  rep(i,1,m)rep(j,0,1<<n)dp[i][j]=0x7f7f7f7f;
  rep(i,1,m)rep(j,0,1<<n)for(int k:nd[j])
    dp[i][j]=min(dp[i][j],dp[i-1][k]+__builtin_popcount(j^a[0][i]));
  int minn=0x7f7f7f7f;rep(i,0,1<<n)minn=min(minn,dp[m-1][i]);
  cout<<minn<<'\n';
  return 0;
}