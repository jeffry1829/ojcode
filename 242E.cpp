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
inline int pmod(int x, int divisor){int m = x % divisor;return m + ((m >> 31) & divisor);}
//head
const int _n=2e5+10;
int t,l,r,x,n,m,a[_n];
class Seg{
  public:
  int nn;
  int t[_n<<2],laz[_n<<2];
  void pull(int v){t[v]=t[2*v+1]+t[2*v+2];}
  void apply(int v,int len){t[v]=len-t[v],laz[v]=(laz[v]?0:len);}
  void push(int v){
    if(laz[v])apply(2*v+1,laz[v]/2),apply(2*v+2,laz[v]/2+laz[v]%2),laz[v]=0;
  }
  void build(int v,int l,int r,int b){
    if(l+1==r)t[v]=((a[l]&(1<<b))>0);
    else{int m=(l+r)>>1;build(2*v+1,l,m,b),build(2*v+2,m,r,b);pull(v);}
  }
  void add(int v,int l,int r,int ql,int qr){
    if(r<=ql or qr<=l)return;
    else if(ql<=l and r<=qr)apply(v,r-l);
    else{
      push(v);int m=(l+r)>>1;
      add(2*v+1,l,m,ql,qr),add(2*v+2,m,r,ql,qr);
      pull(v);
    }
  }
  void add(int l,int r){add(0,0,nn,l,r);}
  void init(int n_,int b){nn=n_;build(0,0,nn,b);}
  int query(int v,int l,int r,int ql,int qr){
    if(r<=ql or l>=qr)return 0;
    if(ql<=l and qr>=r)return t[v];
    int m=(l+r)>>1,res;push(v);
    res=query(2*v+1,l,m,ql,qr)+query(2*v+2,m,r,ql,qr);
    pull(v);return res;
  }
};
Seg STs[21];
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n;rep(i,0,n)cin>>a[i];
  rep(i,0,21)STs[i].init(n,i);
  cin>>m;while(m--){
    cin>>t;
    if(t==1){
      cin>>l>>r;l--;
      ll res=0;rep(i,0,21)res+=1ll*(STs[i].query(0,0,n,l,r))*(1<<i);
      cout<<res<<'\n';
    }else{
      cin>>l>>r>>x;l--;
      rep(i,0,21)if(x&(1<<i))STs[i].add(l,r);
    }
  }
  return 0;
}