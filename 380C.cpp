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
inline int pmod(int x, int divisor){int m = x % divisor;return m + ((m >> 31) & divisor);}
//head
const int _n=1e6+10;
ll n,m;
char s[_n];
struct WE{ll a,b,c;};
namespace Seg{
  int nn;
  ll a[_n<<2],b[_n<<2],c[_n<<2];
  void pull(int v){
    ll t=min(b[2*v+1],c[2*v+2]);
    a[v]=a[2*v+1]+a[2*v+2]+t;
    b[v]=b[2*v+1]+b[2*v+2]-t;
    c[v]=c[2*v+1]+c[2*v+2]-t;
  }
  void build(int v, int l, int r){
    if(l+1==r){
      if(s[l]=='(')b[v]=1;
      else c[v]=1;
    }
    else{int m=(l+r)>>1;build(2*v+1,l,m),build(2*v+2,m,r);pull(v);}
  }
  WE query(int v,int l,int r,int ql,int qr){ //懶標記未確認運作
    if(r<=ql or l>=qr)return {0,0,0};
    if(ql<=l and qr>=r)return {a[v],b[v],c[v]};
    int m=(l+r)>>1; WE res,rl,rr;
    rl=query(2*v+1,l,m,ql,qr),rr=query(2*v+2,m,r,ql,qr);
    ll t=min(rl.b,rr.c);
    res.a=rl.a+rr.a+t;
    res.b=rl.b+rr.b-t;
    res.c=rl.c+rr.c-t;
    pull(v);return res;
  }
  void init(ll n_){nn=n_;build(0,0,nn);}
}
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>s>>m;n=strlen(s);Seg::init(n);
  while(m--){
    int ll,rr;cin>>ll>>rr;ll--,rr--;cout<<Seg::query(0,0,n,ll,rr+1).a*2ll<<'\n';
  }
  return 0;
}