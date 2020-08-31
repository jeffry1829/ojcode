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
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
//#define end aononcncnccc
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
//head
const int _n=1e6+10;
int t,n,m;
const int _N = _n;  // str len
const int _p1 = 31, _M = 1000000009;
int pnM[_N] = {0};  // p^n mod M
int hp[_N] = {0};   // hash prefix
char p[_N];
int lenp,y[_n];

inline void genpnM() {
  int res = 1;  //p^0%M
  pnM[0] = 1;
  for (int i = 1; i < _N; i++) pnM[i] = res = (res * 1ll * _p1) % _M;
}
inline void genhp() {  //hp[n]=hash prefix[0,n)
  int res = 0;
  hp[0] = 0;  //[0,0) is empty string
  for (int i = 1; i <= lenp; i++) hp[i] = res = (res * 1ll * _p1 + p[i - 1] * 1ll) % _M;
}
inline int dhash(char s[]) {  //direct hash
  int len = strlen(s);
  int res = 0;
  for (int i = 1; i <= len; i++) res = (res * 1ll * _p1 + s[i - 1] * 1ll) % _M;
  return res;
}
inline int hashlr(int l, int r) {  //[l,r)
  int tmp = hp[r] * 1ll - pnM[r - l] * 1ll * hp[l] % _M;
  if (tmp < 0) tmp += _M;
  return tmp;
}
//以上是rolling hash模板
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>p;lenp=strlen(p);rep(i,0,m){cin>>y[i];y[i]--;}
  genpnM();genhp();
  int cnt=y[0];rep(i,1,m){
    if(y[i-1]+lenp-1>=y[i]){
      if(hashlr(y[i]-y[i-1],lenp)!=hashlr(0,lenp-(y[i]-y[i-1]))){
        cout<<0<<'\n';return 0;
      }
    }
    else cnt+=y[i]-(y[i-1]+lenp-1)-1;
  }cnt+=n-(y[m-1]+lenp);
  if(m==0)cnt=n;
  cout<<powmod(26,cnt)<<'\n';
  return 0;
}