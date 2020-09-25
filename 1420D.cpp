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
const ll mod=998244353;
int rnd(int x){return mrand()%x;}
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
//#define end aononcncnccc
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
#define la kaofjpfo
//head
const int _n=3e5+10,MAXB=21;
int t,n,k,a,b;
PII la[_n];
int fac[_n],inv[_n];
void exgcd(int a,int b,int& d,int& x,int& y){
  if(!b)x=1,y=0,d=a;
  else exgcd(b,a%b,d,y,x),y-=x*(a/b);
}
int C(int m,int n){
  if(m<n)return 0;
  if(m<mod and n<mod)return 1ll*fac[m]*inv[n]%mod*inv[m-n]%mod;
  return 1ll*C(m/mod,n/mod)*C(m%mod,n%mod)%mod;
}
void genInv(){
  fac[0]=1;rep(i,1,n+1)fac[i]=1ll*fac[i-1]*i%mod;
  //int tmp1,tmp2;rep(i,0,n+1)exgcd(fac[i],mod,tmp1,inv[i],tmp2);
  rep(i,0,n+1)inv[i]=powmod(fac[i],mod-2);
}
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>k;rep(i,0,n){cin>>a>>b; la[i].fi=a,la[i].se=b;} 
  sort(la,la+n); genInv(); ll ans=0;
  per(i,0,n){
    int res1=0;per(j,0,MAXB)if(res1+(1<<j)<i and la[res1+(1<<j)].se<la[i].fi)res1+=(1<<j);
    t=i-res1;
    ans+=C(t,k-1),ans%=mod;
  }cout<<ans<<'\n';
  return 0;
}