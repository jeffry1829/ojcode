#pragma GCC optimize(1)
#pragma GCC optimize(2)
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
#define abs(x) ((x<0)?(-x):(x))
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
//head
const int _n=5e5+10;
int n,m[_n],l[_n],r[_n];
ll pre[_n],suf[_n];
VI ans;
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n;rep(i,0,n)cin>>m[i];
  stack<int> s;rep(i,0,n){
    while(!s.empty() and m[s.top()]>m[i])s.pop();
    l[i]=s.empty()?-1:s.top();
    s.push(i);
  }
  while(!s.empty())s.pop(); per(i,0,n){
    while(!s.empty() and m[s.top()]>m[i])s.pop();
    r[i]=s.empty()?-1:s.top();
    s.push(i);
  }
  pre[0]=m[0],suf[n-1]=m[n-1];
  rep(i,1,n){
    if(l[i]==-1)pre[i]=1ll*(i+1)*m[i];
    else pre[i]=pre[l[i]]+1ll*(i-l[i])*m[i];
  }
  per(i,0,n-1){
    if(r[i]==-1)suf[i]=1ll*(n-i)*m[i];
    else suf[i]=suf[r[i]]+1ll*(r[i]-i)*m[i];
  }
  pair<ll,ll> maxx={-2e9,-1};
  rep(i,0,n)
    if(pre[i]+suf[i]-m[i]>maxx.fi)maxx.fi=pre[i]+suf[i]-m[i],maxx.se=i;
  int tmp=2e9;per(i,0,maxx.se){if(tmp>m[i])tmp=m[i]; ans.pb(tmp);}
  reverse(all(ans));tmp=2e9;
  rep(i,maxx.se,n){if(tmp>m[i])tmp=m[i]; ans.pb(tmp);}
  rep(i,0,SZ(ans))cout<<ans[i]<<' ';
  cout<<'\n';
  return 0;
}