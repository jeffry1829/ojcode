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
  inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
//head
const int _n=1010;
int t,n,x,y,g,A,B,C,cnt;
PII pts[_n];
struct L{
  int A,C,B;
  bool operator<(const L& rhs)const{
    if(A==rhs.A){
      if(B==rhs.B)return C<rhs.C;
      return B<rhs.B;
    }return A<rhs.A;
  }
};
map<L,int> mp;
map<PII,int> mp2;
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n;rep(i,1,n+1)cin>>pts[i].fi>>pts[i].se;
  rep(i,1,n)rep(j,i+1,n+1){
    x=pts[j].fi-pts[i].fi,y=pts[j].se-pts[i].se,g=__gcd(abs(x),abs(y));
    A=y/g,C=x/g,B=(pts[i].fi*pts[j].se-pts[j].fi*pts[i].se)/g;
    if(A<0)A=-A,C=-C,B=-B;if(A==0 and C<0)C=-C,B=-B;
    if(!mp[{A,C,B}]){
      mp[{A,C,B}]++,mp2[{A,C}]++,cnt++;
    }
  }ll ans=0;
  for(auto it=mp2.begin();it!=mp2.end();it++){
    A=it->fi.fi,C=it->fi.se;
    ans+=1ll*mp2[{A,C}]*(cnt-mp2[{A,C}]);
  }cout<<ans/2<<'\n';
  return 0;
}