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
int tt,n,m,a[_n],b[_n],x,y,k;
struct M{int x,y,k;};
M res;
namespace Seg{
  int nn;
  M t[_n<<2],laz[_n<<2];
  void pull(int v){}
  void apply(int v, M val){t[v]=val,laz[v]=val;}
  void push(int v){
    if(laz[v].k!=0)apply(2*v+1,laz[v]),apply(2*v+2,laz[v]),laz[v]={0,0,0};
  }
  void build(int v, int l, int r){
    if(l+1==r)t[v]={0,0,0};
    else{int m=(l+r)>>1;build(2*v+1,l,m),build(2*v+2,m,r);pull(v);}
  }
  void add(int v,int l,int r,int ql,int qr,M val){
    if(r<=ql or qr<=l)return;
    else if(ql<=l and r<=qr)apply(v,val);
    else{
      push(v);int m=(l+r)>>1;
      add(2*v+1,l,m,ql,qr,val),add(2*v+2,m,r,ql,qr,val);
      pull(v);
    }
  }
  void add(int l,int r,M val){add(0,0,nn,l,r,val);}
  void add(int pos,M val){add(0,0,nn,pos,pos+1,val);}
  void init(int n_){nn=n_;build(0,0,nn);}
  void chk(int v,int l,int r,int pos){
    int m=(l+r)>>1;if(l+1==r){res=t[v];return;}
    push(v);
    if(pos<m)chk(2*v+1,l,m,pos);
    else chk(2*v+2,m,r,pos);
  }
}
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;rep(i,0,n)cin>>a[i];rep(i,0,n)cin>>b[i];
  Seg::init(n);
  while(m--){
    cin>>tt;
    if(tt==1){
      cin>>x>>y>>k;x--,y--;
      Seg::add(y,y+k,{x,y,k});
    }
    if(tt==2){
      cin>>x;x--;
      Seg::chk(0,0,n,x);
      if(res.k!=0)cout<<a[res.x+(x-res.y)]<<'\n';
      else cout<<b[x]<<'\n';
    }
  }
  return 0;
};