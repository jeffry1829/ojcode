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
typedef pair<ll,ll> PII;
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
int t,n,m;
PII p,prev,ps[_n];
db minn=1e9,maxx=-1e9,pi=acos(-1);
bool sgn(db x){
  return x>=0.0?0:1;
}
db cp(PII u,PII v){
  return (db)(u.fi*v.se-u.se*v.fi);
}
db len(PII u){
  return sqrt(u.fi*u.fi+u.se*u.se);
}
void f(PII x,PII y){
  PII tt2={y.fi-p.fi,y.se-p.se},tt3={x.fi-p.fi,x.se-p.se},tt1={-(tt3.se-tt2.se),tt3.fi-tt2.fi};
  db res1=len(tt2),res2=len(tt3),res3=abs((db)(tt1.fi*tt2.fi+tt1.se*tt2.se))/len(tt1);
  bool z=1;if(sgn(cp(tt1,tt2))==sgn(cp(tt1,tt3)))z=0;
  if(z){
    minn=min(minn,min(res1,min(res2,res3)));
    maxx=max(maxx,max(res1,max(res2,res3)));
  }else{
    minn=min(minn,min(res1,res2));
    maxx=max(maxx,max(res1,res2));
  }
}
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //這邊的PII必須是pair<ll,ll>
  cin>>n>>p.fi>>p.se;rep(i,0,n)cin>>ps[i].fi>>ps[i].se; prev=ps[0];
  rep(i,1,n)f(prev,ps[i]),prev=ps[i];
  f(prev,ps[0]);
  cout<<setprecision(20)<<pi*(maxx*maxx-minn*minn)<<'\n';
  return 0;
}