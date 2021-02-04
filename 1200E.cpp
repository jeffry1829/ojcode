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
const int _n=1e5+10;
int t,tt,n;
string s[_n],res;

typedef unsigned long long ull; 
//Generate random p in (before, after) open interval:
//max(a[i]) < p < M
int gen_p(const int before, const int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}
struct PolyHash{
  static const int M=1e9+123; //M2=2^64, which use the fact that ull automatically % 2^64
  static vector<int> pow1; //p^i%M
  static vector<ull> pow2; //p^i%2^64
  static int p;
  static void genpnM(int nn){
    while(SZ(pow1)<=nn)pow1.pb(1ll*pow1.back()*p%M),pow2.pb(pow2.back()*p);
  }
  vector<int> pref1; //hash prefix modulo M
  vector<ull> pref2; //.. modulo 2^64
  PolyHash()=default;
  //Calculate for s
  PolyHash(string& s){calc(s,0,SZ(s));}
  //Calculate the characters appended after the initialization
  //[l,r), i.e. calc pref[l+1]~pref[r]
  //pref[0]=0
  void calc(string& s,int l,int r){
    if(r+1>SZ(pref1)){pref1.resize(r+1,0);pref2.resize(r+1,0);}
    assert(p<M); genpnM(r); rep(i,l+1,r+1){
      assert(p>s[i]); //pref[i] is prefix for [0,i)
      pref1[i]=(1ll*pref1[i-1]*p+1ll*s[i-1])%M;
      pref2[i]=pref2[i-1]*p+s[i-1];
    }
  }
  //[l,r)
  pair<int,ull> operator()(int l,int r){
    int h1=pref1[r]-1ll*pow1[r-l]*pref1[l]%M;
    if(h1<0)h1+=M;
    ull h2=pref2[r]-pow2[r-l]*pref2[l];
    return {h1,h2};
  }
};
//Need this init
int PolyHash::p(1e9+7);
vector<int> PolyHash::pow1{1};
vector<ull> PolyHash::pow2{1};
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;rep(i,0,n)cin>>s[i]; res=s[0];
  PolyHash::p=gen_p(256,PolyHash::M);
  PolyHash ph1(res),ph2; tt=SZ(res);
  rep(i,1,n){
    ph2.calc(s[i],0,SZ(s[i]));
    t=0;per(j,1,min(SZ(res),SZ(s[i]))+1)
      if(ph1(SZ(res)-j,SZ(res))==ph2(0,j)){t=j;break;}
    rep(j,t,SZ(s[i]))res+=s[i][j];
    ph1.calc(res,tt,SZ(res)); tt=SZ(res);
  }cout<<res<<'\n';
  return 0;
}