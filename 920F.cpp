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
const int _n=3e5+10,_d=1e6+10;
int n,m,s[_n],d[_d];
struct Seg{
  int nn;
  ll t[_n<<2],tt[_n<<2];
  void pull(int v){t[v]=t[2*v+1]+t[2*v+2],tt[v]=max(tt[2*v+1],tt[2*v+2]);}
  void apply(int v){t[v]=d[t[v]];tt[v]=t[v];}
  void build(int v, int l, int r){
    if(l+1==r)tt[v]=t[v]=s[l];
    else{int m=(l+r)>>1;build(2*v+1,l,m),build(2*v+2,m,r);pull(v);}
  }
  void add(int v,int l,int r,int ql,int qr){
    if(r<=ql or qr<=l or tt[v]<=2)return;
    else if(ql<=l and r<=qr and l+1==r)apply(v);
    else{
      int m=(l+r)>>1;
      add(2*v+1,l,m,ql,qr),add(2*v+2,m,r,ql,qr);
      pull(v);
    }
  }
  void init(int n_){nn=n_;build(0,0,nn);}
  ll query(int v,int l,int r,int ql,int qr){
    if(r<=ql or l>=qr)return 0;
    if(ql<=l and qr>=r)return t[v];
    ll m=(l+r)>>1,res;
    res=query(2*v+1,l,m,ql,qr)+query(2*v+2,m,r,ql,qr);
    return res;
  }
  int qmax(int v,int l,int r,int ql,int qr){
    if(r<=ql or l>=qr)return -1e6;
    if(ql<=l and qr>=r)return tt[v];
    int m=(l+r)>>1,res;
    res=max(qmax(2*v+1,l,m,ql,qr),qmax(2*v+2,m,r,ql,qr));
    return res;
  }
} seg;
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;rep(i,0,n)cin>>s[i]; seg.init(n);
  rep(i,1,_d+1)for(int j=i;j<=_d;j+=i)d[j]++;
  while(m--){
    int t,l,r;cin>>t>>l>>r;
    if(t==1)seg.add(0,0,n,l-1,r);
    else cout<<seg.query(0,0,n,l-1,r)<<'\n';
  }
  return 0;
}