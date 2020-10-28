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
//#define abs(x) (((x)<0)?(-(x)):(x))
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
const db eps=1e-8,pi=acos(-1);
bool same(db a,db b){return abs(a-b)<eps;}
db sq(db x){return x*x;}
struct P{
  db x,y;
  P():x(0),y(0){}
  P(db x,db y):x(x),y(y){}
  P operator+(P b){return P(x+b.x,y+b.y);}
  P operator-(P b){return P(x-b.x,y-b.y);}
  P operator*(db b){return P(x*b,y*b);}
  P operator/(db b){return P(x/b,y/b);}
  db operator*(P b){return x*b.x+y*b.y;}
  db operator^(P b){return x*b.y-y*b.x;}
  db abs(){return hypot(x,y);}
  P unit(){return *this/abs();}
  P spin(db o){
    db c=cos(o),s=sin(o);
    return P(c*x-s*y,s*x+c*y);
  }
  db angle(){return atan2(y,x);}
};
struct C{
  P c;
  db r;
  C(P c=P(0,0),db r=0):c(c),r(r){}
};
vector<pair<db,db>> CoverSegment(C &a,C &b){
  db d=(a.c-b.c).abs();
  vector<pair<db,db>> res;
  if(same(a.r+b.r,d));
  else if(d<=abs(a.r-b.r)+eps){
    if(a.r<b.r)res.pb({0,2*pi});
  }else if(d<abs(a.r+b.r)-eps){
    db o=acos((sq(a.r)+sq(d)-sq(b.r))/(2*a.r*d)),z=(b.c-a.c).angle();
    if(z<0)z+=2*pi;
    db l=z-o,r=z+o;
    if(l<0)l+=2*pi;if(r>2*pi)r-=2*pi;
    if(l>r)res.pb({l,2*pi}),res.pb({0,r});
    else res.pb({l,r});
  }return res;
}
db CircleUnionArea(vector<C> c){//circles should be distinct
  db res=0;
  rep(i,0,SZ(c)){
    db w=0;vector<pair<db,db>> s={{2*pi,9}},z;
    rep(j,0,SZ(c))if(i!=j){
      z=CoverSegment(c[i],c[j]);
      for(auto &e:z)s.pb(e);
    }sort(all(s));
    auto f=[&](db t){return c[i].r*(c[i].c.x*sin(t)-c[i].c.y*cos(t)+c[i].c.y+c[i].r*t);};
    for(auto &e:s){
      if(e.fi>w)res+=f(e.fi)-f(w);
      w=max(w,e.se);
    }
  }return res/2;
}
const int _n=110;
db t,n,r,x,y;
vector<C> a;
vector<PII> ps;
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>r;rep(i,0,n){cin>>x>>y;ps.pb({x,y});}
  int nn=unique(all(ps))-ps.begin();rep(i,0,nn)a.pb(C({ps[i].fi,ps[i].se},r));
  cout<<fixed<<setprecision(2)<<round(CircleUnionArea(a)*100)/100<<'\n';
  return 0;
}